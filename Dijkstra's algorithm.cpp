//Алгоритм Дейкстри в неорієнтованому графі
#include <iostream>

using namespace std;

#define INT_MAX 2147483647

int sizeOfMatrix();
int** createMatrix(int size);
void inputFromKeyboard(int** arr, int size);
void Dijkstra(int** arr, int size, int st);
int dotToFind();
void printMatrix(int** arr, int size);

int main() {
	int size = sizeOfMatrix();
	int** arr = createMatrix(size);
	inputFromKeyboard(arr, size);
	printMatrix(arr, size);
	int dot = dotToFind();
	Dijkstra(arr, size, dot);
	return 0;
}

int sizeOfMatrix() {
	cout << "Enter an size of matrix adjacency (rows and columns): ";
	int size;
	cin >> size;
	return size;
}

int** createMatrix(int size) {
	int** arr = new int* [size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}
	return arr;
}

void inputFromKeyboard(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "Enter [" << i << "][" << j << "]: ";
			cin >> arr[i][j];
		}
	}
}

void printMatrix(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int dotToFind() {
	cout << "Enter the number of dot, which you want to find: ";
	int dot;
	cin >> dot;
	return dot;
}

void Dijkstra(int** arr, int size, int dot) {

	int* distance = new int[size];
	int m = dot;
	bool* visited = new bool[size];

	for (int i = 0; i < size; i++) {
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[dot] = 0;
	for (int count = 0; count < size - 1; count++) {
		int min = INT_MAX;
		int index;
		for (int i = 0; i < size; i++) {

			if (!visited[i] && distance[i] <= min) {
				min = distance[i];
				index = i;
			}
		}
		int u = index;
		visited[u] = true;
		for (int i = 0; i < size; i++) {
			if (!visited[i] && arr[u][i] && distance[u] != INT_MAX && distance[u] + arr[u][i] < distance[i]) {
				distance[i] = distance[u] + arr[u][i];
			}
		}

	}
	cout << "The cost of the path from the selected node to the others:\t\n";
	for (int i = 0; i < size; i++) {
		if (distance[i] != INT_MAX) {
			cout << m << " > " << i << " = " << distance[i] << endl;
		}
		else {
			cout << m << " > " << i << " = " << "route is unavailable" << endl;
		}
	}
}