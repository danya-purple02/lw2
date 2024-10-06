#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main() 
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i = 0, j = 0, r, volume = 100, elem_c;;
	long int start_time = 0, end_time = 0, search_time = 0;

	while (1) 
	{
		int** a = new int *[volume];
		int** b = new int* [volume];
		int** c = new int* [volume];
		for (int z = 0; z < volume; z++) 
		{
			a[z] = new int[volume];
			b[z] = new int[volume];
			c[z] = new int[volume];
		}
	
		std::cout << "volume elements:" << volume << endl;

		start_time = clock();

		i = 0; j = 0;
		srand(time(NULL));
		while (i < volume)
		{
			while (j < volume)
			{
				a[i][j] = rand() % 100 + 1;
				j++;
			}
			i++;
		}

		i = 0; j = 0;
		srand(time(NULL));
		while (i < volume)
		{
			while (j < volume)
			{
				b[i][j] = rand() % 100 + 1;
				j++;
			}
			i++;
		}

		for (i = 0; i < volume; i++)
		{
			for (j = 0; j < volume; j++)
			{
				elem_c = 0;
				for (r = 0; r < volume; r++)
				{
					elem_c = elem_c + a[i][r] * b[r][j];
					c[i][j] = elem_c;
				}
			}
		}

		end_time = clock();
		search_time = end_time - start_time;
		delete[]a;
		delete[]b;
		delete[]c;

		cout << "time: " << search_time / 1000.0 << endl << endl;

		switch (volume) 
		{
			case 100: 
			{
				volume = 200;
				continue;
			}
			case 200:
			{
				volume = 400;
				continue;
			}
			case 400:
			{
				volume = 1000;
				continue;
			}
			case 1000:
			{
				volume = 2000;
				continue;
			}
			case 2000:
			{
				volume = 4000;
				continue;
			}
			case 4000:
			{
				volume = 10000;
				continue;
			}
			case 10000: 
			{
				return 0;
			}
		}
	}
}