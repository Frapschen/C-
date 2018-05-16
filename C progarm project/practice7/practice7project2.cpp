#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
typedef struct Student

{
	int id;
	char name[9];
	char sex[3];
	int old;
	float C_language;
	float Engkish;
	float Math;
	float average;
	Student *next;
};
int number;
//studentInfo.dat
//���� ɾ�� �޸ģ��飻
int  p72Display();
int input(Student* &head);//��������
int output(Student* head);//������ݵ��ļ�
int  read(Student* &head);//���ļ���ȡ����

void show(Student* head);//�������
void addstudent(Student* &head);//���Ԫ��
void delatestudent(Student* &head);//ɾ��Ԫ��
void changestudent(Student* &head);//�޸�����

//���
void practice7project2()
{
	Student *head;
	head = NULL;
	int key;
	FILE *fp;
	printf("�Ƿ��ǵ�һ�����б�����1.��\t2.����\t3.�����\n");
	scanf("%d", &key);

	//ԭʼ��ȡ
	while (true)
	{
		switch (key)
		{
		case 1://��������ԭʼ���ݲ�д���ļ�
		{
			number = input(head);
			if (output(head))
				printf("д���ļ��ɹ���\n");
			else
				printf("д���ļ�ʧ��");
			getch();
			break;
		}
		case 2://��ȡ����
			number= read(head);
			break;
		case 3://����Ƿ������ݣ����ݽ��ѡ�����
		{
			if ((fp = fopen("practice7project2.dat", "r")) == NULL)
			{
				printf("��鵽û������ļ���������������Ϣ��\n");
				number = input(head);
				if (output(head))//������д���ļ�
					printf("д���ļ��ɹ���\n");
				else
					printf("д���ļ�ʧ��");
				getch();
			}
			else
			{
				printf("��鵽�ļ�\n");
				number = read(head);
				if (number != 0)
					printf("�ļ���ȡ�ɹ���\n");
				else
					printf("�ļ���ȡʧ�ܣ�\n");
			}
			getch();
			break;
		}
		default:
			printf("�������");
			break;
		}
		if (key == 1 || key == 2 || key == 3)
			break;
	}
	//���ݴ���
	while (true)
	{
		system("cls");
		key = p72Display();
		switch (key)
		{
		case 1://��ѯ����
			show(head);
			break;
		case 2://�������
			addstudent(head);
			break;
		case 3://ɾ������
			delatestudent(head);
			break;
		case 4://�޸�����
			changestudent(head);
			break;
		case 5:
			break;
		default:
			printf("�������1");
			break;
		}
		if (key == 5)
			break;
	}
}

int p72Display()
{
	int key;
	printf("============================================================\n");
	printf("\t1.��ѯ����\n");
	printf("\t2.�������\n");
	printf("\t3.ɾ������\n");
	printf("\t4.�޸ĳ���\n");
	printf("\t5.������һ���˵�\n");
	printf("============================================================\n");
	scanf("%d", &key);
	return key;
}


//��������
int input(Student* &head)
{
	int num;
	Student *p = NULL;
	Student *q =NULL;
	printf("\n\n��������Ҫ�����ѧ����������");
	scanf("%d",&num);
	for (int i = 0; i < num; i++)
	{
		if (head == NULL)
		{
			head = (Student*)malloc(sizeof(Student));
			head->next = NULL;
			printf("==========================================================================\n");
			printf("������ѧ�ţ�");
			scanf("%d", &head->id);
			printf("������������");
			scanf("%s", &head->name);
			printf("�������Ա�");
			scanf("%s", &head->sex);
			printf("���������䣺");
			scanf("%d", &head->old);
			printf("������C���ԣ�");
			scanf("%f", &head->C_language);
			printf("������Ӣ�");
			scanf("%f", &head->Engkish);
			printf("��������ѧ��");
			scanf("%f", &head->Math);
			head->average = (head->Math + head->C_language + head->Engkish) / 3;
			q = head;
		}
		else
		{
			p = (Student*)malloc(sizeof(Student));
			p->next = NULL;
			q->next = p;
			printf("==========================================================================\n");
			printf("������ѧ�ţ�");
			scanf("%d", &p->id);
			printf("������������");
			scanf("%s", &p->name);
			printf("�������Ա�");
			scanf("%s", &p->sex);
			printf("���������䣺");
			scanf("%d", &p->old);
			printf("������C���ԣ�");
			scanf("%f", &p->C_language);
			printf("������Ӣ�");
			scanf("%f", &p->Engkish);
			printf("��������ѧ��");
			scanf("%f", &p->Math);
			p->average = (p->Math + p->C_language + p->Engkish) / 3;
			q = p;
		}
	}
	printf("��������������������...");
	getch();
	return num;
}

