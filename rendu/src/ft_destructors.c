/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_destructors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/23 17:04:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 18:13:23 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_delsegment(t_seg **seg)
{
	ft_delpoint(&(*seg)->a);
	ft_delpoint(&(*seg)->b);
	free(*seg);
	*seg = NULL;
}

void	ft_delpoint(t_point **p)
{
	free(*p);
	*p = NULL;
}

void	ft_delgrid(t_grid **grid)
{
	int i;

	i = 0;
	while (i < (*grid)->y)
	{
		free((*grid)->data[i++]);
	}
	free(*grid);
	*grid = NULL;
}

void	ft_delenv(t_env **env)
{
	ft_delgrid(&(*env)->grid);
	ft_delgrid(&(*env)->piece);
	ft_delgrid(&(*env)->strat);
	free(*env);
	*env = NULL;
}
