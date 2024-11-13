#include <stdio.h>
#define SIZE 8

typedef enum { false, true } bool;

int queue[SIZE];
int rear = -1, front = 0;
void add(int index) {
	queue[++rear] = index;
}
int delete(void) {
	if (rear<front) return -1;
	return queue[front++];
}

void BreadFirstSearch(char V[], bool G[][SIZE]) {
	int i, j;
	char startVertex;
	bool searchOK[SIZE] = { false };
	printf("출발 정점 : "); scanf_s("%c", &startVertex, 1); //startVertex == F
	for (i = 0; i < SIZE; i++) if (V[i] == startVertex)break; //i=5
	printf("너비우선탐색:%c", startVertex); //V[i]
	searchOK[i] = true; //F->C
	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && searchOK[j] == 0) { //1 = ture, 0 = false
				printf("->%c", V[j]);
				searchOK[j] = true;
				add(j);
			}//if
		}//for
		i = delete();
	} while (i >= 0);

}

int main(void) {
	char V[] = { 'A', 'B', 'C', 'D','E', 'F', 'G', 'H' };
	bool G[SIZE][SIZE] = { {0,1,1,0,0,0,0,0},{1,0,0,1,1,0,0,0},{1,0,0,0,0,1,1,0},{0,1,0,0,0,0,0,1},{0,1,0,0,0,0,0,1},{0,0,1,0,0,0,0,1},{0,0,1,0,0,0,0,1},{0,0,0,1,1,1,1,0} };
	BreadFirstSearch(V, G);
	return 0;
}