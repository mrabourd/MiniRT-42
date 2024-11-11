/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_forms_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:28:28 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/22 14:31:21 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	init_rgb(t_obj *obj, char *param)
{
	char	**rgb;

	rgb = check_rgb(param);
	if (!rgb)
		return (1);
	obj->color = create_color(ft_atof(rgb[0]),
			ft_atof(rgb[1]), ft_atof(rgb[2]));
	ft_free_arr((void **)rgb);
	obj->color = color_to_unit(obj->color);
	obj->material = init_material();
	obj->material.color = obj->color;
	return (0);
}

int	init_xyz(t_obj *obj, char *param)
{
	char		**xyz;

	xyz = ft_split(param, ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0])
		|| !is_number(xyz[1]) || !is_number(xyz[2]))
		return (ft_free_arr((void **)xyz));
	obj->x = ft_atof(xyz[0]);
	obj->y = ft_atof(xyz[1]);
	obj->z = ft_atof(xyz[2]);
	ft_free_arr((void **)xyz);
	return (0);
}

int	init_sp(char **params, t_obj *sp)
{
	sp->shape = SPHERE;
	sp->closed = 0;
	sp->diameter = set_diameter(params[2]);
	if (sp->diameter <= 0)
		return (1);
	if (init_xyz(sp, params[1]))
		return (1);
	if (init_rgb(sp, params[3]))
		return (1);
	sp->transform = matrix_mult_4(translation(sp->x, sp->y, sp->z), \
					scaling(sp->diameter / 2, sp->diameter / 2,
				sp->diameter / 2));
	return (0);
}

t_matrix_4	pl_transform_matr(t_obj *pl)
{
	t_matrix_4	res;

	res = translation(pl->x, pl->y, pl->z);
	res = matrix_mult_4(res, \
					rotation_x(PI * pl->direction.x));
	res = matrix_mult_4(res, \
					rotation_y(PI * pl->direction.y));
	res = matrix_mult_4(res, \
					rotation_z(PI * pl->direction.z));
	return (res);
}

int	init_plane(char **params, t_obj	*pl)
{
	char		**vec;

	pl->shape = PLANE;
	pl->closed = 0;
	if (init_xyz(pl, params[1]))
		return (1);
	if (init_rgb(pl, params[3]))
		return (1);
	vec = check_vectors(params[2]);
	if (!vec)
		return (1);
	pl->direction = create_vector(ft_atof(vec[0]),
			ft_atof(vec[1]), ft_atof(vec[2]));
	ft_free_arr((void **)vec);
	pl->transform = pl_transform_matr(pl);
	return (0);
}
