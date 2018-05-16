#include "ticket.h"


//վ�����
int  stmDisplay();//��ʾ�˵�
void foundstation(Station &station, Ticket &ticket, Book &book);//��ѯվ��
void addstation(Station &station, Ticket &ticket, Book &book);//����վ��
void changestation(Station &station, Ticket &ticket, Book &book);//�޸�վ��
void delatestation(Station &station, Ticket &ticket, Book &book);//ɾ��վ��			

void stationManage(Station &station, Ticket &ticket, Book &book)
{
	int key;//��ʾ�˵�;
	while (true)
	{
		system("cls");
		key = stmDisplay();
		switch (key)
		{
		case 1:
			foundstation(station, ticket, book);//��ѯվ��
			break;
		case 2:
			addstation(station, ticket, book);//����վ��
			break;
		case 3:
			changestation(station, ticket, book);//�޸�վ��
			break;
		case 4:
			delatestation(station, ticket, book);//ɾ��վ��
			break;
		case 0:
			//������һ���˵�
			break;
		}
		if (key == 0)
			break;
	}
}

//��ʾ�˵�
int stmDisplay()
{
	int key;
	printf("\t\t******************************\n");
	printf("\t\t\t��ѯվ��----------------1\n");
	printf("\t\t\t����վ��----------------2\n");
	printf("\t\t\t�޸�վ��----------------3\n");
	printf("\t\t\tɾ��վ��----------------4\n");
	printf("\t\t\t������һ���˵�----------0\n");
	printf("\t\t******************************\n");
	printf("\t\t��ѡ��");
	scanf("%d", &key);
	return key;
}

//��ѯվ��
void foundstation(Station &station, Ticket &ticket, Book &book)
{
	printf("��վ��\t���\t�յ�\t����\t    ����\tʱ��\t Ʊ��\t �۸�\n");
	for (int i = 0; i < station.count; i++)
	{
		printf("%-4d\t%-4s\t%-4s\t %-4s\t %-8s\t%-4s\t  %-4d\t %-4d\n",station.station[i].stationId, station.station[i].from, station.station[i].to, station.station[i].trainId, station.station[i].data, station.station[i].time, station.station[i].numbers, station.station[i].money);
	}
	getch();
}

//����վ��
void addstation(Station &station, Ticket &ticket, Book &book)
{
	printf("------------------------------------------------------------------------\n");
	printf("�����վ�㣺\n");
	printf("------------------------------------------------------------------------\n");
	printf("������վ��ţ�");
	scanf("%d", &station.station[station.count].stationId);
	printf("��������ʼվ̨��");
	scanf("%s", &station.station[station.count].from);
	printf("�������յ�վ̨��");
	scanf("%s", &station.station[station.count].to);
	printf("�����복�ѣ�");
	scanf("%d", &station.station[station.count].money);
	printf("������Ʊ����");
	scanf("%d", &station.station[station.count].numbers);
	printf("�����Ʊ����Ϣ��\n");
	printf("�г�����(����)��");
	scanf("%s", &station.station[station.count].trainId);
	printf("�г��������ڣ�");
	scanf("%s", &station.station[station.count].data);
	printf("������ʱ�䣺");
	scanf("%s", &station.station[station.count].time);
	station.count++;
	printf("**��վ��Ϣ��ӳɹ���\n");
	printf("------------------------------------------------------------------------\n");
	getch();
}

//�޸�վ��
void changestation(Station &station, Ticket &ticket, Book &book)
{
	int key;
	printf("��������Ҫ�޸ĵ�վ��ţ�");
	scanf("%d", &key);
	for(int i=0;i<station.count;i++)
		if (key == station.station[i].stationId)
		{
			printf("------------------------------------------------------------------------\n");
			printf("�����������վ������ݣ�\n");
			printf("------------------------------------------------------------------------\n");
			printf("������վ��ţ�");
			scanf("%d", &station.station[i].stationId);
			printf("��������ʼվ̨��");
			scanf("%s", &station.station[i].from);
			printf("�������յ�վ̨��");
			scanf("%s", &station.station[i].to);
			printf("�����복�ѣ�");
			scanf("%d", &station.station[i].money);
			printf("������Ʊ����");
			scanf("%d", &station.station[i].numbers);
			printf("�����Ʊ����Ϣ��\n");
			printf("�г�����(����)��");
			scanf("%s", &station.station[i].trainId);
			printf("�г��������ڣ�");
			scanf("%s", &station.station[i].data);
			printf("������ʱ�䣺");
			scanf("%s", &station.station[i].time);
			printf("**��վ��Ϣ���³ɹ���\n");
			printf("------------------------------------------------------------------------\n");
			key = -1;
			break;
		}
	if (key != -1)
		printf("û�����վ��");
	getch();
}

//ɾ��վ��	
void delatestation(Station &station, Ticket &ticket, Book &book)
{
	int key;
	printf("��������Ҫ�޸ĵ�վ��ţ�");
	scanf("%d", &key);
	for (int i = 0; i<station.count; i++)
		if (key == station.station[i].stationId)
		{
			for (int j = i; j < station.count-1; j++)
				station.station[i] = station.station[i + 1];
			key = -1;
			printf("ɾ���ɹ���");
		}
	station.count--;
	if (key != -1)
		printf("û�����վ��!");
	getch();
}