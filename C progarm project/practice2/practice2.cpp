#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice2project1.h"
#include "practice2project2.h"
#include "practice2project3.h"
int Practice2DisplayMenu();
void practice2()
{
	int key;
	for (;;)
	{
		key = Practice2DisplayMenu();//��ʵս1�Ķ�ܲ˵�
		switch (key)
		{
		case 1:
			practice2project1();
			break;
		case 2:
			practice2project2();
			break;
		case 3:
			practice2project3();
			break;
		case 4:
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
int Practice2DisplayMenu()
{
	system("cls");
	int key;
	printf("******************ʵս2���ܲ˵�****************\n");
	printf("*****        1. ��Ŀ1->���ӳ�������       *****\n");
	printf("*****        2. ��Ŀ2->��ŵ������         *****\n");
	printf("*****        3. ��Ŀ3->��չ��Ŀ���ӳ���   *****\n");
	printf("*****        4.  ������һ���˵�           *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}