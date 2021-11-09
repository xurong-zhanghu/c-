#include <stdio.h>
#include <malloc.h>
typedef struct LNode *List;
struct LNode {
	int Data;
	List Next;
};
List PtrL;//����ָ��յĽ�� 

//��������
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
	
	//дһ��forѭ����������ʾ����
	List temp;
	temp = PtrL;
	for(int i = 1; i <= Length(PtrL); i++) {
		printf("��%d������Data = %d\n",i,temp->Data);
		temp = temp->Next;
	} 
	return 0;
}


//��������������
int Length(List PtrL) {
	List p = PtrL;
	int j = 0;
	while(p) {
		p = p->Next;
		j++;
	}
	return j;
} 

//�������в���ĳһ��Ԫ��
//�˴����ð�ֵ����
List Find(int x,List Ptrl) {
	List p = Ptrl;//����һ����ʱָ��ָ��������ͷ�ڵ� 
	while (p != NULL && p->Data != x) {
		p = p->Next;
	} 
	return p;
}

//����Ų���
List FindKth(int K, List Ptrl) {//K�����K��Ԫ�� 
	List p = Ptrl;
	int i = 1;//ע�⣺PtrL��ָ���ͷ,��ָ������ĵ�һ����Ҳ����ָ������ĵ�һ��Ԫ�أ�����i=1
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

 
//����--�ڵ�i-1���ڵ�����һ��ֵΪx���½ڵ�
/*�˲��뷽����һ��ȱ�㣺��main������ע�Ϳɼ������ڸ���������루��δ�ͷ�����룩ֻ���ڵ�һ�β������ɹ�--
ԭ�򣺸÷���û�ж�ͷ��������õĴ������ڸ������ⷽ����ÿ�η��صĶ���ͷ����㣬��ÿ�ε���Insert(3,1,PtrL);
���еĲ���Ptrl����ָ���ͷ���ڵ��ָ�룬���ǵ���2�β����Ժ�û�н���PtrL = Insert(2,1,PtrL);�ò�����Ҳ����
û�ж������ͷ�����PtrL�ĸ��£�ͷ������ָ�����ĵ�һ��Ԫ�أ���ô��Ȼ�޷����в������������취���£����߲���
�����ʦ����һ����Ʋ���ķ����� ������ͷ��PtrL������ 
 	PtrL = Insert(1,1,PtrL);
	PtrL = Insert(2,1,PtrL); 
	PtrL = Insert(3,1,PtrL); 
	PtrL = Insert(4,1,PtrL); 
	PtrL = Insert(5,1,PtrL); 
*/
List Insert(int x,int i,List PtrL) {//Ҳ����˵�ڵ�i���ڵ�֮��������½ڵ� 
	List p,s;
	if(i == 1) {
		s=(List)malloc(sizeof(struct LNode));//Ϊ�½ڵ㿪��һ���ڴ� 
		s->Data = x;//�Ѵ������ֵ��ֵ�����½ڵ�ṹ���еı���Data 
		s->Next = PtrL;//��Ϊi����1��Ҳ����˵�ڵ�һ���ڵ㴦����ýڵ㣬Ҳ����˵���²���Ľڵ�����ͷ�ڵ� 
		return s;
	}
	p = FindKth(i-1,PtrL);//�ҵ�������ڵ����һ���ڵ� 
	if(p == NULL) {//��i-1���ڵ㲻���ڣ����ܲ��� 
		printf("����i��");
		return NULL; 
	}else {
		s = (List)malloc(sizeof(struct LNode));//���룬��װ�ڵ� 
		s->Data = x;
		s->Next = p->Next;
		p->Next = s;
		return PtrL; 
	}
} 


//ɾ����i����� 
List Delect(int i, List PtrL) {
	List p,s;
	if(i == 1) {
		s = PtrL;//��s���ָ��ͷ��㣬���ں����ͷ��ڴ���� 
		if (PtrL != NULL) {
			PtrL = PtrL->Next; 
		} else {
			return NULL;		
		}
		free(s);
		return PtrL;
	}
	p = FindKth(i-1, PtrL);//�ҵ���ɾ��������һ����� 
	if(p == NULL) {
		printf("��%d����㲻����",i-1);
		return NULL;
	} else if (p->Next == NULL) {
		printf("��%d����㲻����",i);
		return NULL;
	} else {
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	} 
}
