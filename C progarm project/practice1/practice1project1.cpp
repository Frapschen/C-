#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"

int TriangleJudgmentDisplayMnue();

void practice1project1()
{
	    float a, b, c;
		printf("�����������ߣ��Կո��������");
		scanf("%f%f%f", &a, &b, &c);
		if ((a + b) < c || (a + c) < b || (b + c) < a)
		{
			printf("���ܹ���������,�������������...\n");
			getch();
		}
	    else
		{
			printf("�ܹ���������\n");
			//��c���
			float temp;
			if (a>b)//�ҵ�a b������
			{
				temp = b;
				b = a;
				a = temp;
			}
			if (b > c)//���ҵ�b c������
			{
				temp = c;
				c = b;
				b = temp;
			}
			int key;
			for (;;)
			{
				key = TriangleJudgmentDisplayMnue();
				switch (key)
				{
				case 1:
					if ((a*a + b * b) == c * c)
						printf("ֱ�������Σ������������...\n");
					else
						printf("����ֱ�������Σ������������...\n");
					getch();
					break;
				case 2:
					if (a == b)
						printf("���������Σ������������...\n");
					else
						printf("���ǵ��������Σ������������...\n");
					getch();
					break;
				case 3:
					if (a == b && a == c && b == c)
						printf("�ȱ������Σ������������...\n");
					else
						printf("���ǵȱ������Σ������������...\n");
					getch();
					break;
				case 4:
					temp = (a + b + c) / 2;
					printf("���Ϊ��%f�������������...", sqrt(temp*(temp - a)*(temp - b)*(temp - c)));
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
}
int TriangleJudgmentDisplayMnue()
{
	system("cls");
	int key;
	printf("******************ʵս1->��Ŀ1*****************\n");
	printf("*****        1. �ж��Ƿ���ֱ��������      *****\n");
	printf("*****        2. �ж��Ƿ��ǵ���������      *****\n");
	printf("*****        3. �ж��Ƿ��ǵȱ�������      *****\n");
	printf("*****        4. ���������ε����          *****\n");
	printf("*****        5.  ������һ���˵�           *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}
