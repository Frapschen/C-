#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice6project1.h"
#include "practice6project2.h"
#include "practice6project3.h"
#include "practice6project4.h"
int Practice6DisplayMenu();
void practice6()
{
	int key;
	for (;;)
	{
		key = Practice6DisplayMenu();//��ʵս1�Ķ�ܲ˵�
		switch (key)
		{
		case 1:
			practice6project1();
			break;
		case 2:
			practice6project2();
			break;
		case 3:
			practice6project3();
			break;
		case 4:
			practice6project4();
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
int Practice6DisplayMenu()
{
	system("cls");
	int key;
	printf("******************ʵս6���ܲ˵�******************\n");
	printf("*****        1. ��Ŀ1->Լɪ�����⣨ָ��ʵ��)*****\n");
	printf("*****        2. ��Ŀ2->ѧ����Ϣ�Ǽǹ���     *****\n");
	printf("*****        3. ��Ŀ3->̰����               *****\n");
	printf("*****        4. ��Ŀ4->������չ��Ŀ         *****\n");
	printf("*****        5.  ������һ���˵�             *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}