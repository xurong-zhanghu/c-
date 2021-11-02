#include <stdio.h>
int main(void) {
	
} 

//二叉搜索树的查找功能
Position Find(int x,BinTree BST) {
	if (!BST) {
		return NULL;
	}
	if (x > BST->Data) {
		return Find(x,BST->Right);
	} else if (x < BST->Left) {
        return Find(x,BST->Left);  
	} else {
		return BST;
	}
} 
