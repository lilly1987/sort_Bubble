#include <iostream> //std
#include <string> //getline
#include <time.h>
#include "�迭���.h"
#include "�迭ȸ��.h"
#include "�迭�Ҵ�.h"
#include "����.h"

using namespace std;

int main(int argc, char* argv[]) {

	unsigned int c;//r:��,c:��

	do
	{

		// �ܼ��� ��� ��¿����� cout �ݺ����� ���°� ���ɻ� ���� ����
		// ���������� ������ �ִٸ� �𸦱�
		// ������ �̸� ó���� �ѹ��� ����ϴ°� �� ����

		// �Է� �ޱ�
		cout << "���ڸ� �Է�." << endl;
		cout << "0 �Է½� ����" << endl;
		cout << "�迭 ����:";
		cin >> c;
		if (c == 0)
		{
			break;
		}

		int *arr = new int[c];//����
		int *arr1 = new int[c];//���纻1
		//int *arr2 = new int[c];//���纻2

		arr_rnd(arr, c, c*2);
		//arr_out(arr, c);

		//copy(arr, arr + c, arr2);

		clock_t begin, end, t1, t2, t3, t4, t5;//�ð� ������

		copy(arr, arr + c, arr1);
		begin = clock();
		sort_Select(arr1, c);//��������
		end = clock();          // �ð�����
		//arr_out(arr1, c);
		t1 = end - begin;

		copy(arr, arr + c, arr1);
		begin = clock();
		sort_Select2(arr1, c);//��������2
		end = clock();          // �ð�����
		//arr_out(arr1, c);
		t2 = end - begin;

		copy(arr, arr + c, arr1);
		begin = clock();
		sort_Bubble(arr1, c);
		end = clock();          // �ð�����
		//arr_out(arr1, c);
		t3 = end - begin;

		copy(arr, arr + c, arr1);
		begin = clock();
		sort_Bubble2(arr1, c);
		end = clock();          // �ð�����
		//arr_out(arr1, c);
		t4 = end - begin;

		copy(arr, arr + c, arr1);
		begin = clock();
		sort_Bubble3(arr1, c);
		end = clock();          // �ð�����
		//arr_out(arr1, c);
		t5 = end - begin;

		cout << "����ð� : " << t1 << endl;
		cout << "����ð� : " << t2 << endl;
		cout << "����ð� : " << t3 << endl;
		cout << "����ð� : " << t4 << endl;
		cout << "����ð� : " << t5 << endl;

	} while (true);
}