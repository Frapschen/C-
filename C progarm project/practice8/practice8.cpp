#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice8project1.h"
#include "practice8project2.h"

#include "practice7project3.h"

int Practice8DisplayMenu();
void practice8()
{
	int key;
	for (;;)
	{
		key = Practice8DisplayMenu();//��ʵս1�Ķ�ܲ˵�
		switch (key)
		{
		case 1:
			practice8project1();
			break;
		case 2:
			practice8project2();
			break;
		case 3:
			practice7project3();
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
int Practice8DisplayMenu()
{
	system("cls");
	int key;
	printf("******************ʵս8���ܲ˵�****************\n");
	printf("*****        1. ��Ŀ1->�������д���       *****\n");
	printf("*****        2. ��Ŀ2->ѧ������ϵͳ       *****\n");
	printf("*****        3. ��Ŀ3->ͼ�����ϵͳ       *****\n");
	printf("*****        4.  ������һ���˵�           *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}