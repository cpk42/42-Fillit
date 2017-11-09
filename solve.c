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

int	placeable(char **grid, piece *head, int row ,int col)
{
      translatepiece(grid, head, row, col, ft_strlen(grid[row]));
      if (isempty(head, grid))
	return (1);
      return (0);
}

int	solve(int size, int row,  char **grid, piece **begin_list)
{
  piece	*lst;
  int   found;
  int   col;

  lst = *begin_list;
  if (!lst)
    return (1);
  while (grid[row])
    {
      col = 0;
      while (grid[row][col])
	{
	  found = placeable(grid, lst, row, col);
	  if (found)
	    {
	      if (solve(size, 0, grid, placepiece(lst, grid)))
		  return (1);
	      pickuppiece(lst, grid);
	    }
	  col++;
	}
      row++;
    }
  return (0);
}
