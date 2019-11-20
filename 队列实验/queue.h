//**********************//
//����ʵ��ͷ�ļ�		//
//������1������ͷ�ļ�	//
//		2���ṹ����		//
//		3����������		//
//		4����������		//
//**********************//

#ifndef QUEUE_H

#define QUEUE_H

#include<iostream>
#include <cstdlib>
#include <ctime>
#include<stdlib.h>

#define random(x,y) rand()%(y-x+1)+x

using namespace std;

#define MAXLEN 100

typedef int elementType;

//***********************˳����нṹ****************************//
typedef struct sQueue											//
{																//
	elementType data[MAXLEN];		//��Ŷ���Ԫ��				//
	int front;						//��ͷָ��					//
	int rear;						//��βָ��					//
}seqQueue;														//
//**************************************************************//

//************************�����нṹ****************************//
//�����н��ṹ												//
typedef struct LNode											//
{																//
	elementType data;											//
	struct LNode* next;											//
}node;															//
																//
//�����нṹ													//
typedef struct LNodes											//
{																//
	node* front;					//��ͷָ��					//
	node* rear;						//��βָ��					//
}linkQueue;														//
//**************************************************************//


//**********************��������************************************************************************//
//˳����к�������																						//
void initialQueue(seqQueue* Q);									//��ʼ��˳�����						//
void printQueue(seqQueue* Q);									//��ӡ˳�����							//
void printQueue(seqQueue* Q, bool flag);						//��ӡ˳����У�Ϊʵ��2��ӡ�ַ�����	//
bool isQueueEmpty(seqQueue* Q);									//�ж�˳������Ƿ�Ϊ��					//
bool isQueueFull(seqQueue* Q);									//�ж�˳������Ƿ�Ϊ��					//
bool enQueue(seqQueue* Q, elementType data);					//˳��������							//
bool outQueue(seqQueue* Q, elementType& data);					//˳����г��ӣ���������Ԫ�أ�			//
bool outQueue(seqQueue* Q);										//˳����г���							//
elementType queueFront(seqQueue* Q);							//˳�����ȡ��ͷԪ��					//
int getQueueLength(seqQueue* Q);								//��ǰ˳�������Ԫ�ظ���				//
void queueIOPFun();												//������ż��ָ���㷨					//
//�����к�������																						//
void initialQueue(linkQueue& Q);								//��ʼ��������							//
void printQueue(linkQueue& Q);									//��ӡ������							//
void printQueue(linkQueue& Q, bool flag);						//��ӡ�����У�Ϊʵ��2��ӡ�ַ�����		//
bool isQueueEmpty(linkQueue& Q);								//�ж�˳������Ƿ�Ϊ��					//
void enQueue(linkQueue& Q, elementType data);					//���������							//
bool outQueue(linkQueue& Q, elementType& data);					//�����г��ӣ���������Ԫ�أ�			//
bool outQueue(linkQueue& Q);									//�����г���							//
elementType queueFront(linkQueue& Q);							//������ȡ��ͷԪ��						//
int getQueueLength(linkQueue& Q);								//��ǰ��������Ԫ�ظ���				//
void linkQueueIOPFun();											//������ż��ָ���㷨					//
bool destroyLinkQueue(linkQueue& Q);							//������ż��ָ���㷨					//
//******************************************************************************************************//

#endif // !QUEUE_H


//******************************��������********************************


//***************************˳����к�������*****************************
//****************��ʼ��һ��˳�����****************
//ʵ����.˳�����.1����ʼ��һ��˳�����
//���룺��Ҫ��ʼ���Ķ���ָ�� 
//�������ʼ����Ŀն���
void initialQueue(seqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}


//****************������������ӡ˳�����****************
//������������ӡ˳�����
//���룺��Ҫ��ӡ��˳�����ָ��
void printQueue(seqQueue* Q)
{
	int i = Q->front;
	while (i != Q->rear)
	{
		i = (i + 1) % MAXLEN;
		cout << Q->data[i] << "\t";
	}
	cout << endl;
}


//****************������������ӡ˳����У�Ϊʵ��2��ӡ�ַ�����****************
//������������ӡ˳����У�Ϊʵ��2��ӡ�ַ�����
//���룺��Ҫ��ӡ��˳�����ָ��
void printQueue(seqQueue* Q, bool flag)
{
	if (flag)
	{
		int i = Q->front;
		while (i != Q->rear)
		{
			i = (i + 1) % MAXLEN;
			cout << (char)(Q->data[i]) << "\t";
		}
		cout << endl;
	}
	else
	{
		printQueue(Q);
	}
}


