/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:14:15 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/13 16:37:08 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	translate(piece *head, int row, int col)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	if (row > head->row[0])
		x = row - head->row[0];
	else
		while ((head->row[0] + x) != row)
			x--;
	if (col > head->col[0])
		y = col - head->col[0];
	else
		while ((head->col[0] + y) != col)
			y--;
	while (i < 4)
	{
		head->row[i] += x;
		head->col[i] += y;
		i++;
	}
/*	
	while ((head->col[0] - y) != col)
		y++;
	i = 0;
	while (i < 4)
	{
//		if ((head->row[i] - x) < 0 || (head->col[i] - y) < 0)//works but takes way to long
//			translatepiece(head, row, col+1);
		head->row[i] -= x;
		head->col[i] -= y;
		i++;
	}
*/
}

/*
int main()
{
	piece *new;

	new = newpiece();
	new->row[0] = 0;
	new->row[1] = 1;
	new->row[2] = 2;
	new->row[3] = 3;
	new->col[0] = 3;
	new->col[1] = 3;
	new->col[2] = 3;
	new->col[3] = 3;
	
	for (int i = 0; i < 4; i++)
		printf("%d %d\n", new->row[i], new->col[i]);
	translatepiece(new, 0, 0);
	for (int i = 0; i < 4; i++)
		printf("%d %d\n", new->row[i], new->col[i]);
}
*/
