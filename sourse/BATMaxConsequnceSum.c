#include <stdio.h>

int MaxConsequnceSum(int arr[],int n);
/*
������������������{ -2, 11, -4, 13, -5, -2 } ���������֮�к� 
��������{ 11, -4, 13 }�����ĺ�20��
˼·��
��һ������洢�����У���2��forѭ������һ��forѭ������ȷ��һ�����е�����ߵ�Ԫ�أ���2��forѭ�����ڴ�ȷ����Ԫ�ؿ�ʼ
���ҽ��б������ҵ��Ը�Ԫ��ȷ���������������кͣ�����ҵ��أ�ֻ��Ҫ����2��������һ���������ڽ����ۼӲ�������һ��
������¼������к� 
��ƣ�
1.
int MaxConsequnceSum(int arr[],int n)//����һ�����飬�Լ�����Ĵ�С 
1-1��

int maxSum = 0;//��¼������к�	 
for(int i = 0; i < n; i++){
    int sum = 0;//���ڽ����ۼӲ���
    for(int j = i; j < n; j++){
         sum += arr[j];
		 if(sum > maxSum)
		 		maxSum = sum; 
	}
}
return maxSum; 
*/
int main(void) {
	int k;
	scanf("%d", &k);
	int arr[k];
	for(int i = 0; i < k; i++){
		scanf("%d",&arr[i]);
	}
	
//	int arr[] = { -2, 11, -4, 13, -5, -2 };
	int maxSum = MaxConsequnceSum(arr,k);
	printf("%d\n",maxSum);
	return 0;
}
int MaxConsequnceSum(int arr[],int n) {	
	int flag = 0;//�ж��Ƿ�ȫΪ������ȫΪ������ֱ�ӷ���0 
	for(int z = 0; z < n; z++) {
		if(arr[z] > 0){
			flag = 0;	  
			break;
		}else {
			flag = 1;
		} 
	}
	if(flag == 1) {//�ж��Ƿ�ȫΪ������ȫΪ������ֱ�ӷ���0
		return 0; 
	}
	
	int maxSum = 0;//��¼������к�	 
	for(int i = 0; i < n; i++){
		int sum = 0;//���ڽ����ۼӲ���
		for(int j = i; j < n; j++){
		     sum += arr[j];
			 if(sum > maxSum)
	 		 		maxSum = sum; 
		}
	}
	return maxSum; 
}
