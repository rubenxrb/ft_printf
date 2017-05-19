#include "libft.h"
#include <stdio.h>
/*

char result[100];
  int dVal, dec, i;

  fVal += 0.005;   // added after a comment from Matt McNabb, see below.

  dVal = fVal;
  dec = (int)(fVal * 100) % 100;

  memset(result, 0, 100);
  result[0] = (dec % 10) + '0';
  result[1] = (dec / 10) + '0';
  result[2] = '.';

  i = 3;
  while (dVal > 0)
  {
	  result[i] = (dVal % 10) + '0';
	  dVal /= 10;
	  i++;
  }

  for (i=strlen(result)-1; i>=0; i--)
	  putc(result[i], stdout);

*/

char	*doubletoa(double n)
{
	(void)n;
	return (0);
}

char	*ft_ftoa(float number)
{
	int		dec;
	int		i;
	int		val;

	(void)	dec;
	(void)	i;
	(void)	val;
	(void)	number;
	return (0);
}

char	*ft_uitoa_base(unsigned int n, int b)
{
	char	*num;
	size_t	len;
	size_t	mod;

	len = ft_unumlen(n, b);
	num = ft_strnew(len);
	while (len--)
	{
		mod = n % b;
		num[len] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}
