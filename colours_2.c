/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:19:33 by znichola          #+#    #+#             */
/*   Updated: 2022/11/30 16:14:59 by znichola         ###   ########.fr       */
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

	str_col = 0x393E46;
	end_col = 0xD61C4E;
	
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
	static const int	count = 11;
	// static int			pallet[count] = {PASTEL, PINK, LIGHT_BLUE, DEEP_BLUE, BACKGROUND, DEEP_BLUE, LIGHT_BLUE, PASTEL};
	// static int			pallet[count] = {0x2E4C6D, 0x396EB0, 0xDADDFC, 0xFC997C, 0xDADDFC, 0x396EB0, 0x2E4C6D}; // blue to pink
	// static int			pallet[count] = {0xEFF5F5, 0xD6E4E5, 0x497174, 0xEB6440, 0x497174, 0xD6E4E5, 0xEFF5F5}; // liht to dark green and red
	// static int			pallet[count] = {0xF2E5E5, 0xE8C4C4, 0xCE7777, 0x2B3A55, 0xCE7777, 0xE8C4C4, 0xF2E5E5}; // liht to dark green and red
	// static int			pallet[count] = {0xfbf8cc, 0xfde4cf, 0xffcfd2, 0xf1c0e8, 0xcfbaf0, 0xa3c4f3, 0x90dbf4, 0x8eecf5, 0x98f5e1, 0xb9fbc0, 0xfbf8cc}; // many shades of pastel
	static int			pallet[count] = {0x6d84a1, 0x7e789c, 0x898cae, 0x77999f, 0x8dad95, 0xa0bb9d, 0xbec59c, 0xdb9d74, 0xbc6c5e, 0xa35c67, 0x6d84a1}; // full rainbow
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
