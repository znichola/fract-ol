/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_def_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:44:16 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 01:57:40 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"

t_pallet	clpt_green_to_red(void)
{
	t_pallet	p;
	
	p.len = 7;
	p.c[0] = 0xEFF5F5;
	p.c[1] = 0xD6E4E5;
	p.c[2] = 0x497174;
	p.c[3] = 0xEB6440;
	p.c[4] = 0x497174;
	p.c[5] = 0xD6E4E5;
	p.c[6] = 0xEFF5F5;
	return (p);
}

t_pallet	clpt_pastel_shades(void)
{
	t_pallet	p;
	
	p.len = 11;
	p.c[0] = 0xfbf8cc;
	p.c[1] = 0xfde4cf;
	p.c[2] = 0xffcfd2;
	p.c[3] = 0xf1c0e8;
	p.c[4] = 0xcfbaf0;
	p.c[5] = 0xa3c4f3;
	p.c[6] = 0x90dbf4;
	p.c[7] = 0x8eecf5;
	p.c[8] = 0x98f5e1;
	p.c[9] = 0xb9fbc0;
	p.c[10] = 0xfbf8cc;
	return (p);
}

t_pallet	clpt_retroearth(void)
{
	t_pallet	p;
	
	p.len = 12;
	p.c[0] = 0x797d62;
	p.c[1] = 0x9b9b7a;
	p.c[2] = 0xbaa587;
	p.c[3] = 0xd9ae94;
	p.c[4] = 0xf1dca7;
	p.c[5] = 0xffcb69;
	p.c[6] = 0xbec59c;
	p.c[7] = 0xe8ac65;
	p.c[8] = 0xd08c60;
	p.c[9] = 0xb58463;
	p.c[10] = 0x997b66;
	p.c[11] = 0x797d62;
	return (p);
}

t_pallet	clpt_fading(void)
{
	t_pallet	p;
	
	p.len = 16;
	p.c[0] = 0xddcf99;
	p.c[1] = 0xcca87b;
	p.c[2] = 0xb97a60;
	p.c[3] = 0x9c524e;
	p.c[4] = 0x774251;
	p.c[5] = 0x4b3d44;
	p.c[6] = 0x4e5463;
	p.c[7] = 0x5b7d73;
	p.c[8] = 0x8e9f7d;
	p.c[9] = 0x645355;
	p.c[10] = 0x8c7c79;
	p.c[11] = 0xa99c8d;
	p.c[12] = 0x7d7b62;
	p.c[13] = 0xaaa25d;
	p.c[14] = 0x846d59;
	p.c[15] = 0xddcf99;
	return (p);
}

t_pallet	clpt_cyberneon(void)
{
	t_pallet	p;
	
	p.len = 16;
	p.c[0] = 0x10133c;
	p.c[1] = 0x005260;
	p.c[2] = 0x009d4a;
	p.c[3] = 0x0aff52;
	p.c[4] = 0x003884;
	p.c[5] = 0x008ac5;
	p.c[6] = 0x00f7ff;
	p.c[7] = 0xff5cff;
	p.c[8] = 0xac29ce;
	p.c[9] = 0x600088;
	p.c[10] = 0xb10585;
	p.c[11] = 0xff004e;
	p.c[12] = 0x2a2e79;
	p.c[13] = 0x4e6ea8;
	p.c[14] = 0xadd4fa;
	p.c[15] = 0x00033c;
	return (p);
}
