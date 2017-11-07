/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:04:53 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/06 19:18:53 by ckrommen         ###   ########.fr       */
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
	char			letter;
	int				placed;
	int				row[4];
	int				col[4];
	struct piece	*next;
	struct piece	*prev;
}				piece;

char	*filetoarr(char *av);
piece	*newpiece();
piece	*createpieces(char **grid, int row, int col, int i, piece *head);
void	translate(piece *head, int row, int col);
void	translatepiece(char **grid, piece *head, int row, int col, int size);
char	**placepiece(piece *head, char **grid);
char	**pickuppiece(piece *head, char **grid);
int		isempty(piece *head, char **grid);
char	**createmap(int size);
int		countpiece(char *arr);
int		tetchecker(char *grid);
void	printgrid(char **map);
void	solve(char **grid, piece *head, int size, piece *start);
char	**resetgrid(char **grid);
piece	*assignletter(piece *head);
piece	*initialpiece();
int		mapsize(char *map);
//void	freemap(char **grid)

#endif
