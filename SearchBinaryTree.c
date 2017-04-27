#include <stdlib.h>
#include "BinaryTree.h"

//
//void initSearchBinaryTree(BinaryTree* root, int* num, int size) {
//   int posi = 1;
//   BinaryNode* parent = NULL;
//   root->value = num[0];
//   root->left = NULL;
//   root->right = NULL;
//   while(posi <= size-1) {
//       parent = getInsertNode(root, num[posi]); 
//       BinaryNode* insert = (BinaryNode*)malloc(sizeof(BinaryNode));
//       insert->value = num[posi];
//       insert->left = NULL;
//       insert->right = NULL;
//       if(insert->value >= num[posi]) {
//            parent->right = insert;
//       }else {
//            parent->left = insert;
//       }
//       posi++;
//   } 
//}
//BinaryNode* getInsertNode(BinaryNode* root, int value) {
//   BinaryNode* cur = root;
//   BinaryNode* pre = cur;
//   while(cur != NULL) {
//       if(value >= cur->value) {
//            pre = cur;
//            cur = cur->right;
//       }else {
//            pre = cur;
//            cur = cur->left;
//       }
//   } 
//   return pre;
//}
