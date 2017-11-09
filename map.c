/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:13:51 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/09 14:00:35 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**createmap(int size)
{
	char	**grid;
	int		row;
	int		col;
	
	row = 0;
	col = 0;
	grid = (char **)malloc(sizeof(char *) * (size + 1));
	while (row < size)
	{
		col = 0;
		grid[row] = ft_strnew(size);
		while (col < size)
		{
			grid[row][col] = '.';
			col++;
		}
		row++;
	}
	return (grid);
}

void	printgrid(char **grid)
{
	int row;
	int col;
	
	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			ft_putchar(grid[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
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
