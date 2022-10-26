/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:30:39 by znichola          #+#    #+#             */
/*   Updated: 2022/10/26 21:37:37 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // strerror perror
# include <unistd.h>
# include <math.h>
# include <stdlib.h> // malloc exit 

# include "mlx.h"


# define WIDTH 1080
# define HIGHT 1080


/* data structure for .. ? */
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_cords {
	int	x;
	int	y;
}	t_cords;

#endif /* fractol.h */