#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

//���ӷֶ�����
int mceat(int n)
{
	if (n == 5)
		return  5;
	else
		return 5 / 4 * (mceat(++n) + 1);
}
void practice2project3()
{
	printf("�����У�%d������", mceat(1));
	getch();
}