//������ݵ��ļ�
int output(Student* head)
{
	int num=0;
	FILE *ff;
	if ((ff = fopen("practice7project2.dat", "w")) == NULL)
		printf("�ļ���ʧ�ܣ�\n");
	else
	{
		while (head != NULL)
		{
			num += fwrite(head, sizeof(Student), 1, ff);
			head = head->next;
		}
	}
	fclose(ff);
	return num;
}
//���ļ���ȡ����
int  read(Student* &head)
{
	int num=0;
	FILE *ff;
	if ((ff = fopen("practice7project2.dat", "r")) == NULL)
		printf("�ļ���ʧ�ܣ�");
	else
	{
		Student *p = NULL;
		Student *q = NULL;
		while (!feof(ff))
		{
			if (head == NULL)
			{
				head = (Student*)malloc(sizeof(Student));
				fread(head, 1, sizeof(Student), ff);
				num++;
				q = head;
			}
			else
			{
				p = (Student*)malloc(sizeof(Student));
				if (fread(p, 1, sizeof(Student), ff) > 2)
				{
					num++;
					p->next = NULL;
					q->next = p;
					q = p;
				}
				else
				{
					free(p);
				}
			}
		}
	}
	return num;
}

//�������
void show(Student* head)
{
	printf("ѧ��\t����\t�Ա�\t����\tC����\tӢ��\t��ѧ\tƽ����\n");
	while (head!=NULL)
	{
		printf("%-4d\t%-4s\t%-4s\t%-4d\t%-4.2f\t%-4.2f\t%-4.2f\t%-4.2f\n",head->id, head->name, head->sex, head->old,head->C_language,head->Engkish,head->Math,head->average );
		head = head->next;
	}
	getch();
}

//���Ԫ��
void addstudent(Student* &head)
{
	Student *oldhead=head;
	int num;
	printf("��������Ҫ��ӵ�ѧ��������");
	scanf("%d", &num);
	number += num;
	while (head->next!=NULL)
	{
		head = head->next;
	}
	Student *p = NULL;
	Student *q = NULL;

	q = head;
	for (int i = 0; i < num; i++)
	{
		p = (Student*)malloc(sizeof(Student));
		p->next = NULL;
		q->next = p;
		printf("==========================================================================\n");
		printf("������ѧ�ţ�");
		scanf("%d", &p->id);
		printf("������������");
		scanf("%s", &p->name);
		printf("�������Ա�");
		scanf("%s", &p->sex);
		printf("���������䣺");
		scanf("%d", &p->old);
		printf("������C���ԣ�");
		scanf("%f", &p->C_language);
		printf("������Ӣ�");
		scanf("%f", &p->Engkish);
		printf("��������ѧ��");
		scanf("%f", &p->Math);
		p->average = (p->Math + p->C_language + p->Engkish) / 3;
		q = p;
	}
	printf("��������������������...");
	getch();
	head = oldhead;
	if (output(head) > 1)
		printf("д���ļ��ɹ���\n");
	else
		printf("д���ļ�ʧ�ܣ�\n");
	getch();

}

//ɾ��Ԫ��
void delatestudent(Student* &head)
{
	int num;
	Student *cp, *star = head;
	printf("����������ɾ��ѧ����ѧ�ţ�");
	scanf("%d", &num);
	while (star!=NULL)
	{
		if (star->id == num)
			break;
		cp = star;
		star = star->next;
	}
	if (cp==NULL)//ɾ����һ���ڵ�
	{
		cp = head;
		 head= head->next;
		free(cp);
	}
	else
		cp->next = star->next;

	//�ڰ��޸ĺ������д���ļ�
	if (output(head) > 1)
		printf("ɾ���ɹ�!\n");
	else
		printf("ɾ��ʧ�ܣ�\n");
	number--;
	getch();
}

//�޸�����
void changestudent(Student* &head)
{
	int num;
	Student *star = head;
	printf("�����������޸�ѧ����ѧ�ţ�");
	scanf("%d", &num);
	while (star != NULL)
	{
		if (star->id == num)
			break;
		star = star->next;
	}
	printf("�������޸ĵ����ݣ�\n");
	printf("==========================================================================\n");
	printf("������ѧ�ţ�");
	scanf("%d", &star->id);
	printf("������������");
	scanf("%s", &star->name);
	printf("�������Ա�");
	scanf("%s", &star->sex);
	printf("���������䣺");
	scanf("%d", &star->old);
	printf("������C���ԣ�");
	scanf("%f", &star->C_language);
	printf("������Ӣ�");
	scanf("%f", &star->Engkish);
	printf("��������ѧ��");
	scanf("%f", &star->Math);
	star->average = (star->Math + star->C_language + star->Engkish) / 3;

	//д�뵽�ļ�
	if (output(head) > 1)
		printf("�޸ĳɹ�!\n");
	else
		printf("�޸�ʧ�ܣ�\n");
	getch();
}