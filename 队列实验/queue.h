//**********************//
//队列实验头文件		//
//包含：1，依赖头文件	//
//		2，结构定义		//
//		3，函数声明		//
//		4，函数定义		//
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

//***********************顺序队列结构****************************//
typedef struct sQueue											//
{																//
	elementType data[MAXLEN];		//存放队列元素				//
	int front;						//队头指针					//
	int rear;						//队尾指针					//
}seqQueue;														//
//**************************************************************//

//************************链队列结构****************************//
//链队列结点结构												//
typedef struct LNode											//
{																//
	elementType data;											//
	struct LNode* next;											//
}node;															//
																//
//链队列结构													//
typedef struct LNodes											//
{																//
	node* front;					//队头指针					//
	node* rear;						//队尾指针					//
}linkQueue;														//
//**************************************************************//


//**********************函数声明************************************************************************//
//顺序队列函数声明																						//
void initialQueue(seqQueue* Q);									//初始化顺序队列						//
void printQueue(seqQueue* Q);									//打印顺序队列							//
void printQueue(seqQueue* Q, bool flag);						//打印顺序队列（为实验2打印字符服务）	//
bool isQueueEmpty(seqQueue* Q);									//判断顺序队列是否为空					//
bool isQueueFull(seqQueue* Q);									//判断顺序队列是否为满					//
bool enQueue(seqQueue* Q, elementType data);					//顺序队列入队							//
bool outQueue(seqQueue* Q, elementType& data);					//顺序队列出队（传出队首元素）			//
bool outQueue(seqQueue* Q);										//顺序队列出队							//
elementType queueFront(seqQueue* Q);							//顺序队列取队头元素					//
int getQueueLength(seqQueue* Q);								//求当前顺序队列中元素个数				//
void queueIOPFun();												//输入奇偶数指定算法					//
//链队列函数声明																						//
void initialQueue(linkQueue& Q);								//初始化链队列							//
void printQueue(linkQueue& Q);									//打印链队列							//
void printQueue(linkQueue& Q, bool flag);						//打印链队列（为实验2打印字符服务）		//
bool isQueueEmpty(linkQueue& Q);								//判断顺序队列是否为空					//
void enQueue(linkQueue& Q, elementType data);					//链队列入队							//
bool outQueue(linkQueue& Q, elementType& data);					//链队列出队（传出队首元素）			//
bool outQueue(linkQueue& Q);									//链队列出队							//
elementType queueFront(linkQueue& Q);							//链队列取队头元素						//
int getQueueLength(linkQueue& Q);								//求当前链队列中元素个数				//
void linkQueueIOPFun();											//输入奇偶数指定算法					//
bool destroyLinkQueue(linkQueue& Q);							//输入奇偶数指定算法					//
//******************************************************************************************************//

#endif // !QUEUE_H


//******************************函数定义********************************


//***************************顺序队列函数定义*****************************
//****************初始化一个顺序队列****************
//实验四.顺序队列.1，初始化一个顺序队列
//输入：需要初始化的队列指针 
//输出：初始化后的空队列
void initialQueue(seqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}


//****************辅助函数：打印顺序队列****************
//辅助函数：打印顺序队列
//输入：需要打印的顺序队列指针
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


//****************辅助函数：打印顺序队列（为实验2打印字符服务）****************
//辅助函数：打印顺序队列（为实验2打印字符服务）
//输入：需要打印的顺序队列指针
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


//****************判断顺序队列是否队空****************
//实验四.顺序队列.2，判断顺序队列是否队空
//输入：需要进行判断的队列指针 
//返回：若队列为空则返回true，若不空则返回false
bool isQueueEmpty(seqQueue* Q)
{
	if (Q->front == Q->rear) return true;
	else return false;
}


//****************判断顺序队列是否队满****************
//实验四.顺序队列.3，判断顺序队列是否队满
//输入：需要进行判断的队列指针 
//返回：若队列满则返回true，若不满则返回false
bool isQueueFull(seqQueue* Q)
{
	if ((((Q->rear) + 1) % MAXLEN) == Q->front) return true;
	else return false;
}


//****************顺序队列入队****************
//实验四.顺序队列.4，顺序队列入队
//输入：需要进行入队的队列指针 
//返回：若运行成功则返回true，若运行失败则返回false
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


//****************顺序队列出队（传出队首元素）****************
//实验四.顺序队列.5，顺序队列出队（传出队首元素）
//输入：需要进行出队的队列指针 
//返回：若运行成功则返回true，若运行失败则返回false
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


