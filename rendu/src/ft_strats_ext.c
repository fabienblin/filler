/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strats_ext.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 19:02:48 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 17:50:03 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_contour(t_grid *grid, t_grid *strat, char me)
{
	int x;
	int y;

	y = 0;
	while (y < grid->y)
	{
		x = 0;
		while (x < grid->x)
		{
			if ((x + 1 < grid->x) && ft_isnotme(me, grid->data[y][x + 1]))
				strat->data[y][x] = CONTOUR;
			else if ((x - 1 > 0) && ft_isnotme(me, grid->data[y][x - 1]))
				strat->data[y][x] = CONTOUR;
			else if ((y + 1 < grid->y) && ft_isnotme(me, grid->data[y + 1][x]))
				strat->data[y][x] = CONTOUR;
			else if ((y - 1 > 0) && ft_isnotme(me, grid->data[y - 1][x]))
				strat->data[y][x] = CONTOUR;
			x++;
		}
		y++;
	}
}

void	ft_sides(t_seg *me, t_seg *he, t_env *env)
{
	t_seg	*sega;
	t_seg	*segb;

	if ((env->above && env->left) || (env->under && env->right))
	{
		sega = ft_newsegment(ft_newpoint(me->a->x, me->b->y),
			ft_newpoint(he->a->x, he->b->y));
		segb = ft_newsegment(ft_newpoint(me->b->x, me->a->y),
			ft_newpoint(he->b->x, he->a->y));
	}
	else
	{
		sega = ft_newsegment(ft_newpoint(me->b->x, me->b->y),
			ft_newpoint(he->b->x, he->b->y));
		segb = ft_newsegment(ft_newpoint(me->a->x, me->a->y),
			ft_newpoint(he->a->x, he->a->y));
	}
	bresenham(env->strat, sega, 50);
	bresenham(env->strat, segb, 50);
	ft_delsegment(&sega);
	ft_delsegment(&segb);
}

void	ft_gobehind(t_seg *he, t_env *env)
{
	t_seg	*behinda;
	t_seg	*behindb;

	if (env->above)
		behinda = ft_newsegment(ft_newpoint(he->a->x, he->a->y),
			ft_newpoint(he->b->x, he->a->y));
	else
		behinda = ft_newsegment(ft_newpoint(he->a->x, he->b->y),
			ft_newpoint(he->b->x, he->b->y));
	if (env->left)
		behindb = ft_newsegment(ft_newpoint(he->a->x, he->b->y),
			ft_newpoint(he->a->x, he->a->y));
	else
		behindb = ft_newsegment(ft_newpoint(he->b->x, he->b->y),
			ft_newpoint(he->b->x, he->a->y));
	bresenham(env->strat, behinda, 100);
	bresenham(env->strat, behindb, 100);
	ft_delsegment(&behinda);
	ft_delsegment(&behindb);
}

void	ft_fuse(t_seg *me, t_env *env)
{
	t_seg	*fuse;

	if ((env->above && env->left) || (env->under && env->right))
		fuse = ft_newsegment(ft_newpoint(me->a->x, me->b->y),
			ft_newpoint(me->b->x, me->a->y));
	else
		fuse = ft_newsegment(ft_newpoint(me->a->x, me->a->y),
			ft_newpoint(me->b->x, me->b->y));
	bresenham(env->strat, fuse, 10);
	ft_delsegment(&fuse);
}

void	ft_frame(t_grid *strat, t_seg *he)
{
	int i;

	i = he->b->y;
	while (i < he->a->y + 1)
	{
		if (i == he->b->y || i == he->a->y)
			ft_memset(strat->data[i] + he->b->x, 50, he->a->x - he->b->x + 1);
		else
		{
			strat->data[i][he->b->x] = 50;
			ft_memset(strat->data[i] + he->b->x + 1, 2, he->a->x - he->b->x);
			strat->data[i][he->a->x] = 50;
		}
		i++;
	}
}
