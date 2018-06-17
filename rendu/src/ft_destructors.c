/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_destructors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/23 17:04:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 14:25:15 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_delsegment(t_seg *seg)
{
	free(seg);
	seg = NULL;
}

void	ft_delpoint(t_point *p)
{
	free(p);
	p = NULL;
}

void	ft_del_grid(t_grid **grid)
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