#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

struct List2
{
	int num;
	char name[11];
	struct List2 *next;
};

void JosephProblem3();
int p6p1Display();
void look(List2 *head,int num);//����
void restar(List2 *head,int num);//��������
void play(List2 *head,int num);
void practice6project1()
{
	char k;
	int num = 0;
	struct List2 *p = NULL;
	struct List2 *q = NULL;
	struct List2 *head = NULL;

	printf("��ʼ��\n");
	do
	{
		if (head == NULL)
		{
			num++;
			head = (struct List2*)malloc(sizeof(struct List2));//��ʼ������				
			printf("���ֺ����룺");
			fflush(stdin);
			scanf("%s%d", &head->name, &head->num);
			head->next = NULL;
			q = head;
		}
		else
		{
			num++;
			p = (struct List2*)malloc(sizeof(struct List2));
			p->next = NULL;
			q->next = p;//��һ���ڵ����ӵ�����ڵ�		
			printf("\n���ֺ����룺");
			fflush(stdin);
			scanf("%s%d", &p->name, &p->num);
			q = p;
		}
		printf("��ӳɹ���������%d���ˡ���y/Y������ӣ������������:", num);
		k = getch();
	} while (k == 'y' || k == 'Y');
	q->next = head;//ѭ������
	fflush(stdin);
	List2 * h1 = head;
	List2 * h2 = head;
	List2 * h3 = head;
	int key;
	while (true)
	{
		system("cls");
		key = p6p1Display();
		switch (key)
		{
		case 1:
			
			look(h1, num);
			break;
		case 2:
			
			restar(h2,num);
			break;
		case 3:
			
			play(h3,num);
			break;
		case 4:
			break;
		default:
			printf("�������");
			getch();
			break;
		}
		if (key == 4)
			break;
	}
}


int p6p1Display()
{
	int k;
	printf("==========================================\n");
	printf("1.��ʾ��Ϣ\n");
	printf("2.������������\n");
	printf("3.��ʼ����N�˳���\n");
	printf("4.������һ���˵�\n");
	printf("==========================================\n");
	printf("��ѡ��");
	scanf("%d", &k);
	return k;
}

void look(List2 *head,int num)//��ʾ����
{
	printf("�������£�\n");
	for (int i = 0; i < num; i++)
	{
		printf("%s\t%d\n", head->name, head->num);
		head = head->next;
	}
	getch();
}

void restar(List2 *head,int num)//������������
{
	printf("��ʼ�������룺\n");
	printf("===============================================\n");
	for (int i = 0; i < num; i++)
	{
		printf("%s\t", head->name);
		scanf("%d", &head->num);
		head = head->next;
	}
	printf("������ɣ�");
	getch();
}



void play(List2 *head,int num)//��ʼ��Ϸ
{
	char k;
	struct List2 *star;
	star = head;
	int key = 0;
	int target = star->num;


	printf("\n��Ϸ��ʼ��\n");
	while (num != 0)
	{
		if (star->num != -1)
		{
			key++;
			if (key == target)
			{
				num--;
				printf("%s\t%d\n", star->name, star->num);
				target = star->num;
				key = 0;
				star->num = -1;

			}
			star = star->next;
		}
		else
			star = star->next;
	}
	getch();
}