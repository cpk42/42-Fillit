/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:50:47 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/13 17:15:30 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*error(char *msg)
{
	ft_putendl(msg);
	return (NULL);
}

t_piece	*buildpieces(char *map)
{
	char	**grid;
	t_piece	*new;

	grid = ft_strsplit(map, '\n');
	free(map);
	new = newpiece();
	new = createpieces(grid, 0, 0, new);
	new = assignletter(new);
	freegrid(grid, ft_strlen(*grid));
	return (new);
}

void	freegrid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
}

int		find_greatest(int *arr)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (i < 4)
	{
		if (arr[i] > num)
			num = arr[i];
		i++;
	}
	return (num);
}

void	assignmax(t_piece *head)
{
	head->h = find_greatest(head->row);
	head->w = find_greatest(head->col);
}
