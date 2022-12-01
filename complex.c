/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:46:01 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 01:16:53 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_complex(char *s, t_complex c)
{
	printf("%s {%.3f + %.3fi}\n", s, c.a, c.b);
}

// c1 + c2 = (a1 + a2) + (b1 + b2)i
t_complex c_addition(t_complex c1, t_complex c2)
{
	t_complex	c;

	c.a = c1.a + c2.a;
	c.b = c1.b + c2.b;
	return (c);
}

// c1 * c2 = (a1*a2 - b1*b2) + (a1*b2 + b1*a2)i
t_complex c_multiplication(t_complex c1, t_complex c2)
{
	t_complex	c;
	c.a = c1.a * c2.a - c1.b * c2.b;
	c.b = c1.a * c2.b + c1.b * c2.a;
	return (c);
}

// c1 ^ 2 = (a1*a1 - b1*b1) + (a1*b1 + b1*a1)i
// c1^2 = (a^2 - b^2) + (2*a*b)i
t_complex c_power2(t_complex c1)
{
	t_complex	c;

	c.a = c1.a * c1.a - c1.b * c1.b;
	c.b = 2 * c1.a * c1.b;
	return (c);
	// return (c_multiplication(c1, c1));
}

double	c_length(t_complex c)
{
	double	ans;
	ans = sqrt(c.a * c.a + c.b * c.b);
	return (ans);
}

int	fractal_set(t_complex z, t_complex c, int depth)
{
	t_complex	ans;
	double		len;
	int			ret;
	
	ans = c_addition(c_power2(z), c);
	len = c_length(ans);
	ret = -1;
	
	if (len > 2)
	{
		// printf("ret depth len%f	%d ", len, DEPTH - depth);
		// print_complex("power", ans);
		// printf ("{%d}", depth);
		return (depth);
	}
	else if (depth > 0)
	{
		// printf("depth len%f	%d ", len, 5 - depth);
		// print_complex("power", ans);
		if (depth > 0)
			ret = fractal_set(ans, c, depth - 1);
		// printf("depth post %d\n", depth);
		// return (depth);
	}
	return (ret);
}