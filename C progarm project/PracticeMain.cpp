//ϵͳͷ�ļ�
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

//�Զ���ͷ�ļ�
#include "HeadFile/practice1.h"
#include "HeadFile/practice2.h"
#include "HeadFile/practice3.h"
#include "HeadFile/practice4.h"
#include "HeadFile/practice5.h"
#include "HeadFile/practice6.h"
#include "HeadFile/practice7.h"
#include "HeadFile/practice8.h"

int MainDisplayMenu();//��ʾ��������

int main()
{
	int key;//���ü�����
	for (;;)
	{
		key = MainDisplayMenu();//������Ŀ�������̲˵�
		switch (key)
		{
		case 1:
			practice1();		
			break;
		case 2:
			practice2();
			break;
		case 3:
			practice3();
			break;
		case 4:
			practice4();
			break;
		case 5:
			practice5();
			break;
		case 6:
			practice6();
			break;
		case 7:
			practice7();
			break;
		case 8:
			practice8();
			break;
		case 9:
			printf("ллʹ�ã�");
			getch();
			exit(0);
		default:
			printf("��������밴���������.....");
			getch();
			break;
		}
	}
	return 0;
}
void MainDisplay()
{

}

int  MainDisplayMenu()
{
	int key;
	system("cls");
	printf("**********��C�����ۺ�ʵս��Ŀ�����˵�**********\n");
	printf("*****        1. ����ʵս1ģ��չʾ         *****\n");
	printf("*****        2. ����ʵս2ģ��չʾ         *****\n");
	printf("*****        3. ����ʵս3ģ��չʾ         *****\n");
	printf("*****        4. ����ʵս4ģ��չʾ         *****\n");
	printf("*****        5. ����ʵս5ģ��չʾ         *****\n");
	printf("*****        6. ����ʵս6ģ��չʾ         *****\n");
	printf("*****        7. ����ʵս7ģ��չʾ         *****\n");
	printf("*****        8. ����ʵս8ģ��չʾ         *****\n");
	printf("*****        9. �˳�                      *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}
