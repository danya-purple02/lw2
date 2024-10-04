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
	int i = 0, j = 0, r, volume = 100;

	while(1)
	{
		srand(time(NULL));
		long int start_time = clock();
		int a[volume][volume], b[volume][volume], c[volume][volume], elem_c;
		std::cout << "volume elements:" << endl;

		int elem_c;
		while (i < volume)
		{
			while (j < volume)
			{
				a[i][j] = rand() % 100 + 1;
				j++;
			}
			i++;
		}
		srand(time(NULL));
		i = 0; j = 0;
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
		long int end_time = clock();

		long int search_time = end_time - start_time;

		printf("%f", search_time / 1000.0);
		return(search_time);
		switch (volume) 
		{
		case 100: 
		{
			volume += 100;
		}
		case 200:
		{
			volume += 200;
		}
		case 400:
		{
			volume += 600;
		}
		case 1000:
		{
			volume += 1000;
		}
		case 2000:
		{
			volume += 2000;
		}
		case 4000:
		{
			volume += 6000;
		}
		}
	}
}