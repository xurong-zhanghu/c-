#include <stdio.h>
#include <malloc.h>
/*采用数组模拟线性表*/
#define MAXSIZE 20
typedef struct LNode * List;//定义一个指向LNode结构的指针 
struct LNode{
	int Data[MAXSIZE];//创建一个int类型的数组 
	int Last;//指向数组最后一个元素的下标,最后一个元素并不代表该数组最后一个位置
	 
}; 
//struct LNode L;
List Ptrl;//定义一个指向该指针结构体的变量 

//建立空的顺序表 
List MakeEmpty(){
	List Ptrl;//定义一个指向该指针结构体的变量  
	Ptrl = (List)malloc(sizeof(struct LNode));//为结构体类型分配一块内存 
	Ptrl->Last = -1;//如果该链表没有元素，就将-指向数组最后一个元素的下标Last指向-1，代表空  
	return Ptrl;
}

//在链表中查找一个元素
int Find(int x, List Ptrl) {//在链表Ptrl中查找一个x 
	int i = 0;
	while(i <= Ptrl->Last && Ptrl->Data[i] != x)
		   i++;
	if (i > Ptrl->Last)
	   return -1;//如果下标大于最后一个元素的下标，说明该线性表中并没有该元素，返回-1 
	else
		return i;//找到x元素所对应的下标	   
} 

//插入
//前提条件：第i(1 <= i <= n+1)个位置上插入一个值为X的新元素，第i个位置也就是i - 1 
void Insert(int x,int i,List Ptrl) {//7,11,Ptrl     
	int j;
	if(Ptrl->Last == MAXSIZE-1) {//指向最后一个元素的下标Last指向了MAXSIZE-1，说明数组满 
		printf("表满");
		return; 
	}
	if(i < 1 || i > Ptrl->Last+2) {
	/*
	  *****
	  插入位置的合法性之说明(2021年11月9日)：
	  i < 1：因为时模拟数组实现的插入，i可以取等于1，也就是可以在下标1-1 = 0处插入元素，也就是说将元素插在顺序表的头部，原先头部元素往后移一个
	  i > Ptrl->Last+2: i表示的是第i个元素，Ptrl->Last+1表示第n(假设数组中有n个元素)个元素，i可以取到Ptrl->Last+2，也就是说可以在最后一个元素的
	  下一个位置插入一个元素，当然这也是合乎我们设计的。 
	*/  
        printf("位置不合法");
        return; 
	} 
	for (j = Ptrl->Last; j >= i-1;j--) {//将下标指向Last 
		Ptrl->Data[j+1] = Ptrl->Data[j];//将元素从后面移一个位置，从最后一个元素开始，从而将Data[i-1]对应位置空出来 
	}
	Ptrl->Data[i-1] = x;
	Ptrl->Last++;//仍然将Last指向最后一个元素 
} 

//删除操作的实现,删除第i个元素，也就是删除i-1下标所对应的元素 
void Delete(int i, List Ptrl) {
	int j;
	if(i < 1 || i >Ptrl->Last + 1) {//检查删除位置的合法性，i可以取到Ptrl->Last + 1，同理表示删除最后有一个元素（2021年11月9日） 
		printf("不存在第%d个元素",i);
	}
	for (j = i; j <= Ptrl->Last; j++) {
		Ptrl->Data[j-1] = Ptrl->Data[j];//与插入不同，该操作是将元素从需要删除的位置逐个往前移 
	}
	Ptrl->Last--; 
} 
int main(void) {
	//建立顺序表 
	Ptrl = MakeEmpty();
 
	//插入--第i(1 <= i <= n+1)个位置上插入一个值为X的新元素，第i个位置也就是i - 1 
	Insert(1,1,Ptrl);//注意：每一次插入，Ptrl->Last都往后移一位 
	Insert(2,2,Ptrl);
	Insert(3,3,Ptrl);
	Insert(4,4,Ptrl);
	
	//查找链表中所有元素
	printf("%d\n",Find(1,Ptrl)); 
	printf("%d\n",Find(2,Ptrl));
	printf("%d\n",Find(3,Ptrl));
	printf("%d\n",Find(4,Ptrl));
 		
	//删除操作的实现
	Delete(2,Ptrl); 
	printf("删除元素2后，看一下元素2的状态为：%d\n",Find(2,Ptrl));
	printf("删除元素2后，查看3所处的位置为：%d\n",Find(3,Ptrl));
	
	printf("Delete报错测试为：\n"); 
	Delete(0,Ptrl);
	printf("\nInsert报错测试为：\n"); 
	Insert(7,4,Ptrl);
	/*
	按照道理，由于只删除了第2个元素，因为第0个元素不存在，那么Ptrl->Last=2指向了第3个元素，
	由Insert()函数中if条件 i > Ptrl->Last+2，4 < Ptrl->Last=3 + 2 == 5,不满足该条件，那么
	就可以继续以下操作，插入元素，但是，实际上并没有插入，因位 Delete(0,Ptrl);语句执行了
	函数中的Ptrl->Last--; 尽管没有第0个元素，实际上Ptrl->Last=1指向了第2个元素，以下输出将验证
	Ptrl->Last的数值 
	 
	*/ 
	printf("\n验证Ptrl->Last所处的位置为：%d\n",Ptrl->Last);
 		
	return 0;
} 
