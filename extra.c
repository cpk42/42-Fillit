/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:50:47 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/14 18:02:59 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*error(char *msg)
{
	ft_putendl(msg);
	return (NULL);
}

t_piece	*buildpieces(char *map)
{
	char	**grid;
	t_piece	*new;

	grid = ft_strsplit(map, '\n');
	free(map);
	new = newpiece();
	new = createpieces(grid, 0, 0, new);
	new = assignletter(new);
	new = assignmax(new);
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

int		findgreatest(int *arr)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (i < 4)
	{
		if (arr[i] > num)
			num = arr[i];
		i++;
	}
	return (num);
}

t_piece	*assignmax(t_piece *head)
{
	t_piece *ptr;

	ptr = head;
	while (head)
	{
		translate(head, 0, 0);
		head->h = findgreatest(head->row);
		head->w = findgreatest(head->col);
		head = head->next;
	}
	return (ptr);
}
