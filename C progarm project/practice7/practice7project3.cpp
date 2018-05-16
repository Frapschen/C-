#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <mysql.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")
MYSQL MYDATE;


//ͼ�����ϵͳ
/*
*ʵ��ϵͳ��ɾ�Ĳ�
*/
typedef struct Bookinfo//ͼ����Ϣ
{
	int bnumber;//���
	int ISBN;//INSBN��
	char bname[20];//����
	char writer[20];//����
	char book_concern[20];//������
	int collection;//�ݲ���
};

typedef struct	Userinfo
{
	int userid;//����֤��
	char name[20];//����
	char sex[4];//�Ա�
	char major[20];//רҵ
};

typedef struct Lendinfo
{
	int bnumber;//s���
	int ISBN;//INSBN��
	int userid;//����֤��
	char lendtime[10];//����ʱ��
};

int initMYSQL();//�������ݿ�
int display(int n);//�˵�
void bookinfo();//ͼ�����
void userinfo();//�û�����
void rentinfo();//���Ĺ��� 

//���
void practice7project3()
{
	if (!initMYSQL())
	{
		printf("���ݿ�����ʧ�ܣ�");
		getch();
	}
	else
	{
		int key;
		while (true)
		{
			key = display(1);
			switch (key)
			{
			case 1:
				bookinfo();
				break;
			case 2:
				userinfo();
				break;
			case 3:
				rentinfo();
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
	mysql_close(&MYDATE);
}

//�������ݿ�
int initMYSQL()
{

	int k = 0;
	mysql_init(&MYDATE);
	mysql_options(&MYDATE, MYSQL_SET_CHARSET_NAME, "gbk");
	if (NULL != mysql_real_connect(&MYDATE, "localhost", "root", "123456", "test", 3306, NULL, 0))
	{
		Sleep(1000);
		printf("���ݿ����ӳɹ�...");
		Sleep(500);
		k = 1;
	}
	return k;
}

//�˵�
int display(int n)
{
	system("cls");
	int key;
	if (n == 1)
	{
		printf("***********��ӭ����ͼ�����ϵͳ***********\n");
		printf("*              1 ͼ�����                *\n");
		printf("*              2 �û�����                *\n");
		printf("*              3 ���Ĺ���                *\n");
		printf("*              4 ��    ��                *\n");
		printf("******************************************\n");
		printf("��ѡ��");
		scanf("%d", &key);
		return key;
	}
	if (n == 2)
	{
		printf("******************************\n");
		printf("**********1������Ϣ***********\n");
		printf("**********2ɾ����Ϣ***********\n");
		printf("**********3��ѯ��Ϣ***********\n");
		printf("**********4�޸���Ϣ***********\n");
		printf("**********5��    ��***********\n");
		printf("******************************\n");
		printf("��ѡ��");
		scanf("%d", &key);
		return key;
	}
}

//ͼ�����
void bookinfo()
{
	Bookinfo bookinfo;
	MYSQL_RES *res_set = NULL;
	MYSQL_ROW row = NULL;
	int key;
	char temp[200];
	system("cls");
	printf("***********ͼ�����***********\n");
	while (true)
	{
		key = display(2);
		switch (key)
		{
		case 1://����ͼ��
		{
			printf("��������ţ�");
			scanf("%d", &bookinfo.bnumber);
			printf("������ISNB�룺");
			scanf("%d", &bookinfo.ISBN);
			printf("������������");
			scanf("%s", &bookinfo.bname);
			printf("���������ߣ�");
			scanf("%s", &bookinfo.writer);
			printf("����������磺");
			scanf("%s", &bookinfo.book_concern);
			printf("������ݲ�����");
			scanf("%d", &bookinfo.collection);
			sprintf(temp, 
				"INSERT p7p3Bookinfo VALUE ( '%d','%d','%s','%s','%s','%d')"
				,bookinfo.bnumber, bookinfo.ISBN, bookinfo.bname, bookinfo.writer, bookinfo.book_concern, bookinfo.collection);
			if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
				printf("��ӳɹ���");
			else
				printf("���ʧ�ܣ�������Ϣ��%s", mysql_error(&MYDATE));
			getch();
			break;
		}
		case 2://ɾ��ͼ��
		{
			printf("��������Ҫɾ����ͼ���ţ�");
			scanf("%d", &bookinfo.bnumber);
			sprintf(temp, "DELETE FROM p7p3Bookinfo WHERE id=%d", bookinfo.bnumber);
			puts(temp);
			if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
			{
				if (mysql_affected_rows(&MYDATE))
					printf("ɾ���ɹ���");
				else
					printf("û��������ݣ�");
			}
			else
				printf("ɾ��ʧ�ܣ�������Ϣ��%s", mysql_error(&MYDATE));
				getch();
			break;
		}
		case 3://��ѯͼ��
		{
			mysql_query(&MYDATE, "SELECT *FROM p7p3Bookinfo");
			res_set = mysql_store_result(&MYDATE);
			if (res_set == NULL)
				printf("mysql_store_result error or Empty set\n");
			else
			{
				if (!(row = mysql_fetch_row(res_set)))
					printf("û�����ݣ�");
				else
				{
					printf("���\tISBN\t����\t����\t������\t�ݲ���\n");
					printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
					while (row = mysql_fetch_row(res_set))
					{
						printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
					}
					printf("-------------------------------------------------------------\n");
				}
			}
			mysql_free_result(res_set);
			getch();
			break;
		}
		case 4://�޸�ͼ��
		{
			printf("��������Ҫ�޸�ͼ��ı�ţ�");
			scanf("%d", &key);
			printf("�������µ��鼮��Ϣ��\n");
			printf("��������ţ�");
			scanf("%d", &bookinfo.bnumber);
			printf("������ISNB�룺");
			scanf("%d", &bookinfo.ISBN);
			printf("������������");
			scanf("%s", &bookinfo.bname);
			printf("���������ߣ�");
			scanf("%s", &bookinfo.writer);
			printf("����������磺");
			scanf("%s", &bookinfo.book_concern);
			printf("������ݲ�����");
			scanf("%d", &bookinfo.collection);
			sprintf(temp,
				"UPDATE p7p3Bookinfo SET id='%d',ISBN='%d',name='%s',writer='%s',book_concern='%s',collection='%d' WHERE id=%d"
				, bookinfo.bnumber, bookinfo.ISBN, bookinfo.bname, bookinfo.writer, bookinfo.book_concern, bookinfo.collection,key);
			puts(temp);
			if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
			{
				if(mysql_affected_rows(&MYDATE))
					printf("�޸ĳɹ���\n");
				else
					printf("�޸�ʧ�ܣ�����������룡\n");
					
			}
			else
				printf("�޸�ʧ�ܣ�������Ϣ��%s", mysql_error(&MYDATE));
			getch();
			break;
		}
		case 5:
			break;
		default:
			printf("�������");
			break;
		}
		if (key == 5)
			break;
	}
}

////�û�����
void userinfo()
{
	Userinfo userinfo;
	MYSQL_RES *res_set = NULL;
	MYSQL_ROW row = NULL;
	char temp[200];
	system("cls");
	printf("***********ͼ�����***********\n");
	int key;
	while (true)
	{
		key = display(2);
		switch (key)
		{
		case 1://�����û�
			{
				printf("���������֤��");
				scanf("%d", &userinfo.userid);
				printf("������������");
				scanf("%s", &userinfo.name);
				printf("�������Ա�");
				scanf("%s", &userinfo.sex);
				printf("������רҵ��");
				scanf("%s", &userinfo.major);
				sprintf(temp, "INSERT p7p3userinfo VALUE('%d','%s','%s','%s')",
					 userinfo.userid,userinfo.name,userinfo.sex,userinfo.major);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
					printf("��ӳɹ���");
			  	else
					printf("���ʧ�ܣ�������Ϣ��%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 2://ɾ���û�
			{
				printf("��������Ҫɾ�����û�ID��");
				scanf("%d", &userinfo.userid);
				sprintf(temp, "DELETE FROM p7p3Userinfo WHERE userid=%d", userinfo.userid);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
				{
					if (mysql_affected_rows(&MYDATE))
						printf("ɾ���ɹ���");
					else
						printf("û��������ݣ�");
				}
				else
					printf("ɾ��ʧ�ܣ�������Ϣ��%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 3://��ѯ�û�
			{
				mysql_query(&MYDATE, "SELECT *FROM p7p3Userinfo");
				res_set = mysql_store_result(&MYDATE);
				if (res_set == NULL)
					printf("mysql_store_result error or Empty set\n");
				else
				{
					if (!(row = mysql_fetch_row(res_set)))
						printf("û�����ݣ�");
					else
					{
						printf("����֤\t����\t�Ա�\tרҵ\n");
						printf("%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3]);
						while (row = mysql_fetch_row(res_set))
							printf("%-s\t%-s\t%-s\t%-s\n", row[0], row[1], row[2], row[3]);
						printf("-------------------------------------------------------------\n");
					}
				}
				mysql_free_result(res_set);
				getch();
				break;
			}
		case 4://�޸��û�
			{
				printf("��������Ҫ�޸ĵĽ���֤ID��");
				scanf("%d", &key);
				printf("���������֤��");
				scanf("%d", &userinfo.userid);
				printf("������������");
				scanf("%s", &userinfo.name);
				printf("�������Ա�");
				scanf("%s", &userinfo.sex);
				printf("������רҵ��");
				scanf("%s", &userinfo.major);
				sprintf(temp, "UPDATE p7p3Userinfo SET userid='%d',name='%s',sex='%s',major='%s'WHERE userid=%d",
					userinfo.userid, userinfo.name, userinfo.sex, userinfo.major,key);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
				{
					if (mysql_affected_rows(&MYDATE))
						printf("�޸ĳɹ���\n");
					else
						printf("�޸�ʧ�ܣ�����������룡\n");
				}
				else
					printf("�޸�ʧ�ܣ�������Ϣ��%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 5:
			break;
		default:
			printf("�������");
			break;
		}
		if (key == 5)
			break;
	}
}

//���Ĺ��� 
void rentinfo()
{
	Lendinfo lendinfo;
	MYSQL_RES *res_set = NULL;
	MYSQL_ROW row = NULL;
	char temp[200];
	system("cls");
	printf("***********���Ĺ���***********\n");
	int key,key2;
	while (true)
	{
		key = display(2);
		switch (key)
		{
		case 1://���ӽ�����Ϣ
			{
				printf("��������ţ�");
				scanf("%d", &lendinfo.bnumber);
				printf("������ISNB��");
				scanf("%d", &lendinfo.ISBN);
				printf("���������֤�ţ�");
				scanf("%d", &lendinfo.userid);
				printf("���������ʱ�䣺");
				scanf("%s", &lendinfo.lendtime);
				sprintf(temp, "INSERT p7p3Lendinfo VALUE(NULL,'%d','%d','%d','%s')",
					lendinfo.bnumber, lendinfo.ISBN, lendinfo.userid, lendinfo.lendtime);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
					printf("��ӳɹ���");
				else
					printf("���ʧ�ܣ�������Ϣ��%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 2://ɾ��������Ϣ
			{
				printf("�����������֤��");
				scanf("%s", &lendinfo.userid);
				printf("��������Ҫ�黹�����ID��");
				scanf("%d",&lendinfo.bnumber);
				sprintf(temp, "DELETE FROM p7p3Lendinfo WHERE book_number='%d' AND userid='%d'", lendinfo.bnumber, lendinfo.userid);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
					if (mysql_affected_rows(&MYDATE))
						printf("�黹�ɹ���");
					else
						printf("û��������ݣ�");
				else
					printf("�黹ʧ�ܣ�������Ϣ��%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 3://��ѯ������Ϣ
			{
				mysql_query(&MYDATE, "SELECT *FROM p7p3Lendinfo");
				res_set = mysql_store_result(&MYDATE);
				if (res_set == NULL)
					printf("mysql_store_result error or Empty set\n");
				else
				{
					if (!(row = mysql_fetch_row(res_set)))
						printf("û�����ݣ�");
					else
					{
						printf("ͼ��ID\t\tͼ��ISBN\t�û�ID\t\t����ʱ��\n");
						printf("%-8s\t%-8s\t%-8s\t%-8s\n", row[1], row[2], row[3], row[4]);
						while (row = mysql_fetch_row(res_set))
							printf("%-s\t\t%-s\t\t%-s\t\t%-s\n", row[1], row[2], row[3], row[4]);
						printf("-------------------------------------------------------------\n");
					}
				}
				mysql_free_result(res_set);
				getch();
				break;
			}
		case 4://�޸Ľ�����Ϣ
			{
				printf("�����������֤��");
				scanf("%d", &key);
				printf("���������������ID��");
				scanf("%d", &key2);
				printf("��ʼ�޸ģ�\n");
				printf("��������ţ�");
				scanf("%d", &lendinfo.bnumber);
				printf("������ISNB��");
				scanf("%d", &lendinfo.ISBN);
				printf("���������֤�ţ�");
				scanf("%d", &lendinfo.userid);
				printf("���������ʱ�䣺");
				scanf("%s", &lendinfo.lendtime);
				sprintf(temp, "UPDATE p7p3Lendinfo SET book_number='%d',ISBN='%d',userid='%d',lendtime='%s' WHERE userid='%d' AND book_number='%d'",
					lendinfo.bnumber, lendinfo.ISBN, lendinfo.userid, lendinfo.lendtime, key,key2);
				if (!mysql_real_query(&MYDATE, temp, strlen(temp)))
				{
					if (mysql_affected_rows(&MYDATE))
						printf("�޸ĳɹ���\n");
					else
						printf("�޸�ʧ�ܣ�����������룡\n");
				}
				else
					printf("�޸�ʧ�ܣ�������Ϣ��%s", mysql_error(&MYDATE));
				getch();
				break;
			}
		case 5:
			break;
		default:
			printf("�������");
			break;
		}
		if (key == 5)
			break;
	}
}