//****************�ж�˳������Ƿ�ӿ�****************
//ʵ����.˳�����.2���ж�˳������Ƿ�ӿ�
//���룺��Ҫ�����жϵĶ���ָ�� 
//���أ�������Ϊ���򷵻�true���������򷵻�false
bool isQueueEmpty(seqQueue* Q)
{
	if (Q->front == Q->rear) return true;
	else return false;
}


//****************�ж�˳������Ƿ����****************
//ʵ����.˳�����.3���ж�˳������Ƿ����
//���룺��Ҫ�����жϵĶ���ָ�� 
//���أ����������򷵻�true���������򷵻�false
bool isQueueFull(seqQueue* Q)
{
	if ((((Q->rear) + 1) % MAXLEN) == Q->front) return true;
	else return false;
}


//****************˳��������****************
//ʵ����.˳�����.4��˳��������
//���룺��Ҫ������ӵĶ���ָ�� 
//���أ������гɹ��򷵻�true��������ʧ���򷵻�false
bool enQueue(seqQueue* Q, elementType data)
{
	if (!isQueueFull(Q))
	{
		Q->rear = ((Q->rear) + 1) % MAXLEN;
		Q->data[Q->rear] = data;

		return true;
	}
	else return false;
}


//****************˳����г��ӣ���������Ԫ�أ�****************
//ʵ����.˳�����.5��˳����г��ӣ���������Ԫ�أ�
//���룺��Ҫ���г��ӵĶ���ָ�� 
//���أ������гɹ��򷵻�true��������ʧ���򷵻�false
bool outQueue(seqQueue* Q, elementType& data)
{
	if (!isQueueEmpty(Q))
	{
		Q->front = ((Q->front) + 1) % MAXLEN;
		data = Q->data[Q->front];

		return true;
	}
	else return false;
}


//****************˳����г���****************
//ʵ����.˳�����.5��˳����г��ӣ�����������Ԫ�أ�
//���룺��Ҫ���г��ӵĶ���ָ�� 
//���أ������гɹ��򷵻�true��������ʧ���򷵻�false
bool outQueue(seqQueue* Q)
{
	if (!isQueueEmpty(Q))
	{
		Q->front = ((Q->front) + 1) % MAXLEN;

		return true;
	}
	else return false;
}


//****************ȡ˳���ͷԪ��****************
//ʵ����.˳�����.6��ȡ˳���ͷԪ��
//���룺��ҪȡԪ�صĶ���ָ�� 
//���أ����ɹ�ȡ���򷵻ظ�Ԫ�أ���ʧ���򷵻�NULL
elementType queueFront(seqQueue* Q)
{
	if (!isQueueEmpty(Q))
		return Q->data[((Q->front) + 1) % MAXLEN];
	else return NULL;
}


//****************��ǰ˳�������Ԫ�ظ���****************
//ʵ����.˳�����.7����ǰ˳�������Ԫ�ظ���
//���룺��Ҫ������Ķ���ָ�� 
//���أ�����Ԫ�ظ���
int getQueueLength(seqQueue* Q)
{
	return (Q->rear - Q->front + MAXLEN) % MAXLEN;
}


//****************������ż��ָ���㷨****************
//ʵ����.˳�����.8��������ż��ָ���㷨
//�����ڴ�ӡ����ǰ�����е�����Ԫ��
void queueIOPFun()
{
	seqQueue Q;
	elementType num = 1;

	initialQueue(&Q);

	while (1)
	{
		cout << "������һ�����֣�\t";
		cin >> num;

		if (num == 0)
		{
			cout << "��ϳ��򼴽��˳�" << endl;
			return;
		}
		else if (num % 2)
		{
			enQueue(&Q, num);
		}
		else
		{
			outQueue(&Q);
		}
		cout << "��ǰ����δ��" << endl;
		printQueue(&Q);
	}
}


//***************************�����к�������*****************************
//ʵ����.������.1����ʼ��һ��������
//���룺��Ҫ��ʼ���Ķ��нṹ 
//�������ʼ����Ŀն���
//���أ���ʼ���ɹ�����true��ʧ�ܷ���false
void initialQueue(linkQueue& Q)
{
	Q.front = nullptr;
	Q.rear = nullptr;
}


//****************������������ӡ������****************
//������������ӡ������
//���룺��Ҫ��ӡ��������ָ��
void printQueue(linkQueue& Q)
{
	node* p = Q.front;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}


