#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"

int n = 0;
//��ŵ������
void hanoi(int mun, char a, char b, char c)
{
	if (mun == 1)
		printf("step %3d:%c-->%c\n", ++n, a, c);
	else
	{
		hanoi(mun - 1, a, c, b);
		printf("Step %3d: %c--> %c\n", ++n, a, c);
		hanoi(mun - 1, b, a, c);
	}
}
void hanoi2(int m, char a, char b, char c)
{
	if (m == 1)
	{
		if (abs(a - c) == 1)
		{
			n++;
			printf("step %-3d:%c-->%c\n", n, a, c);
		}
		if ((abs(a - c) == 2))
		{
			n++;
			printf("step %-3d:%c-->%c\n", n, a, b);
			n++;
			printf("Step %-3d:%c-->%c\n", n, b, c);
		}
	}
	else
	{
		hanoi2(m - 1, a, b, c);
		hanoi2(1, a, c, b);
		hanoi2(m - 1, c, b, a);
		hanoi2(1, b, a, c);
		hanoi2(m - 1, a, b, c);
	}
}
void practice2project2()
{
	printf("��������������");
	int mun;
	scanf("%d", &mun);
	printf("��ѡ��Ҫ������ֺ�ŵ�����⣿\n");
	printf("1.��ͨ��ŵ��\n");
	printf("2.��ǿ��ŵ����ÿ��ֻ���ƶ������ڵ����ϣ�");
	int key;
	scanf("%d", &key);
	if (key == 1)
		hanoi(mun, 'A', 'B', 'C');
	else if (key == 2)
		hanoi2(mun, 'A', 'B', 'C');
	else
		printf("�������");
	printf("�밴���������...");
	getch();
}