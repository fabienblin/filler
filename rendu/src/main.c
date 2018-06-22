/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 14:25:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 21:25:21 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_point	best;
	t_env	*env;

	env = ft_init();
	if (ft_init_my(env) == -1)
		ft_exit("Fail to connect to virtual machine.");
	while (1)
	{
		if (ft_setgrid(env) == -1)
			ft_exit("grid error");
		if (ft_setpiece(env) == -1)
			ft_exit("piece error");
		if (ft_strat(env) == -1)
			ft_exit("strat error");
		best = ft_play(env);
		ft_printf("%d %d\n", best.y, best.x);
	}
	ft_delenv(&env);
	return (0);
}