//****************������������ӡ˳����У�Ϊʵ��2��ӡ�ַ�����****************
//������������ӡ˳����У�Ϊʵ��2��ӡ�ַ�����
//���룺��Ҫ��ӡ��˳�����ָ��
void printQueue(linkQueue& Q, bool flag)
{
	if (flag)
	{
		node* p = Q.front;
		while (p)
		{
			cout << (char)(p->data) << "\t";
			p = p->next;
		}
		cout << endl;
	}
	else
	{
		printQueue(Q);
	}
}


//****************�ж��������Ƿ�ӿ�****************
//ʵ����.������.2���ж��������Ƿ�ӿ�
//���룺��Ҫ�����жϵĶ���ָ�� 
//���أ�������Ϊ���򷵻�true���������򷵻�false
bool isQueueEmpty(linkQueue& Q)
{
	if (Q.rear == nullptr) return true;
	else return false;
}


//****************���������****************
//ʵ����.������.4�����������
//���룺��Ҫ������ӵĶ���ָ�� 
//���أ������гɹ��򷵻�true��������ʧ���򷵻�false
void enQueue(linkQueue& Q, elementType data)
{
	if (Q.rear == nullptr)
	{
		Q.rear = new node;
		Q.rear->data = data;
		Q.rear->next = nullptr;
		Q.front = Q.rear;
	}
	else
	{
		Q.rear->next = new node;
		Q.rear = Q.rear->next;
		Q.rear->data = data;
		Q.rear->next = nullptr;
	}
}


//****************�����г��ӣ���������Ԫ�أ�****************
//ʵ����.������.5�������г��ӣ���������Ԫ�أ�
//���룺��Ҫ���г��ӵĶ���ָ�� 
//���أ������гɹ��򷵻�true��������ʧ���򷵻�false
bool outQueue(linkQueue& Q, elementType& data)
{
	node* dp = nullptr;

	if (!isQueueEmpty(Q))
	{
		data = Q.front->data;
		dp = Q.front;
		Q.front = Q.front->next;
		delete(dp);
		if (Q.front == nullptr)
		{
			Q.rear = nullptr;
		}

		return true;
	}
	else return false;
}


//****************�����г���****************
//ʵ����.������.5�������г��ӣ�����������Ԫ�أ�
//���룺��Ҫ���г��ӵĶ���ָ�� 
//���أ������гɹ��򷵻�true��������ʧ���򷵻�false
bool outQueue(linkQueue& Q)
{
	node* dp;

	if (!isQueueEmpty(Q))
	{
		dp = Q.front;
		Q.front = Q.front->next;
		delete(dp);
		if (Q.front == nullptr)
		{
			Q.rear = nullptr;
		}

		return true;
	}
	else return false;
}


//****************ȡ����ͷԪ��****************
//ʵ����.������.6��ȡ����ͷԪ��
//���룺��ҪȡԪ�صĶ���ָ�� 
//���أ����ɹ�ȡ���򷵻ظ�Ԫ�أ���ʧ���򷵻�NULL
elementType queueFront(linkQueue& Q)
{
	if (!isQueueEmpty(Q))
		return Q.front->data;
	else return NULL;
}


//****************��ǰ��������Ԫ�ظ���****************
//ʵ����.������.7����ǰ��������Ԫ�ظ���
//���룺��Ҫ������Ķ���ָ�� 
//���أ�����Ԫ�ظ���
int getQueueLength(linkQueue& Q)
{
	node* nowP = Q.front;
	int i = 0;

	while (nowP)
	{
		i++;
		nowP = nowP->next;
	}
	return i;
}


//****************������ż��ָ���㷨****************
//ʵ����.������.8��������ż��ָ���㷨
//�����ڴ�ӡ����ǰ�����е�����Ԫ��
void linkQueueIOPFun()
{
	linkQueue Q;
	elementType num = 0;

	initialQueue(Q);

	while (1)
	{
		cout << "������һ�����֣�\t";
		cin >> num;

		if (num == 0)
		{
			cout << "��ϳ��򼴽��˳�" << endl;
			if (destroyLinkQueue(Q)) cout << "��ջ���ٳɹ���" << endl;
			else cout << "��ջ����ʧ�ܣ�" << endl;
			return;
		}
		else if (num % 2)
		{
			enQueue(Q, num);
		}
		else
		{
			outQueue(Q);
		}
		cout << "��ǰ����δ��" << endl;
		printQueue(Q);
	}

}


//****************��������������������****************
//��������������������
//���룺��Ҫ���ٵ�������ָ��
//���أ����ٳɹ�����true�����򷵻�false
bool destroyLinkQueue(linkQueue& Q)
{
	while (Q.front)
	{
		outQueue(Q);
	}

	if (Q.front == nullptr && Q.rear == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}