/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:32:28 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/07/23 14:25:38 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 21

typedef	struct	s_cord
{
	int		x[4];
	int		y[4];
	char	alpha;
}				t_cord;

typedef	struct	s_m
{
	int		fd;
	char	**tab;
	int		d;
	int		n;
	t_cord	*line;
}				t_m;

typedef struct	s_check
{
	int		r;
	int		c;
	char	*p;
	char	*t;
	char	tab[BUFF_SIZE + 1];
	t_cord	*cod;
}				t_check;

typedef	struct	s_var
{
	int		i;
	int		j;
	int		k;
	int		d;
	int		c;
	t_cord	*cod;
}				t_var;

void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *str);
void			ft_putchar(char c);
char			*ft_strnew(size_t size);
void			ft_putendl(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_tetris(char *tab, int r);
int				ft_liaison(char *tab);
int				ft_check(t_cord **line, int fd, int *n);
void			move_to_up(t_cord *cod, int nb);
char			**ft_2d(int n);
int				ft_set(char ***tab, t_cord *tetri, int n);
void			ft_print_words_tables(char **tab);

#endif
