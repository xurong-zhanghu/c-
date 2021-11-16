#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>//引入false,与true 
typedef struct LNode *PtrToLNode;
struct LNode {
    int Data;//结点中存储的数据 
    PtrToLNode Next;//用于指向下一个结点 
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position p;//定义一个所要插入的位置
List L;

/* 查找 */
#define ERROR  NULL 
 
Position Find( List L, int X )
{
    Position p = L; /* p指向L的第1个结点 也就是说代表整个链表，为什么不可以直接用L呢，原因是头结点不可以改变*/

    while ( p && p->Data!=X )//当该链表不是空，或者其结点的数据不等于X的时候，将结点下移 
        p = p->Next;

    /* 下列语句可以用 return p;替换 */
    if ( p )
        return p;
    else
        return ERROR;
}

/* 带头结点的插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
bool Insert( List L, int X, Position P )//Position P：所想要插入的位置 
{ 
  	 /* 这里默认L有头结点 */
    Position tmp, pre;

    /* 查找P的前一个结点 */        
    for ( pre=L; pre&&pre->Next != P; pre = pre->Next); //试图寻找P的前一个结点           
    if ( pre==NULL ) { /* P所指的结点不在L中 */
        printf("插入位置参数错误\n");
        return false;
    }
    else { /* 找到了P的前一个结点pre */
        /* 在P前插入新结点 */
        tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
        tmp->Data = X; 
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}

/* 带头结点的删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
bool Delete( List L, Position P )
{ /* 这里默认L有头结点 */
    Position pre;

    /* 查找P的前一个结点 */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next );////试图寻找P的前一个结点            
    if ( pre==NULL || P==NULL) { /* P所指的结点不在L中 */
        printf("删除位置参数错误\n");
        return false;
    }
    else { /* 找到了P的前一个结点pre */
        /* 将P位置的结点删除 */
        pre->Next = P->Next;
        free(P);
        return true;
    }
}

//遍历出链表的长度 
int Length(List PtrL) {
	List p = PtrL;
	int j = 0;
	while(p) {
		p = p->Next;
		j++;
	}
	return j;
} 
int main(void) {
	//创建一个链表用于测试,当然该测试有缺陷，仅供参考 
	L = (List)malloc(sizeof(struct LNode));
	L->Data = 1;
	L->Next = NULL; 
	
	//bool Insert( List L, int X, Position P )//Position P：所想要插入的位置 
	Insert(L,2,NULL);
	Insert(L,3,NULL); 
	Insert(L,4,NULL); 
	Insert(L,5,NULL); 
	Insert(L,6,NULL); 
	

	List temp;//注意需要建立一个temp临时变量指向头结点，因为头结点L是不能随便改变
	temp = L;
	
	int length = Length(temp);//遍历出链表的长度
	//写一个for循环将链表显示出来 
	for(int i = 1; i <= length; i++) {
		printf("第%d个结点数据为：%d\n",i,temp->Data);//注意需要建立一个temp临时变量指向头结点，因为头结点L是不能随便改变 
		temp = temp->Next;
	} 
	return 0;
}




