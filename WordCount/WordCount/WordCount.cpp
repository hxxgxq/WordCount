// WordCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

char wordCount[100];
int count_char(const char *t);//��¼�ַ���	
int count_word(const char *t);//��¼������
int count_row(const char *t);//��¼����
void output(const char* t, const char* a, int num);//����ͳ�Ƶ���������ض��ļ���
void output_f(const char* t, const char* w, int count, int row, int word);//����ͳ�Ƶ��������ָ���ļ���
char input[100];//��ȡ������
char a[100];
char * flie_name;//�������л�õ�Ŀ���ļ���
char * Outfile_name;//�������л�õ����Ŀ���ļ���
int main()
{
	int char_num = 0;
	int word_num = 0;
	int row = 0;
	scanf_s("%[^\n]", input, 50);
	for (int i = 0; input[i] != NULL; i++)
	{
		if(input[i] == '-')
			if (input[i+1] == 'o')
				for (int j = i+1; input[j] != NULL; j++)
				{
					if (input[j] == ' ')
						if (input[j + 1] != ' '&&input[j + 1] != '-')
						{
							Outfile_name = input + j + 1;
							break;
						}
				}				
	}
	for (int i = 1; input[i] != NULL; i++)
	{
		if (input[i-1] == ' ')
			if (input[i] !=' '&&input[i] !='-')
			{
				int j = i;
				while (input[i] != ' '&& input[i]!=NULL)
				{
					a[i] = input[i];
					i++;
				}
				flie_name = a + j;
				break;
			}					//��ȡĿ���ļ���
	}
	for (int i = 0; input[i] != NULL; i++)   //���������Ҫ��ִͬ�в�ͬ�Ĺ���
	{
		if (input[i] == '-')
		{
			if (input[i + 1] == 'c')		//-c
			{
				char_num = count_char(flie_name);
				printf("�ַ�����%d", char_num);
				output(flie_name, "�ַ���", char_num);
				printf_s("\n");
			}
			if (input[i + 1] == 'l')		//-l
			{
				row = count_row(flie_name);
				printf("������%d", row);
				output(flie_name, "����", row);
				printf("\n");
			}
			if (input[i + 1] == 'w')	//-w
			{
				word_num = count_word(flie_name);
				printf("��������%d", word_num);
				output(flie_name, "������", word_num);
				printf("\n");
			}
			if (input[i + 1] == 'o')     //-o
			{
				output_f(flie_name, Outfile_name,char_num,row,word_num);
				printf("\n");
			}
		}
	}
	getchar();
	return 0;
}
int count_char(const char *t) 
{
	FILE *fp;
	char data;
	int char_num = 0;
	if ((fp = fopen(t, "r")) == NULL)
	{
		printf("Open the file failure\n");
		return -1;
	}
	for (int i = 0; (data = getc(fp)) != EOF; i++)
	{
		char_num++;			//��¼�ַ���
	}
	fclose(fp);
	return char_num;
}
int count_word(const char *t) 
{
	FILE *fp;
	char data;
	int word_num = 0;
	if ((fp = fopen(t, "r")) == NULL)
	{
		printf("Open the file failure\n");
		return -1;
	}
	for (int i = 0; (data = getc(fp)) != EOF; i++)
	{
		wordCount[i] = data;
	}
	if (wordCount[0] != ' ' || wordCount[0] != ',')
		word_num++;
	for (int i = 0; wordCount[i] != NULL; i++)
	{
		if (wordCount[i] == ' ' || wordCount[i] == ',' || wordCount[i] == '\n')
			if (wordCount[i + 1] != ' ' && wordCount[i + 1] != ',' && wordCount[i + 1] != '\n')
				word_num++;    //��¼������
	}
	fclose(fp);
	return word_num;
}
int count_row(const char *t)
{
	FILE *fp;
	char data;
	int row = 0;
	if ((fp = fopen(t, "r")) == NULL)
	{
		printf("Open the file failure\n");
		return -1;
	}
	for (int i = 0; (data = getc(fp)) != EOF; i++)
	{
		if (data == '\n')
			row++;			//��¼����
	}
	fclose(fp);
	return row;
}
void output(const char* t, const char* a, int num)//�����ָ���ļ���
{
	FILE *fp;
	if ((fp = fopen("result.txt", "a+")) == NULL)
	{
		printf("can't write file\n");
	}
	fprintf(fp, "%s, %s��%d ", t, a, num);
	fclose(fp);
}
void output_f(const char* t, const char* w, int count, int row, int word)
{
	FILE *fp;
	if ((fp = fopen(w, "a+")) == NULL)
	{
		printf("can't write file\n");
	}
	fprintf(fp, "%s���ַ�����%d��������%d����������%d", t, count, row, word);
	fclose(fp);
}
