#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"


//���ӳ���
void practice1project3()
{
	int mun=1;
	int day;
	printf("������ڼ���ʣ��һ�����ӣ�");
	scanf("%d", &day);
	day--;
	for (; day > 0; day--)
	{
		mun = (mun + 1) * 2;
		printf("��%d��ʣ��%d������\n", day, mun);
	}
	getch();
}