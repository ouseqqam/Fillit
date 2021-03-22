/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:10:54 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/07/23 13:30:54 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_2d(int n)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		j = 0;
		while (j < n)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int		test(t_cord cod, char **map, int i, int j)
{
	int k;
	int n;

	n = 0;
	k = 0;
	while (map[n])
		n++;
	while (k < 4)
	{
		if (cod.x[k] + i >= n || cod.y[k] + j >= n)
			return (0);
		k++;
	}
	if (map[cod.x[0] + i][cod.y[0] + j] != '.'
			|| map[cod.x[1] + i][cod.y[1] + j] != '.'
			|| map[cod.x[2] + i][cod.y[2] + j] != '.'
			|| map[cod.x[3] + i][cod.y[3] + j] != '.')
		return (0);
	return (1);
}

void	placer(t_cord cod, char **map, int i, int j)
{
	map[cod.x[0] + i][cod.y[0] + j] = cod.alpha;
	map[cod.x[1] + i][cod.y[1] + j] = cod.alpha;
	map[cod.x[2] + i][cod.y[2] + j] = cod.alpha;
	map[cod.x[3] + i][cod.y[3] + j] = cod.alpha;
}

void	efface(char **tab, char c, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (tab[i][j] == c)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_set(char ***tab, t_cord *tetri, int n)
{
	int i;
	int j;

	i = 0;
	if ((*tetri).x[0] == -1)
		return (1);
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (test(*tetri, *tab, i, j) == 1)
			{
				placer(*tetri, *tab, i, j);
				if (ft_set(tab, ++tetri, n))
					return (1);
				tetri--;
				efface(*tab, (*tetri).alpha, n);
			}
			j++;
		}
		i++;
	}
	return (0);
}
