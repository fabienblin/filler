/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strats_ext.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 19:02:48 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 15:27:39 by fablin      ###    #+. /#+    ###.fr     */
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
				strat->data[y][x] = 50;
			else if ((x - 1 > 0) && ft_isnotme(me, grid->data[y][x - 1]))
				strat->data[y][x] = 50;
			else if ((y + 1 < grid->y) && ft_isnotme(me, grid->data[y + 1][x]))
				strat->data[y][x] = 50;
			else if ((y - 1 > 0) && ft_isnotme(me, grid->data[y - 1][x]))
				strat->data[y][x] = 50;
			x++;
		}
		y++;
	}
}

void	ft_sides(t_seg *me, t_seg *he, t_grid *strat)
{
	t_seg	*segA;
	t_seg	*segB;
	int		above;
	int		under;
	int		left;
	int		right;

	above = (((me->a->y - me->b->y) / 2) + me->b->y <=
		((he->a->y - he->b->y) / 2) + he->b->y);
	under = !above;
	left = (((me->a->x - me->b->x) / 2) + me->b->x <=
		((he->a->x - he->b->x) / 2) + he->b->x);
	right = !left;
	segA = NULL;
	segB = NULL;
	if ((above && left) || (under && right))
	{
		segA = ft_newsegment(ft_newpoint(me->a->x, me->b->y),
			ft_newpoint(he->a->x, he->b->y));
		segB = ft_newsegment(ft_newpoint(me->b->x, me->a->y),
			ft_newpoint(he->b->x, he->a->y));
	}
	else
	{
		segA = ft_newsegment(ft_newpoint(me->b->x, me->b->y),
			ft_newpoint(he->b->x, he->b->y));
		segB = ft_newsegment(ft_newpoint(me->a->x, me->a->y),
			ft_newpoint(he->a->x, he->a->y));
	}
	bresenham(strat, segA, 50);
	bresenham(strat, segB, 50);
	ft_delsegment(&segA);
	ft_delsegment(&segB);
}

void	ft_gobehind(t_seg *he, t_seg *me, t_grid *strat)
{
	t_seg	*behindA;
	t_seg	*behindB;
	int		above;
	int		under;
	int		left;
	int		right;

	above = (((me->a->y - me->b->y) / 2) + me->b->y <=
		((he->a->y - he->b->y) / 2) + he->b->y);
	under = !above;
	left = (((me->a->x - me->b->x) / 2) + me->b->x <=
		((he->a->x - he->b->x) / 2) + he->b->x);
	right = !left;
	behindA = NULL;
	behindB = NULL;
	if (above)
		behindA = ft_newsegment(ft_newpoint(he->a->x, he->a->y),
			ft_newpoint(he->b->x, he->a->y));
	else
		behindA = ft_newsegment(ft_newpoint(he->a->x, he->b->y),
			ft_newpoint(he->b->x, he->b->y));
	if (left)
		behindB = ft_newsegment(ft_newpoint(he->a->x, he->b->y),
			ft_newpoint(he->a->x, he->a->y));
	else
		behindB = ft_newsegment(ft_newpoint(he->b->x, he->b->y),
			ft_newpoint(he->b->x, he->a->y));
	bresenham(strat, behindA, 100);
	bresenham(strat, behindB, 100);
	ft_delsegment(&behindA);
	ft_delsegment(&behindB);
}

void	ft_fuse(t_seg *he, t_seg *me, t_grid *strat)
{
	t_seg	*fuse;
	int above;
	int under;
	int left;
	int right;

	above = (((me->a->y - me->b->y) / 2) + me->b->y <=
		((he->a->y - he->b->y) / 2) + he->b->y);
	under = !above;
	left = (((me->a->x - me->b->x) / 2) + me->b->x <=
		((he->a->x - he->b->x) / 2) + he->b->x);
	right = !left;
	fuse = NULL;
	if ((above && left) || (under && right))
		fuse = ft_newsegment(ft_newpoint(me->a->x, me->b->y),
			ft_newpoint(me->b->x, me->a->y));
	else
		fuse = ft_newsegment(ft_newpoint(me->a->x, me->a->y),
			ft_newpoint(me->b->x, me->b->y));
	bresenham(strat, fuse, 10);
	ft_delsegment(&fuse);
}

void	ft_frame(t_grid *grid, t_grid *strat, t_seg *he)
{
	int i;
	int smallest = (grid->x < grid->y) ? grid->x : grid->y;
	int maxval = smallest % 2 ? smallest / 2 : (smallest + 1) / 2;

	i = he->b->y;
	while (i < he->a->y + 1 )
	{
		if (i == he->b->y || i == he->a->y)
			ft_memset(strat->data[i] + he->b->x, 50, he->a->x - he->b->x + 1);
		else
		{
			strat->data[i][he->b->x] = 50;
			strat->data[i][he->a->x] = 50;
		}
		i++;
	}
}
