#include "ticket.h"
int  tsDisplay();//��ʾ�˵�
void found(Station &station, Ticket &ticket, Book &book);
void bookticket(Station &station, Ticket &ticket, Book &book);
void delateticket(Station &station, Ticket &ticket, Book &book);
void ticketServices(Station &station, Ticket &ticket, Book &book)
{
	int key;//��ʾ�˵�;
	while (true)
	{
		system("cls");
		key = tsDisplay();
		switch (key)
		{
		case 1:
			//��ѯ��Ʊ
			found(station, ticket, book);
			break;
		case 2:
			//Ԥ����Ʊ
			bookticket(station, ticket, book);
			break;
		case 3:
			delateticket(station, ticket, book);
			break;
		default:
			printf("�������");
		case 0:
			//������һ���˵�
			break;
		}
		if (key == 0)
			break;		
	}
}
//��ʾ�˵�
int tsDisplay()
{
	int key;
	printf("\t\t******************************\n");
	printf("\t\t\t��ѯ��Ʊ----------------1\n");
	printf("\t\t\tԤ����Ʊ----------------2\n");
	printf("\t\t\t��Ʊ����----------------3\n");
	printf("\t\t\t������һ���˵�----------0\n");
	printf("\t\t******************************\n");
	printf("\t\t��ѡ��");
	scanf("%d", &key);
	return key;
}

//��ѯ��Ʊ
void found(Station &station, Ticket &ticket, Book &book)
{
	char star[STR_LEN];
	char end[STR_LEN];
	printf("�����������㣺");
	scanf("%s", &star);
	printf("����������յ㣺");
	scanf("%s", &end);
	printf("��վ��\t���\t�յ�\t����\t    ����\tʱ��\t Ʊ��\t �۸�\n");
	int key=0;
	for(int i=0;i<station.count;i++)
		if (strcmp(star, station.station[i].from) == 0 && strcmp(end, station.station[i].to) == 0)
		{
			printf("%-4d\t%-4s\t%-4s\t %-4s\t %-8s\t%-4s\t  %-4d\t %-4d\n", station.station[i].stationId, station.station[i].from, station.station[i].to, station.station[i].trainId, station.station[i].data, station.station[i].time, station.station[i].numbers, station.station[i].money);
			key = -1;
		}
	if (key != -1)
		printf("û����Ҫ�ҵ�·�ߣ�");
	getch();

}

//Ԥ����Ʊ
void bookticket(Station &station, Ticket &ticket, Book &book)
{
	int key=0;
	char choise[STR_LEN];
	printf("��������ҪԤ���ĳ��Σ�");
	scanf("%s", &choise);
	for (int i = 0; i<station.count; i++)
		if (strcmp(choise,station.station->trainId)==0)
			if (station.station[i].numbers > 0)
			{
				printf("%-4d\t%-4s\t%-4s\t %-4s\t %-8s\t%-4s\t  %-4d\t %-4d\n", station.station[i].stationId, station.station[i].from, station.station[i].to, station.station[i].trainId, station.station[i].data, station.station[i].time, station.station[i].numbers, station.station[i].money);
				station.station[i].numbers--;
				book.book[book.count].ticketINfo.stationId = station.station[i].stationId;
				book.book[book.count].ticketINfo.seatId = rand();//�������
				strcpy(book.book[book.count].ticketINfo.time, station.station[i].time);
				strcpy(book.book[book.count].ticketINfo.trainId, station.station[i].trainId);
				strcpy(book.book[book.count].ticketINfo.time, station.station[i].time);
				strcpy(book.book[book.count].ticketINfo.data, station.station[i].data);
				strcpy(book.book[book.count].ticketINfo.from, station.station[i].from);
				strcpy(book.book[book.count].ticketINfo.to, station.station[i].to);
				book.book[book.count].autId = rand();
				printf("������������֣�");
				scanf("%s", &book.book[book.count].name);
				book.count++;
				break;
				key = -1;
				printf("Ԥ���ɹ���");
				getch();
			}
			else
			{
				printf("û��Ʊ�ˣ�");
				getch();
			}
	if (key != -1)
		printf("Ԥ��ʧ��");
}
//ɾ����Ʊ
void delateticket(Station &station, Ticket &ticket, Book &book)
{
	char name[STR_LEN];
	int key = 0;
	printf("������������֣�");
	scanf("%s",&name);
	for (int i = 0; i < book.count; i++)
		if (strcmp(name, book.book[i].name))
		{
			for (int k = 0; k < station.count; k++)
				if (strcmp(book.book[i].ticketINfo.trainId, station.station[k].trainId) == 0)
				{
					station.station[k].numbers++;
					break;
				}
			for (int j = i; j < book.count - 1; j++)
				book.book[j] = book.book[j + 1];
			book.count--;
			key = -1;
			break;
		}
	if (key != -1)
		printf("���Ʊ�����ڣ�");
}