/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:55:38 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/26 16:23:49 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **av)
{
	piece *new;
	char *map;
	char **grid;
	
	if (argc != 2)
		ft_putstr("error\n");
	else
	{
		new = newpiece();
		map = filetoarr(av[1]);
//		if (!tetchecker(map))
//			ft_putstr("error\n");
		grid = ft_strsplit(map, '\n');
		free(map);
		new = newpiece();
		new = createpieces(grid, 0, 0, 0, new);
		grid = createmap(6);
		solve(grid, new, 0, 0, 4);
	}
}
	//translatepiece(grid, new->next, 0, 2);
	//if (isempty(new->next, grid))
	//placepiece(new->next, grid);
	//pickuppiece(new->next, grid);
	//for (int x = 0; x < 10; x++)
	//printf("%s\n", grid[x]);
	//if (isempty(new, grid))
	//placepiece(new, grid);
