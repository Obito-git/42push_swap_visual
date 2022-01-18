#include "visualiser.h"
static int op_count = 0;

void	side_wall(int i)
{
	//yellow();
	printf("%s ", YELLOW);
	if (i % 2 == 0)
		printf("*");
	else
		printf("|");
	printf(" %s", RESET);
	//reset();
}
void	topbot_wall(t_stack *a, t_stack *b, int print_stat)
{
	yellow();
	printf(" ");
	for (int i = 0; i < a->size + b->size + 7; i++)
	{
		if (i % 2 == 0)
			printf("*");
		else
			printf("-");
	}
	reset();
	if (print_stat)
	{
		printf(" Operation count = %d\n", op_count / 2);
		op_count++;
	}
	else
		printf("\n");

}
int visualize(t_stack *a, t_stack *b)
{
	msleep(MS_PAUSE);
	int devisor;
	if (a->size + b->size < 50)
		devisor = 1;
	else if (a->size + b->size < 75)
		devisor = 2;
	else
		devisor = 3;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for (int i = 0; i < a->size + b->size + 7; i++)
	{
		if ((a->size >= 5 && i == (a->size - 5) / 2))
		{
			printf("Stack A");
			i += 5;
		}
		else if (a->size < 5)
		{
			printf("  A  ");
			i += 5;
		}
		else if (i == a->size && b->size < 5)
		{
			printf("      B  ");
			i += 7;
		}
		else if (i > a->size && b->size >= 5 && i - a->size == b->size / 2)
		{
			printf("Stack B");
			i += 5;
		}
		else
			printf(" ");
	}
	printf("\n");
	topbot_wall(a, b, 0);
	for (int i = (a->size + 1 + b->size) / devisor; i > 0; i--)
	{
		t_elem *ae = a->head;
		t_elem *be = b->head;
		side_wall(i);
		while (ae)
		{
			printf("%s", ae->marker);
			if (ae->high / devisor >= i || i == 1)
				printf("@");
			else
				printf(" ");
			ae = ae->next;
			printf("%s", RESET);
		}
		side_wall(i);
		while (be)
		{
			printf("%s", be->marker);
			if (be->high / devisor >= i)
				printf("@");
			else
				printf(" ");
			be = be->next;
			printf("%s", RESET);
		}
		side_wall(i);
		printf(" \n");
	}
	topbot_wall(a, b, 1);
	msleep(MS_PAUSE);
}
