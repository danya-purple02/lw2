#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

void shell(int* items, int count);
void qs(int* items, int left, int right);
int cmp(const void* a, const void* b);

int main() 
{
    int z = 0, volume = 100000;
    long int start_time = 0, end_time = 0, compare_time = 0;
    int* a = new int [volume];
    int* b = new int [volume];
    int* c = new int [volume];
    
    cout << "now sorting randomized arrays" << endl;
    srand(time(NULL));
    for (int i = 0; i < volume; i++) 
    {
    a[i] = rand() % 100 + 1;
    b[i] = rand() % 100 + 1;
    c[i] = rand() % 100 + 1;
    }
    cout << "shell() sort" << endl;
    start_time = clock();
    shell(a, volume);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl << endl;

    cout << "qs() sort" << endl;
    start_time = clock();
    qs(b, 0, volume - 1);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl << endl;

    cout << "qsort() sort" << endl;
    start_time = clock();
    qsort(c, volume, sizeof(int), cmp);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl;
    z++;
    cout << "----------------------" << endl << endl;



    cout << "now sorting arrays cons. of increasing sequence" << endl;
    for (int i = 0; i < volume; i++) 
    {
        a[i] = i;
        b[i] = i;
        c[i] = i;
    }
    cout << "shell() sort" << endl;
    start_time = clock();
    shell(a, volume);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl << endl;

    cout << "qs() sort" << endl;
    start_time = clock();
    qs(b, 0, volume - 1);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl << endl;

    cout << "qsort() sort" << endl;
    start_time = clock();
    qsort(c, volume, sizeof(int), cmp);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl;
    z++;
    cout << "----------------------" << endl << endl;



    cout << "now sorting arrays cons. of decreasing sequence" << endl;
    for (int i = 0, j = volume-1; i < volume; i++, j--)
    {
        a[i] = j;
        b[i] = j;
        c[i] = j;
    }
    cout << "shell() sort" << endl;
    start_time = clock();
    shell(a, volume);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl << endl;

    cout << "qs() sort" << endl;
    start_time = clock();
    qs(b, 0, volume - 1);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl << endl;

    cout << "qsort() sort" << endl;
    start_time = clock();
    qsort(c, volume, sizeof(int), cmp);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl;
    z++;
    cout << "----------------------" << endl << endl;



    cout << "now sorting half-increasing and half-decreasing sequence of numbers arrays" << endl;
    for (int i = 0, j = volume-1; i < volume; i++, j--)
    {
        if (0 <= i <= volume/2-1) 
        {
            a[i] = i;
            b[i] = i;
            c[i] = i;
        }
        else if (volume/2-1 <= i <= volume-1)
        {
            a[i] = j;
            b[i] = j;
            c[i] = j;
        }
    }
    cout << "shell() sort" << endl;
    start_time = clock();
    shell(a, volume);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl << endl;

    cout << "qs() sort" << endl;
    start_time = clock();
    qs(b, 0, volume - 1);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl << endl;

    cout << "qsort() sort" << endl;
    start_time = clock();
    qsort(c, volume, sizeof(int), cmp);
    end_time = clock();
    compare_time = end_time - start_time;
    cout << "sort time: " << compare_time / 1000.0 << endl;
    delete[]a;
    delete[]b;
    delete[]c;
    z++;
    cout << "----------------------" << endl << endl;
    
    cout << "done!" << endl;
}

int cmp(const void* a, const void* b) 
{
    {
        return *(int*)a - *(int*)b;
    }
}


void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right)
{
    int i, j;
    int x, y;

    i = left; j = right;
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}