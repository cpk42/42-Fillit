/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:13:16 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/09 13:13:46 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

piece	*newpiece()
{
	piece	*new;
	
	if (!(new = malloc(sizeof(piece))))
		return (NULL);
	new->letter = 'A';
	new->placed = 0;
	ft_bzero(new->row, 4);
	ft_bzero(new->col, 4);
	new->next = NULL;
	return (new);
}


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

piece	*assignletter(piece *head)
{
	char	letter;
	piece	*ptr;
	
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

int	countpiece(piece **start)
{
	piece	*head;
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
