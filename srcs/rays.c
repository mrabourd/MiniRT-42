/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:59:11 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/25 16:41:28 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	t_tuple	pos;

	pos.x = ray.origin.x + (ray.direction.x * t);
	pos.y = ray.origin.y + (ray.direction.y * t);
	pos.z = ray.origin.z + (ray.direction.z * t);
	pos.w = 1;
	return (pos);
}

t_ray	transform_ray(t_ray r, t_matrix_4 m)
{
	t_ray	new;

	new.direction = matrix_mult_tuple(m, r.direction);
	new.origin = matrix_mult_tuple(m, r.origin);
	return (new);
}
