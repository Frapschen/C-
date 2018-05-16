#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
int num=0;
int key2;//��ô����
//���ݶ���
typedef struct data
{
	char id[13];
	char name[11];
	char sex[5];
	int old;
	int C_Language;
	int English;
	int Math;
	float average;
};
typedef struct Student
{
	data student;
	Student *prev;
	Student *next;
};

Student *start();//��ʼ������
int p6Display(int n);//�˵�
void show1(Student *head);//ԭʼ����չʾ
void show2(data target[]);//����˳����ʾ

void sort1(Student *head);
void sort2(Student *head);
void sort3(Student *head);
void sort4(Student *head);
void sort5(Student *head);
void sort6(Student *head);
void sort7(Student *head);
void sort8(Student *head);


void practice6project2()
{
	Student  *head=start();
	int key1;//1��һ���˵�  2�Ƕ����˵�
	while (true)
	{
		key1= p6Display(1);
		if(key1!=9&&key1!=0)
		    key2= p6Display(2);
		switch (key1)
		{
		case 1:
			sort1(head);
			break;
		case 2:
			sort2(head);
			break;
		case 3:
			sort3(head);
			break;
		case 4:
			sort4(head);
			getch();
			break;
		case 5:
			sort5(head);
			break;
		case 6:
			sort6(head);
			break;
		case 7:
			sort7(head);
			break;
		case 8:
			sort8(head);
			break;
		case 9:
			show1(head);
			break;
		case 0:
			break;
		default:
			printf("�������");
			break;
		}
		if (key1 == 0)
			break;
	}
}

//��ʼ������
Student *start()
{
	Student *head=NULL;
	Student *p = NULL;
	Student *q = NULL;
	char k;
	printf("������ѧ����Ϣ��");
	do
	{
		if (head == NULL)
		{
			num++;
			head = (Student*)malloc(sizeof(Student));
			printf("�����һ����Ϣ��");
			printf("ѧ�ţ�");
			scanf("%s", &head->student.id);
			printf("����:");
			scanf("%s", &head->student.name);
			printf("�Ա�:");
			scanf("%s", &head->student.sex);
			printf("����:");
			scanf("%d", &head->student.old);
			printf("C����:");
			scanf("%d", &head->student.C_Language);
			printf("Ӣ��:");
			scanf("%d", &head->student.English);
			printf("��ѧ:");
			scanf("%d", &head->student.Math);
			head->student.average = (head->student.Math + head->student.English + head->student.C_Language)/3;
			head->next = NULL;
			head->prev = NULL;
			q = head;
		}
		else
		{
			num++;
			p= (Student*)malloc(sizeof(Student));
			printf("\n�����һ����Ϣ��");
			printf("ѧ�ţ�");
			scanf("%s", &p->student.id);
			printf("������");
			scanf("%s", &p->student.name);
			printf("�Ա�");
			scanf("%s", &p->student.sex);
			printf("���䣺");
			scanf("%d", &p->student.old);
			printf("C���ԣ�");
			scanf("%d", &p->student.C_Language);
			printf("Ӣ�");
			scanf("%d", &p->student.English);
			printf("��ѧ��");
			scanf("%d", &p->student.Math);
			p->student.average = (p->student.Math + p->student.English + p->student.C_Language)/3;
			//��ɽڵ�����
			p->prev = q;//����ڵ�ָ���ϸ��ڵ�
			q->next = p;//�ϸ��ڵ�ָ������ڵ�
			q = p;
		}
		fflush(stdin);
		printf("��ӳɹ���������%d���ˡ���y/Y������ӣ������������:",num);
		k = getch();
	} while (k == 'y' || k == 'Y');
	return head;
}

//�˵�
int p6Display(int n)
{
	int key;
	system("cls");
	switch (n)
	{
	case 1:
	{
		printf("\n");
		printf("ѡ������ʽ��\n");
		printf("-----------------------------------------------------------------\n");
		printf("1.ѧ��\t2.����\t3.�Ա�\t4.����\n");
		printf("5.C����\t6.Ӣ��\t7.����\t8.ƽ����\n");
		printf("9.��ʾԭʼ����\t0.������һ���˵�\n");
		printf("-----------------------------------------------------------------\n");
		break;
	}
	case 2:
	{
		printf("\n");
		printf("-----------------------------------------------------------------\n");
		printf("1.����\t\t2.����\t\t0.������һ���˵�\n");
		printf("-----------------------------------------------------------------\n");
	}
	default:
		break;
	}
	scanf("%d", &key);
	return key;
}

//��ʾԭʼ����
void show1(Student *head)
{
	Student * start = head;
	printf("ѧ��\t����\t�Ա�\t����\tC����\tӢ��\t����\tƽ����\n");
		for (int i = 0; i <num; i++)
		{
			printf("%-8s%-8s%-8s%-8d%-8d%-8d%-8d%-8f\n", start->student.id, start->student.name,
				start->student.sex, start->student.old, start->student.C_Language,
				start->student.English, start->student.Math, start->student.average);
			start = start->next;
		}
	getch();
}

//��ʾ����������
void show2(data target[])
{
	printf("ѧ��\t����\t�Ա�\t����\tC����\tӢ��\t����\tƽ����\n");
	if (key2 == 1)
		for (int i = 0; i < num; i++)
		{
			printf("%-8s%-8s%-8s%-8d%-8d%-8d%-8d%-8f\n", target[i].id, target[i].name,
				target[i].sex, target[i].old, target[i].C_Language, target[i].English,
				target[i].Math, target[i].average);
		}
	else
		for (int i = num-1; i >=0; i--)
		{
			printf("%-8s%-8s%-8s%-8d%-8d%-8d%-8d%-8f\n", target[i].id, target[i].name,
				target[i].sex, target[i].old, target[i].C_Language, target[i].English,
				target[i].Math, target[i].average);
		}
	getch();
}

//ѧ��
void sort1(Student *head)
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i < num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for(int i=0;i<num;i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].id > target[j + 1].id)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//��ʾ����	
	free(target);
}

//����
void sort2(Student *head)
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i < num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (strcmp(target[j].name,target[j + 1].name)>0)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//��ʾ����
	free(target);
}
void sort3(Student *head)//�Ա�
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i < num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (strcmp(target[j].sex, target[j + 1].sex)>0)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//��ʾ����
	free(target);
}
void sort4(Student *head)//����
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].old > target[j + 1].old)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//��ʾ����
	free(target);
}
void sort5(Student *head)//C����
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].C_Language> target[j + 1].C_Language)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//��ʾ����
	free(target);
}
void sort6(Student *head)//Ӣ��
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].C_Language > target[j + 1].C_Language)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//��ʾ����
	free(target);
}
void sort7(Student *head)//����
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].Math > target[j + 1].Math)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//��ʾ����
	free(target);
}
void sort8(Student *head)//ƽ����
{
	Student * start = head;
	data *target = (data*)malloc(sizeof(data)*num);
	data temp;
	for (int i = 0; i <num; i++)
	{
		target[i] = start->student;
		start = start->next;
	}
	for (int i = 0; i<num; i++)
		for (int j = 0; j < num - 1 - i; j++)
			if (target[j].average > target[j + 1].average)
			{
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
	show2(target);//��ʾ����
	free(target);
}