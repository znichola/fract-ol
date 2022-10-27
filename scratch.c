	// neede to intialise the display engine
	mlx = mlx_init();
	
	// initialises a new windoes and places it inside thie pointer
	mlx_win = mlx_new_window(mlx, WIDTH, HIGHT, "Hello world!");

	// retraving the temporary buffer frame on wich we write before writing,
	//	to fill with the image we want to display
	//	it's only been initialised here.
	img.img = mlx_new_image(mlx, WIDTH, HIGHT);
	
	// now we need to populate the image parameters using the function.
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	

	//	L system
	//		fractal binary tree
	//	variables 1 0
	//	way too hard in C

// testing shit //
// 	t_complex c;
// 	c.a = 10;
// 	c.b = 20;

// 	t_complex k;
// 	k.a = 5;
// 	k.b = 7;

	// print_complex(c_multiplication(c, k));
	complex double foo = 10.0 + 20.0 * I;
	complex double bar = 5.0 + 7.0 * I;
	// complex double bar = csqrt(foo);
	print_complex("addition", c_power2(k));
	printf("real ans: %f + %fi\n", creal(foo), cimag(foo));
	bar = bar * bar;
	printf("real ans: %f + %fi\n", creal(bar), cimag(bar));
	return (0);

	// more testing.
	t_complex k;
	k.a = 5;
	k.b = 7;

	// print_complex(c_multiplication(c, k));
	// complex double foo = 10.0 + 20.0 * I;
	complex double bar = 5.0 + 7.0 * I;
	complex double two = 2.0 + 0.0 * I;
	print_complex("power", c_power2(k));
	printf("real ans: %f + %fi\n", creal(bar), cimag(bar));
	bar = cpow(bar, two);
	printf("real ans: %f + %fi\n", creal(bar), cimag(bar));

		else
	{
		// printf("depth len%f	%d ", len, 5 - depth);
		// print_complex("power", ans);
		if (depth > 0)
			fractal_set(ans, c, depth - 1);
		// printf("depth post %d\n", depth);
		// return (depth);
	}