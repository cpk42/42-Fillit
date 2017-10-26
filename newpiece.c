/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:39:56 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/26 15:10:06 by ckrommen         ###   ########.fr       */
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
