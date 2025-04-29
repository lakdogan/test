/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:10:41 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/26 06:02:21 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

/**
 * @brief Auto-detects the numerical base from the string prefix.
 *
 * If the provided base is 0, this function examines the beginning of the string.
 * - If the string starts with "0x" or "0X", 
 *   the base is set to 16 (hexa) and the pointer
 *   is advanced past the prefix.
 * - If it starts with "0b" or "0B", the base is 
 *   set to 2 (binary) and the pointer is advanced.
 * - If it starts with '0' and is followed by any other character,
 *   the base is set to 8 (octal).
 * - Otherwise, the base is set to 10 (decimal).
 *
 * @param str The input string.
 * @param base Pointer to an integer representing the base. It is updated if 0.
 * @return A pointer to the string after any base prefix.
 */
const char	*auto_detect_base_if_zero(const char *str, int *base)
{
	if (*base != 0)
		return (str);
	if (*str == '0')
	{
		if (str[1] == 'x' || str[1] == 'X')
		{
			*base = 16;
			return (str + 2);
		}
		else if (str[1] == 'b' || str[1] == 'B')
		{
			*base = 2;
			return (str + 2);
		}
		else if (str[1] != '\0')
			*base = 8;
		else
			*base = 10;
	}
	else
		*base = 10;
	return (str);
}

/**
 * @brief Parses a character as a digit and checks for potential overflow.
 *
 * Converts the given character to its numeric value in the specified base.
 * If the character is not a valid digit or its value is not less than the base,
 * -1 is returned. Additionally, if adding the digit to the current result would
 * overflow, -2 is returned for positive numbers and -3 for negative numbers.
 *
 * @param c The character to parse.
 * @param base The numerical base.
 * @param result The current accumulated result.
 * @param sign The sign of the number (1 for positive, -1 for negative).
 * @return The parsed digit (0 to base-1) if valid; 
 * otherwise, a special negative code:
 *         -1 for an invalid character, 
 *         -2 for positive overflow, 
 *      or -3 for negative overflow.
 */
int	parse_digit_and_check_overflow(char c, int base, long result, int sign)
{
	int	digit;

	if (ft_isdigit((unsigned char)c))
		digit = c - '0';
	else if (ft_isalpha((unsigned char)c))
		digit = ft_tolower((unsigned char)c) - 'a' + 10;
	else
		return (-1);
	if (digit >= base)
		return (-1);
	if (result > (LONG_MAX - digit) / base)
	{
		if (sign == 1)
			return (-2);
		else
			return (-3);
	}
	return (digit);
}

/**
 * @brief Accumulates the numerical value from the string.
 *
 * Iterates through the string, converting valid digits in the specified base
 * and accumulating the result. 
 * The function uses parse_digit_and_check_overflow()
 * to both parse digits and check for overflow.
 *
 * @param str The input string containing the number.
 * @param sign The sign of the number (1 or -1).
 * @param base The numerical base.
 * @param stop A pointer to a pointer that will be
 * updated to point where parsing stopped.
 * @return The accumulated number, or LONG_MAX/LONG_MIN if overflow occurs.
 */
static long	accumulate_number(const char *str, int sign, int base,
		const char **stop)
{
	long	result;
	int		ret;

	result = 0;
	*stop = str;
	while (*str)
	{
		ret = parse_digit_and_check_overflow(*str, base, result, sign);
		if (ret == -1)
			break ;
		if (ret == -2)
		{
			*stop = str;
			return (LONG_MAX);
		}
		if (ret == -3)
		{
			*stop = str;
			return (LONG_MIN);
		}
		result = result * base + ret;
		str++;
		*stop = str;
	}
	return (result);
}

/**
 * @brief Converts the numeric portion of a string to a long integer.
 *
 * Processes the string starting from the given pointer, 
 * converts valid digits according
 * to the specified base and sign, 
 * and updates endptr to point to the character where
 * conversion stopped. Overflow is handled by returning LONG_MAX or LONG_MIN.
 *
 * @param str The input string.
 * @param sign The sign of the number.
 * @param base The numerical base.
 * @param endptr A pointer to a pointer that
 * will be updated to the stopping point.
 * @return The converted number.
 */
long	convert_the_number(const char *str, int sign, int base, char **endptr)
{
	const char	*stop;
	long		result;

	result = accumulate_number(str, sign, base, &stop);
	if (endptr)
	{
		*endptr = (char *)stop;
		if (stop == str)
			*endptr = (char *)str;
	}
	return (result);
}

/**
 * @brief Converts a string to a long integer.
 *
 * Skips any leading whitespace, processes 
 * an optional '+' or '-' sign, and detects the
 * numerical base if base is 0. 
 * Then it converts the valid number portion of the string,
 * handles overflow, and sets endptr to the character where conversion stopped.
 *
 * @param str The input string.
 * @param endptr A pointer to a pointer that will be 
 * updated to the conversion stopping point.
 * @param base The numerical base (or 0 to auto-detect the base).
 * @return The converted long integer.
 */
long	ft_strtol(const char *str, char **endptr, int base)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (base && (base < 2 || base > 36))
	{
		if (endptr)
			*endptr = (char *)str;
		return (0);
	}
	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	str = auto_detect_base_if_zero(str, &base);
	result = convert_the_number(str, sign, base, endptr);
	return (result * sign);
}
