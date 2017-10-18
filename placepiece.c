/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:00:53 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/16 15:58:30 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**placepiece(piece *head, char **grid)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid[head->row[i]][head->col[i]] = '#';
		i++;
	}
	return (grid);
}

int main(int argc, char **av)
{
	piece *new;
	char **map;
	char **grid;

	argc = 2;
	new = newpiece();
	map = filetoarr(av[1]);
	new = newpiece();
	new = createpieces(map, 0, 0, 0, new);
	grid = createmap(new);
	translatepiece(grid, new, 0, 10);
	if (isempty(new, grid))
		placepiece(new, grid);
//	translatepiece(grid, new->next, 0, 2);
//	if (isempty(new->next, grid))
//		placepiece(new->next, grid);
	for (int x = 0; x < 10; x++)
			printf("%s\n", grid[x]);
	//printf("\n");
	//pickuppiece(new->next, grid);
	//for (int x = 0; x < 10; x++)
	//printf("%s\n", grid[x]);
}
