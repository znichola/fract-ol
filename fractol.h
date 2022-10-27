/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:30:39 by znichola          #+#    #+#             */
/*   Updated: 2022/10/28 00:00:06 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // strerror perror
# include <unistd.h>
# include <stdlib.h> // malloc exit 

# include <math.h>
# include <complex.h>

# include "mlx.h"


# define WIDTH 800
# define HIGHT 400
# define DEPTH 100

/* data structure for .. ? */
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_c {
	int	x;
	int	y;
}	t_c;

typedef struct	s_sacle {
	int		x;
	int		y;
	double	a;
	double	b;
}	t_scale;

/* the madelbrot set bounry*/
typedef struct s_window {
	double	a_min;
	double	a_max;
	double	b_min;
	double	b_max;
}	t_window;

typedef struct	s_complex {
	double	a; //real
	double	b; //imaginary
}	t_complex;

/* comlplex.c */
int			fractal_set(t_complex z, t_complex c, int depth);
void		print_complex(char *s, t_complex c);
t_complex	c_addition(t_complex c1, t_complex c2);
t_complex	c_multiplication(t_complex c1, t_complex c2);
t_complex	c_power2(t_complex c1);

/* map */
double	map(int val, int in_max, double out_min, double out_max);

#endif /* fractol.h */