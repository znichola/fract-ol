/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:52:35 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 15:00:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_like(t_complex z, t_complex c, int depth)
{
	t_complex	ans;
	double		len;
	int			ret;

	ans = c_addition(c_power2(z), c);
	len = c_length(ans);
	ret = -1;
	if (len >= 2)
		return (depth);
	else if (depth > 0)
		ret = mandelbrot_like(ans, c, depth - 1);
	return (ret);
}

int	burningship(t_complex z, t_complex c, int depth)
{
	t_complex	ans;
	double		len;
	int			ret;

	ans = c_abs(c_addition(c_power2(z), c));
	len = c_length(ans);
	ret = -1;
	if (len >= 2)
		return (depth);
	else if (depth > 0)
		ret = burningship(ans, c, depth - 1);
	return (ret);
}

int	fractal_selector(t_app *a, t_ipoint pix, int fractal, int depth)
{
	t_complex	test;

	test = ftc(rscreen_to_world(a, pix));
	if (fractal == JULIA)
		return (mandelbrot_like(test, ftc(a->world_mouse_right), depth));
	else if (fractal == BURNINGSHIP)
		return (burningship(ftc(fpoint(0.0, 0.0)), test, depth));
	return (mandelbrot_like(ftc(fpoint(0.0, 0.0)), test, depth));
}

int	generate_fractal(t_app *p)
{
	int			h;
	int			w;
	int			d;
	int			colour;

	h = p->img.hight;
	while (h--)
	{
		w = p->img.width;
		while (w--)
		{
			d = fractal_selector(p, ipoint(w, h), p->fractal_select, p->cf.depth);
			colour = WHITE;
			if (d != -1)
				colour = colour_ramp(1, 100, p->cf.depth - d,
						p->pallets.p[p->pallet_index]);
			my_mlx_pixel_put(&p->img, w, h, colour);
		}
	}
	return (0);
}
