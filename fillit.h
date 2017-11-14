/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:04:53 by ckrommen          #+#    #+#             */
/*   Updated: 2017/11/13 17:14:43 by ckrommen         ###   ########.fr       */
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

typedef struct	s_piece
{
	char			letter;
	int				h;
	int				w;
	int				row[4];
	int				col[4];
	struct s_piece	*next;
}				t_piece;

char			*filetoarr(char *av);
t_piece			*newpiece();
t_piece			*createpieces(char **grid, int row, int i, t_piece *head);
void			translate(t_piece *head, int row, int col);
void			translatepiece(char **grid, t_piece *head, int row, int col, int size);
t_piece			**placepiece(t_piece *head, char **grid);
void			pickuppiece(t_piece *head, char **grid);
int				isempty(t_piece *head, char **grid);
char			**createmap(int size);
int				countpiece(t_piece **start);
int				tetchecker(char *grid);
void			printgrid(char **map, int size);
t_piece			*assignletter(t_piece *head);
int				get_size(t_piece *lst);
int				solve(int size, int row, char **grid, t_piece **begin_list);
int				find_sqrt(int n, int nb);
void			*error(char *msg);
t_piece			*buildpieces(char *map);
void			freegrid(char **grid, int size);
int				tetchecker(char *grid);
int				findgreates(int *arr);
void			assignmax(t_piece *head);

#endif
