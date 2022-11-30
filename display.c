/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:25:27 by znichola          #+#    #+#             */
/*   Updated: 2022/11/30 23:28:56 by znichola         ###   ########.fr       */
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
	*(unsigned int*)dst = color;
}

int	put_circle(t_data *d, int r, t_ipoint center, int colour)
{
	double		angle;
	t_fpoint	q;

	angle = 0.0;
	while(angle < 360)
	{
		q.x = r * cos(angle * PI / 180);
		q.y = r * sin(angle * PI / 180);
		my_mlx_pixel_put(d, q.x + center.x, q.y + center.y, colour);
		angle += 0.1;
	}
	return (1);
}

void	init_app(t_app *p)
{
	// calc_complex_field(&p->cf, 500, 500);
	p->cf.depth = 1;
	p->cf.scale = 1;
	p->vars.mlx = mlx_init();
	p->img.width = WIDTH;
	p->img.hight = HIGHT;
	p->vars.win = mlx_new_window(p->vars.mlx, p->img.width, p->img.hight, "Hello Fractal!");
	p->img.img = mlx_new_image(p->vars.mlx, p->img.width, p->img.hight);
	p->img.addr = mlx_get_data_addr(p->img.img,
									&p->img.bits_per_pixel,
									&p->img.line_length,
									&p->img.endian);
	// p->scale = fpoint(1, 1);
	p->scale = fpoint(p->img.width * 0.2, p->img.hight * 0.2);
	p->offset = fpoint(0, 0);
	p->offset = rscreen_to_world(p, ipoint(-p->img.width/2, -p->img.hight/2));
	init_pallets(&p->pallets);
	p->pallet_index = 0;
	// printf("screen center: "); pi(ipoint(p->img.width/2, p->img.hight/2)); printf("\n");
	// printf("world corrds: "); pf(rscreen_to_world(p, ipoint(-p->img.width/2, -p->img.hight/2))); printf("\n");
}

int	calc_display_itterations(t_app *p)
{
	t_complex z;
	t_complex c;
	int	i;

	i = 1;
	p->points[0] = rworld_to_screen(p, fpoint(0.0, 0.0));
	while (i < MAXPOINTS && i < p->cf.depth)
	{
		z = ftc(rscreen_to_world(p, p->points[i - 1]));
		c = ftc(rscreen_to_world(p, p->mouse_down));
		p->points[i] = rworld_to_screen(p, ctf(c_addition(c_power2(z), c)));
		put_circle(&p->img, 1, p->points[i], colour_lerp(1, MAXPOINTS, i));
		i++;
	}
	return (1);
}

int	render_next_frame(t_app *p)
{
	if (p->render)
	{
		p->cf.depth +=1;
		generate_madelbrot(p);
	}
	put_circle(&p->img, 1, p->mouse_down, BACKGROUND);
	calc_display_itterations(p);
	// printf("mouse_down put circle"); pi(p->mouse_down); printf("\n");
	mlx_put_image_to_window(p->vars.mlx, p->vars.win, p->img.img, 0, 0);
	return (0);
}

t_pallet	get_pallet(t_app *a, int i)
{
	return (a->pallets.p[i]);
}