#include <time.h>

// �ڵ尡 �ܼ��Ҽ��� �ڵ� ���� ���̰� �ӵ����̷� �̾���

#pragma once
// ��Ŀ���� �ű��� ���ڰ� �ٸ������� swap�� �Ͼ
// ���⵵ O(n^{2})
// 2���� 1190ms
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
// ��Ŀ���� �ű涧���� swap �� �ѹ��� �Ͼ
// ���⵵ O(n^{2}) ������ swap Ƚ�����̷� ���� �ӵ��� ������
// 2���� 433ms
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

// ���⵵ O(n^{2})
// 2���� 1117ms
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

// ������ �� ������쿡 �н��� ��ǻ� �� ������ ������ ����
// 2���� 1079ms
void sort_Bubble2(int *&arr, const unsigned int c) {
	int t;
	unsigned int j, i, f = 1;
	for (i = c - 1; f > 0; i--)
	{
		f = 0;
		for (j = 0; j < i; j++)// ���⿡�� if ���� �ѹ��� ���� ���ϸ� ���� �� �Ǿ��ٴ¶�
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

// �¿� ���� ����
// 2���� 825ms
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