#include <stdio.h>
#include "test.h"

void	print_light(t_light *l)
{
	printf("light info\nposition: ");
	print_vector(l->position);
	printf("color: ");
	print_vector(l->color);
	printf("ratio: %lf\n", l->ratio);
}