/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:38:41 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/09 13:08:08 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	placeable(char **grid, piece *head, int row ,int col)
{
	translatepiece(grid, head, row, col, ft_strlen(grid[row]));
	if (isempty(head, grid))
		return (1);
	return (0);
}

int	solve(int size, int row,  char **grid, piece **start)
{
	piece	*head;
	int   found;
	int   col;
	
	head = *start;
	if (!head)
		return (1);
	while (grid[row])
    {
		col = 0;
		while (grid[row][col])
		{
			found = placeable(grid, head, row, col);
			if (found)
			{
				if (solve(size, 0, grid, placepiece(head, grid)))
					return (1);
				pickuppiece(head, grid);
			}
			col++;
		}
		row++;
    }
	return (0);
}
