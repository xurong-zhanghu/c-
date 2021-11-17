#include <stdio.h>
#include <malloc.h>

typedef struct SNode *Stack;
struct SNode {
	int Data;
	Stack Next;
};


//����һ����ջ��ͷ��㣬����ָ��
Stack CreateStack() {
	Stack S; // S��һ��ָ�� 
	S = (Stack)malloc(sizeof (struct SNode));
	S->Next = NULL;
	return S;
} 

//�ж϶�ջ�Ƿ�Ϊ��
int IsEmpty(Stack S) {
	return (S->Next == NULL);
} 

//push����
void Push(int item,Stack S) {
	Stack TmpCell;
	TmpCell = (Stack)malloc(sizeof (struct SNode)); // ��̬�����µ��ڴ��

	TmpCell->Data = item; // �� ѹ�������д�� �½ڵ�� data����
	TmpCell->Next = S->Next; // ���½ڵ�� ��һ��ָ��ָ��
	S->Next = TmpCell; // �� �ڵ�ͷ�� ��һ����������Ϊ �½ڵ�
} 


//Pop���� ����ջ����
int Pop(Stack S) {
	
	Stack FirstCell; 
	int TopElem;
	if (IsEmpty(S)) {
	printf("��ջ��");
	// return NULL; 
	} else {
		FirstCell = S->Next;
		S->Next = FirstCell->Next;//�ò������ɾ���ڵ�
		TopElem = FirstCell->Data;
		free(FirstCell);//�ͷ��ڴ�
		return TopElem; 
	} 
}

//��������������
int Length(Stack PtrL) {
	Stack p = PtrL;
	int j = 0;
	while(p) {
		p = p->Next;
		j++;
	}
	return j;
} 

//��ʾջ 
void ShowStack(Stack S) {
    Stack temp = S->Next;//����һ����ʱָ�룬ָ��ͷ������һ�����
    int length = Length(S);//�õ�����ĳ��� 
    printf("ջ�ĳ���Ϊ��%d\n",length); 
	for (int i = 1; i < length; i++) { 
		/*
		�˴�Ҫ�ر�ע�⣬��Ϊֱ�Ӵ�ͷ������һ����㿪ʼ������㣬Length(S)����Ľ���������ͷ��㣬ʵ�ʽ�������Length(S)��1
		����˱������ʱ����д��--i <= length--��ʵ�ʱ������һ����㣩��д��--i < length����i <= length-1�����i <= length����д
		�����������һ�����ʱ��NULL,����NULL->Data�ᵼ�±��� 
		*/
		printf("��%d������ֵΪ��%d\n", i, temp->Data);
		temp = temp->Next;
	}  
}
 
 
int main(void) {
	
	//����һ��ջ
	Stack S = CreateStack(); 
	
	//void Push(int item,Stack S)
	Push(9,S);
	Push(6,S);
	Push(3,S);
	Push(1,S);
	printf("��ջ�����ʾ��\n");
	ShowStack(S);//��ʾջ
	
	Pop(S); 
	Pop(S);
	Pop(S);
	printf("\nPop��3���ڵ����ʣ�µ�ֵ��\n");
	ShowStack(S);
	
	int lastVlue = Pop(S);//�õ����һ���ڵ��ֵ 
	printf("\n���һ���ڵ��ֵΪ��%d\n",lastVlue);
	
	return 0;
}
