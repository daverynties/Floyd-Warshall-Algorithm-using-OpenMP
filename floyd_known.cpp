#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <climits>
#include <ctime>
using namespace std;

using namespace std;

clock_t start_par, finish_par, start_seq, finish_seq;
void gen_known_matrix(int *data);
void print_matrix(std::string fileName, int *data, int size);

#define MAX_WEIGHT 20

void gen_adj_matrix(int *, int);
void print_matrix(int*, int);
void floyds_algo(int*, int);

int main()
{
	
	int numVertices = 1000;
	int avgConnectivity = 1000;

	int *adjMatrix = new int[numVertices * numVertices];

	start_seq = clock();
	//generate random graph/matrix
	gen_adj_matrix(adjMatrix, numVertices);
	finish_seq = clock();
	//print matrix
	print_matrix(adjMatrix, numVertices);
	//compute
	start_par = clock();
	floyds_algo(adjMatrix, numVertices);
	//print matrix
	finish_par = clock();
	print_matrix(adjMatrix, numVertices);
	

	int time_par = (finish_par - start_par);
	int time_seq = (finish_seq - start_seq);

	//gen_adj_matrix(data);
	//print_matrix("matrix.out", data, 5);

	printf("matrix complete\n\n");
	printf("Time Parallel: %d\n", (time_par));
	printf("Time Seq: %d", (time_seq));
	_getch();
    return 0;
}

void floyds_algo(int *data, int size) {
	int i, j, k;


	for (k = 0; k < size; k++)
#pragma omp parallel for
		for (i = 0; i < size; i++)
			for (j = 0; j < size; j++)
				if ((data[i*size + k] + data[k*size + j]) < data[i*size + j])
					data[i*size + j] = data[i*size + k] + data[k*size + j];
}

void gen_adj_matrix(int *data, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			data[i*size + j] = 1 + (rand() % size); 
}


void print_matrix(int *data, int size)
{
	int i, j;
	ofstream outputFile;

	outputFile.open("matrix.out");
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			outputFile << data[i*size + j] << "\t";
		//outputFile << "\n";
	}

	outputFile.close();
}
