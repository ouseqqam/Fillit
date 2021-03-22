/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:19:51 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/07/22 21:03:02 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_numtetr(char *tab)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
			c++;
		i++;
	}
	return (c / 4);
}

void	var_fonction(int *k, int *i, int *j, int *d)
{
	if (*k == 4)
	{
		*k = 0;
		*i += 1;
		*j = 0;
		(*d)++;
	}
}

void	var(int *i, int *j, int *k, int *l)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*l = 0;
}

t_cord	*detrmine(char *p)
{
	t_var v;

	var(&v.i, &v.c, &v.j, &v.k);
	v.d = 0;
	if (!(v.cod = (t_cord *)malloc(sizeof(t_cord) * (ft_numtetr(p) + 1))))
		return (NULL);
	while (p[v.i] != '\0')
	{
		if (p[v.i] == '#')
		{
			v.cod[v.d].x[v.j] = v.k;
			v.cod[v.d].y[v.j] = v.c % 4;
			v.j++;
		}
		if (p[v.i] != '\n')
			v.c++;
		else if (p[v.i] == '\n')
			v.k++;
		var_fonction(&v.k, &v.i, &v.j, &v.d);
		v.i++;
	}
	v.cod[ft_numtetr(p)].x[0] = -1;
	return (v.cod);
}

int		ft_check(t_cord **line, int fd, int *n)
{
	t_check v;

	v.p = ft_strnew(0);
	while ((v.r = read(fd, v.tab, BUFF_SIZE)))
	{
		v.tab[v.r] = '\0';
		if ((!ft_tetris(v.tab, v.r)) || (!ft_liaison(v.tab)))
		{
			free(v.p);
			return (0);
		}
		v.t = ft_strjoin(v.p, v.tab);
		free(v.p);
		v.p = v.t;
		v.c = v.r;
	}
	if (v.c != 20 || ((*n = ft_numtetr(v.p)) > 26))
	{
		free(v.p);
		return (0);
	}
	v.cod = detrmine(v.p);
	free(v.p);
	*line = v.cod;
	return (1);
}
