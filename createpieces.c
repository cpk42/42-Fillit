/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createpieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:03:33 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/06 15:51:36 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

piece	*dellast(piece *head)
{
	piece *last;
	piece *seclast;

	last = head;
	while (last->next)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	free(last);
	return (head);
}

piece	*createpieces(char **grid, int row, int col, int i, piece *head)
{
	piece	*ptr;

	ptr = head;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			if (grid[row][col] == '#')
			{
				head->row[i] = row;
				head->col[i] = col;
				i++;
				if (i == 4)
				{
					head->next = newpiece();
					head = head->next;
					i = 0;
				}
			}
			col++;
		}
		row++;
	}
	return (dellast(ptr));
}

/*
int main(int argc, char **av)
{
	int fd;
	piece *new;
	char **map;

	new = newpiece();
	fd = open(av[1], O_RDONLY);
	map = ft_createmap(fd, av[1]);
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
	new = newpiece();
	new = createpieces(map, 0, 0, 0, new);
	while (new)
	{
		printf("X: %d Y: %d X: %d Y: %d X: %d Y: %d X: %d Y: %d\n",new->row[0], new->col[0],new->row[1], new->col[1], new->row[2], new->col[2], new->row[3], new->col[3]);
		new = new->next;
	}
}
*/
