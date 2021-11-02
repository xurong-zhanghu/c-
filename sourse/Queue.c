#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//���е�˳��洢ʵ�� 
typedef int Position;
struct QNode {
	int *Data;
	Position Front,Rear;//������е�ͷ���Լ�β�� 
	int MaxSize;//����Ĵ�С 
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize) {
	Queue Q = (Queue)malloc(sizeof(struct QNode));//Ϊ�ö��з���һ���ڴ�ռ� 
	Q->Data = (int *)malloc(MaxSize * sizeof(int));//Ϊ�������һ���ڴ�ռ� 
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize; 
	return Q;
}

bool IsFull(Queue Q) {
	/*���е�˳��洢��ʵ��--���ؼ�֮����(Q->Rear + 1) % Q->MaxSize == Q->Front 
	�ô����ȡԤ��һ����λ�����(Front==Rear)ʱ�������������ǿյ����⡣�ù�ʽ��ʵ��
	�˸��жϣ���ע��Front==Rear==0�������ҵ�����Ϊ��ʱ���϶��Ƕ���ֻʣ��һ����λ
	��Front����ָ��ÿ�λ����Frontָ���λ��һ��û��Ԫ�أ�Rear����ָ�����β�������һ��Ԫ�� 
	*/ 
	return ((Q->Rear + 1) % Q->MaxSize == Q->Front); 
}
bool AddQ(Queue Q, int x) {
	if (IsFull(Q)) {
		printf("������");
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
		printf("���п�");
//		return ERROR; 
	} else {
		Q->Front = (Q->Front+1) % Q->MaxSize;
		return Q->Data[Q->Front];
	}	
} 

//����һ����ʾ���еķ���
void showQueue(Queue Q){
	//�ж��Ƿ�Ϊ��
	if(IsEmpty(Q)) {
		printf("����Ϊ�գ�������ʾ����");
		return; 
	}
	//�������飬��ʾ����
	/*
	(Q->Rear+Q->MaxSize-Q->Front) % Q->MaxSize)��
	���������Front��Rear�����٣�����һ��Q->Front����Ϊi�趨�˱߽�ֵ 
	*/
	for (int i = Q->Front + 1; i <= Q->Front + ((Q->Rear+Q->MaxSize-Q->Front) % Q->MaxSize); i++) {
		printf("Q->Data[%d] = %d\n",i%Q->MaxSize,Q->Data[i%Q->MaxSize]);//ȡģ���������֮�� 
	}
} 
int main(void) {
	
	Queue Q = CreateQueue(5);
	printf("ֱ����ʾ����Test����ΪԤ����һ��λ�ã�����ֻ������4��Ԫ�أ����������СΪ5��:\n"); 
	AddQ(Q,1);
	AddQ(Q,2);
	AddQ(Q,3);
	AddQ(Q,4);
	showQueue(Q);
	 
	printf("������Test��\n"); 
	AddQ(Q,5);
	
	printf("\nԪ�س�����Test:\n"); 
	printf("������ֵ��%d\n",DeleteQ(Q));
	printf("������ֵ��%d\n",DeleteQ(Q));
	printf("������ֵ��%d\n",DeleteQ(Q));
	printf("������ֵ��%d\n",DeleteQ(Q));
	printf("\n�ն�����ʾTest��\n");
	DeleteQ(Q); 
	return 0;
}
