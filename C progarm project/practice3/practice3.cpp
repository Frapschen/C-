#include "stdio.h"
#include "stdlib.h"
#include "conio.h"



int Practice3DisplayMenu();
void practice3()
{
	int key;
	for (;;)
	{
		key = Practice3DisplayMenu();//��ʵս1�Ķ�ܲ˵�
		switch (key)
		{
		case 1:
			
			break;
		case 2:
			break;
		case 3:

			break;
		case 4:

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
int Practice3DisplayMenu()
{
	system("cls");
	int key;
	printf("***********************************************\n");
	printf("*****        1. ��Ŀ1->Լɪ������         *****\n");
	printf("*****        2. ��Ŀ2->����������       *****\n");
	printf("*****        3. ��Ŀ3->���ӳ���           *****\n");
	printf("*****        4. ��Ŀ4->������չ��Ŀ       *****\n");
	printf("*****        5.  ������һ���˵�           *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}