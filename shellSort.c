#include <stdio.h>

void shellSort(int a[], int n) {
	int i, j, key, t=n/2;

	for (t >= 1; t /= 2;) {
		for (i = t; i < n; i++) {
			key = a[i];
			for (j = i-t; j >= 0; j -= t) {
				if (a[j] <= key) break;
				else a[j + t] = a[j];
			}//for j
			a[j + t] = key;
		}//for i
	}//for t
}//ShellSort

int main(void) {
	int a[] = {17, 8, 20, 11, 5, 12, 15, 7, 35, 21, 48, 30, 25};
	int n = sizeof(a) / sizeof(int);
	shellSort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}//for
	return 0;
}//main