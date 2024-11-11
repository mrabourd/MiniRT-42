/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:31:09 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/25 15:03:32 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_obj	*void_obj(void)
{
	t_obj		*obj;
	static int	id = 0;

	obj = ft_calloc(1, sizeof(t_obj));
	obj->id = id++;
	obj->shape = SPHERE;
	obj->x = 0;
	obj->y = 0;
	obj->z = 0;
	obj->diameter = 1;
	obj->transform = identity_matrix();
	obj->color = create_color(0, 0, 0);
	obj->material = init_material();
	return (obj);
}

t_obj	*void_plane(void)
{
	t_obj		*obj;
	static int	id = 0;

	obj = ft_calloc(1, sizeof(t_obj));
	obj->id = id++;
	obj->shape = PLANE;
	obj->x = 0;
	obj->y = 0;
	obj->z = 0;
	obj->transform = identity_matrix();
	obj->color = create_color(0, 0, 0);
	obj->material = init_material();
	return (obj);
}

t_obj	*void_cylinder(void)
{
	t_obj		*obj;
	static int	id = 0;

	obj = ft_calloc(1, sizeof(t_obj));
	obj->id = id++;
	obj->shape = CYLINDER;
	obj->x = 0;
	obj->y = 0;
	obj->z = 0;
	obj->radius = 1;
	obj->min = -INFINITY;
	obj->max = INFINITY;
	obj->closed = 0;
	obj->transform = identity_matrix();
	obj->color = create_color(0, 0, 0);
	obj->material = init_material();
	return (obj);
}

void	set_transform(t_obj *s, t_matrix_4 m)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			s->transform.tab[x][y] = m.tab[x][y];
			y++;
		}
		x++;
	}
}
