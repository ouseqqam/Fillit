/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:20:36 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/07/22 19:11:24 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min(int a, int b, int c, int d)
{
	int t1;
	int t2;

	t1 = a <= b ? a : b;
	t2 = c <= d ? c : d;
	return (t1 <= t2 ? t1 : t2);
}

void	add_to(t_cord *ele)
{
	int min_x;
	int min_y;
	int i;

	i = 0;
	min_x = min(ele->x[0], ele->x[1], ele->x[2], ele->x[3]);
	min_y = min(ele->y[0], ele->y[1], ele->y[2], ele->y[3]);
	while (i < 4)
	{
		ele->x[i] = ele->x[i] - min_x;
		ele->y[i] = ele->y[i] - min_y;
		i++;
	}
}

void	move_to_up(t_cord *cod, int nb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		add_to(&cod[i]);
		cod[i].alpha = i + 'A';
		i++;
	}
}
