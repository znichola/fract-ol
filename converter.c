/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:59:52 by znichola          #+#    #+#             */
/*   Updated: 2022/11/29 20:22:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex ftc(t_fpoint f)
{
	t_complex c;
	
	c.a = f.x;
	c.b = f.y;
	return (c);
}

t_fpoint ctf(t_complex c)
{
	t_fpoint f;

	f.x = c.a;
	f.y = c.b;
	return (f);
}

t_ipoint ipoint(int x, int y)
{
	t_ipoint i;
	
	i.x = x;
	i.y = y;
	return (i);
}

t_fpoint fpoint(double x, double y)
{
	t_fpoint f;
	
	f.x = x;
	f.y = y;
	return (f);
}