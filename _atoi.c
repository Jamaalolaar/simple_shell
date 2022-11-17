#include "shell.h"

/**
 * interactive_mode - returns true if shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @ch: the char to be checked
 * @delim_string: the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delim(char ch, char *delim_string)
{
	while (*delim_string)
		if (*delim_string++ == ch)
			return (1);
	return (0);
}

/**
 *_isalphabet - checks for alphabetic character
 *@ch: The character to be checked
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalphabet(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@str: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;
	i = 0;

	while (*(str + i) != '\0' && flag != 2)
	{
		if (*(str + i) == '-')
			sign *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		i++;
	}

	if (sign != -1)
		output = result;
	else
		output = -result;
	return (output);
}
