#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice7project1.h"
#include "practice7project2.h"
#include "practice7project3.h"

int Practice7DisplayMenu();
void practice7()
{
	int key;
	for (;;)
	{
		key = Practice7DisplayMenu();//��ʵս1�Ķ�ܲ˵�
		switch (key)
		{
		case 1:
			practice7project1();
			break;
		case 2:
			practice7project2();
			break;
		case 3:
			practice7project3();
			break;
		case 4:
			break;
		default:
			printf("��������밴���������.....");
			getch();
			break;
		}
		if (key == 4)
			break;
	}

}
int Practice7DisplayMenu()
{
	system("cls");
	int key;
	printf("******************ʵս�߹��ܲ˵�****************\n");
	printf("*****        1. ��Ŀ1->������ʵ��          *****\n");
	printf("*****        2. ��Ŀ2->ѧ��ѧ������        *****\n");
	printf("*****        3. ��Ŀ3->������չ��Ŀ        *****\n");
	printf("*****        4.  ������һ���˵�            *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}