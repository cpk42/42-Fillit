/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetoarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:02:45 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/16 13:52:15 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**filetoarr(char *av)
{
	char	*s;
	char	**grid;
	int		i;
	int		fd;
	char	buf;

	i = 0;
	fd = open(av, O_RDONLY);
	s = (char *)malloc(sizeof(char) * 2048);
	while (read(fd, &buf, 1))
	{
		s[i] = buf;
		i++;
	}
	s[i] = '\0';
	grid = ft_strsplit(s, '\n');
	free(s);
	close(fd);
	return (grid);
}
