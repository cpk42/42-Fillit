/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:13:51 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/10 19:40:09 by ckrommen         ###   ########.fr       */
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

void	printgrid(char **grid, int size)
{
	int row;
	int col;
	
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			ft_putchar(grid[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int	isempty(t_piece *head, char **grid)
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

void	translate(t_piece *head, int row, int col)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	if (row > head->row[0])
		x = row - head->row[0];
	else
		while ((head->row[0] + x) != row)
			x--;
	if (col > head->col[0])
		y = col - head->col[0];
	else
		while ((head->col[0] + y) != col)
			y--;
	while (i < 4)
	{
		head->row[i] += x;
		head->col[i] += y;
		i++;
	}
}

void	translatepiece(char **grid, t_piece *head, int row, int col, int size)
{
	size_t	i;

	i = 0;
	translate(head, row, col);
	while (i < 4)
	{
		if (head->col[i] < 0)
			translatepiece(grid, head, row, col+1, size);
		else if (head->row[i] >= size)
			translatepiece(grid, head, row-1, col, size);
		else if (grid[head->row[i]][head->col[i]] == '\0')
			translatepiece(grid, head, row, col-1, size);
		i++;
	}
}
