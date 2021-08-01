#include <unistd.h>

void	ft_putnbr(int n)
{
    char    ans[13];
    int     ind;
    char    outp;
    int		k;

	k = n;
    ind = 12;
    if (n < 0)
	{
        outp = 45;
        write(1, &outp, 1);
		ans[ind] = -(n % 10);
		ind--;
		n = -(n / 10);
	}
    ans[ind] = 0;
    while (n != 0)
    {
        ans[ind] = n % 10;
        n = n / 10;
        ind--;
    }
	if (k != 0)
		ind++;
    while (ind < 13)
    {
		
        outp = ans[ind] + 48;
        write(1, &outp, 1);
        ind++;
    }
    write(1,"\n",1);
}
