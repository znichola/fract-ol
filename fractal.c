/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:52:35 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 01:38:57 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
