#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxData 10000
#define ERROR -1 /* �����ʶӦ���ݾ����������Ϊ���в����ܳ��ֵ�Ԫ��ֵ */

typedef struct HeapStruct *MaxHeap;
typedef int ElementType;

struct HeapStruct {
	ElementType *Elements;//�洢��Ԫ�ص����� 
	int Size;//�ѵĵ�ǰԪ�صĸ��� 
	int Capacity;//�ѵ�������� 
}; 

//��������
bool IsEmpty(MaxHeap H);
bool IsFull(MaxHeap H);

//��������ΪMaxSize�ĿյĶ�
MaxHeap Creat(int MaxSize);
//�ѵĲ������,��Ԫ�ز��� ����H�У�����H->Elements[0]�Ѿ�����Ϊ�ڱ� 
void Insert(MaxHeap H, ElementType item); 
//��������ȡ����ֵΪ����Ԫ��,��ɾ���ý��
ElementType DeleteMax (MaxHeap H);

//��������
/**
	���ˣ��ú����ǽ�H����H->Elements[p]Ϊ�����Ӷѵ���Ϊ���� 
*/
void PercDown(MaxHeap H, int p);
//����PercDown(MaxHeap H, int p)�Զѽ��е�������֤���ѵ�������
void BuildHeap (MaxHeap H);

int main(void) {
	//------------��һ�����Ƕ�BuildHeap (MaxHeap H)�����Ĳ���----��������Ϊ��79 66 43 83 30 87 38 55 91 72 49 9 
	printf("--------��һ�����Ƕ�BuildHeap (MaxHeap H)�����Ĳ���----��������Ϊ��79 66 43 83 30 87 38 55 91 72 49 9----------- \n\n");
	//��������Ϊ12(�洢���ݵ����鵥Ԫ)�Ķ�
	printf("��������Ϊ13(�洢���ݵ����鵥Ԫ)�Ķѣ���������Ϊ12����д��13��Ϊ�˺������Insert(MaxHeap H, ElementType item)������׼��\n");
	MaxHeap H; 
	H = Creat(13);
	
	//������в�������
	printf("������в�������:\n");
	for (int n = 1; n <= 12; n++) {
		scanf("%d",&H->Elements[n]); 
	}
	
	//���������������
	H->Size = 12;
	H->Capacity = 13;
	printf("���������������:\n");
	BuildHeap (H);
	
	//��ʾ�����ṹ�е�����˳��
	printf("��ʾ�����ṹ�е�����˳��:\n");
	for(int i = 1; i <= 12; i++) {
		printf("%d	",H->Elements[i]);
	} 
	
	//-----��2�����ǲ���Insert(MaxHeap H, ElementType item)������������������Ϊ92--------
	printf("\n\n-----��2�����ǲ���Insert(MaxHeap H, ElementType item)������������������Ϊ100--------\n\n");
	Insert(H, 100); 
	printf("��ʾ�����ṹ�е�����˳��:\n");
	for(int i = 1; i <= 13; i++) {
		printf("%d	",H->Elements[i]);
	} 
	
	//----��3�����Ƕ�--��������ȡ����ֵΪ����Ԫ��,��ɾ���ý��--����----
	printf("\n\n---��3�����Ƕ�--��������ȡ����ֵΪ����Ԫ��,��ɾ���ý��--����----\n\n");
	printf("ɾ����������Ϊ��%d\n",DeleteMax (H));
	printf("��ʾ�����ṹ�е�����˳��:\n");
	for(int i = 1; i <= 12; i++) {
		printf("%d	",H->Elements[i]);
	} 
	return 0;
}

//�ѿ��ж�
bool IsEmpty(MaxHeap H) {
	return (H->Size == 0);
}
//����
bool IsFull(MaxHeap H) {
	return (H->Size == H->Capacity);
}
//��������ΪMaxSize�ĿյĶ�
MaxHeap Creat(int MaxSize) {
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));//Ϊ�öѷ����ڴ� 
	H->Elements = (ElementType*)malloc((MaxSize+1)*sizeof(ElementType));
	//Ϊ������������ڴ�,ΪʲôҪ��1�أ���Ϊ�����±�Ϊ0��Ϊ�ڱ���MaxSize��ʾ����ɴ洢Ԫ�صĸ������������ڱ���ռ�洢��Ԫ�� 
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;//�����ڱ����ڱ�Ϊ���ڶ������п��ܵ�ֵ�������Ժ�������
	return H; 
} 

