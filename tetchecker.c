/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:46:39 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/25 21:03:13 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	tetchecker(char *grid)
{
	int i;
	int count;
	int linecount;

	i = 0;
	linecount = 0;
	while (grid[i])
	{
		count = 0;
		if (grid[i] != '#' && grid[i] != '.' && grid[i] != '\n')
			return (0);
		count = grid[i] == '#' ? count+1 : count;
		if (linecount > 3)
			return (0);
		i++;
		linecount++;
	}
	//printf("count: %d countpiece: %d\n", count, countpiece(grid));
	return (!(count % 4) ? 1 : 0);
}
/*
int main(int argc, char **argv)
{
	char **map;

	argc = 2;
	map = filetoarr(argv[1]);
	ft_putstr(map);
	printf("%d\n", tetchecker(map));
}
*/
