/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:16:22 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/09 13:17:52 by ckrommen         ###   ########.fr       */
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

int	isempty(piece *head, char **grid)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_isalpha(grid[head->row[i]][head->col[i]]))
			return (0);
		else if (grid[head->row[i]][head->col[i]] == '\0')
			return (0);
		else if (i == 3)
			return (1);
		i++;
	}
	return (0);
}
