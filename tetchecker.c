/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quintonponcelet <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:25:52 by quintonpo         #+#    #+#             */
/*   Updated: 2017/11/14 17:21:17 by quintonpo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		linecount(char *grid)
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
			if ((lc + 1) % 5 != 0 || !grid[i + 2])
				return (0);
			lc = 0;
			i += 2;
		}
		i++;
	}
	if (lc > 0)
		if (lc % 4 != 0)
			return (0);
	return (1);
}

int		hashcount(char *grid)
{
	int hc;
	int i;

	hc = 0;
	i = 0;
	while (grid[i])
	{
		if (grid[i] != '.' && grid[i] != '#' && grid[i] != '\n')
			return (0);
		if (grid[i] == '#')
			hc++;
		i++;
	}
	if (hc % 4 != 0)
		return (0);
	if (grid[i - 1] != '\n')
		return (0);
	return (1);
}

int		ishash(char c)
{
	if (c == '#')
		return (1);
	return (0);
}

int		checkislands(char *grid)
{
	int i;
	int c;

	i = 0;
	c = 5;
	while (grid[i])
	{
		if (ishash(grid[i]))
			if (!ishash(grid[i + 1]) && !ishash(grid[i + 5]) &&
				!ishash(grid[i - 1]) && !ishash(grid[i - 5]))
				return (0);
		i++;
	}
	return (1);
}

int		charcount(char *grid)
{
	int i;
	int cc;

	i = 0;
	cc = 0;
	while (grid[i])
	{
		cc = 0;
		while (grid[i] != '\n')
		{
			cc++;
			i++;
		}
		if (cc != 4 && grid[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		tetchecker(char *grid)
{
	if (!linecount(grid))
		return (0);
	else if (!hashcount(grid))
		return (0);
	else if (!checkislands(grid))
		return (0);
	else if (!charcount(grid))
		return (0);
	return (1);
}
