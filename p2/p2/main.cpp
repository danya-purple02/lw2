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
	int i = 0, j = 0, r, elem_c;
	int  volume[7] = { 100, 200, 400, 1000, 2000, 4000, 10000 };
	long int start_time = 0, end_time = 0, search_time = 0;

	for (int y = 0; y < 7; y++)
	{
		int** a = new int* [volume[y]];
		int** b = new int* [volume[y]];
		int** c = new int* [volume[y]];
		for (int z = 0; z < volume[y]; z++)
		{
			a[z] = new int[volume[y]];
			b[z] = new int[volume[y]];
			c[z] = new int[volume[y]];
		}

		std::cout << "volume elements:" << volume[y] << endl;

		start_time = clock();

		i = 0; j = 0;
		srand(time(NULL));
		while (i < volume[y])
		{
			while (j < volume[y])
			{
				a[i][j] = rand() % 100 + 1;
				j++;
			}
			i++;
		}

		i = 0; j = 0;
		srand(time(NULL));
		while (i < volume[y])
		{
			while (j < volume[y])
			{
				b[i][j] = rand() % 100 + 1;
				j++;
			}
			i++;
		}

		for (i = 0; i < volume[y]; i++)
		{
			for (j = 0; j < volume[y]; j++)
			{
				elem_c = 0;
				for (r = 0; r < volume[y]; r++)
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
	}
}