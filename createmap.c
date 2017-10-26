/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:48:17 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/25 21:22:05 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**createmap(int size)
{
	char	**grid;
	int		row;
	int		col;

	row = 0;
	col = 0;
	grid = (char **)malloc(sizeof(char *) * (size + 1));
	while (row < size)
	{
		col = 0;
		grid[row] = ft_strnew(size);
		while (col < size)
		{
			grid[row][col] = '.';
			col++;
		}
		row++;
	}
	return (grid);
}
