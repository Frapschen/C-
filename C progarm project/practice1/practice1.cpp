#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice1project1.h"
#include "practice1project2.h"
#include "practice1project3.h"
#include "practice1project4.h"




int Practice1DisplayMenu();
void practice1()
{
	int key;
	for (;;)
	{
		key = Practice1DisplayMenu();//��ʵս1�Ĺ��ܲ˵�
		switch (key)
		{
		case 1:
			practice1project1();
			break;
		case 2:
			practice1project2();
			break;
		case 3:
			practice1project3();
			break;
		case 4:
			practice1project4();
			break;
		case 5:
			key = 0;
			break;
		default:
			printf("��������밴���������.....");
			getch();
			break;
		}
		if (key == 0)
			break;
	}
		
}
int Practice1DisplayMenu()
{
	system("cls");
	int key;
	printf("******************ʵս1���ܲ˵�****************\n");
	printf("*****        1. ��Ŀ1->����������ж�     *****\n");
	printf("*****        2. ��Ŀ2->����������       *****\n");
	printf("*****        3. ��Ŀ3->���ӳ���           *****\n");
	printf("*****        4. ��Ŀ4->������չ��Ŀ       *****\n");
	printf("*****        5.  ������һ���˵�           *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}