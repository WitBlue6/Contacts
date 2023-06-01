#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//初始化通讯录
//void InitContact(Contact* pc)//静态版本
//{
//	pc->sz = 0;
//	memset(pc->Data, 0, sizeof(pc->Data));
//}
void LoadContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//读文件
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{	//是否需要增容
		if (pc->sz == pc->capacity)
		{
			PeoInfo* ptr = (PeoInfo*)realloc(pc->Data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
			if (ptr != NULL)
			{
				pc->Data = ptr;
				pc->capacity += INC_SZ;
			}
			else
			{
				perror("AddContact");
				printf("增加失败\n");
				return;
			}
		}
		//读文件
		pc->Data[pc->sz] = tmp;
		pc->sz++;	
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}
void InitContact(Contact* pc)//动态版本
{
	pc->Data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->Data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	//加载文件
	LoadContact(pc);
}
//增加联系人
//void AddContact(Contact* pc)//静态版本
//{
//	if (pc->sz == MAX_DATA)
//	{
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	//增加一个人的信息
//	printf("请输入名字:>");
//	scanf("%s", pc->Data[pc->sz].name);
//	printf("请输入年龄:>");
//	scanf("%d", &(pc->Data[pc->sz].age));
//	printf("请输入性别:>");
//	scanf("%s", pc->Data[pc->sz].sex);
//	printf("请输入电话:>");
//	scanf("%s", pc->Data[pc->sz].tele);	
//
//	pc->sz++;
//	printf("添加成功\n");
//}
void AddContact(Contact* pc)//动态版本
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->Data, (pc->capacity+INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->Data = ptr;
			pc->capacity += INC_SZ;
		}
		else
		{
			perror("AddContact");
			printf("增加失败\n");
			return;
		}
	}
	
	printf("请输入名字:>");
	scanf("%s", pc->Data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->Data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->Data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->Data[pc->sz].tele);	
	pc->sz++;
	printf("添加成功\n");
}
//打印通讯录
void PrintContact(Contact* pc)
{	
	//打印标题
	printf("%-20s\t%-10s\t%-12s\t%-12s\n", "名字", "年龄", "性别", "电话");
	//打印数据
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-10d\t%-12s\t%-12s\n",
			pc->Data[i].name,
			pc->Data[i].age,
			pc->Data[i].sex,
			pc->Data[i].tele);
	}
}
//查找联系人
static int FindByName(Contact* pc,char name[])
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->Data[i].name, name) == 0)
		{
			return i;
		}
	}
	
	return -1;
}

//删除联系人
void DeleteContact(Contact* pc)
{	
	char Name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入要删除人的名字:>");
	scanf("%s", Name);
	//查找
	int pos = FindByName(pc, Name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//删除
	for (int i = pos; i < pc->sz - 1; i++)
	{
		pc->Data[i] = pc->Data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}
//查找联系人
void SearchContact(Contact* pc)
{
	char Name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", Name);

	int pos = FindByName(pc, Name);
	if (pos == -1)
	{
		printf("未查找到该联系人\n");
	}
	else
	{
		printf("查找到该联系人序号为%d\n", pos);
	}
}
//修改联系人
void ModifyContact(Contact* pc)
{
	char Name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", Name);

	int pos = FindByName(pc, Name);
	if (pos == -1)
	{
		printf("未查找到该联系人\n");
	}
	else
	{
		printf("正在重新录入信息\n");
		printf("请输入名字:>");
		scanf("%s", pc->Data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->Data[pos].age));
		printf("请输入性别:>");
		scanf("%s", pc->Data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", pc->Data[pos].tele);

		printf("修改成功\n");
	}
}

//排列联系人
void SortContact(Contact* pc)
{
	printf("排列功能暂未实现\n");
	printf("联系QQ：2281509968，发源码给你自己做一个排列\n");
}
//销毁通讯录
void DestoryContact(Contact* pc)
{
	free(pc->Data);
	pc->Data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}
//保存通讯录
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//写文件
	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->Data + i, sizeof(PeoInfo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}



