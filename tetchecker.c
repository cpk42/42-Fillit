/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:46:39 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/09 17:07:19 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int linecount(char *grid)
{
	int lc;
	int cc;

	lc = 0;
	cc = 0;
	while (*grid)
	{
		if (*grid == '\n')
			lc++;
		if (*grid != '\n')
			cc++;
		grid++;
	}
	if (lc % 5 != 0 || cc / lc != 4)
		return (0);
	return (1);
}

int hashcount(char *grid)
{
	int hc;

	hc = 0;
	while (*grid)
	{
		if (*grid != '.' && *grid != '#')
			return (0);
		if (*grid == '#')
			hc++;
		grid++;
	}
	if (hc % 4 != 0)
		return (0);
	return (1);
}

int checkislands(char *grid)
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
