/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:38:41 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/02 21:06:30 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piecesplaced(piece *head)
{
	piece *ptr;

	ptr = head;
	while (ptr)
	{
		if (ptr->placed)
			ptr = ptr->next;
		else
			return (0);
	}
	return (1);
}

void	resetpieces(piece *head)
{
	while (head)
	{
		head->placed = 0;
		head = head->next;
	}
}
/*
char	**findideal(char **grid, piece *head)// TRYING TO MAKE A VERTICAL PLACER FOR IDEAL PLACEMENTS:: ROW IS MAIN INCREMENTER INSTEAD OF COLUMN
{
	int row;
	int col;

	col = 0;
	row = 0;
	while (grid[row][col])
	{
		row = 0;
		while (grid[row])
		{
			translatepiece(grid, head, row, col, ft_strlen(grid[row]));
			if (isempty(head, grid) && !head->placed)
			{
				placepiece(head, grid);
				return (grid);
			}
			row++;
		}
		col++;
	}
	return (grid);
}
*/

char	**findideal(char **grid, piece *head)
{
	int row;
	int col;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			translatepiece(grid, head, row, col, ft_strlen(grid[row]));
			if (isempty(head, grid))
			{
//				printf("is empty: %d\n", isempty(head, grid));
				placepiece(head, grid);
				return (grid);
			}
			col++;
		}
		row++;
	}
	return (grid);
}

piece	*pushtofront(piece *head)
{
	piece *seclast;
	piece *last;

	last = head;
	while (last->next)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = head;
	head = last;
	return (head);
}

int		placeable(char **grid, piece *head)
{
	int row;
	int col;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			translatepiece(grid, head, row, col, ft_strlen(grid[row]));
			if (isempty(head, grid))
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

int		emptygrid(char **grid)
{
	int row;
	int col;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			if (grid[row][col] != '.')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

void	solve(char **grid, piece *head, int size, piece *start)
{
	piece	*ptr;

	ptr = head;
//	if (head == start && emptygrid(grid))
//		solve(createmap(size+1), head, size+1, start);
	if (piecesplaced(head))
		printgrid(grid);
	else
	{
		while (ptr->next && ptr->placed)
			ptr = ptr->next;
		if (ptr->placed == 0 && placeable(grid, ptr))
		{
			grid = findideal(grid, ptr);
			printgrid(grid);
			ft_putchar(ptr->letter);
			ft_putchar('\n');
			solve(grid, head, size, start);
		}
		else
		{
			resetpieces(head);
			solve(resetgrid(grid), pushtofront(head), size, start);
		}
	}
}
