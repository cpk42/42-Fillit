/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:04:53 by ckrommen          #+#    #+#             */
/*   Updated: 2017/10/16 13:42:13 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "ckrommen/libft.h"

typedef struct	piece
{
//	int				height;
	int				row[4];
	int				col[4];
	struct piece	*next;
}				piece;

char	**filetoarr(char *av);
piece	*newpiece();
piece	*createpieces(char **grid, int row, int col, int i, piece *head);
void	translate(piece *head, int row, int col);
void	translatepiece(char **grid, piece *head, int row, int col);
char	**placepiece(piece *head, char **grid);
char	**pickuppiece(piece *head, char **grid);
int		isempty(piece *head, char **grid);
char	**createmap(piece *head);
int		countpiece(char *arr);

#endif
