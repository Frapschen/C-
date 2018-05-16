#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define N 3

typedef struct Subject
{
	float C_langeuage;
	float Engelish;
	float Math;

};

typedef struct Student
{
	int id;
	char name[10];
	char sex[4];
	int age;
	Subject subject;
	float averagescore;

};

int DisplayMenu(int n);
void InputStudent(Student stu[], Student stucpy[]);
void SortStudnet(Student stu[], Student stucpy[],int k ,int n);//k�ǰ�ʲô����,n=1����n=0����
void OutputStudent(Student stu[]);
void copy(Student *stu, Student *stucpy,int c,int num);
//�����
void practice5project1()
{
	Student stu[N],stucpy[N];
	InputStudent(stu, stucpy);
	int key;
	int key2;
	while (true)
	{
		key = DisplayMenu(1);//��������
		if(key!=0&&key!=9)
		   key2 = DisplayMenu(2);//��ô����
		switch (key)
		{
		case 1://ѧ��
			Student temp;
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 2://����
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 3://�Ա�
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 4://����
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 5://C����
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 6://Ӣ��
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 7://����
			SortStudnet(stu, stucpy, key, key2);
			getch();
			break;
		case 8://ƽ����
			break;
		case 9:
			OutputStudent(stu);
		case 0:
			break;
		default:
				printf("�������");
		}
		if (key == 0)
			break;
	}
}

//��ʾ�˵�
int DisplayMenu(int n)
{
	system("cls");
	switch (n)
	{
	case 1:
		printf("-----------------------------------------------------------------\n");
		printf("��ѡ�������ֶΣ�\n");
		printf("1.ѧ��             2.����                3.�Ա�              4����\n");
		printf("5.C����            6.Ӣ��                7.����              8.ƽ����\n");
		printf("9.��ʾȫ��ԭʼ��Ϣ                       0.�˳�����\n");
		printf("-----------------------------------------------------------------\n");
		break;
	case 2:
		printf("-----------------------------------------------------------------\n");
		printf("1.����                   2.����                     0.�˳�����   \n");
		printf("-----------------------------------------------------------------\n");
		break;
	default:
		printf("�������\n");
		break;
	}
	int k;
	scanf("%d", &k);
	return k;
}
//����ѧ������Ϣ
void InputStudent(Student stu[], Student stucpy[]){
	for (int i = 0; i < N; i++)
	{
		printf("�������%d/%d��ѧ����Ϣ��\n",i+1,N);
		printf("------------------------------------------------------------\n");
		printf("ѧ�ţ�");
		scanf("%d", &stu[i].id);
		printf("������10���ַ��ڣ���");
		scanf("%s", &stu[i].name);
		printf("�Ա�(�ĸ��ַ���)��");
		scanf("%s",&stu[i].sex);
		printf("����(����)��");
		scanf("%d", &stu[i].age);
		printf("��C���ԡ��ɼ�(����)��");
		scanf("%f", &stu[i].subject.C_langeuage);
		printf("��Ӣ��ɼ�(����)��");
		scanf("%f", &stu[i].subject.Engelish);
		printf("���������ɼ�(����)��");
		scanf("%f", &stu[i].subject.Math);
		printf("------------------------------------------------------------\n");
		stu[i].averagescore = (stu[i].subject.C_langeuage + stu[i].subject.Engelish + stu[i].subject.Math) / 2;
	}
	stucpy = stu;
}
//���ѧ������Ϣ
void OutputStudent(Student stu[])
{
	printf("====================================================================================\n");
	printf("ѧ��ȫ����Ϣ��\n");
	printf("ѧ��      ����    �Ա�       ����       C����     Ӣ��      ��ѧ      ƽ����\n");
	for (int i = 0; i < N; i++)
	{
		printf("%-10d", stu[i].id);
		printf("%-10s", stu[i].name);
		printf("%-10s",stu[i].sex);
		printf("%-10d", stu[i].age);
		printf("%-10.2f", stu[i].subject.C_langeuage);
		printf("%-10.2f", stu[i].subject.Engelish);
		printf("%-10.2f", stu[i].subject.Math);
		printf("%-10.2f", stu[i].averagescore);
		putchar('\n');
	}
	getch();
}
//�����ṹ�帴��
void copy(Student *stu, Student *stucpy,int c,int num)
{
	/*int id;
	char name[10];
	char sex[4];
	int age;
	Subject subject;
	float averagescore;*/

	stucpy[c].id = stucpy[num].id;
	stucpy[c].age = stu[num].age;
	stucpy[c].averagescore = stu[num].averagescore;
	
	stucpy[c].subject.C_langeuage = stu[num].subject.C_langeuage;
	stucpy[c].subject.Engelish = stu[num].subject.Engelish;
	stucpy[c].subject.Math = stu[num].subject.Math;
	
	strcpy(stucpy[c].name, stu[num].name);
	strcpy(stucpy[c].sex, stu[num].sex);

}
//����ѡ������
void SortStudnet(Student stu[], Student stucpy[],int k,int n)
{
	//ע������ʽn==1������==0�ǽ���
	Student temp;
	switch (k)
	{
	case 1://ѧ��
	{
		//ð������
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].id > stu[j + 1].id)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else//����
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].id < stu[j + 1].id)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//��ʾ��������
		OutputStudent(stu);
		break;
	}
	case 2://����
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (strcmp(stu[j].name,stu[j+1].name)>0)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else

		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (strcmp(stu[j].name, stu[j + 1].name)<0)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//��ʾ��������
		OutputStudent(stu);
		break;
	case 3://�Ա�
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (strcmp(stu[j].sex, stu[j + 1].sex)>0)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else

		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (strcmp(stu[j].sex, stu[j + 1].sex)<0)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//��ʾ��������
		OutputStudent(stu);
		break;
	case 4://����
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].age > stu[j + 1].age)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else

		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].age < stu[j + 1].age)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//��ʾ��������
		OutputStudent(stu);
		break;
	case 5://C����
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.C_langeuage > stu[j + 1].subject.C_langeuage)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.C_langeuage < stu[j + 1].subject.C_langeuage)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//��ʾ��������
		OutputStudent(stu);
		break;
	case 6://Ӣ��
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.Engelish > stu[j + 1].subject.Engelish)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.Engelish < stu[j + 1].subject.Engelish)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//��ʾ��������
		OutputStudent(stu);
		break;
	case 7://��ѧ
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.Engelish > stu[j + 1].subject.Engelish)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].subject.Math < stu[j + 1].subject.Math)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//��ʾ��������
		OutputStudent(stu);
		break;
	case 8://ƽ����
		if (n == 1)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].averagescore > stu[j + 1].averagescore)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		else
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N - 1 - i; j++)
					if (stu[j].averagescore < stu[j + 1].averagescore)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
		}
		//��ʾ��������
		OutputStudent(stu);
		break;
	default:
		break;
	}
}