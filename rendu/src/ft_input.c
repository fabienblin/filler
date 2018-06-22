/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_input.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 14:52:19 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 14:52:30 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		ft_setgrid(t_env *env)
{
	char	*line;
	int		line_nb;
	int		gnl;

	line = NULL;
	line_nb = -1;
	while (++line_nb < env->grid->y + 2 && (gnl = get_next_line(0, &line)) > 0)
	{
		if (line_nb == 0)
		{
			ft_delgrid(&env->grid);
			env->grid = ft_newgrid(ft_atoi(ft_strrchr(line, ' ')),
				ft_atoi(ft_strchr(line, ' ')));
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
	while (++line_nb < env->piece->y + 1 && (gnl = get_next_line(0, &line)) > 0)
	{
		if (line_nb == 0)
		{
			ft_delgrid(&env->piece);
			env->piece = ft_newgrid(ft_atoi(ft_strrchr(line, ' ')),
				ft_atoi(ft_strchr(line, ' ')));
		}
		else if (line_nb >= 1 && line_nb - 1 < env->piece->y)
			ft_strcpy(env->piece->data[line_nb - 1], line);
		ft_strdel(&line);
	}
	return (gnl);
}
