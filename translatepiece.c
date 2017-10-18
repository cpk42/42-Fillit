/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translatepiece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:38:33 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/16 12:56:28 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	translatepiece(char **grid, piece *head, int row, int col)
{
	size_t	i;

	i = 0;
	translate(head, row, col);
	while (i < 4)
	{
		if (head->row[i] < 0)
		{
			translate(head, row, col+1);
			i = 0;
		}
		else if (grid[head->row[i]][head->col[i]] == '\0')
		{
			translate(head, row, col-1);
		 	i = 0;
		}
		i++;
	}
}
