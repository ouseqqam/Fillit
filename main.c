/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:30:02 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/07/24 09:24:25 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_2d(char **tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int		main(int ac, char **av)
{
	t_m v;

	if (ac == 2)
	{
		v.d = 2;
		v.fd = open(av[1], O_RDONLY);
		if (ft_check(&v.line, v.fd, &v.n) == 0)
		{
			ft_putendl("error");
			return (0);
		}
		move_to_up(v.line, v.n);
		v.tab = ft_2d(v.d);
		while (ft_set(&v.tab, v.line, v.d) == 0)
		{
			free_2d(v.tab, v.d);
			v.tab = ft_2d(++v.d);
		}
		ft_print_words_tables(v.tab);
		free_2d(v.tab, v.d);
		free(v.line);
		close(v.fd);
	}
	else
		ft_putendl("usage: fillit source_file");
}
