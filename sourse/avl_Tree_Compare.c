#include <stdio.h>
#include <stdlib.h> 

/**
平衡二叉树的判断之应用 
两个序列是否对应相同搜索树的判别（浙--建议采用“调试”体会函数的调用过程）

*/
typedef struct TreeNode *Tree;
struct TreeNode{
	int v;
	Tree Left,Right;
	int flag;//设立标志判断是否为找过的函数，为函数check()与Judge()做准备 
};

//如何建立搜索树
Tree MakeTree (int N);

//根据首个元素创建一个结点，形成树根或创建一个新的结点 
Tree NewNode (int V);

//向树插入给定的元素 
Tree Insert(Tree T,int V);

//对节点进行判别，看是否是已经找过的结点
int check(Tree T,int V);

//如何判别该树是否为同一棵树 
int Judge(Tree T,int N);

//清除T中各结点的flag标记
void ResetT(Tree T);

//释放T的空间
void FreeTree(Tree T);

int main(void) {
	int N,L,i;//N代表序列的元素个数，L代表有多少个序列 
	Tree T;//定义一个Tree类型的变量 
	printf("读入序列元素的个数:\n"); 
	scanf("%d",&N);//读入序列元素的个数 
	while(N) {//如果序列元素的个数是，那就没有可比的必要了 
	
		printf("读入有多少个序列，为for循环条件做准备:\n");
		scanf("%d",&L);//读入有多少个序列，为for循环条件做准备 
		
		printf("输入N个数，建立一个被比较的树：\n");
		T = MakeTree(N);//根据序列元素的个数建立其所对应的树结构 
		
		printf("接下来输入待比较的序列数与被比较的树进行判断是否为相同的树：");
		for (i = 0; i < L; i++) {
			if (Judge(T,N)) {//
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			ResetT(T);//清除T中的标记flag 
		} 
		FreeTree(T);
		printf("对下一组不同序列号的树进行比较\n");
		scanf("%d",&N);
		printf("\n"); 
	}
	return 0;
}

//如何建立搜索树
Tree MakeTree (int N) {//根据序列元素的个数建立其所对应的树结构 
	Tree T;
	int i,V;
	
	scanf("%d",&V);
	T = NewNode(V);//已经建立好了树根，接下来的操作就是要对树进行插入 
	for (i = 1; i < N; i++) {//该序列的首个元素已经用掉了，因此i从1开始读入接下来（N-1）个元素，进行插入树操作 
		scanf("%d",&V);
		T = Insert(T,V);//T是树根，V是要对树进行插入的元素-      
	}
	return T;
} 

//根据首个元素创建一个结点，形成树根或创建一个新的结点 
Tree NewNode (int V) {
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
} 

//向树插入给定的元素 
Tree Insert(Tree T,int V) {
	if (!T) {         
		T = NewNode(V);//该步骤要在最后才起作用 
	} else {
		if (V > T->v) {
			T->Right = Insert(T->Right,V);
		} else {
			T->Left = Insert(T->Left,V);
		}
	}
	return T;
}

//对节点进行判别，看是否是已经找过的结点
int check(Tree T,int V) {
	if(T->flag) {//已经找过的结点 
		if(V < T->v) {//（2 < 3） 
			return check(T->Left,V);//(T->Left,2)
		} else if (V > T->v) {
			return check(T->Right,V);
		} else {
			return 0;
		}
	} else {
		if (V == T->v) {//恰好该结点的值与我要找的值相等 
			T->flag = 1;
			return 1;
		} else {//(2 != 1)
			return 0;
		}
	}
} 

//如何判别该树是否为同一棵树 
int Judge(Tree T,int N) {
	int i,V,flag = 0;//flag:0代表目前还一致，1代表已经不一致 
	scanf("%d",&V);
	if(V != T->v) {//如果第一个数据都不同，也就是说根节点都不同，那么该树肯定不同 
		flag = 1; 
	} else {
		T->flag = 1;
	}
	
	for (i = 1; i < N; i++) {//该序列中除去第一个结点的其他所有结点进行遍历 
		scanf("%d",&V);
		if ((!flag) && (!check(T,V))) { 
			flag = 1;//拿数据说话：3241中的2导致该flag设置为1，自然该if条件进不来，但是还是会把该序列读完，从而不影响下一个序列 
		}
	}
	if (flag) {////该条件保证程序会把序列读完，不会干扰下一个序列的比较 （3142，3241） 
		return 0;
	} else {
		return 1;
	}
} 

//清除T中各结点的flag标记
void ResetT(Tree T) {
	if (T->Left) {
		ResetT(T->Left);
	}
	if (T->Right) {
		ResetT(T->Right);
	}
	T->flag = 0;
} 

//释放T的空间
void FreeTree(Tree T) {
	if (T->Left) {
		FreeTree(T->Left);
	}
	if (T->Right) {
		FreeTree(T->Right);
	}
	free(T);
} 
