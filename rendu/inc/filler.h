/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 14:08:20 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 17:48:07 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define CONTOUR 15

# include "libft.h"

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
	int		above;
	int		under;
	int		left;
	int		right;
}				t_env;

void			ft_delgrid(t_grid **grid);
void			ft_delsegment(t_seg **seg);
void			ft_delpoint(t_point **p);
void			ft_delenv(t_env **env);

t_grid			*ft_newgrid(int x, int y);
t_seg			*ft_newsegment(t_point *a, t_point *b);
t_point			*ft_newpoint(int x, int y);
t_env			*ft_newenv(t_grid *grid, t_grid *piece, t_grid *strat, char my);

void			bresenham(t_grid *grid, t_seg *seg, int val);

void			ft_contour(t_grid *grid, t_grid *strat, char me);
void			ft_sides(t_seg *me, t_seg *he, t_env *env);
void			ft_gobehind(t_seg *he, t_env *env);
void			ft_fuse(t_seg *me, t_env *env);
void			ft_frame(t_grid *strat, t_seg *he);
int				ft_strat(t_env *env);

int				ft_isnotme(char me, char c);
int				ft_isme(char me, char c);
void			ft_put_grid(t_grid *grid);

int				ft_init_my(t_env *env);
t_env			*ft_init(void);

int				ft_setgrid(t_env *env);
int				ft_setpiece(t_env *env);

t_point			ft_play(t_env *env);
#endif
