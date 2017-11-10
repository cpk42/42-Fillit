/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:04:53 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/09 16:21:26 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

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
piece	**placepiece(piece *head, char **grid);
void    pickuppiece(piece *head, char **grid);
int		isempty(piece *head, char **grid);
char	**createmap(int size);
int		countpiece(piece **start);
int		tetchecker(char *grid);
void	printgrid(char **map, int size);
piece	*assignletter(piece *head);
int		get_size(piece *lst);
int		solve(int size, int row, char **grid, piece **begin_list);
int		find_sqrt(int n, int nb);
void	*error(char *msg);
piece	*buildpieces(char *map);
void	freegrid(char **grid);
#endif
