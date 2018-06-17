/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fblin <fblin@student.42.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2016/01/02 13:22:38 by fblin        #+#   ##    ##    #+#       */
/*   Updated: 2018/05/28 17:28:51 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 127

# include <fcntl.h>

# include "libft.h"

typedef struct	s_reader
{
	int		fd;
	char	*prev;
}				t_reader;

int				get_next_line(int const fd, char **line);

#endif
