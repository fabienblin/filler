/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 14:49:18 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 14:51:02 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		ft_init_my(t_env *env)
{
	char	*line;
	int		gnl;

	line = NULL;
	env->my = 0;
	if ((gnl = get_next_line(0, &line)) > 0)
	{
		if (line[10] == '1')
			env->my = 'o';
		else if (line[10] == '2')
			env->my = 'x';
		else
			ft_exit("player num is invalid");
		ft_strdel(&line);
	}
	return (gnl);
}

t_env	*ft_init(void)
{
	t_env	*env;

	env = ft_newenv(ft_newgrid(0, 0), ft_newgrid(0, 0), ft_newgrid(0, 0), 0);
	return (env);
}
