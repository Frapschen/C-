#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

void practice7project1()
{
	int count = 1;
	int key = 0;
	FILE *fp;
	if ((fp = fopen("practice7project1.dat", "r")) != NULL)//�ļ��Ѿ����ڣ�����count++
	{
		//��������
		fscanf(fp, "%d", &count);
		fclose(fp);//�ر�ֻ��
		//����д������
		fp = fopen("practice7project1.dat", "w");
		count++;
		fprintf(fp, "%d", count);
		fclose(fp);
	}
	else if ((fp = fopen("practice7project1.dat", "w+")) == NULL)//��һ�δ��ļ�
	{
		printf("�������");
		getch();
		key = -1;
		if (key != -1)
		{
			fprintf(fp, "%d", count);
		}
	}
	if (key !=-1)
	{
		printf("�����������%d��", count);
		getch();
	}
}