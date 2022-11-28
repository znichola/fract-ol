/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:52:35 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 23:25:34 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_cmpx_field(char *msg, t_cmpx_fld *cf)
{
	printf("%s a{%.2f, %.4f} b{%.4f, %.4f}\n", msg, 
			cf->a_min, cf->a_max, cf->b_min, cf->b_max);
}

void	calc_complex_field(t_cmpx_fld *cf, int w_ctr, int h_ctr)
{
	double	h_ratio;
	double	w_ratio;

	w_ratio = w_ctr / (double)HIGHT;
	h_ratio = h_ctr / (double)HIGHT;

	// double	b_min = fabs(a_min - a_max) * ((double)HIGHT / (double)WIDTH) * (500 / (double)HIGHT - 1);

	// double	a_min = 2.05 * (500 / (double)HIGHT - 1) * 2;
	// double	a_max = 0.5 * (500 / (double)HIGHT) * 2;
	// double	b_min = fabs(a_min - a_max) * ((double)HIGHT / (double)WIDTH) * (500 / (double)HIGHT - 1);
	// double	b_max = fabs(a_min - a_max) * ((double)HIGHT / (double)WIDTH) * (500 / (double)HIGHT);

	cf->a_min = 2.05 * (w_ratio - 1) * 2 * cf->scale;
	cf->a_max = .6 * (h_ratio) * 2 * cf->scale;
	cf->b_min = fabs(cf->a_min - cf->a_max) * ((double)HIGHT / (double)WIDTH) * (h_ratio - 1);
	cf->b_max = fabs(cf->a_min - cf->a_max) * ((double)HIGHT / (double)WIDTH) * (h_ratio);
	// printf("depth %d ", cf->depth);
	// print_cmpx_field("complex filed at depth", cf);
}

int	generate_madelbrot(t_cmpx_fld *cf, t_data *img)
{
	t_complex	z;
	t_complex	c;
	int			h;
	int			w;
	
	z.a = 0.0;
	z.b = 0.0;
	c.a = 0.0;
	c.b = 0.0;

	// int	colour = 0XE2DED0;
	h = img->hight;
	while (h--)
	{
		w = img->width;
		while (w--)
		{
			c.a = map(w,  img->width, cf->a_min, cf->a_max);
			if (w ==  img->width - 1)
				c.b = map(h,  img->width, cf->b_min, cf->b_max);
			if (cf->depth < 50)
			{	
				int d = fractal_set(z, c, cf->depth);
				// printf("% 3d ", d);
				int	colour = WHITE;
				if (d != -1)
					// colour = colour_lerp(1, 100, d);
					// colour = colour_ramp(1, 50, 50 - d);
					colour = colour_shades(colour, d, cf);
				my_mlx_pixel_put(img, w, h, colour);
			}
		}
	}
	return (0);
}