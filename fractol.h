/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:30:39 by znichola          #+#    #+#             */
/*   Updated: 2022/12/01 01:16:34 by znichola         ###   ########.fr       */
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
# include "defines.h"
# include "colours.h"

typedef struct s_ipoint
{
	int	x;
	int	y;
}				t_ipoint;

typedef struct s_fpoint
{
	double	x;
	double	y;
}				t_fpoint;

typedef struct s_pallet
{
	int	len;
	int	c[16];
}				t_pallet;

typedef struct s_pallets
{
	t_pallet	p[10];
}				t_pallets;

// typedef struct	s_app
// {
// 	t_data		data;
// 	void		*mlx;
// 	void		*mlx_win;
// 	t_ipoint	mouse;
// 	t_ipoint	mouse_left;
// 	t_ipoint	mouse_right;
// 	t_ipoint	center;
// 	t_fpoint	scale;
// 	t_fpoint	offset;
// }				t_app;

/* actually used */
typedef struct s_complex
{
	double	a;
	double	b;
}	t_complex;

/* holds frame information 
 * to print to screen */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		hight;
}				t_data;

/* event system */
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;
	// void	*mlx; // factor out this usless thing

/* scalling the complex number
 * filed to the screen space */
typedef struct s_cmpx_fld
{
	double	scale;
	double	a_min;
	double	a_max;
	double	b_min;
	double	b_max;
	int		depth;
}				t_cmpx_fld;

/* struc to hold app information */
typedef struct s_app
{
	t_data		img;
	t_vars		vars;
	t_cmpx_fld	cf;
	t_ipoint	mouse;
	t_ipoint	mouse_down;
	t_fpoint	offset;
	t_fpoint	scale;
	t_ipoint	points[MAXPOINTS];
	int			render;
	t_pallets	pallets;
	int			pallet_index;
}				t_app;

/* comlplex.c */
int			fractal_set(t_complex z, t_complex c, int depth);
void		print_complex(char *s, t_complex c);
t_complex	c_addition(t_complex c1, t_complex c2);
t_complex	c_multiplication(t_complex c1, t_complex c2);
t_complex	c_power2(t_complex c1);

/* map */
t_ipoint	rworld_to_screen(t_app *a, t_fpoint w);
t_fpoint	rscreen_to_world(t_app *a, t_ipoint s);

/* init */
void		init_app(t_app *p);
t_pallet	get_pallet(t_app *a, int i);

/* display */
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			render_next_frame(t_app *p);

void		put_circle_fast(t_data *d, int r, t_ipoint center, int colour);

/* events */
int			destroy(t_vars *vars);
int			mouse_hook(int action, int x, int y, t_app *a);
int			mouse_move(int x, int y, t_app *a);
void		zoom(t_app *a, int dir);

/* events 2 */
int			key_press(int keycode, t_app *a);

/* fractal */
int			generate_madelbrot(t_app *p);

/* converter */
t_complex	ftc(t_fpoint f);
t_fpoint	ctf(t_complex c);
t_fpoint	fpoint(double x, double y);
t_ipoint	ipoint(int x, int y);
int			toggle(int a);

/* debug */
void		pi(t_ipoint p);		// uses printf
void		pf(t_fpoint p);		// uses printf

// ----- COLOUR ----- //

// colours
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

// colours funcs
int			colour_lerp(int min, int max, int point);
int			colour_ramp(int min, int max, int point, t_pallet p);
void		init_pallets(t_pallets *p);
int			colour_shades(int colour, int depth, t_cmpx_fld *cf);

// colours init 1
t_pallet	clpt_greyscale(void);
t_pallet	clpt_pollen(void);
t_pallet	clpt_full_rainbow(void);
t_pallet	clpt_twilight(void);
t_pallet	clpt_blue_to_pink(void);

// colours init 2
t_pallet	clpt_green_to_red(void);
t_pallet	clpt_pastel_shades(void);
t_pallet	clpt_retroearth(void);
t_pallet	clpt_fading(void);
t_pallet	clpt_cyberneon(void);

#endif /* fractol.h */
