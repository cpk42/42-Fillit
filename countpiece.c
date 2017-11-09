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

int	countpiece(piece **begin_list)
{
  piece	*lst;
  int	i;

  i = 0;
  lst = *begin_list;
  while (lst)
    {
      i++;
      lst = lst->next;
    }
  return (i);
}

int	ft_countpiece(char *arr)
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

