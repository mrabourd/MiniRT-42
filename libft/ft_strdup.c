/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:23:04 by avedrenn          #+#    #+#             */
/*   Updated: 2023/02/17 14:04:50 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*dup;

	size = 0;
	while (s[size])
		size ++;
	dup = (char *) malloc (size + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = s[i];
		i ++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strdup_size(const char *s, int size)
{
	int		i;
	char	*dup;

	dup = (char *) malloc (size + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = s[i];
		i ++;
	}
	dup[i] = 0;
	return (dup);
}
