// floyd_known.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

void gen_known_matrix(int *data);
void print_matrix(std::string fileName, int *data, int size);



int main()
{
	int *data = new int[5 * 5];

	gen_known_matrix(data);
	print_matrix("someting.csv", data, 5);
    return 0;
}

void gen_known_matrix(int *data)
{
	int i, j;
	int size = 5;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			data[i*size + j] = INT_MAX;
		}
	}

	data[0 * size + 1] = 18;
	data[0 * size + 2] = 14;
	data[0 * size + 3] = 7;
	data[1 * size + 4] = 20;
	data[2 * size + 1] = 1;
	data[2 * size + 4] = 12;
	data[3 * size + 4] = 3;
	data[4 * size + 2] = 10;
}

void print_matrix(std::string fileName, int *data, int size)
{
	int i, j;
	ofstream outputFile;

	outputFile.open(fileName);
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (data[i*size + j] != INT_MAX) {
				outputFile << data[i*size + j];
			}
			if ((j + 1) != size) {
				outputFile << ",";
			}
		}
		outputFile << endl;
	}
	outputFile.close();
}
