//**********************//
//队列实验主程序		//
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
		cout << "实验四：队列实验" << endl;
		cout << "*****************************************************************" << endl;
		cout << "*\t*\t*\t*第一组：顺序队列*\t*\t*\t*" << endl;
		cout << "*1，初始化并创建队列，判断为空或为满。\t\t\t\t*" << endl;
		cout << "*2，顺序队列入队。\t\t\t\t\t\t*" << endl;
		cout << "*3，顺序队列出队。\t\t\t\t\t\t*" << endl;
		cout << "*4，顺序队列取队头元素。\t\t\t\t\t*" << endl;
		cout << "*5，计算队列长度。\t\t\t\t\t\t*" << endl;
		cout << "*6，组合程序。\t\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*\t*\t*\t*第二组： 链队列*\t*\t*\t*" << endl;
		cout << "*7，初始化并创建队列，判断为空。\t\t\t\t*" << endl;
		cout << "*8，链队列入队。\t\t\t\t\t\t*" << endl;
		cout << "*9，链队列出队。\t\t\t\t\t\t*" << endl;
		cout << "*10，链队列取队头元素。\t\t\t\t\t*" << endl;
		cout << "*11，计算队列长度。\t\t\t\t\t\t*" << endl;
		cout << "*12，组合程序。\t\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*0，退出程序。\t\t\t\t\t\t\t*" << endl;
		cout << "*****************************************************************" << endl;
		cout << "请输入菜单编号：\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验（入队n（n=50）个元素）：" << endl;
			initialQueue(&Q);
			srand((int)time(nullptr));
			for (int i = 0; i < 50; i++)
			{
				enQueue(&Q, random(100, 999));
			}
			cout << "当前队列如下：" << endl;
			printQueue(&Q);
			if (isQueueFull(&Q)) cout << "队列已满！" << endl;
			else cout << "队列未满。" << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验（入队n（n=99）个元素）：" << endl;
			initialQueue(&Q);
			for (int i = 1; i < 100; i++)
			{
				enQueue(&Q, i);
			}
			cout << "当前队列如下：" << endl;
			printQueue(&Q);
			if (isQueueFull(&Q)) cout << "队列已满！" << endl;
			else cout << "队列未满。" << endl;
			//********************************************************************
			break;
		case 2:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "当前输入数据依次为：\t";
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				cout << data[0][i] << "\t";
				enQueue(&Q, data[0][i]);
			}
			cout << endl;
			cout << "打印入队后的队列：\t";
			printQueue(&Q);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验：" << endl;
			cout << "当前输入数据依次为：\t";
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				cout << (char)(data[1][i]) << "\t";
				enQueue(&Q, data[1][i]);
			}
			cout << endl;
			cout << "打印入队后的队列：\t";
			printQueue(&Q, true);
			//********************************************************************
			break;
		case 3:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：" << endl;
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				enQueue(&Q, data[0][i]);
			}
			cout << "当前队列为：\t";
			printQueue(&Q);
			cout << endl;
			outQueue(&Q);
			cout << "打印出队后的队列：\t";
			printQueue(&Q);
			//********************************************************************
			cout << endl;
			break;
		case 4:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：" << endl;
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				enQueue(&Q, data[0][i]);
			}
			cout << "当前队列为：\t";
			printQueue(&Q);
			cout << endl;
			cout << "打印对头元素：\t";
			cout << queueFront(&Q) << endl;
			//********************************************************************
			cout << endl;
			break;
		case 5:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：" << endl;
			initialQueue(&Q);
			for (int i = 0; i < 6; i++)
			{
				enQueue(&Q, data[0][i]);
			}
			cout << "当前队列为：\t";
			printQueue(&Q);
			cout << endl;
			cout << "当前队列元素个数为：\t";
			cout << getQueueLength(&Q) << endl;
			//********************************************************************
			cout << endl;
			break;
		case 6:
			system("cls");
			//测试***************************************************************
			queueIOPFun();
			//********************************************************************
			break;
		case 7:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验（入队n（n=50）个元素）：" << endl;
			initialQueue(LQ);
			srand((int)time(nullptr));
			for (int i = 0; i < 50; i++)
			{
				enQueue(LQ, random(100, 999));
			}
			cout << "当前队列如下：" << endl;
			printQueue(LQ);
			if (isQueueEmpty(LQ)) cout << "队列为空！" << endl;
			else cout << "队列不空。" << endl;
			//第一组测试结束，销毁链队列，便于下次测试****************************
			if (destroyLinkQueue(LQ)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验（入队n（n=99）个元素）：" << endl;
			initialQueue(LQ);
			for (int i = 1; i < 100; i++)
			{
				enQueue(LQ, i);
			}
			cout << "当前队列如下：" << endl;
			printQueue(LQ);
			if (isQueueEmpty(LQ)) cout << "队列为空！" << endl;
			else cout << "队列不空。" << endl;
			//第二组测试结束，销毁链队列，便于下次测试****************************
			if (destroyLinkQueue(LQ)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			//********************************************************************
			break;
		case 8:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "当前输入数据依次为：\t";
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				cout << data[0][i] << "\t";
				enQueue(LQ, data[0][i]);
			}
			cout << endl;
			cout << "打印入队后的队列：\t";
			printQueue(LQ);
			//第一组测试结束，销毁链队列，便于下次测试****************************
			if (destroyLinkQueue(LQ)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验：" << endl;
			cout << "当前输入数据依次为：\t";
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				cout << (char)(data[1][i]) << "\t";
				enQueue(LQ, data[1][i]);
			}
			cout << endl;
			cout << "打印入队后的队列：\t";
			printQueue(LQ, true);
			//第二组测试结束，销毁链队列，便于下次测试****************************
			if (destroyLinkQueue(LQ)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			//********************************************************************
			break;
		case 9:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：" << endl;
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				enQueue(LQ, data[0][i]);
			}
			cout << "当前队列为：\t";
			printQueue(LQ);
			cout << endl;
			outQueue(LQ);
			cout << "打印出队后的队列：\t";
			printQueue(LQ);
			//第一组测试结束，销毁链队列，便于下次测试****************************
			if (destroyLinkQueue(LQ)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 10:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：" << endl;
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				enQueue(LQ, data[0][i]);
			}
			cout << "当前队列为：\t";
			printQueue(LQ);
			cout << endl;
			cout << "打印对头元素：\t";
			cout << queueFront(LQ) << endl;
			//第一组测试结束，销毁链队列，便于下次测试****************************
			if (destroyLinkQueue(LQ)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 11:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：" << endl;
			initialQueue(LQ);
			for (int i = 0; i < 6; i++)
			{
				enQueue(LQ, data[0][i]);
			}
			cout << "当前队列为：\t";
			printQueue(LQ);
			cout << endl;
			cout << "当前队列元素个数为：\t";
			cout << getQueueLength(LQ) << endl;
			//第一组测试结束，销毁链队列，便于下次测试****************************
			if (destroyLinkQueue(LQ)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 12:
			system("cls");
			//测试***************************************************************
			linkQueueIOPFun();
			//********************************************************************
			break;
		case 0:
			if (destroyLinkQueue(LQ)) cout << "链栈销毁成功！" << endl;
			else cout << "链栈销毁失败！" << endl;
			return 0;
		default:
			system("cls");
			cout << "输入错误！" << endl;
			break;
		}
	}

	return 0;
}