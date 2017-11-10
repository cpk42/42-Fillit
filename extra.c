/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:50:47 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/09 16:04:30 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*error(char *msg)
{
	ft_putendl(msg);
	return (NULL);
}

piece	*buildpieces(char *map)
{
	char	**grid;
	piece	*new;

	grid = ft_strsplit(map, '\n');
	free(map);
	new = newpiece();
	new = createpieces(grid, 0, 0, 0, new);
	new = assignletter(new);
	freegrid(grid);
	return (new);
}

void	freegrid(char **grid)
{
	char *ptr;
	int i;

	i = 0;
	while (grid[i])
	{
		ptr = grid[i];
		free(ptr);
		i++;
	}
}
