/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bresenham.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 14:19:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 15:41:40 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

#include <stdio.h>

static void	tracex(t_grid *grid, t_seg *seg, int val)
{
	int x;
	int y;
	int cumul;
	int i;

	x = seg->a->proj_x;
	y = seg->a->proj_y;
	cumul = seg->dx / 2;
	i = 1;
	while (i <= seg->dx)
	{
		x += seg->xinc;
		cumul += seg->dy;
		if (cumul >= seg->dx)
		{
			cumul -= seg->dx;
			y += seg->yinc;
		}
		grid->data[y][x] = val;
		i++;
	}
}

static void	tracey(t_grid *grid, t_seg *seg, int val)
{
	int x;
	int y;
	int cumul;
	int i;

	x = seg->a->proj_x;
	y = seg->a->proj_y;
	cumul = seg->dy / 2;
	i = 1;
	while (i <= seg->dy)
	{
		y += seg->yinc;
		cumul += seg->dx;
		if (cumul >= seg->dy)
		{
			cumul -= seg->dy;
			x += seg->xinc;
		}
		grid->data[y][x] = val;
		i++;
	}
}

void	bresenham(t_grid *strat, t_seg *seg, int val)
{
	if (seg && strat)
	{
		strat->data[seg->a->proj_y][seg->a->proj_x] = val;
		if (seg->dx > seg->dy)
			tracex(strat, seg, val);
		else
			tracey(strat, seg, val);
	}
}