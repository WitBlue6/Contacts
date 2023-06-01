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
//��������
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
}PeoInfo;

//typedef struct Contact//��̬�汾
//{
//	PeoInfo Data[MAX_DATA];//�����ӽ������˵���Ϣ
//	int sz;//��ǰͨѶ¼����Ч��Ϣ�ĸ���
//}Contact;
typedef struct Contact//��̬�汾
{
	PeoInfo* Data;//ָ��̬����Ŀռ䣬���������ϵ����Ϣ
	int sz;//��¼��ǰ��ϵ�˸���
	int capacity;//��¼��ǰ�ռ�����
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//������ϵ��
void AddContact(Contact* pc);
//��ӡͨѶ¼
void PrintContact(Contact* pc);
//ɾ����ϵ��
void DeleteContact(Contact* pc);
//������ϵ��
void SearchContact(Contact* pc);
//�޸���ϵ��
void ModifyContact(Contact* pc);
//������ϵ��
void SortContact(Contact* pc);
//����ͨѶ¼
void DestoryContact(Contact* pc);
//����ͨѶ¼�ļ�
void SaveContact(Contact* pc);
//����ͨѶ¼�ļ�
void LoadContact(Contact* pc);