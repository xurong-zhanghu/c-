#include <stdio.h>
#include <malloc.h>
typedef struct LNode *List;
struct LNode {
	int Data;
	List Next;
};
List PtrL;//创建指向空的结点 

//函数声明
int Length(List PtrL); 
List Find(int x,List Ptrl);
List FindKth(int K, List Ptrl);
List Insert(int x,int i,List PtrL);
List Delect(int i, List PtrL);


int main() {
	PtrL = Insert(1,1,PtrL);
	Insert(2,2,PtrL); 
	Insert(3,3,PtrL); 
	Insert(4,4,PtrL); 
	Insert(5,5,PtrL); 
	
//	PtrL = Insert(1,1,PtrL);
//	Insert(2,1,PtrL); 
//	Insert(3,1,PtrL); 
//	Insert(4,1,PtrL); 
//	Insert(5,1,PtrL); 
	
	//写一个for循环将链表显示出来
	List temp;
	temp = PtrL;
	for(int i = 1; i <= Length(PtrL); i++) {
		printf("第%d个结点的Data = %d\n",i,temp->Data);
		temp = temp->Next;
	} 
	return 0;
}


//遍历链表求出其表长
int Length(List PtrL) {
	List p = PtrL;
	int j = 0;
	while(p) {
		p = p->Next;
		j++;
	}
	return j;
} 

//在链表中查找某一个元素
//此处采用按值查找
List Find(int x,List Ptrl) {
	List p = Ptrl;//设立一个临时指针指向该链表的头节点 
	while (p != NULL && p->Data != x) {
		p = p->Next;
	} 
	return p;
}

//按序号查找
List FindKth(int K, List Ptrl) {//K代表第K个元素 
	List p = Ptrl;
	int i = 1;//注意：PtrL是指向表头,即指向链表的第一个表，也就是指向链表的第一个元素，所以i=1
	while(p != NULL && i < K) {
		p = p->Next;
		i++; 
	}
	if (i == K) {
		return p;
	} else {
		return NULL;
	} 	   
	
} 

 
//插入--在第i-1个节点后插入一个值为x的新节点
/*此插入方法有一个缺点：在main方法中注释可见，对于该种特殊插入（多次从头部插入）只会在第一次插入插入成功--
原因：该方法没有对头部结点做好的处理，对于该种特殊方法，每次返回的都是头部结点，而每次调用Insert(3,1,PtrL);
其中的参数Ptrl就是指向该头部节点的指针，但是当第2次插入以后，没有进行PtrL = Insert(2,1,PtrL);该操作，也就是
没有对其进行头部结点PtrL的更新，头部还是指向插入的第一个元素，那么自然无法进行插入操作，解决办法如下（或者采用
浙大老师的另一种设计插入的方法） ：更新头部PtrL就行了 
 	PtrL = Insert(1,1,PtrL);
	PtrL = Insert(2,1,PtrL); 
	PtrL = Insert(3,1,PtrL); 
	PtrL = Insert(4,1,PtrL); 
	PtrL = Insert(5,1,PtrL); 
*/
List Insert(int x,int i,List PtrL) {//也就是说在第i个节点之处插入该新节点 
	List p,s;
	if(i == 1) {
		s=(List)malloc(sizeof(struct LNode));//为新节点开辟一块内存 
		s->Data = x;//把待插入的值赋值给该新节点结构体中的变量Data 
		s->Next = PtrL;//因为i等于1，也就是说在第一个节点处插入该节点，也就是说该新插入的节点想变成头节点 
		return s;
	}
	p = FindKth(i-1,PtrL);//找到待插入节点的上一个节点 
	if(p == NULL) {//第i-1个节点不存在，不能插入 
		printf("参数i错");
		return NULL; 
	}else {
		s = (List)malloc(sizeof(struct LNode));//申请，填装节点 
		s->Data = x;
		s->Next = p->Next;
		p->Next = s;
		return PtrL; 
	}
} 


//删除第i个结点 
List Delect(int i, List PtrL) {
	List p,s;
	if(i == 1) {
		s = PtrL;//将s结点指向头结点，便于后面释放内存操作 
		if (PtrL != NULL) {
			PtrL = PtrL->Next; 
		} else {
			return NULL;		
		}
		free(s);
		return PtrL;
	}
	p = FindKth(i-1, PtrL);//找到待删除结点的上一个结点 
	if(p == NULL) {
		printf("第%d个结点不存在",i-1);
		return NULL;
	} else if (p->Next == NULL) {
		printf("第%d个结点不存在",i);
		return NULL;
	} else {
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	} 
}
