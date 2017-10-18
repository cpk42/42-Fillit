/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:48:17 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/13 18:02:41 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**createmap(piece *head)
{
	char **grid;
	piece *fuck;
	
	fuck = head;
	grid = (char **)malloc(sizeof(char *) * 10);
	for (int i = 0; i < 10; i++)
	{
		grid[i] = ft_strnew(10);
		for (int j = 0; j < 10; j++)
		{
			grid[i][j] = '.';
		}
	}
	return (grid);
}
/*char	**createmap(char **map, piece *head)//This is all primarily bullshit
{
	char **grid;
	int i;
	int j;

	i = countpieces(head);
	j = 0;
	if (i < 2)
	{
		grid = (char **)malloc(sizeof(char *) * 4);
		while (j < 4)
		{
			grid[j] = ft_strnew(4);
			ft_memset(grid[j], '.', 4);
			j++;
		}
	}
	else
	{
		grid = (char **)malloc(sizeof(char *) * (i + 1));
		while (j < (i + 1))
		{
			grid[j] = ft_strnew(4);
			ft_memset(grid[j], '.', 4);
			j++;
		}
	}
	ft_memdel(map);
	return (grid);
}
*/
