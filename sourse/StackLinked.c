#include <stdio.h>
#include <malloc.h>

typedef struct SNode *Stack;
struct SNode {
	int Data;
	Stack Next;
};


//构建一个堆栈的头结点，返回指针
Stack CreateStack() {
	Stack S; // S是一个指针 
	S = (Stack)malloc(sizeof (struct SNode));
	S->Next = NULL;
	return S;
} 

//判断堆栈是否为空
int IsEmpty(Stack S) {
	return (S->Next == NULL);
} 

//push操作
void Push(int item,Stack S) {
	Stack TmpCell;
	TmpCell = (Stack)malloc(sizeof (struct SNode)); // 动态申请新的内存块

	TmpCell->Data = item; // 将 压入的数据写入 新节点的 data属性
	TmpCell->Next = S->Next; // 将新节点的 下一个指针指向
	S->Next = TmpCell; // 将 节点头的 下一个属性设置为 新节点
} 


//Pop操作 弹出栈操作
int Pop(Stack S) {
	
	Stack FirstCell; 
		int TopElem;
		if (IsEmpty(S)) {
		printf("堆栈空");
		// return NULL; 
	} else {
		FirstCell = S->Next;
		S->Next = FirstCell->Next;//该操作完成删除节点
		TopElem = FirstCell->Data;
		free(FirstCell);//释放内存
		return TopElem; 
	} 
}

//遍历链表求出其表长
int Length(Stack PtrL) {
	Stack p = PtrL;
	int j = 0;
	while(p) {
		p = p->Next;
		j++;
	}
	return j;
} 

//显示栈 
void ShowStack(Stack S) {
    Stack temp = S->Next;//设置一个临时指针，指向头结点的下一个结点
    int length = Length(S);//得到链表的长度 
    printf("栈的长度为：%d\n",length); 
	for (int i = 1; i < length; i++) { 
		/*
		此处要特别注意，因为直接从头结点的下一个结点开始遍历结点，Length(S)计算的结点个数包含头结点，实际结点个数比Length(S)少1
		，因此遍历结点时不能写成--i <= length--（实际比这个少一个结点），写成--i < length，或i <= length-1，如果i <= length这样写
		当遍历到最后一个结点时是NULL,但是NULL->Data会导致报错 
		*/
		printf("第%d个结点的值为：%d\n", i, temp->Data);
		temp = temp->Next;
	}  
}
 
 
int main(void) {
	
	//创建一个栈
	Stack S = CreateStack(); 
	
	//void Push(int item,Stack S)
	Push(9,S);
	Push(6,S);
	Push(3,S);
	Push(1,S);
	printf("入栈结点显示：\n");
	ShowStack(S);//显示栈
	
	Pop(S); 
	Pop(S);
	Pop(S);
	printf("\nPop出3个节点后所剩下的值：\n");
	ShowStack(S);
	
	int lastVlue = Pop(S);//得到最后一个节点的值 
	printf("\n最后一个节点的值为：%d\n",lastVlue);
	
	return 0;
}
