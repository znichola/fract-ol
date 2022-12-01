/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:46:01 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 11:17:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// c1 + c2 = (a1 + a2) + (b1 + b2)i
t_complex	c_addition(t_complex c1, t_complex c2)
{
	t_complex	c;

	c.a = c1.a + c2.a;
	c.b = c1.b + c2.b;
	return (c);
}

// c1 * c2 = (a1*a2 - b1*b2) + (a1*b2 + b1*a2)i
t_complex	c_multiplication(t_complex c1, t_complex c2)
{
	t_complex	c;

	c.a = c1.a * c2.a - c1.b * c2.b;
	c.b = c1.a * c2.b + c1.b * c2.a;
	return (c);
}

// c1 ^ 2 = (a1*a1 - b1*b1) + (a1*b1 + b1*a1)i
// c1^2 = (a^2 - b^2) + (2*a*b)i
t_complex	c_power2(t_complex c1)
{
	t_complex	c;

	c.a = c1.a * c1.a - c1.b * c1.b;
	c.b = 2 * c1.a * c1.b;
	return (c);
}

double	c_length(t_complex c)
{
	double	ans;

	ans = sqrt(c.a * c.a + c.b * c.b);
	return (ans);
}
