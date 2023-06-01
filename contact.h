#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_DATA 50
#define DEFAULT_SZ 3
#define INC_SZ 2
//定义类型
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
}PeoInfo;

//typedef struct Contact//静态版本
//{
//	PeoInfo Data[MAX_DATA];//存放添加进来的人的信息
//	int sz;//当前通讯录中有效信息的个数
//}Contact;
typedef struct Contact//动态版本
{
	PeoInfo* Data;//指向动态申请的空间，用来存放联系人信息
	int sz;//记录当前联系人个数
	int capacity;//记录当前空间容量
}Contact;

//初始化通讯录
void InitContact(Contact* pc);
//增加联系人
void AddContact(Contact* pc);
//打印通讯录
void PrintContact(Contact* pc);
//删除联系人
void DeleteContact(Contact* pc);
//查找联系人
void SearchContact(Contact* pc);
//修改联系人
void ModifyContact(Contact* pc);
//排列联系人
void SortContact(Contact* pc);
//销毁通讯录
void DestoryContact(Contact* pc);
//保存通讯录文件
void SaveContact(Contact* pc);
//加载通讯录文件
void LoadContact(Contact* pc);