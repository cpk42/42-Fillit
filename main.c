/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:55:38 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/06 19:20:20 by ckrommen         ###   ########.fr       */
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
		map = filetoarr(av[1]);
		printf("%d\n", mapsize(map));
//		if (!tetchecker(map))
//			ft_putstr("error\n");
		grid = ft_strsplit(map, '\n');
		free(map);
		new = newpiece();
		new = createpieces(grid, 0, 0, 0, new);
		new = assignletter(new);
//		grid = createmap(6);
//		solve(grid, new, 6, new);
	}
}
