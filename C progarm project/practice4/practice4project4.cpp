#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
//��·�鲢�㷨

//���
void combine(int num[], int p, int q, int r)
{
	int *L = NULL;
	int *R = NULL;
	int n1 = r - p + 1;//1
	int n2 = q - r + 1;//2                                                                                              
	L = (int*)malloc(n1 * sizeof(int));
	R = (int*)malloc(n2 * sizeof(int));
	int key = 0;
	int i = 0, j = 0;
	for (i; p + i <= r; i++)
		L[key++] = num[p + i];
	n1 = key;//�ľ��峤��
	key = 0;
	for (j = j + r + 1; j <= q; j++)
		R[key++] = num[j];
	n2 = key;//R�ľ��峤��

	key = p;
	i = j = 0;
	while (i != n1 && j != n2)
	{
		if (L[i] <= R[j])
			num[key++] = L[i++];
		else
			num[key++] = R[j++];
	}
	while (i < n1)
		num[key++] = L[i++];
	while (j < n2)
		num[key++] = R[j++];
	free(L);
	free(R);

}
//��
void sort(int num[],int p,int q)
{
	if (p < q)
	{
		int r = (p + q) / 2;
		sort(num, p, r);
		sort(num, r + 1, q);
		combine(num, p, q, r);
	}
}
//���ֲ���
int fine(int num[], int l, int h, int n)
{
	int d = (l + h) / 2;
	if (n == num[d])
		return 1;
	if (l == d)
		return -1;
	if (n < num[d])
		fine(num, l, d, n);
	else
		fine(num, d + 1, h, n);
}
void practice4project4()
{
		int num[10];
		int p, q;
		printf("������10������");
		for (int i = 0; i < 10; i++)
			scanf("%d", &num[i]);
		p = 0;
		q = 10;
		sort(num, p, q);
		int n;
		printf("��������Ҫ�ҵ�����");
		scanf("%d", &n);
		if (fine(num, 0, 10, n) > 0)
			printf("�ҵ��ˣ�");
		else
			printf("û���ҵ�");
		getch();
}
