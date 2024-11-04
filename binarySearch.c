#include <stdio.h>

int cnt = 0;
int binarySearch(int a[], int n, int key) {
	int left = 0, right = n - 1, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		cnt++;
		if (key == a[mid]) return mid;
		if (key > a[mid]) left = mid + 1;
		else right = mid - 1;
	}//while
	return -1;
}//binarySearch

int main(void) {
	int a[] = { 3,7,10,12,14,18,21,33,35,48 };
	int n = sizeof(a) / sizeof(int);

	int key, index;


	printf("\nã�� �� : ");
	scanf_s("%d", &key);
	index = binarySearch(a, n, key);

	if (index >= 0) printf("\n%d��(��) ��ġ���� %d���� %dȸ ���Ͽ� ã��!\n", key, index, cnt);
	else printf("%dã���� �ϴ� ���� ����!\n", key);
	return 0;
}