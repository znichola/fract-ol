/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:30:39 by znichola          #+#    #+#             */
/*   Updated: 2022/10/30 12:54:30 by znichola         ###   ########.fr       */
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

# define WIDTH 1000
# define HIGHT 1000
# define DEPTH 60

# define GREY 0XE2DED0
# define IVORY 0X4E4F50
# define BLACK 0X0
# define WHITE 0XFFFFFF

// typedef enum	e_keycodes {
// 	esc = 53,
	
// } e_keycode;

typedef struct	s_c {
	int	x;
	int	y;
}	t_c;

/* actually used */
typedef struct	s_complex {
	double	a; //real
	double	b; //imaginary
}	t_complex;

/* holds frame information 
 * to print to screen */
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* event system */
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

/* scalling the complex number
 * filed to the screen space */
typedef struct	s_cmpx_fld {
	double	scale;
	double	a_min;
	double	a_max;
	double	b_min;
	double	b_max;
	int		depth;
}	t_cmpx_fld;

/* struc to hold app information */
typedef struct	s_app {
	t_data img;
	t_vars vars;
	t_cmpx_fld cf;
} t_app;

/* comlplex.c */
int			fractal_set(t_complex z, t_complex c, int depth);
void		print_complex(char *s, t_complex c);
t_complex	c_addition(t_complex c1, t_complex c2);
t_complex	c_multiplication(t_complex c1, t_complex c2);
t_complex	c_power2(t_complex c1);

/* map */
double	map(int val, int in_max, double out_min, double out_max);

/* display */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		render_next_frame(t_app *p);
void	init_app(t_app *p);

int	colour_shades(int colour, int depth, t_cmpx_fld *cf);
int	colour_list(int colour, int depth, t_cmpx_fld *cf);

/* events */
int	e_close(int keycode, t_vars *vars);
int	mouse_hook(int action, int *foo);//, t_vars *vars); t_app *ap, 
int	destroy(t_vars *vars);

/* fractal */
void	calc_complex_field(t_cmpx_fld *cf, int w_ctr, int h_ctr);
void	print_cmpx_field(char *msg, t_cmpx_fld *cf);
int		generate_madelbrot(t_cmpx_fld *cf, t_data *img);

#endif /* fractol.h */