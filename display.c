/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:25:27 by znichola          #+#    #+#             */
/*   Updated: 2022/10/30 10:52:24 by znichola         ###   ########.fr       */
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

void	init_app(t_app *p)
{
	calc_complex_field(&p->cf, 500, 500);
	p->cf.depth = 1;
	p->cf.scale = 1;
	p->vars.mlx = mlx_init();
	p->vars.win = mlx_new_window(p->vars.mlx, WIDTH, HIGHT, "Hello world!");
	p->img.img = mlx_new_image(p->vars.mlx, WIDTH, HIGHT);
	p->img.addr = mlx_get_data_addr(p->img.img,
									&p->img.bits_per_pixel,
									&p->img.line_length,
									&p->img.endian);
}

// void	

int	render_next_frame(t_app *p)
{
	p->cf.depth +=1;
	
	int x = 0;
	int y = 0;


	mlx_mouse_get_pos(p->vars.win, &x, &y);
	// printf("{%d, %d}\n", x, y);

	calc_complex_field(&p->cf, 500, 500);
	
	generate_madelbrot(&p->cf, &p->img);
	
	mlx_put_image_to_window(p->vars.mlx, p->vars.win, p->img.img, 0, 0);
	return (0);
}

	// calc_complex_field(&cf, 500, 500, 1);
	
	// generate_madelbrot(&cf,&img);
	
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

int	colour_shades(int colour, int depth, t_cmpx_fld *cf)
{
	(void)colour;
	return (((cf->depth - depth) * 16) << 16);
}

int	colour_list(int colour, int depth, t_cmpx_fld *cf)
{
	int	c;
	int	w;
	
	(void)colour;
	
	w = cf->depth;
	c = (int)map(depth%100, 100, 0, 16);

	if ( c == 0)
		return (0xeeeeec);
	else if (c == 1)
		return (0xdcf4ff);
	else if (c == 2)
		return (0xbed6ff);
	else if (c == 3)
		return (0XFE6C76);
	else if (c == 4 )
		return (0xff9dff);
	else if (c == 5 )
		return (0xf680ff);
	else if (c == 6 )
		return (0x5eb7f7);
	else if (c == 7 )
		return (0x4099ff);
	else if (c == 8 )
		return (0xffe48b);
	else if (c == 9 )
		return (0xffc66d);
	else if (c == 10 )
		return (0x9dff91);
	else if (c == 11 )
		return (0x7fe173);
	else if (c == 12 )
		return (0xf07070);
	else if (c == 13 )
		return (0xd25252);
	else if (c == 14 )
		return (0x535353);
	else if (c == 15 )
		return (0x323232);
	else
		return (0xffffff);
}

	// if ( c == 0)
	// 	return (0XF9D4A3);
	// else if (c == 1)
	// 	return (0XD93250);
	// else if (c == 2)
	// 	return (0XFDA671);
	// else if (c == 3)
	// 	return (0XFE6C76);
	// else if (c == 4 )
	// 	return (0X8A615F);
	// else
	// 	return (0XBCD0BC);

	// line drawring
	// int	blue = cf->depth - depth*2 % 255;
	// int	c = (cf->depth - depth*2) % 255;
	// colour = colour >> depth;
	// return ((0 << 24 | c << 16 | 0 << 8 | 0));