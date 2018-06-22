/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_misc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 19:09:52 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 20:29:24 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

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
