/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:19:33 by znichola          #+#    #+#             */
/*   Updated: 2022/11/30 22:52:29 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"

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

// 0.0    |---:---^---:---^---:-->| 1.0 	^ = 4 - 2	chunk_offset -> colour_switch_boundry
//     [  :  ] [  :  ] [  :  ] [  :  ]		: = 4 - 1	chunk

int	colour_ramp(int min, int max, int point, t_pallet p)
{
	double				prct;
	double				chunk;
	double				col_p;
	int					col_i;

	point = point % (max - min);
	prct = (point - min) / (double)(max - min);
	chunk = 1 / (double)(p.len - 1);
	col_i = (int)(prct / (double)chunk);
	col_p = (prct - (col_i * chunk)) / chunk;
	return(create_trgb(0,
					get_r(p.c[col_i]) * (1 - col_p) + get_r(p.c[col_i + 1]) * (col_p),
					get_g(p.c[col_i]) * (1 - col_p) + get_g(p.c[col_i + 1]) * (col_p),
					get_b(p.c[col_i]) * (1 - col_p) + get_b(p.c[col_i + 1]) * (col_p)
					));
}

int	colour_shades(int colour, int depth, t_cmpx_fld *cf)
{
	(void)colour;
	return (((cf->depth - depth) * 16) << 16);
}

void	init_pallets(t_pallets *p)
{
	p->p[0] = clpt_greyscale();
	p->p[1] = clpt_pastel_shades();
	p->p[2] = clpt_pollen();
	p->p[3] = clpt_full_rainbow();
	p->p[4] = clpt_twilight();
	p->p[5] = clpt_blue_to_pink();
	p->p[6] = clpt_green_to_red();
	p->p[7] = clpt_retroearth();
	p->p[8] = clpt_fading();
	p->p[9] = clpt_cyberneon();
}
