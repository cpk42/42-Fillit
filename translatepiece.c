/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translatepiece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:38:33 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/25 21:44:03 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	translatepiece(char **grid, piece *head, int row, int col, int size)
{
	size_t	i;

	i = 0;
	translate(head, row, col);
	while (i < 4)
	{
		if (head->col[i] < 0)
			translatepiece(grid, head, row, col+1, size);
		else if (head->row[i] == size)
			translatepiece(grid, head, row-1, col, size);
		else if (grid[head->row[i]][head->col[i]] == '\0')
			translatepiece(grid, head, row, col-1, size);
		i++;
	}
}
