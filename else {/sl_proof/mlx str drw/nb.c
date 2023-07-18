static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			i++;
		}
		while (n > 9)
		{
			n = n / 10;
			i++;
		}
		return (i);
	}
}

static int	sign(char *p, int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		p[i] = '-';
		p[++i] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		p[i] = '-';
		n = n * -1;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		len;

	i = 0;
	len = ft_intlen(n);
	p = (char *)malloc(sizeof(*p) * (len + 1));
	if (!p)
		return (0);
	p[len] = '\0';
	n = sign(p, n);
	while (n > 9)
	{
		p[len - 1] = (n % 10) + '0';
		len--;
		n = n / 10;
	}
	if (n <= 9)
		p[len - 1] = n + '0';
	return (p);
}
#include <mlx.h>

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    char *string;
    int i = 0;
    int x = 0;
    int y = 300;

      
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 4000, 500, "GAME");
    while (i <= 110)
    {
        string = ft_itoa(i);
        mlx_string_put(mlx_ptr, win_ptr, x, y, 0xFEFEFE, string);
         //string = ft_itoa(i);
        i++;
        if(i <= 9)
            x += 20;
        if(i >= 10 && i <= 100)
            x += 30;
        if(i > 100)
            x += 40;
    } 
mlx_loop(mlx_ptr);
}