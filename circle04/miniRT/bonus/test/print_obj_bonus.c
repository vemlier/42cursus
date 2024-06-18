#include <stdio.h>
#include "test.h"

void	print_cylinder(t_cylinder *c)
{
	printf("cylinder info\n");
	printf("bot: ");
	print_vector(c->bottom);
	printf("top: ");
	print_vector(c->top);	
	printf("direction: ");
	print_vector(c->direction);
	printf("diameter: %lf\nheight: %lf\n", c->diameter, c->height);
}

void	print_plane(t_plane *p)
{
	printf("plane info\n");
	printf("point: ");
	print_vector(p->point);
	printf("nv: ");
	print_vector(p->nv);
}

void	print_sphere(t_sphere *s)
{
	printf("sphere info\ncenter: ");
	print_vector(s->center);
	printf("radius: %lf\n", s->radius);
}

void	print_material(t_material *t)
{
	printf("material info\nmat_color_1: ");
	print_vector(t->m_c1);
	printf("mat_color_2: ");
	print_vector(t->m_c2);
	printf("diffuse: %lf\nspecular: %lf\nreflection: %lf\n", t->m_d, t->m_s, t->m_r);
}

void	print_obj(t_obj *obj)
{
	printf("\nobj info\ntype: _%d_  mat_type: _%d_\n", obj->type, obj->mat_type);
	if (obj->type == Sphere)
		print_sphere(obj->s);
	else if (obj->type == Plane)
		print_plane(obj->p);
	else if (obj->type == Cylinder)
		print_cylinder(obj->c);
	printf("material: ");
	print_material(obj->material);
}
