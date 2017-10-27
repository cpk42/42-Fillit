/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countpiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:45:56 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/25 21:12:55 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	countpiece(char *arr)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		if (arr[i] == '#')
			count++;
		i++;
	}
	return (count /= 4);
}