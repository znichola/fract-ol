/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:38:15 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 11:11:17 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pi(t_ipoint p)
{
	printf("(%d, %d)", p.x, p.y);
}

void	pf(t_fpoint p)
{
	printf("(%.1f, %.1f)", p.x, p.y);
}

void	print_complex(char *s, t_complex c)
{
	printf("%s {%.3f + %.3fi}\n", s, c.a, c.b);
}
