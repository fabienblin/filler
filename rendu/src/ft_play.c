/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_play.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 14:48:21 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 18:20:27 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		ft_piece_try(t_env *e, int gy, int gx)
{
	int		c;
	t_point	p;
	int		score;

	p.y = -1;
	score = 0;
	c = 0;
	while (c <= 1 && ++p.y < e->piece->y)
	{
		p.x = -1;
		while (c <= 1 && ++p.x < e->piece->x)
		{
			if (c <= 1 && p.x < e->piece->x && e->piece->data[p.y][p.x] == '*')
			{
				if (p.x < e->piece->x &&
					e->grid->data[gy + p.y][gx + p.x] == '.')
					score += e->strat->data[gy + p.y][gx + p.x] + 1;
				else if (ft_isme(e->my, e->grid->data[gy + p.y][gx + p.x]))
					c++;
				else
					return (0);
			}
		}
	}
	return (c == 1 ? score : 0);
}

t_point	ft_play(t_env *env)
{
	t_point g;
	t_point	best;
	int		score;
	int		best_score;

	best_score = 0;
	best.x = 0;
	best.y = 0;
	g.y = 0;
	while (g.y <= env->grid->y - env->piece->y)
	{
		g.x = 0;
		while (g.x <= env->grid->x - env->piece->x)
		{
			if ((score = ft_piece_try(env, g.y, g.x)) > best_score)
			{
				best_score = score;
				best.x = g.x;
				best.y = g.y;
			}
			g.x++;
		}
		g.y++;
	}
	return (best);
}
