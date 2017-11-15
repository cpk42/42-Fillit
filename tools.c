/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:16:22 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/14 17:58:31 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_sqrt(int n, int nb)
{
	if (n * n > nb)
		return (0);
	if (n * n == nb)
		return (n);
	else
		return (find_sqrt(n + 1, nb));
}

int		get_size(t_piece *new)
{
	unsigned int size;
	unsigned int i;

	size = countpiece(&new);
	size *= 4;
	i = 0;
	while (!i)
	{
		i = find_sqrt(1, size);
		size++;
	}
	return (i);
}

char	*filetoarr(char *av)
{
	char	*s;
	int		i;
	int		fd;
	char	buf;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return ("error");
	if (fd == 0)
		return ("error");
	s = (char *)malloc(sizeof(char) * 547);
	while (read(fd, &buf, 1))
	{
		s[i] = buf;
		i++;
		if (i >= 547)
			return ("error");
	}
	s[i] = '\0';
	if (!tetchecker(s))
		return ("error");
	close(fd);
	return (s);
}

int		isempty(t_piece **head)
{
	t_piece *ptr;

	ptr = *head;
	while (ptr)
	{
		if (ptr->placed)
			ptr = ptr->next;
		else
			return (0);
	}
	return (1);
}

int		ishash(char c)
{
	if (c == '#')
		return (1);
	return (0);
}
