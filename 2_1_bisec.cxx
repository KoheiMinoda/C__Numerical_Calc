/*
 * 2_1_bisec.cxx
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

double f (const double x) {
	return log(x);
}

int main()
{
	double a, b, c, fc, eps;
	int i;
	a = 0.5;
	b = 2.0;
	eps = 1.0e-8;
	i = 1;
	while (1) {
		c = (a + b) / 2.0;
		printf("%d // a: %e / b: %e / c: %e\n", i, a, b, c);
		printf("diff : %e\n", fabs(a - b) / 2.0);
		if (fabs(a - b) / 2.0 < eps) break;
		fc = f(c);
		printf(" fc: %e\n", fc);
		if (fc > 0.0) b = c;
		if (fc < 0.0) a = c;
		if (fc == 0.0) break;
		i ++;
	}
	printf("root of log_e(x) is : %e\n", c);
	return 0;
}

