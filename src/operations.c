#include "visualiser.h"

void	print_stack(t_stack *one, t_stack *two)
{
	char *s;
	if (one->name == 'a')
		visualize(one, two);
	else
		visualize(two, one);
}

void	swap(t_stack *a, t_stack *b)
{
	t_elem	*tmp;

	if (!a || a->size < 2)
		return ;
	a->head->marker = RED;
	a->head->next->marker = GREEN;
	print_stack(a, b);
	tmp = a->head;
	a->head = a->head->next;
	tmp->next = a->head->next;
	a->head->next = tmp;
	if (a->size == 2)
		a->last = a->head->next;
	print_stack(a, b);
	a->head->marker = RESET;
	a->head->next->marker = RESET;
} 

void	push(t_stack *from, t_stack *to)
{
	from->head->marker = RED;

	print_stack(from, to);
	t_elem *new_head;

	if (!from || !from->head || !to)
		return ;
	new_head = from->head;
	from->size--;
	from->head = from->head->next;
	new_head->next = to->head;
	to->head = new_head;
	to->size++;
	print_stack(from, to);
	to->head->marker = RESET;
}


void	rotate(t_stack *st, t_stack *pr)
{
	t_elem	*tmp;
	t_elem	*last_tmp;

	if (!st || !st->head || !st->head->next)
		return ;
	st->head->marker = RED;
	print_stack(st, pr);
	tmp = st->head;
	st->head = st->head->next;
	tmp->next = NULL;
	st->last = tmp;
	last_tmp = st->head;
	while (last_tmp->next)
		last_tmp = last_tmp->next;
	last_tmp->next = tmp;
	print_stack(st, pr);
	st->last->marker = RESET;
}

void	revrotate(t_stack *st, t_stack *pr)
{
	t_elem *tmp;

	if (!st || !st->head || !st->head->next)
		return ;
	tmp = st->head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->marker = RED;
	print_stack(st, pr);
	tmp->next->next = st->head;
	st->head = tmp->next;
	tmp->next = NULL;
	print_stack(st, pr);
	st->head->marker = RESET;
} 
