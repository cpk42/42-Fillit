/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:38:41 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/26 16:44:22 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piecesplaced(piece *head)
{
	if (!head)
		return (1);
	else if (!head->placed)
		return (0);
	else
		piecesplaced(head->next);
	return (0);
}

void	pieceadd(piece **alst, piece *new)
{
	new->next = *alst;
	*alst = new;
}

void	solve(char **grid, piece *head, int row, int col, int size)
{
	piece *ptr;

	ptr = head;
	printgrid(grid);
	if (!grid)
		grid = createmap(size);
	if (piecesplaced(head))
	{
		printgrid(grid);
		printf("here\n");
	}
	else
	{
		while (ptr->placed && ptr->next)
			ptr = ptr->next;
		translatepiece(grid, ptr, row, col, size);
		printf("row: %d col: %d\n", row, col);
		if (isempty(head, grid))
		{
			printf("here\n");
			placepiece(ptr, grid);
			if (grid[row][col+1] != '\0')
				solve(grid, head, row, col+1, size);
			else if (grid[row+1][col])
				solve(grid, head, row+1, 0, size);
			while (ptr->next)
			{
				pickuppiece(ptr, grid);
				ptr = ptr->next;
			}
		}
		else
			if (grid[row][col+1] != '\0')
				solve(grid, head, row, col+1, size);
			else
				solve(grid, head, row+1, 0, size);
	}
}

