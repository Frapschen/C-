#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <mysql.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")
MYSQL mydata;

int initmysql();//�������ݿ�
int display_p8p2();//��ʾ�˵�
void adddata();//����ѧ��
void delatedata();//ɾ��ѧ��
void showtable();//��ʾ�˵�
void updata();//�޸�����

//���
void practice8project2()
{
	int key;
	if (!initmysql())
	{
		printf("���ݿ�����ʧ�ܣ�");
		getch();
	}
	else
	{
		while (true)
		{
			key = display_p8p2();
			switch (key)
			{
			case 1:
				adddata();
				break;
			case 2:
				delatedata();
				break;
			case 3:
				updata();
				break;
			case 4:
				showtable();
				getch();
				break;
			case 5:
				break;
			default:
				printf("�������,��������������룡");
				getch();
				break;
			}
			if (key == 5)
				break;
		}
		mysql_close(&mydata);
	}
}

//�������ݿ�
int initmysql()
{

	int k = 0;
	mysql_init(&mydata);
	mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk");
	if (NULL != mysql_real_connect(&mydata, "localhost", "root", "123456", "test", 3306, NULL, 0))
	{
		Sleep(1000);
		printf("���ݿ����ӳɹ�...");
		Sleep(500);
		k = 1;
	}
	return k;
}

//��ʾ�˵�
int display_p8p2()
{
	system("cls");
	int key;
	printf("******************��ӭ����ѧ������ϵͳ******************\n");
	printf("*****        1. ���ѧ��                           *****\n");
	printf("*****        2. ɾ��ѧ��                           *****\n");
	printf("*****        3. �޸�ѧ��                           *****\n");
	printf("*****        4. ��ѯ����                           *****\n");
	printf("*****        5.  ������һ���˵�                    *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}

//����ѧ��
void adddata()
{
	char id[15];
	char name[15];
	char sex[8];
	char age[3];
	char score_cp[3], score_en[3], score_math[3];
	printf("������ѧ�ţ��ַ�����");
	scanf("%s", &id);
	printf("�������������ַ�����");
	scanf("%s", &name);
	printf("�������Ա��ַ�����");
	scanf("%s", &sex);
	printf("���������䣨���ͣ���");
	scanf("%s", &age);
	printf("������C���Եķ��������ͣ���");
	scanf("%s", &score_cp);
	printf("������Ӣ��ķ��������ͣ���");
	scanf("%s", &score_en);
	printf("��������ѧ�ķ��������ͣ���");
	scanf("%s", &score_math);

	char temp[200];
	strcpy(temp, "INSERT student_tbl VALUE(");
	strcat(temp, id);
	strcat(temp, ",'");
	strcat(temp, name);
	strcat(temp, "','");
	strcat(temp, sex);
	strcat(temp, "',");
	strcat(temp, age);
	strcat(temp, ",");
	strcat(temp, score_cp);
	strcat(temp, ",");
	strcat(temp, score_en);
	strcat(temp, ",");
	strcat(temp, score_math);
	strcat(temp, ",");
	strcat(temp, "(score_cp+score_en+score_math)/3)");

	if (!mysql_real_query(&mydata, temp, strlen(temp)))
	{
		printf("��ӳɹ���");
		getch();
	}
	else
	{
		printf("���ʧ�ܣ�������Ϣ��\s", mysql_error(&mydata));
		
		getch();
	}
}

//ɾ��ѧ��
void delatedata()
{
	showtable();
	char temp[200];
	char id[15];
	printf("\n------------------------------------------------------------\n");
	printf("��������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%s", &id);
	strcpy(temp, "DELETE FROM student_tbl WHERE id=");
	strcat(temp, id);
	if (!mysql_real_query(&mydata, temp, strlen(temp)))
	{
		printf("ɾ���ɹ���");
		getch();
	}
	else
	{
		printf("ɾ��ʧ�ܣ�������Ϣ��%s", mysql_error(&mydata));
		getch();
	}
}

//��ʾ����
void showtable()
{
	MYSQL_RES *res_set=NULL;
	MYSQL_ROW row=NULL;
	if (mysql_query(&mydata,
		"SELECT *FROM student_tbl"
	))
	{
		printf("ʧ�ܣ�������Ϣ��\s\n", mysql_error(&mydata));
		getch();
	}
	else
	{
		res_set = mysql_store_result(&mydata);
		if (res_set == NULL)
			printf("mysql_store_result error or Empty set\n");
		else
		{
			if (!(row = mysql_fetch_row(res_set)))
			{
				printf("û�����ݣ�");
				getch();
			}
			else
			{
				printf("ѧ��\t\t����\t�Ա�\t����\tC����\tӢ��\t��ѧ\tƽ����\n");
				printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
				while (row = mysql_fetch_row(res_set))
				{
					printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
				}
			}	
		}
	}
	//�ͷŽ����
	mysql_free_result(res_set);
}

//�޸�����
void updata()
{
	showtable();
	char oldid[15];
	printf("\n------------------------------------------------------------\n");
	printf("��������Ҫ�޸�ѧ����ѧ�ţ�");
	scanf("%s", &oldid);
	printf("������������Ϣ��");
	char id[15];
	char name[15];
	char sex[8];
	char age[3];
	char score_cp[3], score_en[3], score_math[3];
	printf("������ѧ�ţ��ַ�����");
	scanf("%s", &id);
	printf("�������������ַ�����");
	scanf("%s", &name);
	printf("�������Ա��ַ�����");
	scanf("%s", &sex);
	printf("���������䣨���ͣ���");
	scanf("%s", &age);
	printf("������C���Եķ��������ͣ���");
	scanf("%s", &score_cp);
	printf("������Ӣ��ķ��������ͣ���");
	scanf("%s", &score_en);
	printf("��������ѧ�ķ��������ͣ���");
	scanf("%s", &score_math);
	char temp[200];
	strcpy(temp, "UPDATE student_tbl SET ");
	strcat(temp, "id="); strcat(temp, id); strcat(temp, ",");
	strcat(temp, "name="); strcat(temp, "'"); strcat(temp, name); strcat(temp, "'"); strcat(temp, ",");
	strcat(temp, "sex=");  strcat(temp, "'");  strcat(temp, sex); strcat(temp, "'"); strcat(temp, ",");
	strcat(temp, "age="); strcat(temp, age); strcat(temp, ",");
	strcat(temp, "score_cp="); strcat(temp, score_cp); strcat(temp, ",");
	strcat(temp, "score_en="); strcat(temp, score_en); strcat(temp, ",");
	strcat(temp, "score_math="); strcat(temp, score_math); strcat(temp, ",");
	strcat(temp, "score_averge=(score_cp+score_en+score_math)/3 ");
	strcat(temp, "WHERE id=");
	strcat(temp, oldid); 
	if (!mysql_real_query(&mydata, temp, strlen(temp)))
	{
		printf("�޸ĳɹ���\n");
		getch();
	}
	else
	{
		printf("�޸�ʧ�ܣ�������Ϣ��%s", mysql_error(&mydata));
		getch();
	}
}
