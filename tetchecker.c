/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quintonponcelet <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:25:52 by quintonpo         #+#    #+#             */
/*   Updated: 2017/11/15 14:17:47 by ckrommen         ###   ########.fr       */
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
			if ((lc + 1) % 5 != 0 || !grid[i + 2] || lc > 5)
				return (0);
			lc = 0;
			i += 2;
		}
		i++;
	}
	if (lc > 0)
		if (lc % 4 != 0 || lc > 4)
			return (0);
	return (1);
}

int		hashcount(char *grid)
{
	int hc;
	int dc;
	int i;

	hc = 0;
	dc = 0;
	i = 0;
	while (grid[i])
	{
		if (grid[i] != '.' && grid[i] != '#' && grid[i] != '\n')
			return (0);
		if (grid[i] == '.')
			dc++;
		if (grid[i] == '#')
			hc++;
		i++;
	}
	if (hc % 4 != 0 || hc < 1 || grid[i - 1] != '\n' || hc * 3 != dc)
		return (0);
	return (1);
}

int		checkislands(char *grid)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (grid[i])
	{
		if (ishash(grid[i]))
		{
			if (ishash(grid[i + 1]))
				c++;
			if (ishash(grid[i + 5]))
				c++;
		}
		if (grid[i] == '\n' && grid[i + 1] == '\n')
		{
			if (c < 3)
				return (0);
			c = 0;
		}
		i++;
	}
	if (c < 3)
		return (0);
	return (1);
}

int		charcount(char *grid)
{
	int cc;
	int i;

	cc = 0;
	i = 0;
	while (grid[i])
	{
		cc++;
		i++;
	}
	if ((cc + 1) % 21 != 0)
		return (0);
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
