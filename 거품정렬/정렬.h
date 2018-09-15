#include <time.h>

// 코드가 단순할수록 코드 한줄 차이가 속도차이로 이어짐

#pragma once
// 뒤커서를 옮긴후 숫자가 다를때마다 swap이 일어남
// 복잡도 O(n^{2})
// 2만건 1190ms
void sort_Select(int *&arr, const unsigned int length) {
	int t;
	unsigned int i, j;
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (arr[i] > arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

// https://ko.wikipedia.org/wiki/%EC%84%A0%ED%83%9D_%EC%A0%95%EB%A0%AC
// 앞커서가 옮길때마다 swap 이 한번만 일어남
// 복잡도 O(n^{2}) 이지만 swap 횟수차이로 인해 속도가 빨라짐
// 2만건 433ms
void sort_Select2(int *&list, const unsigned int n) {
	int indexMin, t;
	unsigned int i, j;
	for (i = 0; i < n - 1; i++)
	{
		indexMin = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[indexMin])
			{
				indexMin = j;
			}
		}
		t = list[indexMin];
		list[indexMin] = list[i];
		list[i] = t;
	}
}

// 복잡도 O(n^{2})
// 2만건 1117ms
void sort_Bubble(int *&list, const unsigned int c) {
	int t = 0;
	unsigned int loop, i;
	for (loop = 0; loop < c - 1; loop++) {
		for (i = 0; i < c - 1 - loop; i++) {
			if (list[i] > list[i + 1]) {
				t = list[i];
				list[i] = list[i + 1];
				list[i + 1] = t;
			}
		}
	}
}

// 정렬이 다 됐을경우에 패스라서 사실상 위 로직과 별차이 없음
// 2만건 1079ms
void sort_Bubble2(int *&arr, const unsigned int c) {
	int t;
	unsigned int j, i, f = 1;
	for (i = c - 1; f > 0; i--)
	{
		f = 0;
		for (j = 0; j < i; j++)// 여기에서 if 문이 한번도 진입 안하면 정렬 다 되었다는뜻
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				f = 1;
			}
		}
	}
}

// 좌우 버블 정렬
// 2만건 825ms
void sort_Bubble3(int *&arr, const unsigned int c) {
	int t;
	unsigned int i, s, st = 0, ed = c - 1;
	while (st < ed)
	{
		for (i = st; i < ed; i++)
		{
			//cout << arr[i] << "\t" << arr[i + 1];
			if (arr[i] > arr[i + 1])
			{
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				s = i;
				//cout << "\t" << s;
			}
			//cout << endl;
		}
		ed = s;
		//arr_out(arr, c);
		for (i = ed; i > st; i--)
		{
			//cout << arr[i - 1] << "\t" << arr[i];
			if (arr[i - 1] > arr[i])
			{
				t = arr[i-1];
				arr[i-1] = arr[i ];
				arr[i ] = t;
				s = i;
				//cout << "\t" << s;
			}
			//cout << endl;
		}
		st = s;
		//arr_out(arr, c);
	}
}