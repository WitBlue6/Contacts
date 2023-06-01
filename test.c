#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//通讯录
//1.能够存放1000个人的信息
//每个人的信息：名字+年龄+性别+电话
//2.增加/删除人的信息
//3.修改指定人的信息
//4.查找指定人的信息
//5.排序通讯录信息

//版本2
//初始存放3人信息，满了后每次开辟2个新空间

//版本3
//通讯录退出时把信息写入文件
//通讯录初始化时加载文件信息


void menu()
{
	puts("*******      通讯录     *******");
	puts("******  1.add    2.delete  ****");
	puts("******  3.search 4.modify  ****");
	puts("******  5.sort   6.print  *****");
	puts("******      0.exit       ******");
	puts("*******************************");
}
enum Option
{
	EXIT,ADD,DELETE,SEARCH,MODIFY,SORT,PRINT
};
int main()
{	
	int input = 0;
	//创建通讯录
	Contact con;
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DELETE:
			DeleteContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			puts("输入错误");
			break;
		}
	} while (input);
	return 0;
}