#include <stdio.h>
#include <stdlib.h> 

/**
ƽ����������ж�֮Ӧ�� 
���������Ƿ��Ӧ��ͬ���������б���--������á����ԡ���ắ���ĵ��ù��̣�

*/
typedef struct TreeNode *Tree;
struct TreeNode{
	int v;
	Tree Left,Right;
	int flag;//������־�ж��Ƿ�Ϊ�ҹ��ĺ�����Ϊ����check()��Judge()��׼�� 
};

//��ν���������
Tree MakeTree (int N);

//�����׸�Ԫ�ش���һ����㣬�γ������򴴽�һ���µĽ�� 
Tree NewNode (int V);

//�������������Ԫ�� 
Tree Insert(Tree T,int V);

//�Խڵ�����б𣬿��Ƿ����Ѿ��ҹ��Ľ��
int check(Tree T,int V);

//����б�����Ƿ�Ϊͬһ���� 
int Judge(Tree T,int N);

//���T�и�����flag���
void ResetT(Tree T);

//�ͷ�T�Ŀռ�
void FreeTree(Tree T);

int main(void) {
	int N,L,i;//N�������е�Ԫ�ظ�����L�����ж��ٸ����� 
	Tree T;//����һ��Tree���͵ı��� 
	printf("��������Ԫ�صĸ���:\n"); 
	scanf("%d",&N);//��������Ԫ�صĸ��� 
	while(N) {//�������Ԫ�صĸ����ǣ��Ǿ�û�пɱȵı�Ҫ�� 
	
		printf("�����ж��ٸ����У�Ϊforѭ��������׼��:\n");
		scanf("%d",&L);//�����ж��ٸ����У�Ϊforѭ��������׼�� 
		
		printf("����N����������һ�����Ƚϵ�����\n");
		T = MakeTree(N);//��������Ԫ�صĸ�������������Ӧ�����ṹ 
		
		printf("������������Ƚϵ��������뱻�Ƚϵ��������ж��Ƿ�Ϊ��ͬ������");
		for (i = 0; i < L; i++) {
			if (Judge(T,N)) {//
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			ResetT(T);//���T�еı��flag 
		} 
		FreeTree(T);
		printf("����һ�鲻ͬ���кŵ������бȽ�\n");
		scanf("%d",&N);
		printf("\n"); 
	}
	return 0;
}

//��ν���������
Tree MakeTree (int N) {//��������Ԫ�صĸ�������������Ӧ�����ṹ 
	Tree T;
	int i,V;
	
	scanf("%d",&V);
	T = NewNode(V);//�Ѿ����������������������Ĳ�������Ҫ�������в��� 
	for (i = 1; i < N; i++) {//�����е��׸�Ԫ���Ѿ��õ��ˣ����i��1��ʼ�����������N-1����Ԫ�أ����в��������� 
		scanf("%d",&V);
		T = Insert(T,V);//T��������V��Ҫ�������в����Ԫ��-      
	}
	return T;
} 

//�����׸�Ԫ�ش���һ����㣬�γ������򴴽�һ���µĽ�� 
Tree NewNode (int V) {
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
} 

//�������������Ԫ�� 
Tree Insert(Tree T,int V) {
	if (!T) {         
		T = NewNode(V);//�ò���Ҫ������������ 
	} else {
		if (V > T->v) {
			T->Right = Insert(T->Right,V);
		} else {
			T->Left = Insert(T->Left,V);
		}
	}
	return T;
}

//�Խڵ�����б𣬿��Ƿ����Ѿ��ҹ��Ľ��
int check(Tree T,int V) {
	if(T->flag) {//�Ѿ��ҹ��Ľ�� 
		if(V < T->v) {//��2 < 3�� 
			return check(T->Left,V);//(T->Left,2)
		} else if (V > T->v) {
			return check(T->Right,V);
		} else {
			return 0;
		}
	} else {
		if (V == T->v) {//ǡ�øý���ֵ����Ҫ�ҵ�ֵ��� 
			T->flag = 1;
			return 1;
		} else {//(2 != 1)
			return 0;
		}
	}
} 

//����б�����Ƿ�Ϊͬһ���� 
int Judge(Tree T,int N) {
	int i,V,flag = 0;//flag:0����Ŀǰ��һ�£�1�����Ѿ���һ�� 
	scanf("%d",&V);
	if(V != T->v) {//�����һ�����ݶ���ͬ��Ҳ����˵���ڵ㶼��ͬ����ô�����϶���ͬ 
		flag = 1; 
	} else {
		T->flag = 1;
	}
	
	for (i = 1; i < N; i++) {//�������г�ȥ��һ�������������н����б��� 
		scanf("%d",&V);
		if ((!flag) && (!check(T,V))) { 
			flag = 1;//������˵����3241�е�2���¸�flag����Ϊ1����Ȼ��if���������������ǻ��ǻ�Ѹ����ж��꣬�Ӷ���Ӱ����һ������ 
		}
	}
	if (flag) {////��������֤���������ж��꣬���������һ�����еıȽ� ��3142��3241�� 
		return 0;
	} else {
		return 1;
	}
} 

//���T�и�����flag���
void ResetT(Tree T) {
	if (T->Left) {
		ResetT(T->Left);
	}
	if (T->Right) {
		ResetT(T->Right);
	}
	T->flag = 0;
} 

//�ͷ�T�Ŀռ�
void FreeTree(Tree T) {
	if (T->Left) {
		FreeTree(T->Left);
	}
	if (T->Right) {
		FreeTree(T->Right);
	}
	free(T);
} 
