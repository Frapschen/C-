#include "ticket.h"

int  timDisplay();//��ʾ�˵�
void foundsellticket(Station &station, Ticket &ticket, Book &book);//������Ʊ
void foundremainticket(Station &station, Ticket &ticket, Book &book);//�������

void ticketManage(Station &station, Ticket &ticket, Book &book)
{
	int key;//��ʾ�˵�;
	while (true)
	{
		system("cls");
		key = timDisplay();
		switch (key)
		{
		case 1:
			//������Ʊ
			foundsellticket(station, ticket, book);
			break;
		case 2:
			//�������
			foundremainticket(station, ticket, book);
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
int  timDisplay()
{
	int key;
	printf("\t\t******************************\n");
	printf("\t\t\t������Ʊ----------------1\n");
	printf("\t\t\t�������----------------2\n");
	printf("\t\t\t������һ���˵�----------0\n");
	printf("\t\t******************************\n");
	printf("\t\t��ѡ��");
	scanf("%d", &key);
	return key;
}

//������Ʊ
void foundsellticket(Station &station, Ticket &ticket, Book &book)
{
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("���\t����\t��λ��\t��վ��\t���\t�յ�\t����\t    ʱ��\t����\n");
	for (int i = 0; i < book.count; i++)
		printf("%-4d\t%-4s\t %-4d\t %-4d\t%-4s\t%-4s\t%-4s\t\t%-4s\t %-4s\n",book.book[i].autId,
			book.book[i].name, book.book[i].ticketINfo.seatId, book.book[i].ticketINfo.stationId,
			book.book[i].ticketINfo.from, book.book[i].ticketINfo.to, book.book[i].ticketINfo.trainId,
			book.book[i].ticketINfo.time, book.book[i].ticketINfo.data);
	getch();
}

//�������
void foundremainticket(Station &station, Ticket &ticket, Book &book)
{
	printf("��վ��\t���\t�յ�\t����\t    ����\tʱ��\t ����Ʊ��\n");
	for(int i=0;i<station.count;i++)
		if(station.station[i].numbers!=0)
			printf("%-4d\t%-4s\t%-4s\t %-4s\t %-8s\t%-4s\t  %-4d\n", station.station[i].stationId, station.station[i].from, station.station[i].to, station.station[i].trainId, station.station[i].data, station.station[i].time, station.station[i].numbers);
		else
		{
			printf("ȫ�����գ�");
		}
	getch();
}