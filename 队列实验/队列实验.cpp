//**********************//
//����ʵ��������		//
//**********************//

#include"queue.h"

int main(void)
{
	int order = NULL;
	int data[2][6] = {
		{4,7,8,12,20,50},
		{(int)'a',(int)'b',(int)'c',(int)'d',(int)'f',(int)'g'}
	};
	seqQueue Q;
	linkQueue LQ;

	while (1)
	{
		cout << "ʵ���ģ�����ʵ��" << endl;
		cout << "*****************************************************************" << endl;
		cout << "*\t*\t*\t*��һ�飺˳�����*\t*\t*\t*" << endl;
		cout << "*1����ʼ�����������У��ж�Ϊ�ջ�Ϊ����\t\t\t\t*" << endl;
		cout << "*2��˳�������ӡ�\t\t\t\t\t\t*" << endl;
		cout << "*3��˳����г��ӡ�\t\t\t\t\t\t*" << endl;
		cout << "*4��˳�����ȡ��ͷԪ�ء�\t\t\t\t\t*" << endl;
		cout << "*5��������г��ȡ�\t\t\t\t\t\t*" << endl;
		cout << "*6����ϳ���\t\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*\t*\t*\t*�ڶ��飺 ������*\t*\t*\t*" << endl;
		cout << "*7����ʼ�����������У��ж�Ϊ�ա�\t\t\t\t*" << endl;
		cout << "*8����������ӡ�\t\t\t\t\t\t*" << endl;
		cout << "*9�������г��ӡ�\t\t\t\t\t\t*" << endl;
		cout << "*10��������ȡ��ͷԪ�ء�\t\t\t\t\t*" << endl;
		cout << "*11��������г��ȡ�\t\t\t\t\t\t*" << endl;
		cout << "*12����ϳ���\t\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*0���˳�����\t\t\t\t\t\t\t*" << endl;
		cout << "*****************************************************************" << endl;
		cout << "������˵���ţ�\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨���n��n=50����Ԫ�أ���" << endl;
			initialQueue(&Q);
			srand((int)time(nullptr));
			for (int i = 0; i < 50; i++)
			{
				enQueue(&Q, random(100, 999));
			}
			cout << "��ǰ�������£�" << endl;
			printQueue(&Q);
			if (isQueueFull(&Q)) cout << "����������" << endl;
			else cout << "����δ����" << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨���n��n=99����Ԫ�أ���" << endl;
			initialQueue(&Q);
			for (int i = 1; i < 100; i++)
			{
				enQueue(&Q, i);
			}
			cout << "��ǰ�������£�" << endl;
			printQueue(&Q);
			if (isQueueFull(&Q)) cout << "����������" << endl;
			else cout << "����δ����" << endl;
			//********************************************************************
			break;
		case 2:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飺" << endl;
			cout << "��ǰ������������Ϊ��\t";
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				cout << data[0][i] << "\t";
				enQueue(&Q, data[0][i]);
			}
			cout << endl;
			cout << "��ӡ��Ӻ�Ķ��У�\t";
			printQueue(&Q);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飺" << endl;
			cout << "��ǰ������������Ϊ��\t";
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				cout << (char)(data[1][i]) << "\t";
				enQueue(&Q, data[1][i]);
			}
			cout << endl;
			cout << "��ӡ��Ӻ�Ķ��У�\t";
			printQueue(&Q, true);
			//********************************************************************
			break;
		case 3:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ�" << endl;
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				enQueue(&Q, data[0][i]);
			}
			cout << "��ǰ����Ϊ��\t";
			printQueue(&Q);
			cout << endl;
			outQueue(&Q);
			cout << "��ӡ���Ӻ�Ķ��У�\t";
			printQueue(&Q);
			//********************************************************************
			cout << endl;
			break;
		case 4:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ�" << endl;
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				enQueue(&Q, data[0][i]);
			}
			cout << "��ǰ����Ϊ��\t";
			printQueue(&Q);
			cout << endl;
			cout << "��ӡ��ͷԪ�أ�\t";
			cout << queueFront(&Q) << endl;
			//********************************************************************
			cout << endl;
			break;
		case 5:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ�" << endl;
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				enQueue(&Q, data[0][i]);
			}
			cout << "��ǰ����Ϊ��\t";
			printQueue(&Q);
			cout << endl;
			cout << "��ǰ����Ԫ�ظ���Ϊ��\t";
			cout << getQueueLength(&Q) << endl;
			//********************************************************************
			cout << endl;
			break;
		case 6:
			system("cls");
			//����***************************************************************
			queueIOPFun();
			//********************************************************************
			break;
		case 7:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨���n��n=50����Ԫ�أ���" << endl;
			initialQueue(LQ);
			srand((int)time(nullptr));
			for (int i = 0; i < 50; i++)
			{
				enQueue(LQ, random(100, 999));
			}
			cout << "��ǰ�������£�" << endl;
			printQueue(LQ);
			if (isQueueEmpty(LQ)) cout << "����Ϊ�գ�" << endl;
			else cout << "���в��ա�" << endl;
			//��һ����Խ��������������У������´β���****************************
			if (destroyLinkQueue(LQ)) cout << "��ջ���ٳɹ���" << endl;
			else cout << "��ջ����ʧ�ܣ�" << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨���n��n=99����Ԫ�أ���" << endl;
			initialQueue(LQ);
			for (int i = 1; i < 100; i++)
			{
				enQueue(LQ, i);
			}
			cout << "��ǰ�������£�" << endl;
			printQueue(LQ);
			if (isQueueEmpty(LQ)) cout << "����Ϊ�գ�" << endl;
			else cout << "���в��ա�" << endl;
			//�ڶ�����Խ��������������У������´β���****************************
			if (destroyLinkQueue(LQ)) cout << "��ջ���ٳɹ���" << endl;
			else cout << "��ջ����ʧ�ܣ�" << endl;
			//********************************************************************
			break;
		case 8:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飺" << endl;
			cout << "��ǰ������������Ϊ��\t";
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				cout << data[0][i] << "\t";
				enQueue(LQ, data[0][i]);
			}
			cout << endl;
			cout << "��ӡ��Ӻ�Ķ��У�\t";
			printQueue(LQ);
			//��һ����Խ��������������У������´β���****************************
			if (destroyLinkQueue(LQ)) cout << "��ջ���ٳɹ���" << endl;
			else cout << "��ջ����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飺" << endl;
			cout << "��ǰ������������Ϊ��\t";
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				cout << (char)(data[1][i]) << "\t";
				enQueue(LQ, data[1][i]);
			}
			cout << endl;
			cout << "��ӡ��Ӻ�Ķ��У�\t";
			printQueue(LQ, true);
			//�ڶ�����Խ��������������У������´β���****************************
			if (destroyLinkQueue(LQ)) cout << "��ջ���ٳɹ���" << endl;
			else cout << "��ջ����ʧ�ܣ�" << endl;
			//********************************************************************
			break;
		case 9:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ�" << endl;
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				enQueue(LQ, data[0][i]);
			}
			cout << "��ǰ����Ϊ��\t";
			printQueue(LQ);
			cout << endl;
			outQueue(LQ);
			cout << "��ӡ���Ӻ�Ķ��У�\t";
			printQueue(LQ);
			//��һ����Խ��������������У������´β���****************************
			if (destroyLinkQueue(LQ)) cout << "��ջ���ٳɹ���" << endl;
			else cout << "��ջ����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 10:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ�" << endl;
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				enQueue(LQ, data[0][i]);
			}
			cout << "��ǰ����Ϊ��\t";
			printQueue(LQ);
			cout << endl;
			cout << "��ӡ��ͷԪ�أ�\t";
			cout << queueFront(LQ) << endl;
			//��һ����Խ��������������У������´β���****************************
			if (destroyLinkQueue(LQ)) cout << "��ջ���ٳɹ���" << endl;
			else cout << "��ջ����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 11:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ�" << endl;
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				enQueue(LQ, data[0][i]);
			}
			cout << "��ǰ����Ϊ��\t";
			printQueue(LQ);
			cout << endl;
			cout << "��ǰ����Ԫ�ظ���Ϊ��\t";
			cout << getQueueLength(LQ) << endl;
			//��һ����Խ��������������У������´β���****************************
			if (destroyLinkQueue(LQ)) cout << "��ջ���ٳɹ���" << endl;
			else cout << "��ջ����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 12:
			system("cls");
			//����***************************************************************
			linkQueueIOPFun();
			//********************************************************************
			break;
		case 0:
			if (destroyLinkQueue(LQ)) cout << "��ջ���ٳɹ���" << endl;
			else cout << "��ջ����ʧ�ܣ�" << endl;
			return 0;
		default:
			system("cls");
			cout << "�������" << endl;
			break;
		}
	}

	return 0;
}