/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strats.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 19:05:45 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 20:42:12 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_me_surround_box(t_seg *me, t_point prgs, char my, t_grid *grid)
{
	if (ft_isme(my, grid->data[prgs.y][prgs.x]))
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

void	ft_he_surround_box(t_seg *he, t_point prgs, char my, t_grid *grid)
{
	if (ft_isnotme(my, grid->data[prgs.y][prgs.x]))
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

void	ft_def_players(t_seg **me, t_seg **he, t_grid *grid, char my)
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
			ft_me_surround_box(*me, progress, my, grid);
			ft_he_surround_box(*he, progress, my, grid);
			progress.x++;
		}
		progress.y++;
	}
}

void	ft_def_positions(t_seg *he, t_seg *me, t_env *env)
{
	env->above = (((me->a->y - me->b->y) / 2) + me->b->y <=
		((he->a->y - he->b->y) / 2) + he->b->y);
	env->under = !env->above;
	env->left = (((me->a->x - me->b->x) / 2) + me->b->x <=
		((he->a->x - he->b->x) / 2) + he->b->x);
	env->right = !env->left;
}

int		ft_strat(t_env *env)
{
	t_seg	*he;
	t_seg	*me;

	ft_delgrid(&env->strat);
	ft_def_players(&me, &he, env->grid, env->my);
	env->strat = ft_newgrid(env->grid->x, env->grid->y);
	ft_def_positions(he, me, env);
	ft_fuse(me, env);
	ft_sides(me, he, env);
	ft_frame(env->strat, he);
	ft_contour(env->grid, env->strat, env->my);
	ft_gobehind(he, env);
	ft_delsegment(&he);
	ft_delsegment(&me);
	return (0);
}
