#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"

int moeat(int n, int k)
{
	int sum;
	if (n == k)
		sum = 1;
	else
		sum = 2 * (moeat(n + 1, k) + 1);
	return sum;
}


int moeat2(int n, int k)
{
	if (n == k)
		return 1;
	else
		return (moeat2(n + 1, k) + 1)*(moeat2(n + 1, k) + 1);
}

void practice2project1()
{
	//���ӳ�������
	int k = 10, sum = 0;
	printf("��������ӳ��ҵ�����k=");
	scanf("%d", &k);
	sum = moeat(1, k);
	printf("���ӵ�һ��ժ����Ϊ=%d", sum);
	getch();
}