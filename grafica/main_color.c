#include <stdio.h>
#include "libft/libft.h"
#include <mlx.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int main(int argc, char **argv)
{
    int t, r, g, b;
    t = ft_atoi(argv[1]);
    r = ft_atoi(argv[2]);
    g = ft_atoi(argv[3]);
    b = ft_atoi(argv[4]);

    int i = create_trgb(t, r, g, b);
    printf("%d\n", i);

    unsigned int g_r = get_t(i);

    printf("\n -- %u", g_r);
    return (0);
}