/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isempty.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:03:56 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/02 20:09:15 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	isempty(piece *head, char **grid)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_isalpha(grid[head->row[i]][head->col[i]]))
			return (0);
		else if (grid[head->row[i]][head->col[i]] == '\0')
			return (0);
		else if (i == 3)
			return (1);
		i++;
	}
	return (0);
}
