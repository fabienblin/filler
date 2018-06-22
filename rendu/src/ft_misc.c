/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_misc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 19:09:52 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 18:15:18 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_put_grid(t_grid *grid)
{
	char	**gy;
	char	*gx;
	int		i;
	int		j;

	gy = grid->data;
	gx = *grid->data;
	i = 0;
	if (!grid)
		return ;
	while (gy && i < grid->y)
	{
		j = 0;
		gx = *grid->data;
		while (gx && j < grid->x)
		{
			dprintf(2, "%3s", ft_itoa(grid->data[i][j]));
			gx++;
			j++;
		}
		dprintf(2, "\n");
		gy++;
		i++;
	}
}

int		ft_isme(char me, char c)
{
	return (c == me || c == me - 32);
}

int		ft_isnotme(char me, char c)
{
	return (ft_abs(c - me) == 9 ||
		ft_abs(c - me) == 41 ||
		ft_abs(c - me) == 23);
}
