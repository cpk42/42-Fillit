/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:55:38 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/10 19:57:57 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **av)
{
  	int   size;
	int   solved;
	t_piece *new;
	char *map;
	char **grid;
	
	if (argc != 2)
		return ((int)error("usage: ./fillit target_file"));
	else
	{
		solved = 0;
		map = filetoarr(av[1]);
		if (!ft_strcmp(map, "error"))
			return ((int)error("error"));
		new = buildpieces(map);
		size = get_size(new);
		while (!solved)
	    {
			grid = createmap(size);
			solved = solve(size, 0, grid, &new);
			if (!solved)
				size++;
	    }
		printgrid(grid, size);
		freegrid(grid, size);
	}
}
