/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:55:38 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/11 12:48:05 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **av)
{
	int		size;
	int		solved;
	char	*map;
	char	**grid;
	t_piece	*new;

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
			size = !solved ? size + 1 : size;
		}
		printgrid(grid, size);
		freegrid(grid, size);
	}
}
