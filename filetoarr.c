/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetoarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:02:45 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/24 17:38:52 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*filetoarr(char *av)
{
	char	*s;
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
	close(fd);
	return (s);
}
