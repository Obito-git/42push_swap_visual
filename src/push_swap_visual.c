#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "visualiser.h"

static int op_count = 0;

int parse(int ac, char **av, t_stack **st)
{
	int	i;
	int	stack_arr[ac];
	int	z;

	i = 0;
	*st = create_stack('a');
	while (i < ac - 1)
	{
		z = 0;
		stack_arr[i] = atoi(av[i + 1]); 
		if ((stack_arr[i] == 0 && (ft_strlen(av[i + 1]) > 1
			|| av[i + 1][0] != '0')) || !(*st))
			return (0);
		while (z < i)
		{
			if (stack_arr[i] == stack_arr[z])
				return (0);
			z++;
		}
		if (!add_element(st, stack_arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
void set_elements_high(t_stack *st)
{
	int i = 0;
	t_elem *tmp = st->head;
	int	*arr = (int *) malloc((st->size + 1) * sizeof(int));
	if (!arr)
		return ;
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	qsort (arr, st->size, sizeof(*arr), comp);
	for (int z = 0; z < st->size; z++)
	{
		tmp = st->head;
		while (tmp->value != arr[z])
			tmp = tmp->next;
		tmp->high = z + 1;
	}
	free(arr);
}
int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b = create_stack('b');
	int op_count = 1;
	
	if (!parse(ac, av, &a))
	{
		printf("Cant parse args numbers\n");
		return (1);
	}
	char *line = NULL;
	int fd = open("operations.log", 'r');
	if (fd < 0)
	{
		return (0);
	}
	set_elements_high(a);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (strcmp(line, "sa\n") == 0)
			swap(a, b);
		else if (strcmp(line, "sb\n") == 0)
			swap(b, a);
		else if (strcmp(line, "pa\n") == 0)
			push(b, a);
		else if (strcmp(line, "pb\n") == 0)
			push(a, b);
		else if (strcmp(line, "ra\n") == 0)
			rotate(a, b);
		else if (strcmp(line, "rb\n") == 0)
			rotate(b, a);
		else if (strcmp(line, "rra\n") == 0)
			revrotate(a, b);
		else if (strcmp(line, "rrb\n") == 0)
			revrotate(b, a);
		else
		{
			printf("Unknown operation: \"%s\"\n", line);
			free(line);
			free_stack(a, b);
			return (-1);
		}
		free(line);
	}
	visualize(a, b);
	close(fd);
	free_stack(a, b);
}
