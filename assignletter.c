/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignletter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:55:58 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/02 13:30:47 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
