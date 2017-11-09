/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:55:38 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/02 20:56:38 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **av)
{
  	int   size;
	int   solved;
	piece *new;
	char *map;
	char **grid;

	if (argc != 2)
		ft_putstr("error\n");
	else
	{
	  solved = 0;
	  map = filetoarr(av[1]);
	  grid = ft_strsplit(map, '\n');
	  free(map);
	  new = newpiece();
	  new = createpieces(grid, 0, 0, 0, new);
	  new = assignletter(new);
	  size = get_size(new);
	  while (!solved)
	    {
	      grid = createmap(size);
	      solved = solve(size, 0, grid, &new);
	      if (!solved)
		size++;
	    }
	  printgrid(grid);
	}
}
