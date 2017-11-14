/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:13:16 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/13 17:19:23 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*newpiece(void)
{
	t_piece	*new;

	if (!(new = malloc(sizeof(t_piece))))
		return (NULL);
	new->letter = 'A';
	new->h = 0;
	new->w = 0;
	new->placed = 0;
	ft_bzero(new->row, 4);
	ft_bzero(new->col, 4);
	new->next = NULL;
	return (new);
}

t_piece	*dellast(t_piece *head)
{
	t_piece *last;
	t_piece *seclast;

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

t_piece	*createpieces(char **grid, int row, int i, t_piece *head)
{
	t_piece	*ptr;
	int		col;

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
				if (++i == 4)
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

t_piece	*assignletter(t_piece *head)
{
	char	letter;
	t_piece	*ptr;

	ptr = head;
	letter = 'A';
	while (head)
	{
		head->letter = letter;
		letter++;
		head = head->next;
	}
	return (ptr);
}

int		countpiece(t_piece **start)
{
	t_piece	*head;
	int		i;

	i = 0;
	head = *start;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
