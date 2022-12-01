/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:25:27 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 11:07:04 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int offset = (y * line_length + x * (bits_per_pixel / 8));
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIDTH || y > HIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// fast aproximative algo from stackoverflow
void	put_circle_fast(t_data *d, int r, t_ipoint center, int colour)
{
	int	y;
	int	x;

	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				my_mlx_pixel_put(d, center.x + x, center.y + y, colour);
			x++;
		}
		y++;
	}
}

int	display_itterations(t_app *p)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 1;
	p->points[0] = rworld_to_screen(p, fpoint(0.0, 0.0));
	while (i < MAXPOINTS && i < p->cf.depth)
	{
		z = ftc(rscreen_to_world(p, p->points[i - 1]));
		c = ftc(rscreen_to_world(p, p->mouse_down));
		p->points[i] = rworld_to_screen(p, ctf(c_addition(c_power2(z), c)));
		put_circle_fast(&p->img, 2, p->points[i], colour_lerp(1, MAXPOINTS, i));
		i++;
	}
	return (0);
}

int	render_next_frame(t_app *p)
{
	if (p->render)
	{
		p->cf.depth += 1;
		generate_madelbrot(p);
	}
	display_itterations(p);
	mlx_put_image_to_window(p->vars.mlx, p->vars.win, p->img.img, 0, 0);
	return (0);
}
		// if (p->cf.depth < p->start_depth + 20)
	// printf("mouse_down put circle"); pi(p->mouse_down); printf("\n");
