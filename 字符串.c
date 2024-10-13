#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void unite(char string[], int lenght);
void Num(char string[], int lenght);

int main()
{
	//����һ���ַ�������
	char string[1000] = {0};
	printf("������һ���ַ���\n");
	gets(string);
	printf("----------------------------------\n");
	//�����ַ�������
	int len = strlen(string);
	//���ַ����е���ĸͳһΪСд��ʽ
	unite(string, len);


	//ͳ���ַ�����ÿ���ַ��ĳ��ִ���
	//����һ���������Ժ������ã���ֹԭ���鷢���ı�
	char tstring[1000] = { 0 };
	//����ԭ�����Ԫ�أ������䴫��������
	for (int i = 0; i <= (len - 1); i++)
	{
		tstring[i] = string[i];
	}
	printf("ͳ�ƽ��\n");
	Num(tstring, len);
	printf("----------------------------------\n");
	

	//�ַ�����ת���ж��Ƿ����
	//����һ���������Լ�¼��ת����ַ���
	char ustring[1000] = {0};
	//����ԭ�����Ԫ�أ������䴫��������
	for (int i = 0; i <= (len - 1); i++)
	{
		ustring[i] = string[i];
	}
	//�����ַ������Ҳ������
	int left = 0, right = (len - 1);
	//��ת�ַ�
	while (left < right)
	{
		char temp = ustring[left];
		ustring[left] = ustring[right];
		ustring[right] = temp;
		left++;
		right--;
	}
	//����һ��������¼λ����ͬʱ��ĸҲ��ͬ�����������
	int num = 0;
	//�����������飬�ж���ͬλ�õ���ĸ�Ƿ���ͬ�����ж��Ƿ����
	for (int i = 0; i <= (len - 1); i++)
	{
		//��ͬλ�õ���ĸ��ͬʱ��num��1
		if (string[i] == ustring[i])
		{
			num++;
		}
	}
	//���ñ����Ĵ�С�����鳤����ͬ,����ַ�������
	if (num == len)
	{
		printf("���ַ�������\n");
	}
	else
	{
		printf("���ַ���������\n");
	}
	printf("----------------------------------\n");
	

	//�������ȡ
	// ����һ���������Լ�¼����string�г��ֹ��ķ���ĸ����������ַ�
	char word[1000] = { 0 }; 
	//����string,�����г��ֹ��ķ���ĸ����������ַ���ֵ��word
	int j = 0;
	int i = 0;
	while (i <= (len - 1))
	{
		//�����������ַ�Ϊ����ĸ����������ַ����򽫸��ַ���ֵ��word
		if (!isalnum(string[i]))
		{
			word[j] = string[i];printf("%s", word);
			j++;
		}
		i++;
	}
	//����һ��������ȡ����
	char* sub;
	// ����һ�����鱣����ȡ�ĵ���
	char* arr[1000] = { 0 };
	//����ָ�״̬��Ϣ
	char* context;
	//��ȡ��һ�����ַ���
	sub = strtok_s(string, word, &context);
	//�������ַ�����ֵ��arr����
	arr[0] = sub;
	int k = 1;
	while (sub != NULL)
	{
		//��ȡ��һ�����ַ���
		sub = strtok_s(NULL, word, &context);
		//�����ַ�����ֵ��arr����
		arr[k] = sub;
		k++;
	}
	//����һ��������¼�����������ʱ������
	int pos = 0;
	size_t longest = strlen(arr[0]);
	for (int l = 1; l < k; l++)
	{
		if (strlen(arr[l]) > longest)
		{
			longest = strlen(arr[l]);
			pos = l;
		}
	}
	printf("�����Ϊ��%s\n", arr[pos]);
	printf("����Ϊ��%zu\n", longest);
	return 0;
}

//����һ�����������ַ����е���ĸͳһΪСд��ʽ
void unite(char string[], int lenght)
{
	//���ַ����е���ĸͳһΪСд
	for (int i = 0; i <= (lenght - 1); i++)
	{
		//����ĸ��ASCIIֵ��65~90�м䣬����ζ�Ÿ���ĸΪ��д��ʽ�����ΪСд��ʽ
		if (string[i] >= 65 && string[i] <= 90)
		{
			//Сд��ĸ��ASCIIֵ�����Ӧ��д��ĸ�Ķ�32���������32�Խ���תΪ����Сд��ʽ
			string[i] = string[i] + 32;
		}
	}
}
//����һ��������ͳ���ַ�����ÿ���ַ��ĳ��ִ���
void Num(char string[], int lenght)
{
	//��������
	for (int i = 0; i <= (lenght - 1); i++)
	{
		//����һ��������¼�����������ַ�����
		int count = 0;
		//�����������ַ�Ϊ��ĸ�����֣������ͳ��
		if (string[i] >= 97 && string[i] <= 122 || string[i] >= 48 && string[i] <= 57)
		{
			//�ӵ�ǰ����λ����������ͬ�ַ�
			for (int j = i; j <= (lenght - 1); j++)
			{
				//�����ҵ���ͬ���ַ�����count��1,�������Ҵ����ַ���Ϊ�ո�
				if (string[i] == string[j])
				{
					count++;
					//������ǰ�����ַ���������뵱ǰ�����ַ���ͬ���ַ���Ϊ�ո�
					if (j != i)
					{
						string[j] = ' ';
					}
				}
			}
			//��count��Ϊ0�����������ַ��������ڣ����Դ�ӡ
			if (count != 0)
			{
				printf("%c ���� %d ��\n", string[i], count);
			}
		}	
	}
}