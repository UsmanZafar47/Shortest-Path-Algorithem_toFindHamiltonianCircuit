#pragma once
#include<iostream>
#include<list>
using namespace std;


class Node
{
public:
	int data;
	Node* next;

	Node(int d = 0)
	{
		data = d;
	}
};




class List {
public:
	Node* head;
	List()
	{
		head = NULL;
	}


	bool isEmpty()
	{
		if (head->next == head && head->data == 0)
			return true;
		else
			return false;
	}


	void insertatend(int val)
	{
		//create a new node
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = NULL;

		//if head is NULL, it is an empty list
		if (head == NULL)
			head = newNode;
		//Otherwise, find the last node and add the newNode
		else
		{
			Node* lastNode = head;

			//last node's next address will be NULL.
			while (lastNode->next != NULL)
			{
				lastNode = lastNode->next;
			}

			//add the newNode at the end of the linked list
			lastNode->next = newNode;
		}


	}

	void Display()
	{
		Node* temp = head;
		if (temp != NULL) {
			do {
				cout << temp->data << " ";
				if (temp->data == -1)
					cout << endl;
				temp = temp->next;

			} while (temp != NULL);
		}


	}

};



class Graph2
{
	int edges;
	int maxVertices;
	List* adj;
public:
	Graph2(int numVertices = 0)
	{
		edges = 0;
		this->maxVertices = numVertices;
		adj = new List[maxVertices];

	}

	Node* createrVertex(int data)
	{
		Node* temp = new Node(data);
		edges++;
		return temp;
	}

	void insertEdge(int src, int dest)
	{
		Node* temp = new Node;
		//		temp = createrVertex(dest);
		adj[src].insertatend(dest);

		//			temp = createrVertex(dest);
		adj[dest].insertatend(src);


	}



	void showGraphStructure()
	{

		for (int i = 0; i < maxVertices; i++)
		{
			cout << i << ": ";
			adj[i].Display();
			cout << endl;
		}

	}

};


