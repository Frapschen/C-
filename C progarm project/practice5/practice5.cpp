#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#include "practice5project1.h"
#include "practice5project2.h"
#include "practice5project3.h"
int Practice5DisplayMenu();
void practice5()
{
	int key;
	for (;;)
	{
		key = Practice5DisplayMenu();//��ʵս5�Ķ�ܲ˵�
		switch (key)
		{
		case 1:
			practice5project1();
			break;
		case 2:
			practice5project2();
			break;
		case 3:
			practice5project3();
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
int Practice5DisplayMenu()
{
	system("cls");
	int key;
	printf("******************ʵս5���ܲ˵�****************\n");
	printf("*****        1. ��Ŀ1->ѧ����Ϣ�Ǽǹ���   *****\n");
	printf("*****        2. ��Ŀ2->��Ʊϵͳ         *****\n");
	printf("*****        3. ��Ŀ3->������չ��Ŀ       *****\n");
	printf("*****        5.  ������һ���˵�           *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}