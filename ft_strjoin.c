/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:13:05 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/07/23 11:36:59 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if ((p = (char*)malloc(sizeof(char) * (i + 1))))
		{
			while (s1[j])
			{
				p[j] = s1[j];
				j++;
			}
			while (s2[k])
				p[j++] = s2[k++];
			p[j] = '\0';
			return (p);
		}
	}
	return (0);
}
