#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#define N 5
#define LEN 10
 struct List
{
	char name[10];
	struct List *next;
};
 struct List2
 {
	 int num;
	 struct List2 *next;
 };

void JosephProblem1(char ary[][LEN], int);
void JosephProblem2();
void JosephProblem3();
int Practice4project1DisplayMenu();

void practice4project1()
{
	int key;
	for (;;)
	{
		system("cls");
		key = Practice4project1DisplayMenu();
		switch (key)
		{
		case 1:
			char name[N][LEN];
			int i, k;//k��ʾ������K�����Ǽ�����
			printf("����������%d��������ÿ������������10���֣���\n", N);
			for (i = 0; i < N; i++)
				scanf("%s", &name[i]);
			printf("\n�����������ڼ������˳���");
			scanf("%d", &k);
			JosephProblem1(name, k);
			getch();
			break;
		case 2:
			JosephProblem2();
			getch();
			break;
		case 3:
			JosephProblem3();
			getch();
			break;
		case 4:
			break;
		default:
			printf("�������");
			break;
		}
		if (key == 4)
			break;
	}
}
int Practice4project1DisplayMenu()
{
	system("cls");
	int key;
	printf("******************ʵս4��Ŀ1���ܲ˵�***********\n");
	printf("*****        1. ����1->��ͨԼɪ������     *****\n");
	printf("*****        2. ����2->����Լɪ������     *****\n");
	printf("*****        3. ����3->Լɪ���������⡱ *****\n");
	printf("*****        4.  ������һ���˵�           *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}
void JosephProblem1(char ary[][LEN], int k)
{
	//��ͨԼɪ��
	int out = 0;//�ڼ����˳���
	int couter = 0;//����conter==nʱ�˳�
	int idx = -1;
	while (out < N)
	{
		idx++;
		if (idx == N)
			idx = 0;
		if (strcmp(ary[idx], "\0") == 0)
			continue;
		else
		{
			couter++;
			if (couter == k)
			{
				out++;
				printf("�ڸ�%d���˳���%s\n", out, ary[idx]);
				strcpy(ary[idx], "\0");
				couter = 0;
			}
		}
	}
}
void JosephProblem2()
{
		char k;
		int num = 0;
		struct List *p = NULL;
		struct List *q = NULL;
		struct List *head = NULL;
		do
		{
			if (head == NULL)
			{
				num++;
				head = (struct List*)malloc(sizeof(struct List));//��ʼ������				
				printf("������������");
				fflush(stdin);
				scanf("%s", head->name);
				head->next = NULL;
				q = head;
			}
			else
			{
				num++;
				p= (struct List*)malloc(sizeof(struct List));
				p->next = NULL;
				q->next= p;//��һ���ڵ����ӵ�����ڵ�				
				printf("\n������������");
				fflush(stdin);
				scanf("%s", p->name);
				q = p;
			}
			printf("��ӳɹ���������%d���ˡ���y/Y������ӣ������������:",num);
			k = getch();
		} while (k=='y'||k=='Y');
		q->next = head;
		struct List *star;
		star = head;
		int key = 0;
		printf("\n��Ϸ��ʼ��\n");
		while (num!=0)
		{
			if (star->name != "\0")
			{
				key++;
				if (key == 3)
				{
					num--;
					printf("\n%s��ɱ����", star->name);
					strcpy(star->name, "\0");
					key = 0;
				}
				star = star->next;
			}
			else
				star = star->next;				
		}
}

void JosephProblem3()
{
	char k;
	int num = 0;
	struct List2 *p = NULL;
	struct List2 *q = NULL;
	struct List2 *head = NULL;
	do
	{
		if (head == NULL)
		{
			num++;
			head = (struct List2*)malloc(sizeof(struct List2));//��ʼ������				
			printf("���������֣�");
			fflush(stdin);
			scanf("%d", &head->num);
			head->next = NULL;
			q = head;
		}
		else
		{
			num++;
			p = (struct List2*)malloc(sizeof(struct List2));
			p->next = NULL;
			q->next = p;//��һ���ڵ����ӵ�����ڵ�				
			printf("\n���������֣�");
			fflush(stdin);
			scanf("%d", &p->num);
			q = p;
		}
		printf("��ӳɹ���������%d�����֡���y/Y������ӣ������������:", num);
		k = getch();
	} while (k == 'y' || k == 'Y');

	q->next = head;//ѭ������
	struct List2 *star;
	star = head;
	int key = 0;
	int target = star->num;


	printf("\n�����ǣ�\n");
	while (num != 0)
	{
		if (star->num !=-1)
		{
			key++;
			if (key == target)
			{
				num--;
				printf("%d  ", star->num);
				target = star->num;
				key = 0;
				star->num = -1;
				
			}
			star = star->next;
		}
		else
			star = star->next;
	}
}







