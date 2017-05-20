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

/*
#include <math.h>
#include <string.h>
// For printf
#include <stdio.h>

static double PRECISION = 0.00000000000001;
static int MAX_NUMBER_STRING_SIZE = 32;

char * dtoa(char *s, double n) {
    // handle special cases
    if (isnan(n)) {
        strcpy(s, "nan");
    } else if (isinf(n)) {
        strcpy(s, "inf");
    } else if (n == 0.0) {
        strcpy(s, "0");
    } else {
        int digit, m, m1;
        char *c = s;
        int neg = (n < 0);
        if (neg)
            n = -n;
        // calculate magnitude
        m = log10(n);
        int useExp = (m >= 14 || (neg && m >= 9) || m <= -9);
        if (neg)
            *(c++) = '-';
        // set up for scientific notation
        if (useExp) {
            if (m < 0)
               m -= 1.0;
            n = n / pow(10.0, m);
            m1 = m;
            m = 0;
        }
        if (m < 1.0) {
            m = 0;
        }
        // convert the number
        while (n > PRECISION || m >= 0) {
            double weight = pow(10.0, m);
            if (weight > 0 && !isinf(weight)) {
                digit = floor(n / weight);
                n -= (digit * weight);
                *(c++) = '0' + digit;
            }
            if (m == 0 && n > 0)
                *(c++) = '.';
            m--;
        }
        if (useExp) {
            // convert the exponent
            int i, j;
            *(c++) = 'e';
            if (m1 > 0) {
                *(c++) = '+';
            } else {
                *(c++) = '-';
                m1 = -m1;
            }
            m = 0;
            while (m1 > 0) {
                *(c++) = '0' + m1 % 10;
                m1 /= 10;
                m++;
            }
            c -= m;
            for (i = 0, j = m-1; i<j; i++, j--) {
                // swap without temporary
                c[i] ^= c[j];
                c[j] ^= c[i];
                c[i] ^= c[j];
            }
            c += m;
        }
        *(c) = '\0';
    }
    return s;
}


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
