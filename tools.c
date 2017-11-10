/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:16:22 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/09 15:47:56 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	find_sqrt(int n, int nb)
{
	if (n * n > nb)
    {
		return (0);
    }
	if (n * n == nb)
    {
		return (n);
    }
	else
    {
		return (find_sqrt(n + 1, nb));
    }
}

int	get_size(piece *lst)
{
	unsigned int size;
	unsigned int i;

	size = countpiece(&lst);
	size *= 4;
	i = 0;
	while (!i)
    {
		i = find_sqrt(1, size);
		size++;
    }
	return (i);
}

piece	**placepiece(piece *head, char **grid)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid[head->row[i]][head->col[i]] = head->letter;
		i++;
	}
	head->placed = 1;
	return (&head->next);
}

void	pickuppiece(piece *head, char **grid)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid[head->row[i]][head->col[i]] = '.';
		i++;
	}
	head->placed = 0;
}

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
