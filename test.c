/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <jmonneri@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 17:03:48 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 15:23:04 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./rendu/inc/filler.h"
#include <stdio.h>

int			main(void)
{
	char	*line;
	int		me;
	int		he;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (dprintf(1, "vm_error1\n"));
	he = atoi(line);
	if (get_next_line(0, &line) <= 0)
		return (dprintf(1, "vm_error2\n"));
	me = atoi(line);
	me < he ? dprintf(1, "LOOSE ") : dprintf(1, "WIN ");
	dprintf(1, "(me = %d him = %d)\n", me, he);
	return (0);
}
