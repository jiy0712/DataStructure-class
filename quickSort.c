#include <stdio.h>

void QuickSort(int a[], int left, int right) {
	//left ����, right ��
	int i = left, j = right, pivot = a[left], temp;
	//i ���ʳ�, j �����ʳ�, pivot �迭�� ù��° ���(���ش���), temp �� ��� ��ȯ�Ҷ� ����� �ӽú���

	if (left < right) { //�迭ũ�Ⱑ 2�̻��� ��쿡�� ����
		while (i < j) { //i�� j�� �������� ������ �ݺ�(������ ������ �ݺ�)
			while (i < right && a[i] <= pivot) i++;
			//pivot���� ū �� ���������� i�� ���������� �̵�(i++)
			while (j > left && a[j] >= pivot) j--;
			//privot���� ���� �� ���������� j�� �������� �̵�(j--)
			if (i < j) { //i�� j���� �۴ٸ�(���� �������� �ʰ�, �������� �ʾҴٸ�)
				temp = a[i]; a[i] = a[j]; a[j] = temp;
				//���� temp�� i�� �ְ�, i�� j�� �ְ�,
				// j���� �ٽ� temp�� �־� a[i]�� a[j]�� ��ȯ�Ѵ�
			}//if
		}//while
		a[left] = a[j];
		//a[left]�� pivot�̴�. a[j]�� �� ������ a[left]�� j���� �ִ°�
		a[j] = pivot;
		//j�� a[left]�� pivot���� �ִ� ��

		//pivot�� �������� �¿� �κ� �迭. ���ȣ�� ����
		//�¸� �� �����ϸ� �� ���� �츦 �����ϴ� ��. �߰�(pivot�� �������� ���� ����)
		QuickSort(a, left, j - 1); //pivot ���� �κ� �迭 ����
		QuickSort(a, j + 1, right); //�ǹ� ������ �κ� �迭 ����
	}
}

int main(void) {
	int a[] = { 15, 7, 2, 20, 33, 17, 26, 5, 21, 30, 27, 29, 11, 10, 3 };
	int i, n = sizeof(a) / sizeof(int); //i, n �迭ũ�� ��� sizeof(a/int)

	printf("���� �� : ");
	for (i = 0; i < n; i++) printf("%5d", a[i]); //���� �� �迭 ��� (n�� �迭��� ����)

	QuickSort(a, 0, n - 1); //�� ���� �Լ� ȣ�� (n-1�� �迭�� ������ ����� �ε���)

	printf("\n�� ���� �� : ");
	for (i = 0; i < n; i++) printf("%5d", a[i]); //���� �� �迭 ���
	printf("\n");

	return 0;
}