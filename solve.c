/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:38:41 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/06 19:12:53 by ckrommen         ###   ########.fr       */
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

piece	*switchlink(piece *head)
{
	piece *temp;

	temp = head;
	head = head->next;
	temp->next = head->next;
	head->next = temp;
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
			{
				return (1);
			}
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
	head = start;
	if (piecesplaced(start))
	{
		printgrid(grid);
		ft_putchar('\n');
	}
	else
	{
		while (head)
		{
			if (!head->placed && placeable(grid, head))
			{
				grid = findideal(grid, head);
				solve(grid, head, size, start);
			}
			else if (!placeable(grid, head) && !head->next)
			{
				resetpieces(start);
				grid = createmap(size+1);
				solve(grid, head , size+1, start);
			}
			head = head->next;
		}
	}
}
void	solve2(char **grid, piece *head, int size, piece *start)
{
	head = start;
	if (piecesplaced(start))
	{
		printgrid(grid);
		ft_putchar('\n');
	}
	else
	{
		while (head)
		{
			if (!head->placed && placeable(grid, head))
			{
				grid = findideal(grid, head);
				solve(grid, head, size, start);
			}
			else if (!placeable(grid, head) && !head->next)
			{
				resetpieces(start);
				solve(grid, head , size+1, start);
			}
			head = head->next;
		}
	}
}
/*
void	solve(char **grid, piece *head, int size, piece *start)
{
	piece	*ptr;

	ptr = head;
	head = start;
	if (piecesplaced(start))
		printgrid(grid);
	else
	{
		while (head->placed)
			head = head->next;
		if (placeable(grid, head))
		{
			grid = findideal(grid, head);
			printgrid(grid);
			ft_putchar('\n');
			solve(grid, ptr, size, start);
		}
		else
		{
			resetpieces(start);
			solve(resetgrid(grid), ptr, size, start);
		}
	}
}
*/
 /*
void	solve(char **grid, piece *head, int size, piece *start)
{
	piece	*ptr;

	ptr = head;
	if (piecesplaced(head))
		printgrid(grid);
	else
	{
		while (ptr->next && ptr->placed)
			ptr = ptr->next;
		if (ptr->placed == 0 && placeable(grid, ptr))
		{
			grid = findideal(grid, ptr);
			ft_putchar(ptr->letter);
			printgrid(grid);
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
////////////////////\/\////\\\\/////\\///\\\\//\/\/\///\\
while (placeable(head) && head)
	{
		grid = findideal(grid, head);
		if (head->next)
			head = head->next;
		else if (piecesplaced(start) && !head->next)
			printgrid(grid);
		else
		{
			while (head->prev)
			{
				if (head->prev->placed)
					head = head->prev;
				else
					findideal(grid, head);
			}
		}
	}

 */
