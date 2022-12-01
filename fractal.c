/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:52:35 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 11:29:55 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_set(t_complex z, t_complex c, int depth)
{
	t_complex	ans;
	double		len;
	int			ret;

	ans = c_addition(c_power2(z), c);
	len = c_length(ans);
	ret = -1;
	if (len > 2)
		return (depth);
	else if (depth > 0)
		ret = fractal_set(ans, c, depth - 1);
	return (ret);
}

int	generate_madelbrot(t_app *p)
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
			d = fractal_set(ftc(fpoint(0.0, 0.0)),
					ftc(rscreen_to_world(p, ipoint(w, h))),
					p->cf.depth);
			colour = WHITE;
			if (d != -1)
				colour = colour_ramp(1, 100, p->cf.depth - d,
						p->pallets.p[p->pallet_index]);
			my_mlx_pixel_put(&p->img, w, h, colour);
		}
	}
	return (0);
}
