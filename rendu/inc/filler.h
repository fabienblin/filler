/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 14:08:20 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 14:50:11 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

void	ft_del_grid(t_grid **grid);
void	ft_delsegment(t_seg *seg);
void	ft_delpoint(t_point *p);
t_grid	*ft_new_grid(int x, int y);
t_seg	*ft_newsegment(t_point *a, t_point *b);
t_point	*ft_newpoint(int x, int y);
void	bresenham(t_grid *grid, t_point *a, t_point *b, int val);

#endif
