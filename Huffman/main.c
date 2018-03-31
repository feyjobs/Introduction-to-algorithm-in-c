/**
 * Huffman Code 
 * Huffman Tree
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Huffman.h"


int main()
{
    char str[500];
    gets(str);

    int len = strlen(str);
    char sortStr[500];

    strcpy(sortStr,str);
    sort(sortStr,len);

    struct Node* arrLeaf[500];
    int charCount = initArrLeaf(arrLeaf,sortStr,len);
    
    struct Node* root = generateHuffmanTree(arrLeaf,charCount);

    int huffmanCode[1024];
    int HuffmanCodeLen = encodeStringWithHuffmanCode(arrLeaf,charCount,str,len,huffmanCode);

    calculateConversionPercent(arrLeaf,charCount,len);

    decodeHuffmanCodeToString(huffmanCode,HuffmanCodeLen,root);
    return 0;
}

void formateTreeCode(struct Node** root,int side,int size){
    if((*root) != NULL){
        int i = 0;
        for(;i < size;i++){
            (*root)->code[i] = (*root)->parent->code[i];
        }
        (*root)->code[size] = side;
        (*root)->codeLen = size+1;
        formateTreeCode(&((*root)->left),0,size+1);
        formateTreeCode(&((*root)->right),1,size+1);
    }
}

void printTree(struct Node* root){
    if(root != NULL){
        if(root->left == NULL){
            printf("character:%c count:%d Huffman Code:",root->c,root->power);
            for(int j = 0;j < root->codeLen;j++){
                printf("%d",root->code[j]);
            }
			printf("\n");
        }
        printTree(root->left);
        printTree(root->right);
    }

}

void sort(char* str,const int size){
    char tmp;
    int i = 0,j = 0;
    for(;i < size;i++){
        for(j = i+1;j < size;j++){
            if(str[i] <= str[j]){
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}

int initArrLeaf(struct Node** arrLeaf,const char* sortStr,const int len){
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    int charCount = 0;
    int i = 0,j = 0;
    cur->c = sortStr[0];
    cur->power = 1;
    cur->left = cur->right = cur->parent = NULL;
    cur->next = NULL;
    arrLeaf[charCount] = cur;
    for(i = 1;i < len;i++){
        if(sortStr[i] == cur->c){
            cur->power++;
        }else{
            charCount++;
            cur = (struct Node*)malloc(sizeof(struct Node));
            cur->c = sortStr[i];
            cur->power = 1;
            cur->left = cur->right = cur->parent = NULL;
			cur->next = NULL;
            arrLeaf[charCount] = cur;
        }
    }

    struct Node* tmpNode;
    for(i = 0;i <= charCount;i++){
        for(j = i+1;j <= charCount;j++){
            if(arrLeaf[i]->power > arrLeaf[j]->power){
                tmpNode = arrLeaf[i];
                arrLeaf[i] = arrLeaf[j];
                arrLeaf[j] = tmpNode;
            }
        }
    }

    for(i = 0;i < charCount;i++){
        arrLeaf[i]->next = arrLeaf[i+1];
    }

    return charCount;
}

struct Node* generateHuffmanTree(struct Node** arrLeaf,int charCount){
    struct Node* head = arrLeaf[0];
    struct Node* root = NULL;
    for(int i=0;i < charCount;i++){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->left = head;
        newNode->right = head->next;
        newNode->next = NULL;
        newNode->c = '\0';
        head->parent = newNode;
        head->next->parent = newNode;
        newNode->power = head->power + head->next->power;
        head = head->next->next;
        struct Node* curNode = head;
        struct Node* preNode = NULL;
        while(curNode != NULL){
            if(curNode->power < newNode->power){
                if(curNode->next == NULL){
                    curNode->next = newNode;
                    break;
                }else{
                    preNode = curNode;
                    curNode = curNode->next;
                }
            }else{
                if(preNode != NULL){
                    preNode->next = newNode;
                }else{
                    head = newNode;
                }
                newNode->next = curNode;
                break;
            }
        }
        root = newNode;
    }
    formateTreeCode(&(root->left),0,0);
    formateTreeCode(&(root->right),1,0);
    printTree(root);
    return root;
}

 int encodeStringWithHuffmanCode(struct Node** arrLeaf,int charCount,char* str,int len,int* huffmanCode){
    printf("The huffman code of the string is:");
    int n = 0;
    for(int i = 0; i < len;i++){
        for(int j = 0;j <= charCount;j++){
            if(str[i] == arrLeaf[j]->c){
                for(int m = 0;m < arrLeaf[j]->codeLen;m++){
                    printf("%d",arrLeaf[j]->code[m]);
					huffmanCode[n] = arrLeaf[j]->code[m];
					n++;
                }
            }
        }
    }
    printf("\n");
    return n;

 }

void calculateConversionPercent(struct Node** arrLeaf,int charCount,int len){
    int normalSize = 0;
    int sum = 0;
    int a = len;
    while(a != 0){
        a = a/2;
        normalSize++;
    }

    for(int i = 0;i <= charCount;i++){
        sum += arrLeaf[i]->codeLen*arrLeaf[i]->power;
    }
    printf("Conversion Percent is %f\n",(float)(sum)/(normalSize*len));
}

void decodeHuffmanCodeToString(int* huffmanCode,int HuffmanCodeLen,struct Node* root){
	struct Node* iter = root;
	printf("The source string of the huffman code is:");
	for (int i = 0; i <= HuffmanCodeLen;i++) {
		if (iter->c != '\0') {
			printf("%c", iter->c);
			iter = root;
		}
		if (huffmanCode[i] == 0) {
			iter = iter->left;
		}
		else {
			iter = iter->right;
		}
	}
	printf("\n");
}








