/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:07:23 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/24 17:12:07 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printgrid(char **grid)
{
	int row;
	int col;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			ft_putchar(grid[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
