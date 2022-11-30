/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:39:15 by znichola          #+#    #+#             */
/*   Updated: 2022/11/30 22:29:05 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
# define COLOURS_H

# include "fractol.h"

# define BACKGROUND	0x00292831
# define DEEP_BLUE	0x00333f58
# define LIGHT_BLUE	0x004a7a96
# define PINK		0x00ee8695
# define PASTEL		0x00fbbbad

// https://lospec.com/palette-list/twilight-5
// https://www.color-hex.com/color/333f58

# define POLLEN_0 0x0073464c
# define POLLEN_1 0x00ab5675
# define POLLEN_2 0x00ee6a7c
# define POLLEN_3 0x00ffa7a5
# define POLLEN_4 0x00ffe07e
# define POLLEN_5 0x00ffe7d6
# define POLLEN_6 0x0072dcbb
# define POLLEN_7 0x0034acba

// https://lospec.com/palette-list/pollen8

# define FUNKYFUTURE_0 0x002b0f54
# define FUNKYFUTURE_1 0x00ab1f65
# define FUNKYFUTURE_2 0x00ff4f69
# define FUNKYFUTURE_3 0x00fff7f8
# define FUNKYFUTURE_4 0x00ff8142
# define FUNKYFUTURE_5 0x00ffda45
# define FUNKYFUTURE_6 0x003368dc
# define FUNKYFUTURE_7 0x0049e7ec

// https://lospec.com/palette-list/funkyfuture-8

// typedef struct	s_pallet
// {
// 	int	len;
// 	int	c[16];
// }				t_pallet;

// typedef struct	s_pallets
// {
// 	t_pallet	p[10];
// }				t_pallets;

// colours
// int			create_trgb(int t, int r, int g, int b);
// int			get_t(int trgb);
// int			get_r(int trgb);
// int			get_g(int trgb);
// int			get_b(int trgb);

// // colours funcs
// int			colour_lerp(int min, int max, int point);
// // int			colour_ramp(int min, int max, int point, t_pallet p);
// // void		init_pallets(t_pallets *p);

// // colours init 1
// t_pallet	clpt_greyscale(void);
// t_pallet	clpt_pollen(void);
// t_pallet	clpt_full_rainbow(void);
// t_pallet	clpt_twilight(void);
// t_pallet	clpt_blue_to_pink(void);

// // colours init 2
// t_pallet	clpt_green_to_red(void);
// t_pallet	clpt_pastel_shades(void);
// t_pallet	clpt_retroearth(void);
// t_pallet	clpt_fading(void);
// t_pallet	clpt_cyberneon(void);

#endif /* colours */
