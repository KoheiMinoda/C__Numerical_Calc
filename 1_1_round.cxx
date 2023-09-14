/*
 * 1_1_round.cxx
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

void d2b(const double d)
{
	union {
		double d;
		unsigned long long ll;
	} u;
	int i, b;
	u.d = d;
	printf("d2b(%f)\n", u.d);
	printf("%llx\n", u.ll);
	for (i = 63; i >= 0; i--) {
		b = (u.ll >> i) & 0x1;
		if(i == 63) {
			printf("%s", b == 0 ? "+":"-");
		} else {
			printf("%d", b);
		}
		if(i == 52) {
			printf(".");
		}
	}
	printf("\n");
}

int main() {
	double Su;
	Su = 0.1 + 0.2 +0.3;
	if (Su == 0.6) {
		printf("Su = 0.6\n");
	} else {
		printf("Su != 0.6\n");
	}
	printf("double to binary for Su\n");
	d2b(Su);
	printf("double to binary for 0.6\n");
	d2b(0.6);
	return 0;	
}
