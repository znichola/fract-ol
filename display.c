/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:25:27 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 18:32:04 by znichola         ###   ########.fr       */
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

int	render_next_frame(t_app *p)
{
	if (p->render && p->cf.depth < MAXDEPTH)
	{
		p->cf.depth += 1;
	}
	generate_fractal(p);
	if (p->fractal_select == JULIA)
		put_circle_fast(&p->img, 3,
			rworld_to_screen(p, p->world_mouse_right), BACKGROUND);
	if (p->mouse_left_toggle)
		display_itterations(p);
	mlx_put_image_to_window(p->vars.mlx, p->vars.win, p->img.img, 0, 0);
	return (0);
}
		// if (p->cf.depth < p->start_depth + 20)
	// printf("mouse_down put circle"); pi(p->mouse_down); printf("\n");
