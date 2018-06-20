/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 14:25:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 19:43:53 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		ft_piece_try(t_env *env, int gy, int gx)
{
	int	commun;
	t_point	p;
	int	score;

	p.y = 0;
	score = 0;
	commun = 0;
	while (commun <= 1 && p.y < env->piece->y)
	{
		p.x = 0;
		while (commun <= 1 && p.x < env->piece->x)
		{
			if (commun <= 1 && p.x < env->piece->x && env->piece->data[p.y][p.x] == '*')
			{
				if (p.x < env->piece->x && env->grid->data[gy + p.y][gx + p.x] == '.')
					score += env->strat->data[gy + p.y][gx + p.x] + 1;
				else if (ft_isme(env->meChar, env->grid->data[gy + p.y][gx + p.x]))
					commun++;
				else
					return (0);
			}
			p.x++;
		}
		p.y++;
	}
	return (commun == 1 ? score : 0);
}

int		ft_setgrid(t_env *env)
{
	char	*line;
	int		line_nb;
	int		gnl;

	line = NULL;
	line_nb = -1;
	while(++line_nb < env->grid->y + 2 && (gnl = get_next_line(0, &line)) > 0)
	{
		if (line_nb == 0)
		{
			ft_delgrid(&env->grid);
			env->grid = ft_newgrid(ft_atoi(ft_strrchr(line, ' ')), ft_atoi(ft_strchr(line, ' ')));
		}
		else if (line_nb >= 2 && line_nb - 2 < env->grid->y)
			ft_strcpy(env->grid->data[line_nb - 2], line + 4);
		ft_strdel(&line);
	}
	return (gnl);
}

int		ft_setpiece(t_env *env)
{
	char	*line;
	int		line_nb;
	int		gnl;

	line = NULL;
	line_nb = -1;
	while(++line_nb < env->piece->y + 1 && (gnl = get_next_line(0, &line)) > 0)
	{
		if (line_nb == 0)
		{
			ft_delgrid(&env->piece);
			env->piece = ft_newgrid(ft_atoi(ft_strrchr(line, ' ')), ft_atoi(ft_strchr(line, ' ')));
		}
		else if (line_nb >= 1 && line_nb - 1 < env->piece->y)
			ft_strcpy(env->piece->data[line_nb - 1], line);
		ft_strdel(&line);
	}
	return (gnl);
}

int		ft_init_meChar(t_env *env)
{
	char	*line;
	int		gnl;

	line = NULL;
	env->meChar = 0;
	if ((gnl = get_next_line(0, &line)) > 0)
	{
		if (line[10] == '1')
			env->meChar = 'o';
		else if (line[10] == '2')
			env->meChar = 'x';
		else
			ft_exit("player num is invalid");
		ft_strdel(&line);
	}
	return (gnl);
}

t_env	*ft_init()
{
	t_env	*env;

	env = ft_newenv(ft_newgrid(0, 0), ft_newgrid(0, 0), ft_newgrid(0, 0), 0);
	return (env);
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
	while(g.y <= env->grid->y - env->piece->y)
	{
		g.x = 0;
		while(g.x <= env->grid->x - env->piece->x)
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

void	ft_clear_env(t_env *env)
{
	ft_delgrid(&env->grid);
	ft_delgrid(&env->piece);
	ft_delgrid(&env->strat);
}

int		main()
{
	t_point	best;
	t_env	*env;

	env = ft_init();
	if (ft_init_meChar(env) == -1)
		ft_exit("Fail to connect to virtual machine.");
	
	while (1)
	{
		if (ft_setgrid(env) == -1)
			ft_exit("grid error");
		if (ft_setpiece(env) == -1)
			ft_exit("piece error");
		if (ft_strat(env) == -1)
			ft_exit("strat error");
		//ft_put_grid(env->strat);
		best = ft_play(env);
		ft_printf("%d %d\n", best.y, best.x);
	}
	ft_delenv(&env);
	return (0);
}