//�ѵĲ������,��Ԫ�ز��� ����H�У�����H->Elements[0]�Ѿ�����Ϊ�ڱ� 
void Insert(MaxHeap H, ElementType item) {
	int i;
	if (IsFull(H)) {
		printf("��������");
		return;		 
	}
	i = ++H->Size;//iָ��������е����һ��Ԫ�ص�λ�� 
	for ( ; H->Elements[i/2] < item; i /= 2) {//���������ĸ����С�ڲ����� 
		H->Elements[i] = H->Elements[i/2];//��������ֵ�����ý�㣬Ҳ���ǽ���С����ֵ���� 
	}
	H->Elements[i] = item;//ȷ������λ�ã�ע���ڱ��ڴ˴������� 
} 

//��������ȡ����ֵΪ����Ԫ��,��ɾ���ý��
ElementType DeleteMax (MaxHeap H) {
	int Parent,Child;//���ӽ���븸�������Ӧ���±� 
	ElementType MaxItem,Temp;
	if (IsEmpty(H)) {
		printf("����Ϊ��");
		return ERROR;//��Ȼ��������ݿ���Ϊ-1�����ǵ�����"����Ϊ��"��˵��ȷʵ�Ƕѿ�	 
	}
	MaxItem = H->Elements[1];//������洢�ģ�Ҫɾ�����Ԫ������Ӧ�Ľ�㲢���ý�����洢��ֵ���أ���ֵ�����ñ��������ڷ��� 
	Temp = H->Elements[H->Size--];//����һ����ʱ�������ڴ洢��ȫ�����������һ��Ԫ�� 
	for (Parent = 1; Parent*2 <= H->Size; Parent = Child) {//Parent*2 <= H->Size���ж��Ƿ�������� 
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child+1])) {
			/**
				���Child == H->Size��˵��ֻ������ӣ�û���Ҷ��ӣ���(H->Elements[Child] < H->Elements[Child+1])����������������� 
			*/
			Child++;//Childָ�������ӽ��Ľϴ��� 
		} 
		if (Temp >= H->Elements[Child]) {
			break;
		} else {
			H->Elements[Parent] = H->Elements[Child];
			/**
				��tempԪ�����²��ƶ�����ʱĩβ��Ԫ�ز�û�������Ԫ������λ�ã����ǿ��Լ����ڴ�λ�ý������ 
			*/ 
		}
	}
	H->Elements[Parent] = Temp; 
	return MaxItem;
} 

//��������
/**
	���ˣ��ú����ǽ�H����H->Elements[p]Ϊ�����Ӷѵ���Ϊ���� 
*/
void PercDown(MaxHeap H, int p) {
	int Parent,Child;//�������ڲ����ѵĸ��ӽ��
	ElementType X;
	X = H->Elements[p];//ȡ��������ŵ�ֵ
	for ( Parent = p; Parent*2 <= H->Size;Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1])) {
			Child++;//��Childָ�������ӽ��Ľϴ��� 
		}
		if (X >= H->Elements[Child]) {
			break;//�ҵ��˺��ʵ�λ�� 
		} else {
			H->Elements[Parent] = H->Elements[Child];
		} 
	} 
	H->Elements[Parent] = X;
} 

//����PercDown(MaxHeap H, int p)�Զѽ��е�������֤���ѵ�������
void BuildHeap (MaxHeap H) {
	//��������H->Size��Ԫ���Ѿ�����H->Elements[]��
	int i;
	//�����һ�����ĸ��ڵ㿪ʼ����������PercDown(MaxHeap H, int p)����
	for (i = H->Size/2;i >0; i--) {
		PercDown(H,i);
	} 
} 

