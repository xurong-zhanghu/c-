#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//队列的顺序存储实现 
typedef int Position;
struct QNode {
	int *Data;
	Position Front,Rear;//定义队列的头部以及尾部 
	int MaxSize;//数组的大小 
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize) {
	Queue Q = (Queue)malloc(sizeof(struct QNode));//为该队列分配一块内存空间 
	Q->Data = (int *)malloc(MaxSize * sizeof(int));//为数组分配一块内存空间 
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize; 
	return Q;
}

bool IsFull(Queue Q) {
	/*队列的顺序存储的实现--理解关键之处：(Q->Rear + 1) % Q->MaxSize == Q->Front 
	该代码采取预留一个空位解决了(Front==Rear)时，对列是满还是空的问题。该公式就实现
	了该判断，（注意Front==Rear==0），并且当队列为满时，肯定是队列只剩余一个空位
	而Front总是指向该空位。（Front指向的位置一定没有元素，Rear总是指向队列尾部的最后一个元素 
	*/ 
	return ((Q->Rear + 1) % Q->MaxSize == Q->Front); 
}
bool AddQ(Queue Q, int x) {
	if (IsFull(Q)) {
		printf("队列满");
		return false;		 
	} else {
		Q->Rear = (Q->Rear + 1) % Q->MaxSize;
		Q->Data[Q->Rear] = x;
		return true;
	}
}

bool IsEmpty(Queue Q) {
	return (Q->Front == Q->Rear);
}

int DeleteQ(Queue Q) {
	if (IsEmpty(Q)) {
		printf("队列空");
//		return ERROR; 
	} else {
		Q->Front = (Q->Front+1) % Q->MaxSize;
		return Q->Data[Q->Front];
	}	
} 

//定义一个显示队列的方法
void showQueue(Queue Q){
	//判断是否为空
	if(IsEmpty(Q)) {
		printf("队列为空，不能显示数据");
		return; 
	}
	//遍历数组，显示数据
	/*
	(Q->Rear+Q->MaxSize-Q->Front) % Q->MaxSize)：
	该语句计算出Front与Rear相差多少，加上一个Q->Front，就为i设定了边界值 
	*/
	for (int i = Q->Front + 1; i <= Q->Front + ((Q->Rear+Q->MaxSize-Q->Front) % Q->MaxSize); i++) {
		printf("Q->Data[%d] = %d\n",i%Q->MaxSize,Q->Data[i%Q->MaxSize]);//取模运算的奇妙之处 
	}
} 
int main(void) {
	
	Queue Q = CreateQueue(5);
	printf("直接显示数据Test：因为预留了一个位置，队列只能增加4个元素（队里数组大小为5）:\n"); 
	AddQ(Q,1);
	AddQ(Q,2);
	AddQ(Q,3);
	AddQ(Q,4);
	showQueue(Q);
	 
	printf("队列满Test：\n"); 
	AddQ(Q,5);
	
	printf("\n元素出队列Test:\n"); 
	printf("出队列值：%d\n",DeleteQ(Q));
	printf("出队列值：%d\n",DeleteQ(Q));
	printf("出队列值：%d\n",DeleteQ(Q));
	printf("出队列值：%d\n",DeleteQ(Q));
	printf("\n空队列显示Test：\n");
	DeleteQ(Q); 
	return 0;
}
