#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//ͨѶ¼
//1.�ܹ����1000���˵���Ϣ
//ÿ���˵���Ϣ������+����+�Ա�+�绰
//2.����/ɾ���˵���Ϣ
//3.�޸�ָ���˵���Ϣ
//4.����ָ���˵���Ϣ
//5.����ͨѶ¼��Ϣ

//�汾2
//��ʼ���3����Ϣ�����˺�ÿ�ο���2���¿ռ�

//�汾3
//ͨѶ¼�˳�ʱ����Ϣд���ļ�
//ͨѶ¼��ʼ��ʱ�����ļ���Ϣ


void menu()
{
	puts("*******      ͨѶ¼     *******");
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
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			puts("�������");
			break;
		}
	} while (input);
	return 0;
}