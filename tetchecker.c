/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quintonponcelet <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:25:52 by quintonpo         #+#    #+#             */
/*   Updated: 2017/11/11 14:29:28 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	linecount(char *grid)
{
	int lc;
	int i;

	lc = 0;
	i = 0;
	while (grid[i])
	{
		if (grid[i] == '\n')
			lc++;
		if (grid[i] == '\n' && grid[i + 1] == '\n')
		{
			if ((lc + 1) % 5 != 0)
				return (0);
			lc = 0;
			i += 2;
		}
		i++;
	}
	return (1);
}

int	hashcount(char *grid)
{
	int hc;

	hc = 0;
	while (*grid)
	{
		if (*grid != '.' && *grid != '#' && *grid != '\n')
			return (0);
		if (*grid == '#')
			hc++;
		grid++;
	}
	if (hc % 4 != 0)
		return (0);
	return (1);
}

int	checkislands(char *grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
		if (grid[i] == '#')
			if (grid[i + 1] != '#' && grid[i - 1] != '#' &&
				grid[i + 5] != '#' && grid[i - 5] != '#')
				return (0);
		i++;
	}
	return (1);
}

/*int charcount(char *grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
*/

int	tetchecker(char *grid)
{
	if (!linecount(grid))
		return (0);
	else if (!hashcount(grid))
		return (0);
	else if (!checkislands(grid))
		return (0);
	return (1);
}