//****************顺序队列出队****************
//实验四.顺序队列.5，顺序队列出队（不传出队首元素）
//输入：需要进行出队的队列指针 
//返回：若运行成功则返回true，若运行失败则返回false
bool outQueue(seqQueue* Q)
{
	if (!isQueueEmpty(Q))
	{
		Q->front = ((Q->front) + 1) % MAXLEN;

		return true;
	}
	else return false;
}


//****************取顺序队头元素****************
//实验四.顺序队列.6，取顺序队头元素
//输入：需要取元素的队列指针 
//返回：若成功取出则返回该元素，若失败则返回NULL
elementType queueFront(seqQueue* Q)
{
	if (!isQueueEmpty(Q))
		return Q->data[((Q->front) + 1) % MAXLEN];
	else return NULL;
}


//****************求当前顺序队列中元素个数****************
//实验四.顺序队列.7，求当前顺序队列中元素个数
//输入：需要求个数的队列指针 
//返回：返回元素个数
int getQueueLength(seqQueue* Q)
{
	return (Q->rear - Q->front + MAXLEN) % MAXLEN;
}


//****************输入奇偶数指定算法****************
//实验四.顺序队列.8，输入奇偶数指定算法
//函数内打印：当前队列中的所有元素
void queueIOPFun()
{
	seqQueue Q;
	elementType num = 1;

	initialQueue(&Q);

	while (1)
	{
		cout << "请输入一个数字：\t";
		cin >> num;

		if (num == 0)
		{
			cout << "组合程序即将退出" << endl;
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
		cout << "当前队列未：" << endl;
		printQueue(&Q);
	}
}


//***************************链队列函数定义*****************************
//实验四.链队列.1，初始化一个链队列
//输入：需要初始化的队列结构 
//输出：初始化后的空队列
//返回：初始化成功返回true，失败返回false
void initialQueue(linkQueue& Q)
{
	Q.front = nullptr;
	Q.rear = nullptr;
}


//****************辅助函数：打印链队列****************
//辅助函数：打印链队列
//输入：需要打印的链队列指针
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


//****************辅助函数：打印顺序队列（为实验2打印字符服务）****************
//辅助函数：打印顺序队列（为实验2打印字符服务）
//输入：需要打印的顺序队列指针
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


//****************判断链队列是否队空****************
//实验四.链队列.2，判断链队列是否队空
//输入：需要进行判断的队列指针 
//返回：若队列为空则返回true，若不空则返回false
bool isQueueEmpty(linkQueue& Q)
{
	if (Q.rear == nullptr) return true;
	else return false;
}


//****************链队列入队****************
//实验四.链队列.4，链队列入队
//输入：需要进行入队的队列指针 
//返回：若运行成功则返回true，若运行失败则返回false
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


//****************链队列出队（传出队首元素）****************
//实验四.链队列.5，链队列出队（传出队首元素）
//输入：需要进行出队的队列指针 
//返回：若运行成功则返回true，若运行失败则返回false
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


//****************链队列出队****************
//实验四.链队列.5，链队列出队（不传出队首元素）
//输入：需要进行出队的队列指针 
//返回：若运行成功则返回true，若运行失败则返回false
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


//****************取链队头元素****************
//实验四.链队列.6，取链队头元素
//输入：需要取元素的队列指针 
//返回：若成功取出则返回该元素，若失败则返回NULL
elementType queueFront(linkQueue& Q)
{
	if (!isQueueEmpty(Q))
		return Q.front->data;
	else return NULL;
}


//****************求当前链队列中元素个数****************
//实验四.链队列.7，求当前链队列中元素个数
//输入：需要求个数的队列指针 
//返回：返回元素个数
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


//****************输入奇偶数指定算法****************
//实验四.链队列.8，输入奇偶数指定算法
//函数内打印：当前队列中的所有元素
void linkQueueIOPFun()
{
	linkQueue Q;
	elementType num = 0;

	initialQueue(Q);

	while (1)
	{
		cout << "请输入一个数字：\t";
		cin >> num;

		if (num == 0)
		{
			cout << "组合程序即将退出" << endl;
			if (destroyLinkQueue(Q)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
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
		cout << "当前队列未：" << endl;
		printQueue(Q);
	}

}


//****************辅助函数：销毁链队列****************
//辅助函数：销毁链队列
//输入：需要销毁的链队列指针
//返回：销毁成功返回true，否则返回false
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