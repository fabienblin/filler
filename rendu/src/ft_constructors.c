/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_constructors.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/23 17:04:25 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 15:20:44 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
 
#include "filler.h"

t_point	*ft_newpoint(int x, int y)
{
	t_point *p;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	p->x = x;
	p->y = y;
	p->proj_x = x;
	p->proj_y = y;
	return (p);
}

t_seg	*ft_newsegment(t_point *a, t_point *b)
{
	t_seg	*seg;

	if (!(seg = (t_seg *)malloc(sizeof(t_seg))))
		return (NULL);
	ft_bzero(seg, sizeof(t_seg));
	if (a && b)
	{
		seg->a = a;
		seg->b = b;
		seg->dx = b->proj_x - a->proj_x;
		seg->dy = b->proj_y - a->proj_y;
		seg->xinc = (seg->dx > 0 ? 1 : -1);
		seg->yinc = (seg->dy > 0 ? 1 : -1);
		seg->dx = abs(seg->dx);
		seg->dy = abs(seg->dy);
	}
	return (seg);
}

t_grid	*ft_new_grid(int x, int y)
{
	t_grid	*new;
	int		i;

	if (!(new = (t_grid *)malloc(sizeof(t_grid))))
		return (NULL);
	new->x = x;
	new->y = y;
	if (x > 0 && y > 0)
	{
		if (!(new->data = (char **)malloc(sizeof(char *) * y + 1)))
			return (NULL);
		new->data[y] = NULL;
		i = 0;
		while(i < y)
		{
			if (!(new->data[i] = ft_strnew(x)))
				return (NULL);
			i++;
		}
	}
	return (new);
}