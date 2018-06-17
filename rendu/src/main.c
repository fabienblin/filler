/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 14:25:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/17 13:29:15 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>


void ft_put_grid(t_grid *grid)
{
	char **gy = grid->data;
	char *gx = *grid->data;
	int i = 0;
	int j;
	if (!grid)
		return ;
	while(gy && i < grid->y)
	{
		j = 0;
		gx = *grid->data;
		while(gx && j < grid->x)
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

int	ft_isme(char me, char c)
{
	return (c == me || c == me - 32);
}

int ft_isnotme(char me, char c)
{
	return (ft_abs(c - me) == 9 || ft_abs(c - me) == 41 || ft_abs(c - me) == 23);
}


t_grid *ft_suround_strat(t_grid *grid, char me)
{
	t_grid *strat = NULL;
	if (grid)
	{
		int maxx;
		int minx;
		int maxy;
		int miny;

		maxx = 0;
		minx = grid->x;
		maxy = 0;
		miny = grid->y;
		
		int i = 0;
		int j;
		while (i < grid->y)
		{
			j = 0;
			while (j < grid->x)
			{
				if (ft_isnotme(me, grid->data[i][j]))
				{
					if (j >= maxx)
						maxx = j < grid->x - 1 ? j + 1 : j;
					if (j < minx)
						minx = j > 0 ? j - 1 : j;
					if (i >= maxy)
						maxy = i < grid->y - 1 ? i + 1 : i;
					if (i < miny)
						miny = i > 0 ? i - 1 : i;
				}
				j++;
			}
			i++;
		}
		
		
		strat = ft_new_grid(grid->x, grid->y);
		i = miny;
		int smallest = (grid->x < grid->y) ? grid->x : grid->y;
		int maxval = smallest % 2 ? smallest / 2 : (smallest + 1) / 2;
		
		
		while (i < maxy + 1 )
		{
			if (i == miny || i == maxy)
				ft_memset(strat->data[i] + minx, 127, maxx - minx + 1);
			else
			{
				strat->data[i][minx] = maxval * 2;
			//	strat->data[i][heminheminx + 1] = 127;
				ft_memset(strat->data[i] + minx + 1, maxval, maxx - minx);
				strat->data[i][maxx] = maxval * 2;
			//	strat->data[i][maxx - 1] = 127;
			}
			//ft_memset(strat->data[i] + heminheminx, maxval + 1, maxx - heminheminx + 1);
			i++;
		}
	}
	return (strat);
}


void	ft_surround2(t_grid *grid, t_grid *strat, char me)
{
	int x;
	int y;
	
	y = 0;
	while (y < grid->y)
	{
		x = 0;
		while (x < grid->x)
		{
			if ((x + 1 < grid->x) && ft_isnotme(me, grid->data[y][x + 1]))
				strat->data[y][x] = 50;
			else if ((x - 1 > 0) && ft_isnotme(me, grid->data[y][x - 1]))
				strat->data[y][x] = 50;
			else if ((y + 1 < grid->y) && ft_isnotme(me, grid->data[y + 1][x]))
				strat->data[y][x] = 50;
			else if ((y - 1 > 0) && ft_isnotme(me, grid->data[y - 1][x]))
				strat->data[y][x] = 50;
			x++;
		}
		y++;
	}
}

t_grid *ft_suround_strat2(t_grid *grid, char me)
{
	t_grid *strat = NULL;
	if (grid)
	{
		// define max and heminhemin ennemy coordinates
		t_point *hemax;
		t_point *hemin;

		hemax = ft_newpoint(0, 0);
		hemin = ft_newpoint(grid->x, grid->y);
		
		int i = 0;
		int j;
		
		// define my max and min coordinates
		t_point *memax;
		t_point *memin;

		memax = ft_newpoint(0, 0);
		memin = ft_newpoint(grid->x, grid->y);
		
		i = 0;
		while (i < grid->y)
		{
			j = 0;
			while (j < grid->x)
			{
				if (ft_isme(me, grid->data[i][j]))
				{
					if (j >= memax->x)
						memax->x = j < grid->x - 1 ? j + 1 : j;
					if (j < memin->x)
						memin->x = j > 0 ? j - 1 : j;
					if (i >= memax->y)
						memax->y = i < grid->y - 1 ? i + 1 : i;
					if (i < memin->y)
						memin->y = i > 0 ? i - 1 : i;
				}
				else if (ft_isnotme(me, grid->data[i][j]))
				{
					if (j >= hemax->x)
						hemax->x = j < grid->x - 1 ? j + 1 : j;
					if (j < hemin->x)
						hemin->x = j > 0 ? j - 1 : j;
					if (i >= hemax->y)
						hemax->y = i < grid->y - 1 ? i + 1 : i;
					if (i < hemin->y)
						hemin->y = i > 0 ? i - 1 : i;
				}
				j++;
			}
			i++;
		}
		
		// define direction
		t_point *meA;
		t_point *meB;
		t_point *heA;
		t_point *heB;
		
		int above = (((memax->y - memin->y) / 2) + memin->y <= ((hemax->y - hemin->y) / 2) + hemin->y);
		int under = !above;
		int left = (((memax->x - memin->x) / 2) + memin->x <= ((hemax->x - hemin->x) / 2) + hemin->x);
		int right = !left;
		//dprintf(2, "above=%d under=%d left=%d right=%d\n", above, under, left, right);
		if ((above && left) || (under && right))
		{
			//dprintf(2, "1.\n");
			meA = ft_newpoint(memax->x, memin->y);
			meB = ft_newpoint(memin->x, memax->y);
			heA = ft_newpoint(hemax->x, hemin->y);
			heB = ft_newpoint(hemin->x, hemax->y);
		}
		else
		{
			//dprintf(2, "2.\n");
			meA = ft_newpoint(memin->x, memin->y);
			meB = ft_newpoint(memax->x, memax->y);
			heA = ft_newpoint(hemin->x, hemin->y);
			heB = ft_newpoint(hemax->x, hemax->y);
		}
			
		
		strat = ft_new_grid(grid->x, grid->y);
		ft_surround2(grid, strat, me);
		i = hemin->y;
		int smallest = (grid->x < grid->y) ? grid->x : grid->y;
		int maxval = smallest % 2 ? smallest / 2 : (smallest + 1) / 2;
		
		
		while (i < hemax->y + 1 )
		{
			if (i == hemin->y || i == hemax->y)
				ft_memset(strat->data[i] + hemin->x, 100, hemax->x - hemin->x + 1);
			else
			{
				strat->data[i][hemin->x] = 100;
			//	strat->data[i][heminheminx + 1] = 127;
			//	ft_memset(strat->data[i] + hemin->x + 1, 10, hemax->x - hemin->x);
				strat->data[i][hemax->x] = 100;
			//	strat->data[i][maxx - 1] = 127;
			}
			//ft_memset(strat->data[i] + heminheminx, maxval + 1, maxx - heminheminx + 1);
			i++;
		}
		
		
		
		bresenham(strat, meA, heA, 50);
		bresenham(strat, meB, heB, 50);
		
	//	ft_put_grid(strat);
	}
	return (strat);
}


int	ft_surround(t_grid *grid, int gx, int gy, int px, int py, char me)
{
	int score;
	
	score = 0;
	if (gx + px + 1 < grid->x && grid->data[gy + py][gx + px + 1] == ft_isnotme(me, grid->data[gy + py][gx + px + 1]))
		return (50);
	else if (gx + px - 1 > 0 && grid->data[gy + py][gx + px - 1] == ft_isnotme(me, grid->data[gy + py][gx + px - 1]))
		return (50);
	else if (gy + py + 1 < grid->y && grid->data[gy + py + 1][gx + px] == ft_isnotme(me, grid->data[gy + py + 1][gx + px]))
		return (50);
	else if (gy + py - 1 > 0 && grid->data[gy + py - 1][gx + px] == ft_isnotme(me, grid->data[gy + py - 1][gx + px]))
		return (50);
	else
		return (score);
}
int	ft_piece_try(t_grid *grid, t_grid *piece, t_grid *dist_strat, t_grid *suround_strat, int gy, int gx, char me)
{
	int	commun;
	int	px;
	int	py;
	int	score;

	py = 0;
	score = 0;
	commun = 0;
	while (commun <= 1 && py < piece->y)
	{
		px = 0;
		while (commun <= 1 && px < piece->x)
		{
			while (commun <= 1 && px < piece->x && piece->data[py][px] == '.')
				px++;
			while (commun <= 1 && px < piece->x && piece->data[py][px] == '*')
			{
				if (px < piece->x && grid->data[gy + py][gx + px] == '.')
				{
					score += dist_strat->data[gy + py][gx + px];
					score += suround_strat->data[gy + py][gx + px];
					score += ft_surround(grid, gx, gy, px, py, me);
				}
				else if (ft_isme(me, grid->data[gy + py][gx + px]))
					commun++;
				else
					return (0);
				px++;
				
			}
			px++;
		}
		py++;
	}
	return (commun == 1 ? score : 0);
}

int	ft_piece_try2(t_grid *grid, t_grid *piece, t_grid *dist_strat, t_grid *suround_strat, int gy, int gx, char me)
{
	int	commun;
	int	px;
	int	py;
	int	score;

	py = 0;
	score = 0;
	commun = 0;
	while (commun <= 1 && py < piece->y)
	{
		px = 0;
		while (commun <= 1 && px < piece->x)
		{
			while (commun <= 1 && px < piece->x && piece->data[py][px] == '.')
				px++;
			while (commun <= 1 && px < piece->x && piece->data[py][px] == '*')
			{
				if (px < piece->x && grid->data[gy + py][gx + px] == '.')
				{
					//score += dist_strat->data[gy + py][gx + px];
					score += 1;
					score += suround_strat->data[gy + py][gx + px];
					//score += ft_surround(grid, gx, gy, px, py, me);
				}
				else if (ft_isme(me, grid->data[gy + py][gx + px]))
					commun++;
				else
					return (0);
				px++;
				
			}
			px++;
		}
		py++;
	}
	return (commun == 1 ? score : 0);
}

void	ft_goto_strat(t_grid *grid, t_grid *strat, char me)
{
	int y;
	int x;
	t_point *a = NULL;
	t_point *b = NULL;
	
	int smallest = (grid->x < grid->y) ? grid->x : grid->y;
	int val = smallest % 2 ? smallest / 2 : (smallest + 1) / 2;
	
	y = 0;
	while (y < grid->y)
	{
		x = 0;
		while(x < grid->x)
		{
			if (ft_isme(me, grid->data[y][x]))
				a = ft_newpoint(x, y);
			else if (ft_isnotme(me, grid->data[y][x]))
				b = ft_newpoint(x, y);
			x++;
		}
		y++;
	}
	/*bresenham(strat, a, b, 127);
	a->proj_x += 1;
	b->proj_y += 1;
	b->proj_x /= 2;
	b->proj_y /= 2;
	*/bresenham(strat, a, b, 127);
	//ft_put_grid(strat);
}

t_grid	*ft_dist_strat(t_grid *grid, t_grid *dist_strat, char me)
{
	if (!dist_strat && grid)
	{
		dist_strat = ft_new_grid(grid->x, grid->y);
		int smallest = (grid->x < grid->y) ? grid->x : grid->y;
		int maxval = smallest % 2 ? smallest / 2 : (smallest + 1) / 2;
		int val = maxval + 1;
		int i = 0;
		int line = 0;
		while (val >= 0)
		{
			
			line = i;
			while (line < smallest - i)
			{
				ft_memset(dist_strat->data[line] + i, val, dist_strat->x - 2 * i);
				line++;
			}
			i++;
			val--;
		}
		ft_goto_strat(grid, dist_strat, me);
	}
	
	return (dist_strat);
}


t_grid	*ft_dist_strat2(t_grid *grid, t_grid *dist_strat, char me)
{
	if (!dist_strat && grid)
	{
		dist_strat = ft_new_grid(grid->x, grid->y);
		int smallest = (grid->x < grid->y) ? grid->x : grid->y;
		int val = 50;
		int divisor = val / (ft_strlen(grid->data[0]) / 2);
		int i = 0;
		int line = 0;
		while (val >= 0)
		{
			line = i;
			while (line < smallest - i)
			{
				ft_memset(dist_strat->data[line] + i, val, dist_strat->x - 2 * i);
				line++;
			}
			i++;
			val -= divisor;
		}
		//ft_put_grid(dist_strat);
		ft_goto_strat(grid, dist_strat, me);
	}
	return (dist_strat);
}


int		main()
{
	char *line;
	int fd;
	char me;
	char enemy;
	char *name;
	char *msg;

	line = NULL;
	fd = 0;
	me = 0;
	name = NULL;
	msg = NULL;

	if (get_next_line(fd, &line) > 0)
	{
		if (line[10] == '1')
		{
			me = 'o';
			enemy = 'x';
		}
		else if (line[10] == '2')
		{
			me = 'x';
			enemy = 'o';
		}
		else
			ft_exit("player num is invalid");
		name = ft_strdup(line + 14);
		ft_strdel(&line);
	}

	int line_nb = 0;
	t_grid	*grid = NULL;
	t_grid	*piece = NULL;
	t_grid	*dist_strat = NULL;
	t_grid	*suround_strat = NULL;
	
	int gy = 0;
	int gx;
	int score;
	int best;
	int best_x;
	int best_y;
	while (1)
	{
		line_nb = 0;
		grid = ft_new_grid(0,0);
		piece = ft_new_grid(0,0);
		suround_strat = ft_new_grid(0,0);
		while(line_nb < grid->y + piece->y + 3 && get_next_line(fd, &line) > 0)
		{
			if (line_nb == 0)
			{
				// get grid size
				ft_del_grid(&grid);
				grid = ft_new_grid(ft_atoi(ft_strrchr(line, ' ')), ft_atoi(ft_strchr(line, ' ')));
			}
			else if (line_nb >= 2 && line_nb - 2 < grid->y)
			{
				//get grid lines
				ft_strcpy(grid->data[line_nb - 2], line + 4);
			}
			else if (line_nb == grid->y + 2)
			{
				// get piece size
				ft_del_grid(&piece);
				piece = ft_new_grid(ft_atoi(ft_strrchr(line, ' ')), ft_atoi(ft_strchr(line, ' ')));
			}
			else if (line_nb >= grid->y + 3 && line_nb < (grid->y + piece->y + 3))
			{
				ft_strcpy(piece->data[line_nb - (grid->y + 3)], line);
			}
			
			ft_strdel(&line);
			line_nb++;
		}
		dist_strat = ft_dist_strat2(grid, dist_strat, me);
		
		ft_del_grid(&suround_strat);
		suround_strat = ft_suround_strat2(grid, me);
		
		gy = 0;
		best = 0;
		best_x = 0;
		best_y = 0;
		while(gy <= grid->y - piece->y)
		{
			gx = 0;
			while(gx <= grid->x - piece->x)
			{
				if ((score = ft_piece_try2(grid, piece, dist_strat, suround_strat, gy, gx, me)) > best)
				{
					best = score;
					best_x = gx;
					best_y = gy;
				}
				gx++;
			}
			gy++;
		}
	//	ft_put_grid(grid);
	//	ft_put_grid(piece);
	//	ft_put_grid(dist_strat);
		
		ft_printf("%d %d\n", best_y, best_x);
		
		ft_del_grid(&grid);
		ft_del_grid(&piece);
		
		
		if (!best)
			ft_exit("fin");
	}
	ft_del_grid(&dist_strat);
	return (0);
}