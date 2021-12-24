void	quick(int *mass, int start, int end)
{
	int	save;
	int	ind;
	int	real_end;

	if (start >= end)
		return ;
	real_end = end;
	ind = start + 1;
	while (ind < end)
	{
		if (mass[ind] > mass[start])
		{
			save = mass[ind];
			mass[ind] = mass[end];
			mass[end--] = save;
		}
		else if (!(mass[ind + 1] > mass[start]))
			ind++;
	}
	save = mass[ind];
	mass[ind] = mass[start];
	mass[start] = save;
	quick(mass, start, ind);
	quick(mass, ind + 1, real_end);
}
