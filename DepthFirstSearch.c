#include <stdio.h>
#define SIZE 8

typedef enum{ false, true } bool; //{true = 1, false = 0}

int stack[SIZE];
int top = -1;
void push(int index) {
	stack[++top] = index; //-1 -> 0
}
int pop(void) {
	if (top == -1) return -1;
	return stack[top--];
}

void DepthFirstSearch(char V[], bool G[][SIZE]) {
	int i, j;
	char startVertex;
	bool searchOK[SIZE] = {false};
	printf("√‚πﬂ ¡§¡° : "); scanf_s("%c", &startVertex, 1); //startVertex == F
	for (i = 0; i < SIZE; i++) if (V[i] == startVertex)break; //i=5
	printf("±Ì¿ÃøÏº±≈Ωªˆ:%c", startVertex); //V[i]
	searchOK[i] = true; //F->C
	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && searchOK[j] == 0) { //1 = ture, 0 = false
				printf("->%c", V[j]);
				searchOK[j] = true;
				push(i);
				i = j;
				break;
			}//if
		}//for
		if (j == SIZE) i = pop();
	} while (i>=0);

}

int main(void) {
	char V[] = { 'A', 'B', 'C', 'D','E', 'F', 'G', 'H' };
	bool G[SIZE][SIZE] = { {0,1,1,0,0,0,0,0},{1,0,0,1,1,0,0,0},{1,0,0,0,0,1,1,0},{0,1,0,0,0,0,0,1},{0,1,0,0,0,0,0,1},{0,0,1,0,0,0,0,1},{0,0,1,0,0,0,0,1},{0,0,0,1,1,1,1,0} };
	DepthFirstSearch(V, G);
	return 0;
}