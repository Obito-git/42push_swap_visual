#include "visualiser.h"
t_stack *create_stack(char name)
{
	t_stack *st;

	st = (t_stack *) malloc(sizeof(struct s_stack));
	if (!st)
		return (NULL);
	st->name = name;
	st->size = 0;
	st->head = NULL;
	st->last = NULL;
	return (st);
}

int	add_element(t_stack **st, int value)
{
	t_elem *elem;
	t_elem *temp;

	elem = (t_elem *) malloc(sizeof(struct s_elem));
	if (!st || !elem)
		return (0);
	elem->value = value;
	(*st)->size++;
	elem->marker = RESET;
	elem->next = NULL;
	if (!(*st)->head)
	{
		(*st)->head = elem;
		return (1);
	}
	temp = (*st)->head;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	(*st)->last = elem;
	return (1);
}

static void free_all(t_stack *st)
{
	t_elem *tmp;

	while (st && st->head)
	{
		tmp = st->head;
		st->head = st->head->next;
		free(tmp);
	}
	free(st);
}

void free_stack(t_stack *a, t_stack *b)
{
	free_all(a);
	free_all(b);
}
