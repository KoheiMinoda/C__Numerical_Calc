/*
 * 1_2_cancel.cxx
 * 
 * Copyright 2023  <koheiminoda@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, x;
	a = 1.0e-15; c = 2.0e-15; b = 3.0e15;
	
	/*pattern 1*/
	x = (-b - sqrt(b*b - 4.0*a*c)) / (2.0 * a);
	printf("x = %e\n", x);
	printf("a x*x + bx + c = %e\n\n", a*x*x + b*x + c);
	
	/*pattern 2*/
	x = (-2.0 * a) / (b + sqrt(b*b - 4.0*a*c));
	printf("Improved x = %e\n", x);
	printf("a x*x + bx + c = %e\n\n", a*x*x + b*x + c);	
	
	return 0;
}

