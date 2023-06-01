#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//��ʼ��ͨѶ¼
//void InitContact(Contact* pc)//��̬�汾
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
	//���ļ�
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{	//�Ƿ���Ҫ����
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
				printf("����ʧ��\n");
				return;
			}
		}
		//���ļ�
		pc->Data[pc->sz] = tmp;
		pc->sz++;	
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}
void InitContact(Contact* pc)//��̬�汾
{
	pc->Data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->Data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	//�����ļ�
	LoadContact(pc);
}
//������ϵ��
//void AddContact(Contact* pc)//��̬�汾
//{
//	if (pc->sz == MAX_DATA)
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	//����һ���˵���Ϣ
//	printf("����������:>");
//	scanf("%s", pc->Data[pc->sz].name);
//	printf("����������:>");
//	scanf("%d", &(pc->Data[pc->sz].age));
//	printf("�������Ա�:>");
//	scanf("%s", pc->Data[pc->sz].sex);
//	printf("������绰:>");
//	scanf("%s", pc->Data[pc->sz].tele);	
//
//	pc->sz++;
//	printf("��ӳɹ�\n");
//}
void AddContact(Contact* pc)//��̬�汾
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
			printf("����ʧ��\n");
			return;
		}
	}
	
	printf("����������:>");
	scanf("%s", pc->Data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &(pc->Data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->Data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->Data[pc->sz].tele);	
	pc->sz++;
	printf("��ӳɹ�\n");
}
//��ӡͨѶ¼
void PrintContact(Contact* pc)
{	
	//��ӡ����
	printf("%-20s\t%-10s\t%-12s\t%-12s\n", "����", "����", "�Ա�", "�绰");
	//��ӡ����
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-10d\t%-12s\t%-12s\n",
			pc->Data[i].name,
			pc->Data[i].age,
			pc->Data[i].sex,
			pc->Data[i].tele);
	}
}
//������ϵ��
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

//ɾ����ϵ��
void DeleteContact(Contact* pc)
{	
	char Name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", Name);
	//����
	int pos = FindByName(pc, Name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//ɾ��
	for (int i = pos; i < pc->sz - 1; i++)
	{
		pc->Data[i] = pc->Data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}
//������ϵ��
void SearchContact(Contact* pc)
{
	char Name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:>");
	scanf("%s", Name);

	int pos = FindByName(pc, Name);
	if (pos == -1)
	{
		printf("δ���ҵ�����ϵ��\n");
	}
	else
	{
		printf("���ҵ�����ϵ�����Ϊ%d\n", pos);
	}
}
//�޸���ϵ��
void ModifyContact(Contact* pc)
{
	char Name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", Name);

	int pos = FindByName(pc, Name);
	if (pos == -1)
	{
		printf("δ���ҵ�����ϵ��\n");
	}
	else
	{
		printf("��������¼����Ϣ\n");
		printf("����������:>");
		scanf("%s", pc->Data[pos].name);
		printf("����������:>");
		scanf("%d", &(pc->Data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", pc->Data[pos].sex);
		printf("������绰:>");
		scanf("%s", pc->Data[pos].tele);

		printf("�޸ĳɹ�\n");
	}
}

//������ϵ��
void SortContact(Contact* pc)
{
	printf("���й�����δʵ��\n");
	printf("��ϵQQ��2281509968����Դ������Լ���һ������\n");
}
//����ͨѶ¼
void DestoryContact(Contact* pc)
{
	free(pc->Data);
	pc->Data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}
//����ͨѶ¼
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//д�ļ�
	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->Data + i, sizeof(PeoInfo), 1, pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}



