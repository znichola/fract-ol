/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_def_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:03:40 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 01:17:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"

t_pallet	clpt_greyscale(void)
{
	t_pallet	p;
	
	p.len = 2;
	p.c[0] = 0xf2f2f2;
	p.c[1] = 0x595959;
	return (p);
}

t_pallet	clpt_pollen(void)
{
	t_pallet	p;
	
	p.len = 9;
	p.c[0] = 0x0073464c;
	p.c[1] = 0x0073464c;
	p.c[2] = 0x00ab5675;
	p.c[3] = 0x00ee6a7c;
	p.c[4] = 0x00ffa7a5;
	p.c[5] = 0x00ffe07e;
	p.c[6] = 0x00ffe7d6;
	p.c[7] = 0x0072dcbb;
	p.c[8] = 0x0034acba;
	return (p);
}

t_pallet	clpt_full_rainbow(void)
{
	t_pallet	p;
	
	p.len = 11;
	p.c[0] = 0x6d84a1;
	p.c[1] = 0x7e789c;
	p.c[2] = 0x898cae;
	p.c[3] = 0x77999f;
	p.c[4] = 0x8dad95;
	p.c[5] = 0xa0bb9d;
	p.c[6] = 0xbec59c;
	p.c[7] = 0xdb9d74;
	p.c[8] = 0xbc6c5e;
	p.c[9] = 0xa35c67;
	p.c[10] = 0x6d84a1;
	return (p);
}

t_pallet	clpt_twilight(void)
{
	t_pallet	p;
	
	p.len = 5;
	p.c[0] = 0x00292831;
	p.c[1] = 0x00333f58;
	p.c[2] = 0x004a7a96;
	p.c[3] = 0x00ee8695;
	p.c[4] = 0x00fbbbad;
	return (p);
}

t_pallet	clpt_blue_to_pink(void)
{
	t_pallet	p;
	
	p.len = 7;
	p.c[0] = 0x2E4C6D;
	p.c[1] = 0x396EB0;
	p.c[2] = 0xDADDFC;
	p.c[3] = 0xFC997C;
	p.c[4] = 0xDADDFC;
	p.c[5] = 0x396EB0;
	p.c[6] = 0x2E4C6D;
	return (p);
}