/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 14:08:20 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 17:13:51 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONTOUR 20

# include "libft.h"

#include <stdio.h>

typedef struct	s_grid
{
	char	**data;
	int		x;
	int		y;
}				t_grid;

typedef struct	s_point
{
	int	x;
	int	y;
	int	proj_x;
	int	proj_y;
}				t_point;

typedef struct	s_segment
{
	t_point *a;
	t_point *b;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
}				t_seg;

typedef struct	s_env
{
	t_grid	*grid;
	t_grid	*piece;
	t_grid	*strat;
	char	my;
}				t_env;

/*
 * ft_destructors.c
 */
void	ft_delgrid(t_grid **grid);
void	ft_delsegment(t_seg **seg);
void	ft_delpoint(t_point **p);
void	ft_delenv(t_env **env);

/*
 * ft_constructors.c
 */
t_grid	*ft_newgrid(int x, int y);
t_seg	*ft_newsegment(t_point *a, t_point *b);
t_point	*ft_newpoint(int x, int y);
t_env	*ft_newenv(t_grid *grid, t_grid *piece, t_grid *strat, char my);

/*
 * ft_bresenham.c
 */
void	bresenham(t_grid *grid, t_seg *seg, int val);

/*
 * ft_strat/ext.c
 */
void	ft_contour(t_grid *grid, t_grid *strat, char me);
void	ft_sides(t_seg *me, t_seg *he, t_grid *strat);
void	ft_gobehind(t_seg *he, t_seg *me, t_grid *strat);
void	ft_fuse(t_seg *he, t_seg *me, t_grid *strat);
void	ft_frame(t_grid *grid, t_grid *strat, t_seg *he);
int		ft_strat(t_env *env);

/*
 * ft_misc.c
 */
int		ft_isnotme(char me, char c);
int		ft_isme(char me, char c);
void	ft_put_grid(t_grid *grid);

/*
 * ft_init.c
 */
 int	ft_init_my(t_env *env);
 t_env	*ft_init(void);
/*
 * ft_input.c
 */
 int	ft_setgrid(t_env *env);
 int	ft_setpiece(t_env *env);
 
/*
 * ft_play.c
 */
t_point	ft_play(t_env *env);
#endif
