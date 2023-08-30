#include "main.h"

/**
 * _pow_recursion - Computes the result of x raised to the power of y.
 * @x: The base value.
 * @y: The exponent value.
 *
 * Return: The result of x raised to the power of y.
 */
int _pow_recursion(int x, int y)
{
	int partial_power;

	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	partial_power = _pow_recursion(x, y - 1);
	return (x * partial_power);
}
