/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublelist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:01:18 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/06 15:45:32 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

piece	*dellast(piece *head)
{
	piece *last;
	piece *seclast;

	last = head;
	while (last->next)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	free(last);
	return (head);
}

piece   *createpieces(char **grid, int row, int col, int i, piece *head)
{
	piece *ptr;
	piece *prev;

	ptr = head;
	while (grid[row])
	{
		while (grid[row][col])
		{
			if (grid[row][col] == '#')
			{
				head->row[i] = row;
				head->col[i] = col;
				i++;
				if (i == 4)
				{
					head->next = newpiece();
					prev = head;
					head = head->next;
					head->prev = prev;
					i = 0;
				}
			}
			col++;
		}
		row++;
	}
	return (dellast(ptr));
}
