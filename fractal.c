/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:52:35 by znichola          #+#    #+#             */
/*   Updated: 2022/10/27 23:55:32 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	colour = 0XE2DED0;
for (int h = 0; h < HIGHT; h++)
{
	for (int w = 0; w < WIDTH; w++)
	{
		c.a = map(w, WIDTH, a_min, a_max);
		if (w == 0)
			c.b = map(h, HIGHT, b_min, b_max);
		int d = fractal_set(z, c, DEPTH);
		// printf("% 3d ", d);
		if (d == -1)
			colour = 0X4E4F50;
		else 
			colour = 0XE2DED0;
		my_mlx_pixel_put(&img, w, h, colour);
	}
	// printf("\n ----");
}