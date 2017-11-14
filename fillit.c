
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:38:41 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/13 17:20:35 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	placeable(char **grid, t_piece *head, int row, int col)
{
  int i;

  i = 0;
  translate(head, row, col);
  while (i < 4)
    {
      if (grid[head->row[i]][head->col[i]] != '.')
	return (0);
      i++;
    }
  return (1);
}

int	fillit(int size, int row, char **grid, t_piece **start)
{
	t_piece	*head;
	int		found;
	int		col;

	head = *start;
	if (isempty(start))
		return (1);
	while (row < size - head->h)
	{
		col = 0;
		while (col < size - head->w)
		{
		  found = placeable(grid, head, row, col);
			if (found)
			{
			  if (fillit(size, 0, grid, placepiece(head, grid)))
				    return (1);
			    pickuppiece(head, grid);
			}
			col++;
		}
		row++;
	}
	return (0);
}
