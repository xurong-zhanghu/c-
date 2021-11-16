#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MaxSizeArray 16//该程序的缺陷之处：调用CreateStack(int MaxSize)函数时，需与MaxSize保持一致（重在理解堆栈，哈哈） 

//用一个数组实现两个堆栈 
typedef struct DStack *Stack;
typedef int Position; 
struct DStack {
	int *Data;//存储元素的数组 
	Position Top1;//堆栈1的顶部指针 
	Position Top2;//堆栈2的顶部指针,也可以说是堆栈的最大容量 
	 
};

//创建一个空的堆栈 
Stack CreateStack(int MaxSize) {
	//为所创造的DStack栈分配内存
	Stack S = (Stack)malloc(sizeof(struct DStack));
	//为数组分配内存
	S->Data = (int *)malloc(MaxSize * sizeof(int));
	
	S->Top1 = -1;
	S->Top2 = MaxSize;
	return S;  
}
 
//判断栈是否为空
bool IsEmpty(Stack PtrS) {
	return PtrS->Top1 == -1;
} 

//判断栈是否为空 
bool IsFull(Stack PtrS) {
	 return PtrS->Top2 - PtrS->Top1 == 1;	
} 

//push操作
void Push(Stack PtrS, int item, int Tag) {
	if(IsFull(PtrS)) {
		printf("堆栈满");
		return; 
	}
	if (Tag == 1) //对第一个栈进行操作
	   PtrS->Data[++(PtrS->Top1)] = item;
	else//对第二个栈进行操作 
		PtrS->Data[--(PtrS->Top2)] = item;
} 

//pop操作
int Pop(Stack PtrS,int Tag) {
	if (Tag == 1) {//对同一个数组中的其中一个堆栈1进行操作 
		if(IsEmpty(PtrS)) {
			printf("堆栈1空");
			return NULL; 
		} else {
			return PtrS->Data[(PtrS->Top1)--];
		}
  		  	   
	} else {
		if(PtrS->Top2 == MaxSizeArray) {//对同一个数组中的其中一个堆栈2进行操作 
			printf("堆栈2空");
			return NULL;	 
		} else {
			return PtrS->Data[(PtrS->Top2)++];
		}
	}
	
} 

//编写一个测试函数
/*
明确：函数返回值是void,函数参数设置：堆栈S,以及其所对应的哪一个堆栈tag
设置一个int类型的临时变量temp指向top1 or to2
利用for循环对堆栈进行遍历，临界值是temp指向-1，或者MaxSize 
*/ 
void ShowStack(Stack S,int tag) {
	Position temp;
	if(tag == 1) {
		temp = S->Top1;
		for(int i = temp; i >= 0; i--) {
			printf("下标为%d的值为：%d\n",i,S->Data[i]);
		}
	} else {
		temp = S->Top2;
		for(int i = temp; i < MaxSizeArray; i++) {
			printf("下标为%d的值为：%d\n",i,S->Data[i]);
		}
	}	
}
int main(void) {
	Stack S = CreateStack(16);
	
	//对堆栈1进行操作 
	Push(S,1,1);
	Push(S,2,1);
	Push(S,3,1);
	Push(S,4,1);
	
	//对堆栈2进行操作 
	Push(S,16,2);
	Push(S,15,2);
	Push(S,14,2);
	Push(S,13,2);
	
//	StackTest(Stack S,int tag)---显示堆栈

//push--test
    printf("pop--test");
	printf("堆栈1为：\n"); 
 	ShowStack(S,1);
 	printf("\n堆栈2为：\n");  
 	ShowStack(S,2);
 	
//pop--test
    printf("\npop--test\n");
	Pop(S,1);//将下标为3所在元素Pop出去
	ShowStack(S,1);	   
	Pop(S,1);//将下标为2所在元素Pop出去	   
	Pop(S,1);//将下标为1所在元素Pop出去
	
	printf("\n只剩一个元素,将其显示\n"); 
	ShowStack(S,1);	   
	Pop(S,1);//将下标为0所在元素Pop出去	   
 	ShowStack(S,1);
 	printf("\n报堆栈1空的提示\n"); 
 	Pop(S,1);//堆栈1中没有元素，报--堆栈1空--的提示
	 		   
	return 0;
}

 
