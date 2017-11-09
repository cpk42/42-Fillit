/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialpiece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:22:53 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/06 15:24:55 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

piece	*initialpiece()
{
	piece	*new;

	if (!(new = malloc(sizeof(piece))))
		return (NULL);
	new->letter = 'A';
	new->placed = 0;
	ft_bzero(new->row, 4);
	ft_bzero(new->col, 4);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
