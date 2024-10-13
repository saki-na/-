#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void unite(char string[], int lenght);
void Num(char string[], int lenght);

int main()
{
	//定义一个字符串数组
	char string[1000] = {0};
	printf("请输入一串字符：\n");
	gets(string);
	printf("----------------------------------\n");
	//计算字符串长度
	int len = strlen(string);
	//将字符串中的字母统一为小写形式
	unite(string, len);


	//统计字符串中每个字符的出现次数
	//定义一个数组用以函数调用，防止原数组发生改变
	char tstring[1000] = { 0 };
	//复制原数组的元素，并将其传给新数组
	for (int i = 0; i <= (len - 1); i++)
	{
		tstring[i] = string[i];
	}
	printf("统计结果\n");
	Num(tstring, len);
	printf("----------------------------------\n");
	

	//字符串反转并判断是否回文
	//定义一个数组用以记录反转后的字符串
	char ustring[1000] = {0};
	//复制原数组的元素，并将其传给新数组
	for (int i = 0; i <= (len - 1); i++)
	{
		ustring[i] = string[i];
	}
	//定义字符串左右侧的索引
	int left = 0, right = (len - 1);
	//反转字符
	while (left < right)
	{
		char temp = ustring[left];
		ustring[left] = ustring[right];
		ustring[right] = temp;
		left++;
		right--;
	}
	//定义一个变量记录位置相同时字母也相同的情况的数量
	int num = 0;
	//遍历两个数组，判断相同位置的字母是否相同，以判断是否回文
	for (int i = 0; i <= (len - 1); i++)
	{
		//相同位置的字母相同时，num加1
		if (string[i] == ustring[i])
		{
			num++;
		}
	}
	//若该变量的大小与数组长度相同,则该字符串回文
	if (num == len)
	{
		printf("该字符串回文\n");
	}
	else
	{
		printf("该字符串不回文\n");
	}
	printf("----------------------------------\n");
	

	//最长单词提取
	// 定义一个数组用以记录所有string中出现过的非字母与与非数字字符
	char word[1000] = { 0 }; 
	//遍历string,将其中出现过的非字母与与非数字字符赋值给word
	int j = 0;
	int i = 0;
	while (i <= (len - 1))
	{
		//若检索到的字符为非字母与与非数字字符，则将该字符赋值给word
		if (!isalnum(string[i]))
		{
			word[j] = string[i];printf("%s", word);
			j++;
		}
		i++;
	}
	//定义一个变量提取单词
	char* sub;
	// 定义一个数组保存提取的单词
	char* arr[1000] = { 0 };
	//保存分割状态信息
	char* context;
	//提取第一个子字符串
	sub = strtok_s(string, word, &context);
	//并将该字符串赋值给arr数组
	arr[0] = sub;
	int k = 1;
	while (sub != NULL)
	{
		//提取下一个子字符串
		sub = strtok_s(NULL, word, &context);
		//将该字符串赋值给arr数组
		arr[k] = sub;
		k++;
	}
	//定义一个变量记录检索到最长单词时的索引
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
	printf("最长单词为：%s\n", arr[pos]);
	printf("长度为：%zu\n", longest);
	return 0;
}

//定义一个函数来把字符串中的字母统一为小写形式
void unite(char string[], int lenght)
{
	//将字符串中的字母统一为小写
	for (int i = 0; i <= (lenght - 1); i++)
	{
		//若字母的ASCII值在65~90中间，则意味着该字母为大写形式，需改为小写形式
		if (string[i] >= 65 && string[i] <= 90)
		{
			//小写字母的ASCII值比其对应大写字母的多32，故需加上32以将其转为对于小写形式
			string[i] = string[i] + 32;
		}
	}
}
//定义一个函数来统计字符串中每个字符的出现次数
void Num(char string[], int lenght)
{
	//遍历数组
	for (int i = 0; i <= (lenght - 1); i++)
	{
		//定义一个变量记录符合条件的字符数量
		int count = 0;
		//若检索到的字符为字母或数字，则进行统计
		if (string[i] >= 97 && string[i] <= 122 || string[i] >= 48 && string[i] <= 57)
		{
			//从当前检索位置向后查找相同字符
			for (int j = i; j <= (lenght - 1); j++)
			{
				//若查找到相同的字符，则count加1,并将查找处的字符改为空格
				if (string[i] == string[j])
				{
					count++;
					//将除当前检索字符外的所有与当前检索字符相同的字符改为空格
					if (j != i)
					{
						string[j] = ' ';
					}
				}
			}
			//若count不为0，即表明该字符数量存在，可以打印
			if (count != 0)
			{
				printf("%c 出现 %d 次\n", string[i], count);
			}
		}	
	}
}