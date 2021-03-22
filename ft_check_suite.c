/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_suite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:02:11 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/07/22 19:36:36 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_tetr(char *tab)
{
	int i;
	int c;
	int d;

	i = 0;
	c = 0;
	d = 0;
	while (tab[i])
	{
		if (tab[i] == '.')
			c++;
		else if (tab[i] == '#')
			d++;
		i++;
	}
	if (c != 12 || d != 4)
		return (0);
	return (1);
}

int	ft_line(char *tab)
{
	int i;

	i = 4;
	while (tab[i])
	{
		if (tab[i] != '\n')
			return (0);
		if (i != 19)
			i += 5;
		else
			break ;
	}
	return (1);
}

int	ft_tetris(char *tab, int r)
{
	if ((!ft_tetr(tab)) || (!ft_line(tab)))
		return (0);
	if (tab[20] != '\n' && r == 21)
		return (0);
	return (1);
}

int	ft_suiteliason(int c)
{
	if (c != 3 && c != 4)
		return (0);
	return (1);
}

int	ft_liaison(char *tab)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
		{
			if (i < 15)
			{
				if (tab[i + 1] == '#')
					c++;
				if (tab[i + 5] == '#')
					c++;
			}
			else if (i >= 15)
				if (tab[i + 1] == '#')
					c++;
		}
		i++;
	}
	if (!ft_suiteliason(c))
		return (0);
	return (1);
}
