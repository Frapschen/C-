#include "practice5project2\\ticket.h";

void init(Station &station, Ticket &ticket, Book &book);//��ʼ���ڸ�һվ̨

void practice5project2()
{
	Station station;
	Ticket ticket;
	Book book;
	//��ʼ��Ʊ����Ϣ
	init(station, ticket, book);
	int key;
	while (true)
	{
		system("cls");
		printf("\t\t***************************************\n");
		printf("\t\t\t��Ʊϵͳ-------------1\n");
		printf("\t\t\tϵͳ����-------------2\n");
		printf("\t\t\t�˳�ϵͳ-------------0\n");
		printf("\t\t**************************************\n");
		printf("\t\t��ѡ��");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			ticketServices(station,ticket,book);
			break;
		case 2:
			systemManage(station, ticket, book);
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
//��ʼ���ڸ�һվ̨
void init(Station &station, Ticket &ticket, Book &book)
{
	station.count = 0;
	ticket.count = 0;
	book.count = 0;
	station.ticketnum = 0;
	printf("------------------------------------------------------------------------\n");
	printf("��ӭ����ϵͳ������ӵ�һ��վ�㣺\n");
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
	printf("**��һ����վ��Ϣ��ӳɹ���\n");
	printf("------------------------------------------------------------------------\n");
	getch();
}


