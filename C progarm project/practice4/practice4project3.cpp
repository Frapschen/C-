#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define LEN 100
int lc = 0,uc = 0,d = 0, s = 0, o = 0;
void count(char ary[]);
//�ַ���ͳ��
void practice4project3()
{
	char ary[LEN + 1];
	printf("������100�����ڵ������ַ�\n");
	printf("���򽫰���Сд��ĸ�����֡��ո�������ַ�����ͳ�ơ�\n");
	printf("�������100���ַ�������ֻ��ǰ100���ַ�����ͳ�ƣ�\n");
	char ch;
	while ((ch = getchar()) != EOF && ch != '\n')
	{
		;
	}
	gets_s(ary);
	puts(ary);
	count(ary);
	printf("Сд��ĸ��%d\n", lc);
	printf("��д��ĸ��%d\n", uc);
	printf("0��9���֣�%d\n", d);
	printf("�ո�%d\n", s);
	printf("�����ַ���%d\n", o);
	printf("��������˳�...");
	getchar();

}
void count(char ary[])
{
	int i = 0;
	char c;
	while (ary[i])
	{
		c = ary[i];
		if (c >= '0'&& c <= '9')
			d++;
		else if (c >= 'a' && c <= 'z')
			lc++;
		else if (c >= 'A' &&c <= 'Z')
			uc++;
		else if (c == ' ')
			s++;
		else
			o++;
		i++;
	}
}