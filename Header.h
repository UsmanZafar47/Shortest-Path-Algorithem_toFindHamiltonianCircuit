#pragma once
#include<iostream>
using namespace std;

class Graph
{
	int** adjMatrix;
	int numVertices;

public:
	Graph(int numVertices = 0)
	{
		this->numVertices = numVertices;
		adjMatrix = new int* [numVertices];
		for (int i = 0; i < numVertices; i++)
			adjMatrix[i] = new int[numVertices];


		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < numVertices; j++)
				adjMatrix[i][j] = 0;
		}
	}

	void addEdge(int i, int j)
	{
		if (i != j) 
		{
			adjMatrix[i][j] += 1;
			adjMatrix[j][i] += 1;
		}
		else
		{
			adjMatrix[i][j] = 1;
			adjMatrix[j][i] = 1;
		}
	}

	void removeEdge(int i, int j)
	{
		adjMatrix[i][j] = 0;
		adjMatrix[j][i] = 0;
	}

	bool isEdge(int i, int j)
	{
		return adjMatrix[i][j];
	}

	void print()
	{
		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < numVertices; j++)
				cout << adjMatrix[i][j] << " ";

			cout << endl;
		}

	}

};

