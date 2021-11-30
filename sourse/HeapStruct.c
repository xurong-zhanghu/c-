#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxData 10000
#define ERROR -1 /* 错误标识应根据具体情况定义为堆中不可能出现的元素值 */

typedef struct HeapStruct *MaxHeap;
typedef int ElementType;

struct HeapStruct {
	ElementType *Elements;//存储堆元素的数组 
	int Size;//堆的当前元素的个数 
	int Capacity;//堆的最大容量 
}; 

//函数声明
bool IsEmpty(MaxHeap H);
bool IsFull(MaxHeap H);

//创建容量为MaxSize的空的堆
MaxHeap Creat(int MaxSize);
//堆的插入操作,将元素插入 最大堆H中，其中H->Elements[0]已经定义为哨兵 
void Insert(MaxHeap H, ElementType item); 
//从最大堆中取出键值为最大的元素,并删除该结点
ElementType DeleteMax (MaxHeap H);

//建造最大堆
/**
	下滤：该函数是将H中以H->Elements[p]为根的子堆调整为最大堆 
*/
void PercDown(MaxHeap H, int p);
//借用PercDown(MaxHeap H, int p)对堆进行调整，保证最大堆的有序性
void BuildHeap (MaxHeap H);

int main(void) {
	//------------第一部分是对BuildHeap (MaxHeap H)函数的测试----测试数据为：79 66 43 83 30 87 38 55 91 72 49 9 
	printf("--------第一部分是对BuildHeap (MaxHeap H)函数的测试----测试数据为：79 66 43 83 30 87 38 55 91 72 49 9----------- \n\n");
	//创建容量为12(存储数据的数组单元)的堆
	printf("创建容量为13(存储数据的数组单元)的堆，测试数据为12个，写成13是为了后面测试Insert(MaxHeap H, ElementType item)函数做准备\n");
	MaxHeap H; 
	H = Creat(13);
	
	//向该树中插入数据
	printf("向该树中插入数据:\n");
	for (int n = 1; n <= 12; n++) {
		scanf("%d",&H->Elements[n]); 
	}
	
	//将该树构造成最大堆
	H->Size = 12;
	H->Capacity = 13;
	printf("将该树构造成最大堆:\n");
	BuildHeap (H);
	
	//显示该树结构中的数据顺序
	printf("显示该树结构中的数据顺序:\n");
	for(int i = 1; i <= 12; i++) {
		printf("%d	",H->Elements[i]);
	} 
	
	//-----第2部分是测试Insert(MaxHeap H, ElementType item)函数，插入数据设置为92--------
	printf("\n\n-----第2部分是测试Insert(MaxHeap H, ElementType item)函数，插入数据设置为100--------\n\n");
	Insert(H, 100); 
	printf("显示该树结构中的数据顺序:\n");
	for(int i = 1; i <= 13; i++) {
		printf("%d	",H->Elements[i]);
	} 
	
	//----第3部分是对--从最大堆中取出键值为最大的元素,并删除该结点--测试----
	printf("\n\n---第3部分是对--从最大堆中取出键值为最大的元素,并删除该结点--测试----\n\n");
	printf("删除结点的数据为：%d\n",DeleteMax (H));
	printf("显示该树结构中的数据顺序:\n");
	for(int i = 1; i <= 12; i++) {
		printf("%d	",H->Elements[i]);
	} 
	return 0;
}

//堆空判断
bool IsEmpty(MaxHeap H) {
	return (H->Size == 0);
}
//堆满
bool IsFull(MaxHeap H) {
	return (H->Size == H->Capacity);
}
//创建容量为MaxSize的空的堆
MaxHeap Creat(int MaxSize) {
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));//为该堆分配内存 
	H->Elements = (ElementType*)malloc((MaxSize+1)*sizeof(ElementType));
	//为堆中数组分配内存,为什么要加1呢，因为数组下标为0处为哨兵，MaxSize表示数组可存储元素的个数（不包括哨兵所占存储单元） 
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;//定义哨兵：哨兵为大于堆中所有可能的值，便于以后更快操作
	return H; 
} 

//堆的插入操作,将元素插入 最大堆H中，其中H->Elements[0]已经定义为哨兵 
void Insert(MaxHeap H, ElementType item) {
	int i;
	if (IsFull(H)) {
		printf("最大堆已满");
		return;		 
	}
	i = ++H->Size;//i指向插入后堆中的最后一个元素的位置 
	for ( ; H->Elements[i/2] < item; i /= 2) {//如果插入结点的父结点小于插入结点 
		H->Elements[i] = H->Elements[i/2];//将父结点的值赋给该结点，也就是将较小结点的值下移 
	}
	H->Elements[i] = item;//确定结点的位置，注意哨兵在此处的运用 
} 

//从最大堆中取出键值为最大的元素,并删除该结点
ElementType DeleteMax (MaxHeap H) {
	int Parent,Child;//孩子结点与父结点所对应的下标 
	ElementType MaxItem,Temp;
	if (IsEmpty(H)) {
		printf("最大堆为空");
		return ERROR;//虽然存入的数据可能为-1，但是但出现"最大堆为空"，说明确实是堆空	 
	}
	MaxItem = H->Elements[1];//用数组存储的，要删除最大元素所对应的结点并将该结点所存储的值返回，将值赋给该变量，便于返回 
	Temp = H->Elements[H->Size--];//建立一个临时变量用于存储完全二叉树的最后一个元素 
	for (Parent = 1; Parent*2 <= H->Size; Parent = Child) {//Parent*2 <= H->Size：判断是否有左儿子 
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child+1])) {
			/**
				如果Child == H->Size，说明只有左儿子，没有右儿子，那(H->Elements[Child] < H->Elements[Child+1])该条件就无需进行了 
			*/
			Child++;//Child指向左右子结点的较大者 
		} 
		if (Temp >= H->Elements[Child]) {
			break;
		} else {
			H->Elements[Parent] = H->Elements[Child];
			/**
				将temp元素向下层移动，此时末尾的元素并没有在最大元素所在位置，但是可以假设在此位置进行理解 
			*/ 
		}
	}
	H->Elements[Parent] = Temp; 
	return MaxItem;
} 

//建造最大堆
/**
	下滤：该函数是将H中以H->Elements[p]为根的子堆调整为最大堆 
*/
void PercDown(MaxHeap H, int p) {
	int Parent,Child;//构造用于操作堆的父子结点
	ElementType X;
	X = H->Elements[p];//取出根结点存放的值
	for ( Parent = p; Parent*2 <= H->Size;Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1])) {
			Child++;//将Child指向左右子结点的较大者 
		}
		if (X >= H->Elements[Child]) {
			break;//找到了合适的位置 
		} else {
			H->Elements[Parent] = H->Elements[Child];
		} 
	} 
	H->Elements[Parent] = X;
} 

//借用PercDown(MaxHeap H, int p)对堆进行调整，保证最大堆的有序性
void BuildHeap (MaxHeap H) {
	//假设所有H->Size个元素已经存在H->Elements[]中
	int i;
	//从最后一个结点的父节点开始，遍历调用PercDown(MaxHeap H, int p)函数
	for (i = H->Size/2;i >0; i--) {
		PercDown(H,i);
	} 
} 

