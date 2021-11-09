#include <stdio.h>
#include <malloc.h>
/*��������ģ�����Ա�*/
#define MAXSIZE 20
typedef struct LNode * List;//����һ��ָ��LNode�ṹ��ָ�� 
struct LNode{
	int Data[MAXSIZE];//����һ��int���͵����� 
	int Last;//ָ���������һ��Ԫ�ص��±�,���һ��Ԫ�ز���������������һ��λ��
	 
}; 
//struct LNode L;
List Ptrl;//����һ��ָ���ָ��ṹ��ı��� 

//�����յ�˳��� 
List MakeEmpty(){
	List Ptrl;//����һ��ָ���ָ��ṹ��ı���  
	Ptrl = (List)malloc(sizeof(struct LNode));//Ϊ�ṹ�����ͷ���һ���ڴ� 
	Ptrl->Last = -1;//���������û��Ԫ�أ��ͽ�-ָ���������һ��Ԫ�ص��±�Lastָ��-1�������  
	return Ptrl;
}

//�������в���һ��Ԫ��
int Find(int x, List Ptrl) {//������Ptrl�в���һ��x 
	int i = 0;
	while(i <= Ptrl->Last && Ptrl->Data[i] != x)
		   i++;
	if (i > Ptrl->Last)
	   return -1;//����±�������һ��Ԫ�ص��±꣬˵�������Ա��в�û�и�Ԫ�أ�����-1 
	else
		return i;//�ҵ�xԪ������Ӧ���±�	   
} 

//����
//ǰ����������i(1 <= i <= n+1)��λ���ϲ���һ��ֵΪX����Ԫ�أ���i��λ��Ҳ����i - 1 
void Insert(int x,int i,List Ptrl) {//7,11,Ptrl     
	int j;
	if(Ptrl->Last == MAXSIZE-1) {//ָ�����һ��Ԫ�ص��±�Lastָ����MAXSIZE-1��˵�������� 
		printf("����");
		return; 
	}
	if(i < 1 || i > Ptrl->Last+2) {
	/*
	  *****
	  ����λ�õĺϷ���֮˵��(2021��11��9��)��
	  i < 1����Ϊʱģ������ʵ�ֵĲ��룬i����ȡ����1��Ҳ���ǿ������±�1-1 = 0������Ԫ�أ�Ҳ����˵��Ԫ�ز���˳����ͷ����ԭ��ͷ��Ԫ��������һ��
	  i > Ptrl->Last+2: i��ʾ���ǵ�i��Ԫ�أ�Ptrl->Last+1��ʾ��n(������������n��Ԫ��)��Ԫ�أ�i����ȡ��Ptrl->Last+2��Ҳ����˵���������һ��Ԫ�ص�
	  ��һ��λ�ò���һ��Ԫ�أ���Ȼ��Ҳ�ǺϺ�������Ƶġ� 
	*/  
        printf("λ�ò��Ϸ�");
        return; 
	} 
	for (j = Ptrl->Last; j >= i-1;j--) {//���±�ָ��Last 
		Ptrl->Data[j+1] = Ptrl->Data[j];//��Ԫ�شӺ�����һ��λ�ã������һ��Ԫ�ؿ�ʼ���Ӷ���Data[i-1]��Ӧλ�ÿճ��� 
	}
	Ptrl->Data[i-1] = x;
	Ptrl->Last++;//��Ȼ��Lastָ�����һ��Ԫ�� 
} 

//ɾ��������ʵ��,ɾ����i��Ԫ�أ�Ҳ����ɾ��i-1�±�����Ӧ��Ԫ�� 
void Delete(int i, List Ptrl) {
	int j;
	if(i < 1 || i >Ptrl->Last + 1) {//���ɾ��λ�õĺϷ��ԣ�i����ȡ��Ptrl->Last + 1��ͬ���ʾɾ�������һ��Ԫ�أ�2021��11��9�գ� 
		printf("�����ڵ�%d��Ԫ��",i);
	}
	for (j = i; j <= Ptrl->Last; j++) {
		Ptrl->Data[j-1] = Ptrl->Data[j];//����벻ͬ���ò����ǽ�Ԫ�ش���Ҫɾ����λ�������ǰ�� 
	}
	Ptrl->Last--; 
} 
int main(void) {
	//����˳��� 
	Ptrl = MakeEmpty();
 
	//����--��i(1 <= i <= n+1)��λ���ϲ���һ��ֵΪX����Ԫ�أ���i��λ��Ҳ����i - 1 
	Insert(1,1,Ptrl);//ע�⣺ÿһ�β��룬Ptrl->Last��������һλ 
	Insert(2,2,Ptrl);
	Insert(3,3,Ptrl);
	Insert(4,4,Ptrl);
	
	//��������������Ԫ��
	printf("%d\n",Find(1,Ptrl)); 
	printf("%d\n",Find(2,Ptrl));
	printf("%d\n",Find(3,Ptrl));
	printf("%d\n",Find(4,Ptrl));
 		
	//ɾ��������ʵ��
	Delete(2,Ptrl); 
	printf("ɾ��Ԫ��2�󣬿�һ��Ԫ��2��״̬Ϊ��%d\n",Find(2,Ptrl));
	printf("ɾ��Ԫ��2�󣬲鿴3������λ��Ϊ��%d\n",Find(3,Ptrl));
	
	printf("Delete�������Ϊ��\n"); 
	Delete(0,Ptrl);
	printf("\nInsert�������Ϊ��\n"); 
	Insert(7,4,Ptrl);
	/*
	���յ�������ֻɾ���˵�2��Ԫ�أ���Ϊ��0��Ԫ�ز����ڣ���ôPtrl->Last=2ָ���˵�3��Ԫ�أ�
	��Insert()������if���� i > Ptrl->Last+2��4 < Ptrl->Last=3 + 2 == 5,���������������ô
	�Ϳ��Լ������²���������Ԫ�أ����ǣ�ʵ���ϲ�û�в��룬��λ Delete(0,Ptrl);���ִ����
	�����е�Ptrl->Last--; ����û�е�0��Ԫ�أ�ʵ����Ptrl->Last=1ָ���˵�2��Ԫ�أ������������֤
	Ptrl->Last����ֵ 
	 
	*/ 
	printf("\n��֤Ptrl->Last������λ��Ϊ��%d\n",Ptrl->Last);
 		
	return 0;
} 
