/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:27:21 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/24 17:35:30 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	charcount(char **grid)
{
	int row;
	int col;
	int count;

	row = 0;
	count = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			count++;
			col++;
		}
		row++;
	}
	return (count);
}
