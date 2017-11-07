/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignletter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:55:58 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/06 16:16:16 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

piece	*assignletter(piece *head)
{
	char	letter;
	piece	*ptr;
	piece	*prev;

	ptr = head;
	letter = 'A';
	while (head)
	{
		head->letter = letter;
		letter++;
		prev = head;
		head = head->next;
		if (head)
			head->prev = prev;
	}
	return (ptr);
}
