/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:19:33 by znichola          #+#    #+#             */
/*   Updated: 2022/11/29 21:10:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// linear interpolatoin
// when there are more than one pixel colour
// coord == 7.8 gives us 0.3 which 
// indicates we are 30% of the way to pixel 8.0's center
// double left_center = floor(coord - 0.5) + 0.5;
// double dist = coord - left_center;
// samll optimisation to remove an extra +0.5 calculation
// double adjusted_coord = coord - 0.5;
// double dist = adjusted_coord - floor(adjusted_coord);
// double right_ratio = dist;
// double left_ratio = 1 - dist;
// // red channel value of 30 for start pixel
// // 						150 for end pixel
// int left_red = 30;// red channel value of the pixel to the left
// int right_red = 150;// red channel value of the pixel to the right
// int red = left_red * left_ratio + right_red * right_ratio;
// https://www.youtube.com/watch?v=IDFB5CDpLDE
int	colour_lerp(int min, int max, int point)
{
	int	str_col;
	int	end_col;

	str_col = LIGHT_BLUE;
	end_col = PASTEL;
	
	double	prct;
	prct = (double)(point - min) / (max - min);
	
	return(create_trgb(0,
						get_r(str_col) * (1 - prct) + get_r(end_col) *prct,
						get_g(str_col) * (1 - prct) + get_g(end_col) * prct,
						get_b(str_col) * (1 - prct) + get_b(end_col) * prct
						));
}

// 0.0    |---:---^---:-->| 1.0				^ = 3 - 2
//     [  :  ] [  :  ] [  :  ]				: = 3 - 1

// 0.0    |---:---^---:---^---:-->| 1.0 	^ = 4 - 2	chunk_offset -> colour_switch_boundry
//     [  :  ] [  :  ] [  :  ] [  :  ]		: = 4 - 1	chunk

int	colour_ramp(int min, int max, int point)
{
	static const int	count = 8;
	static int			pallet[count] = {PASTEL, PINK, LIGHT_BLUE, DEEP_BLUE, BACKGROUND, DEEP_BLUE, LIGHT_BLUE, PASTEL};
	// static int			pallet[count] = {POLLEN_0, POLLEN_1, POLLEN_2, POLLEN_3, POLLEN_4, POLLEN_5, POLLEN_6, POLLEN_7};
	// static int			pallet[count] = {FUNKYFUTURE_0, FUNKYFUTURE_1, FUNKYFUTURE_2, FUNKYFUTURE_3, FUNKYFUTURE_4, FUNKYFUTURE_5, FUNKYFUTURE_6, FUNKYFUTURE_7};
	double				prct;
	double				chunk;
	double				col_p;
	int					col_i;

	point = point % (max - min);
	prct = (point - min) / (double)(max - min);
	chunk = 1 / (double)(count - 1);
	col_i = (int)(prct / (double)chunk);
	col_p = (prct - (col_i * chunk)) / chunk;
	return(create_trgb(0,
					get_r(pallet[col_i]) * (1 - col_p) + get_r(pallet[col_i + 1]) * (col_p),
					get_g(pallet[col_i]) * (1 - col_p) + get_g(pallet[col_i + 1]) * (col_p),
					get_b(pallet[col_i]) * (1 - col_p) + get_b(pallet[col_i + 1]) * (col_p)
					));
}

int	colour_shades(int colour, int depth, t_cmpx_fld *cf)
{
	(void)colour;
	return (((cf->depth - depth) * 16) << 16);
}
