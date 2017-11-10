/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:50:47 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/09 17:02:07 by ckrommen         ###   ########.fr       */
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
	freegrid(grid, ft_strlen(*grid));
	return (new);
}

void	freegrid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
}