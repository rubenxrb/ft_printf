
/* if type specifier found, return it, else char != specifier */
int		isSpecifier(char c)
{
	char conv[] = "sSpdDioOuUxXcCeEfFgGaAn%";

	while (*conv)
		if (c == *conv++)
			return (c);
	return (0);
}
