#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice4project1.h"
#include "practice4project2.h"
#include "practice4project3.h"
#include "practice4project4.h"
int Practice4DisplayMenu();
void practice4()
{
	int key;
	for (;;)
	{
		key = Practice4DisplayMenu();//��ʵս4�Ķ�ܲ˵�
		switch (key)
		{
		case 1:
			practice4project1();
			break;
		case 2:
			practice4project2();
			break;
		case 3:
			practice4project3();
			break;
		case 4:
			practice4project4();
			getch();
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
int Practice4DisplayMenu()
{
	system("cls");
	int key;
	printf("******************ʵս4���ܲ˵�****************\n");
	printf("*****        1. ��Ŀ1->Լɪ������         *****\n");
	printf("*****        2. ��Ŀ2->�ַ�����������     *****\n");
	printf("*****        3. ��Ŀ3->�ַ�������ͳ��     *****\n");
	printf("*****        4. ��Ŀ4->��չ��Ŀ           *****\n");
	printf("*****        5.  ������һ���˵�           *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}