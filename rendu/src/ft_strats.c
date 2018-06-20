/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strats.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 19:05:45 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 16:50:32 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"


void	ft_me_surround_box(t_seg *me, t_point prgs, char meChar, t_grid* grid)
{
	if (ft_isme(meChar, grid->data[prgs.y][prgs.x]))
	{
		if (prgs.x >= me->a->x)
			me->a->x = prgs.x < grid->x - 1 ? prgs.x + 1 : prgs.x;
		if (prgs.x < me->b->x)
			me->b->x = prgs.x > 0 ? prgs.x - 1 : prgs.x;
		if (prgs.y >= me->a->y)
			me->a->y = prgs.y < grid->y - 1 ? prgs.y + 1 : prgs.y;
		if (prgs.y < me->b->y)
			me->b->y = prgs.y > 0 ? prgs.y - 1 : prgs.y;
	}
}

void	ft_he_surround_box(t_seg *he, t_point prgs, char meChar, t_grid* grid)
{
	if (ft_isnotme(meChar, grid->data[prgs.y][prgs.x]))
	{
		if (prgs.x >= he->a->x)
			he->a->x = prgs.x < grid->x - 1 ? prgs.x + 1 : prgs.x;
		if (prgs.x < he->b->x)
			he->b->x = prgs.x > 0 ? prgs.x - 1 : prgs.x;
		if (prgs.y >= he->a->y)
			he->a->y = prgs.y < grid->y - 1 ? prgs.y + 1 : prgs.y;
		if (prgs.y < he->b->y)
			he->b->y = prgs.y > 0 ? prgs.y - 1 : prgs.y;
	}
}

void	ft_def_players(t_seg **me, t_seg **he, t_grid *grid, char meChar)
{
	t_point	progress;

	if (!grid)
		return ;
	*he = ft_newsegment(ft_newpoint(0, 0), ft_newpoint(grid->x, grid->y));
	*me = ft_newsegment(ft_newpoint(0, 0), ft_newpoint(grid->x, grid->y));
	progress.y = 0;
	while (progress.y < grid->y)
	{
		progress.x = 0;
		while (progress.x < grid->x)
		{
			ft_me_surround_box(*me, progress, meChar, grid);
			ft_he_surround_box(*he, progress, meChar, grid);
			progress.x++;
		}
		progress.y++;
	}
}

int	ft_strat(t_env *env)
{
	t_seg	*he;
	t_seg	*me;

	ft_delgrid(&env->strat);
	if (env->grid)
	{
		ft_def_players(&me, &he, env->grid, env->meChar);
		env->strat = ft_newgrid(env->grid->x, env->grid->y);
		ft_sides(me, he, env->strat);
		ft_fuse(he, me, env->strat);
		ft_contour(env->grid, env->strat, env->meChar);
		ft_frame(env->grid, env->strat, he);
		ft_gobehind(he, me, env->strat);
		ft_delsegment(&he);
		ft_delsegment(&me);
		return (0);
	}
	return (-1);
}
