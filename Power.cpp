//Power algorithm
//input x , n power.
//Power(int x, int n)
//  if n > 1
//    do int y <- Power(x, n/2)
//      if n%2 == 0
//       do return y*y;
//      else
//       do return y*y*x;
//  if n == 1
//    return x;

long power(long x, int n)
{
	if (n > 1)
	{
		int ret = power(x, n / 2);
		if (n % 2 == 0)
		{
			return ret*ret;
		}
		else
		{
			return ret*ret*x;
		}
	}
	
	if (n == 1)
	{
		return x;
	}
}

