#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MaxSizeArray 16//�ó����ȱ��֮��������CreateStack(int MaxSize)����ʱ������MaxSize����һ�£���������ջ�������� 

//��һ������ʵ��������ջ 
typedef struct DStack *Stack;
typedef int Position; 
struct DStack {
	int *Data;//�洢Ԫ�ص����� 
	Position Top1;//��ջ1�Ķ���ָ�� 
	Position Top2;//��ջ2�Ķ���ָ��,Ҳ����˵�Ƕ�ջ��������� 
	 
};

//����һ���յĶ�ջ 
Stack CreateStack(int MaxSize) {
	//Ϊ�������DStackջ�����ڴ�
	Stack S = (Stack)malloc(sizeof(struct DStack));
	//Ϊ��������ڴ�
	S->Data = (int *)malloc(MaxSize * sizeof(int));
	
	S->Top1 = -1;
	S->Top2 = MaxSize;
	return S;  
}
 
//�ж�ջ�Ƿ�Ϊ��
bool IsEmpty(Stack PtrS) {
	return PtrS->Top1 == -1;
} 

//�ж�ջ�Ƿ�Ϊ�� 
bool IsFull(Stack PtrS) {
	 return PtrS->Top2 - PtrS->Top1 == 1;	
} 

//push����
void Push(Stack PtrS, int item, int Tag) {
	if(IsFull(PtrS)) {
		printf("��ջ��");
		return; 
	}
	if (Tag == 1) //�Ե�һ��ջ���в���
	   PtrS->Data[++(PtrS->Top1)] = item;
	else//�Եڶ���ջ���в��� 
		PtrS->Data[--(PtrS->Top2)] = item;
} 

//pop����
int Pop(Stack PtrS,int Tag) {
	if (Tag == 1) {//��ͬһ�������е�����һ����ջ1���в��� 
		if(IsEmpty(PtrS)) {
			printf("��ջ1��");
			return NULL; 
		} else {
			return PtrS->Data[(PtrS->Top1)--];
		}
  		  	   
	} else {
		if(PtrS->Top2 == MaxSizeArray) {//��ͬһ�������е�����һ����ջ2���в��� 
			printf("��ջ2��");
			return NULL;	 
		} else {
			return PtrS->Data[(PtrS->Top2)++];
		}
	}
	
} 

//��дһ�����Ժ���
/*
��ȷ����������ֵ��void,�����������ã���ջS,�Լ�������Ӧ����һ����ջtag
����һ��int���͵���ʱ����tempָ��top1 or to2
����forѭ���Զ�ջ���б������ٽ�ֵ��tempָ��-1������MaxSize 
*/ 
void ShowStack(Stack S,int tag) {
	Position temp;
	if(tag == 1) {
		temp = S->Top1;
		for(int i = temp; i >= 0; i--) {
			printf("�±�Ϊ%d��ֵΪ��%d\n",i,S->Data[i]);
		}
	} else {
		temp = S->Top2;
		for(int i = temp; i < MaxSizeArray; i++) {
			printf("�±�Ϊ%d��ֵΪ��%d\n",i,S->Data[i]);
		}
	}	
}
int main(void) {
	Stack S = CreateStack(16);
	
	//�Զ�ջ1���в��� 
	Push(S,1,1);
	Push(S,2,1);
	Push(S,3,1);
	Push(S,4,1);
	
	//�Զ�ջ2���в��� 
	Push(S,16,2);
	Push(S,15,2);
	Push(S,14,2);
	Push(S,13,2);
	
//	StackTest(Stack S,int tag)---��ʾ��ջ

//push--test
    printf("pop--test");
	printf("��ջ1Ϊ��\n"); 
 	ShowStack(S,1);
 	printf("\n��ջ2Ϊ��\n");  
 	ShowStack(S,2);
 	
//pop--test
    printf("\npop--test\n");
	Pop(S,1);//���±�Ϊ3����Ԫ��Pop��ȥ
	ShowStack(S,1);	   
	Pop(S,1);//���±�Ϊ2����Ԫ��Pop��ȥ	   
	Pop(S,1);//���±�Ϊ1����Ԫ��Pop��ȥ
	
	printf("\nֻʣһ��Ԫ��,������ʾ\n"); 
	ShowStack(S,1);	   
	Pop(S,1);//���±�Ϊ0����Ԫ��Pop��ȥ	   
 	ShowStack(S,1);
 	printf("\n����ջ1�յ���ʾ\n"); 
 	Pop(S,1);//��ջ1��û��Ԫ�أ���--��ջ1��--����ʾ
	 		   
	return 0;
}

 
