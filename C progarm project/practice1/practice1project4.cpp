#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"

int mc(long n, long i)
{
	if (n == i)
		return 1;
	else
		return (mc(n + 1, i) + 1)*(mc(n + 1, i) + 1);
}

void practice1project4()
{
	int i;
	printf("����������ʱ�䣺");
	scanf("%ld", &i);
	printf("����ժ��%d��", mc(0, i));
	getch();
}

