#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string"

#define N 50 //����������
#define M 26 //���ʳ�������

int Practice4project2DisplayMenu();
void print(const char word[][M], int);
void stringsort1(char word[][M], int n);
void stringsort2(char word[][M], int n);
void stringsort3(char word[][M], int n);
void practice4project2()
{
	int key;
	for (;;)
	{
		system("cls");
		key = Practice4project2DisplayMenu();
		     
		char word[N][M];
		int m = M - 1;
		int count = N;
		int n = 0, i;
		switch (key)
		{
		case 1:
			//��������ĵ�������1-50֮��
			while (n < 1 || n>50)
			{
				printf("�������㽫Ҫ����ĵ�������(1-%d)\n", count);
				scanf("%d", &n);
			}
			printf("������%d�����ʣ��Կո�ֿ�\n(���ʳ��Ȳ�����%d,��������������Զ����Գ�������)\n", n, m);
			for (i = 0; i < n; i++)
			{
				scanf("%s", &word[i]);
				word[i][M - 1] = '\0';
			}
			stringsort1(word, n);
			printf("������Ϊ��\n");
			print(word, n);
			getch();
			break;
		case 2:
			//��������ĵ�������1-50֮��
			while (n < 1 || n>50)
			{
				printf("�������㽫Ҫ����ĵ�������(1-%d)\n", count);
				scanf("%d", &n);
			}
			printf("������%d�����ʣ��Կո�ֿ�\n(���ʳ��Ȳ�����%d,��������������Զ����Գ�������)\n", n, m);
			for (i = 0; i < n; i++)
			{
				scanf("%s", &word[i]);
				word[i][M - 1] = '\0';
			}
			stringsort2(word, n);
			stringsort1(word, n);
			printf("������Ϊ��\n");
			print(word, n);
			getch();
			break;
		case 3:
			//��������ĵ�������1-50֮��
			while (n < 1 || n>50)
			{
				printf("�������㽫Ҫ����ĵ�������(1-%d)\n", count);
				scanf("%d", &n);
			}
			printf("������%d�����ʣ��Կո�ֿ�\n(���ʳ��Ȳ�����%d,��������������Զ����Գ�������)\n", n, m);
			for (i = 0; i < n; i++)
			{
				scanf("%s", &word[i]);
				word[i][M - 1] = '\0';
			}
			stringsort3(word, n);
			printf("������Ϊ��\n");
			print(word, n);
			getch();
			break;
		case 4:
			;
		default:
			printf("�������");
			break;

		}
		if (key == 4)
			break;
	}
}

int Practice4project2DisplayMenu()
{
	system("cls");
	int key;
	printf("******************ʵս4��Ŀ2���ܲ˵�*************\n");
	printf("*****        1. ����1->�ַ�����������       *****\n");
	printf("*****        2. ����2->��Сд�������ַ����� *****\n");
	printf("*****        3. ����3->���ʽ�������(�ǲ���) *****\n");
	printf("*****        4.  ������һ���˵�             *****\n");
	printf("�����빦�ܺţ�");
	scanf("%d", &key);
	return key;
}

void stringsort1(char word[][M], int n)
{
	char key[M];
	int i, j;
	for (i = 1; i < n; i++)
	{
		strcpy(key, word[i]);
		j = i;
		while (j >= 1 && 1 == strcmp(word[j - 1], key))
		{
			strcpy(word[j], word[j - 1]);
			j--;
		}
		strcpy(word[j], key);
	}
}

void stringsort2(char word[][M],int n)
{
	char key[M];
	//��д����Сд
	for (int i = 0; i < n; i++) 
	{
		strcpy(key, word[i]);	
			for (int k = 0; word[i][k] != '\0'; k++)
				if (word[i][k] >= 'A'&&word[i][k] <= 'Z')
			                word[i][k] += 32;
	}
	int len;
	for (int i=0; i < n; i++)
	{
		len = strlen(word[i]);
		if (!(word[i][len - 1] >= 'a'&&word[i][len - 1] <= 'z'))
			word[i][len - 1] = '\0';
	}
}

void stringsort3(char word[][M], int n)
{
	char key[M];
	int i, j,c;
	for (i = 0; i < n - 1; i++)
	{
		strcpy(key, word[i]);
		for(j=i;j<n;j++)
			if (strcmp(key, word[j])>0)//key ��
			{
				c = j;
				strcpy(key, word[j]);
			}
		strcpy(word[c], word[i]);
		strcpy(word[i], key);
		
	}
}
void print(const char word[][M], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s\n", word[i]);	
}