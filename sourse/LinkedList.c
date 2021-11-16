#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>//����false,��true 
typedef struct LNode *PtrToLNode;
struct LNode {
    int Data;//����д洢������ 
    PtrToLNode Next;//����ָ����һ����� 
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position p;//����һ����Ҫ�����λ��
List L;

/* ���� */
#define ERROR  NULL 
 
Position Find( List L, int X )
{
    Position p = L; /* pָ��L�ĵ�1����� Ҳ����˵������������Ϊʲô������ֱ����L�أ�ԭ����ͷ��㲻���Ըı�*/

    while ( p && p->Data!=X )//���������ǿգ�������������ݲ�����X��ʱ�򣬽�������� 
        p = p->Next;

    /* ������������ return p;�滻 */
    if ( p )
        return p;
    else
        return ERROR;
}

/* ��ͷ���Ĳ��� */
/*ע��:�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P��������ָ�룬��P֮ǰ�����½�� */
bool Insert( List L, int X, Position P )//Position P������Ҫ�����λ�� 
{ 
  	 /* ����Ĭ��L��ͷ��� */
    Position tmp, pre;

    /* ����P��ǰһ����� */        
    for ( pre=L; pre&&pre->Next != P; pre = pre->Next); //��ͼѰ��P��ǰһ�����           
    if ( pre==NULL ) { /* P��ָ�Ľ�㲻��L�� */
        printf("����λ�ò�������\n");
        return false;
    }
    else { /* �ҵ���P��ǰһ�����pre */
        /* ��Pǰ�����½�� */
        tmp = (Position)malloc(sizeof(struct LNode)); /* ���롢��װ��� */
        tmp->Data = X; 
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}

/* ��ͷ����ɾ�� */
/*ע��:��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P����ɾ�����ָ�� */
bool Delete( List L, Position P )
{ /* ����Ĭ��L��ͷ��� */
    Position pre;

    /* ����P��ǰһ����� */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next );////��ͼѰ��P��ǰһ�����            
    if ( pre==NULL || P==NULL) { /* P��ָ�Ľ�㲻��L�� */
        printf("ɾ��λ�ò�������\n");
        return false;
    }
    else { /* �ҵ���P��ǰһ�����pre */
        /* ��Pλ�õĽ��ɾ�� */
        pre->Next = P->Next;
        free(P);
        return true;
    }
}

//����������ĳ��� 
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
	//����һ���������ڲ���,��Ȼ�ò�����ȱ�ݣ������ο� 
	L = (List)malloc(sizeof(struct LNode));
	L->Data = 1;
	L->Next = NULL; 
	
	//bool Insert( List L, int X, Position P )//Position P������Ҫ�����λ�� 
	Insert(L,2,NULL);
	Insert(L,3,NULL); 
	Insert(L,4,NULL); 
	Insert(L,5,NULL); 
	Insert(L,6,NULL); 
	

	List temp;//ע����Ҫ����һ��temp��ʱ����ָ��ͷ��㣬��Ϊͷ���L�ǲ������ı�
	temp = L;
	
	int length = Length(temp);//����������ĳ���
	//дһ��forѭ����������ʾ���� 
	for(int i = 1; i <= length; i++) {
		printf("��%d���������Ϊ��%d\n",i,temp->Data);//ע����Ҫ����һ��temp��ʱ����ָ��ͷ��㣬��Ϊͷ���L�ǲ������ı� 
		temp = temp->Next;
	} 
	return 0;
}




