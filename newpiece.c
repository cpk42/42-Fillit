/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:39:56 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/06 15:46:14 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

piece	*newpiece()
{
	piece	*new;

	if (!(new = malloc(sizeof(piece))))
		return (NULL);
	ft_bzero(new->row, 4);
	ft_bzero(new->col, 4);
	new->letter = 'A';
	new->placed = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
