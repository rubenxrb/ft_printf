
/* if type specifier found, return it, else char != specifier */
int		isSpecifier(char c)
{
	char conv[] = "%sSpdDioOuUxXcCeEfFgGaAn";
	int		i;

	i = 0;
	while (conv[i])
		if (c == conv[i++])
			return (c);
	return (0);
}
