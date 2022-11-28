/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:19:33 by znichola          #+#    #+#             */
/*   Updated: 2022/11/28 22:45:02 by znichola         ###   ########.fr       */
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
	static const int	count = 5;
	static int			pallet[count] = {PASTEL, PINK, LIGHT_BLUE, DEEP_BLUE, BACKGROUND};
	double				prct;
	double				chunk;
	double				col_p;
	int					col_i;

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