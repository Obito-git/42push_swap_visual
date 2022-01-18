#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "get_next_line/get_next_line.h"

#ifndef MS_PAUSE
	#define MS_PAUSE 50
#endif
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define GREEN "\033[0;32m"
#define RED "\033[1;31m"

typedef struct s_elem
{
	int	value;
	int	high;
	char *marker;
	struct s_elem	*next;
} t_elem;

typedef struct s_stack {
	char	name;
	int		size;
	struct s_elem	*last;
	struct s_elem	*head;
}	t_stack;

//STACK
t_stack *create_stack(char name);
int		add_element(t_stack **st, int value);
void	free_stack(t_stack *a, t_stack *b);
void	set_minmax(t_stack *st);

//print
int visualize(t_stack *a, t_stack *b);
void	current_operation(char *op);

//OPERATIONS
void	push(t_stack *from, t_stack *to);
void	swap(t_stack *a, t_stack *b);
void	rotate(t_stack *st, t_stack *pr);
void	revrotate(t_stack *st, t_stack *pr);

//COLORS
void red ();
void yellow();
void green();
void reset();

//utils
int msleep(long msec);

#endif
