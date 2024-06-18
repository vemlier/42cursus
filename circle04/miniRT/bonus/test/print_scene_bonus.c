#include <stdio.h>
#include "test.h"

void	print_scene(t_scene *s)
{
	t_obj	**obj;
	t_light **l;
	int			i;
	
	i = 0;
	printf("\n\nscene info\n\ncamera: ");
	print_camera(s->camera);
	printf("\n\nobjects: ");
	obj = s->objects;
	for (int i = 0; i < s->ob_n; i++)
	{		
		print_obj(obj[i]);
	}
	l = s->lights;
	printf("\n\nlights: ");
	for (int i = 0; i < s->l_n; i++)
		print_light(l[i]);
	printf("\n\nambient: ");
	print_vector(s->ambient);
	printf("\n\nambient_ratio: %lf\nwidth: %d\nheight: %d\nlights_num: %d\nobjects_num: %d\n", s->ambient_ratio, s->width, s->height, s->l_n, s->ob_n);	
}
