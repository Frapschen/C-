#include "ticket.h"
void systemManage(Station &station, Ticket &ticket, Book &book)
{
	int key;
	while (true)
	{
		system("cls");
		printf("\t\t***************************************\n");
		printf("\t\t\t��վ����-------------1\n");
		printf("\t\t\tƱ�����-------------2\n");
		printf("\t\t\t������һ���˵�-------0\n");
		printf("\t\t**************************************\n");
		printf("\t\t��ѡ��");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			stationManage(station, ticket, book);
			break;
		case 2:
			ticketManage(station, ticket, book);
			break;
		case 0:
			break;
		default:
			printf("������󣡰����������...");
			getch();
			break;
		}
		if (key == 0)
			break;
	}
}