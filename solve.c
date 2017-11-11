/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:38:41 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/11 13:41:52 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	placeable(char **grid, t_piece *head, int row, int col, int size)
{
	translatepiece(grid, head, row, col, size);
	if (isempty(head, grid))
		return (1);
	return (0);
}

int	solve(int size, int row, char **grid, t_piece **start)
{
	t_piece	*head;
	int		found;
	int		col;

	head = *start;
	if (!head)
		return (1);
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			found = placeable(grid, head, row, col, size);
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
