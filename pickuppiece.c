/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickuppiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:16:25 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/10 18:40:53 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**pickuppiece(piece *head, char **grid)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid[head->row[i]][head->col[i]] = '.';
		i++;
	}
	return (grid);
}
