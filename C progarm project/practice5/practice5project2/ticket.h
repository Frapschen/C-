#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define STATION_NUM 100
#define TICKET_NUM 1000
#define STR_LEN 15

typedef struct {
	int stationId;//��վ��
	char from[STR_LEN];//��Ʊ���
	char to[STR_LEN];//��վ�յ�
	char trainId[STR_LEN];//�𳵳���
	char data[STR_LEN];
	char time[STR_LEN];
	int money;//Ʊ��
	int numbers;//Ʊ��
}StationInfo;//��վƱ����Ϣ

typedef struct {
	StationInfo station[STATION_NUM];
	int count;
	int ticketnum;
}Station;//վƱ����Ϣ������

typedef struct {
	int stationId;//��վ��
	int seatId;//��λ��
	char trainId[STR_LEN];//�𳵳���  �������
	char time[STR_LEN];//����ʱ��
	char data[STR_LEN];
	char from[STR_LEN];//��Ʊ���
	char to[STR_LEN];//��վ�յ�
}TicketInfo;//��Ʊ��Ϣ


typedef struct
{
	TicketInfo ticket;
	int count;
}Ticket;//��Ʊ��Ϣ

typedef struct {
	int autId;
	char name[STR_LEN];
	TicketInfo ticketINfo;
}BookInfo;//��Ʊ��Ϣ

typedef struct {
	BookInfo book[TICKET_NUM];
	int count;
}Book;//��Ʊ��Ϣ������

void systemManage(Station &station, Ticket &ticket, Book &book);
void stationManage(Station &station, Ticket &ticket, Book &book);
void ticketManage(Station &station, Ticket &ticket, Book &book);
void ticketServices(Station &station, Ticket &ticket, Book &book);

