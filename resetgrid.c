/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:26:53 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/02 14:06:47 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**resetgrid(char **grid)
{
	int row;
	int col;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			grid[row][col] = '.';
			col++;
		}
		row++;
	}
	return (grid);
}
