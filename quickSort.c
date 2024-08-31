#include <stdio.h>

void QuickSort(int a[], int left, int right) {
	//left 시작, right 끝
	int i = left, j = right, pivot = a[left], temp;
	//i 왼쪽끝, j 오른쪽끝, pivot 배열의 첫번째 요소(기준느낌), temp 두 요소 교환할때 사용할 임시변수

	if (left < right) { //배열크기가 2이상인 경우에만 진행
		while (i < j) { //i와 j가 같아지기 전까지 반복(만나기 전까지 반복)
			while (i < right && a[i] <= pivot) i++;
			//pivot보다 큰 값 만날때까지 i를 오른쪽으로 이동(i++)
			while (j > left && a[j] >= pivot) j--;
			//privot보다 작은 값 만날때까지 j를 왼쪽으로 이동(j--)
			if (i < j) { //i가 j보다 작다면(아직 같아지지 않고, 만나지도 않았다면)
				temp = a[i]; a[i] = a[j]; a[j] = temp;
				//먼저 temp에 i를 넣고, i엔 j를 넣고,
				// j값은 다시 temp로 넣어 a[i]와 a[j]를 교환한다
			}//if
		}//while
		a[left] = a[j];
		//a[left]는 pivot이다. a[j]가 더 작으니 a[left]에 j값을 넣는것
		a[j] = pivot;
		//j엔 a[left]인 pivot값을 넣는 것

		//pivot을 기준으로 좌우 부분 배열. 재귀호출 진행
		//좌를 다 정렬하면 그 다음 우를 정렬하는 것. 중간(pivot을 기준으로 나눠 정렬)
		QuickSort(a, left, j - 1); //pivot 왼쪽 부분 배열 정렬
		QuickSort(a, j + 1, right); //피벗 오른쪽 부분 배열 정렬
	}
}

int main(void) {
	int a[] = { 15, 7, 2, 20, 33, 17, 26, 5, 21, 30, 27, 29, 11, 10, 3 };
	int i, n = sizeof(a) / sizeof(int); //i, n 배열크기 계산 sizeof(a/int)

	printf("정렬 전 : ");
	for (i = 0; i < n; i++) printf("%5d", a[i]); //정렬 전 배열 출력 (n은 배열요소 개수)

	QuickSort(a, 0, n - 1); //퀵 정렬 함수 호출 (n-1은 배열의 마지막 요소의 인덱스)

	printf("\n퀵 정렬 후 : ");
	for (i = 0; i < n; i++) printf("%5d", a[i]); //정렬 후 배열 출력
	printf("\n");

	return 0;
}