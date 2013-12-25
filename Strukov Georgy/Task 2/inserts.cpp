//task 7
#include <stdio.h>
#include <stdlib.h>
typedef struct List{
	int value;
	List* left;
	List* right;
} List;
List* head=(List*)malloc(sizeof(List));
int length;
int main(){
 	printf("Enter length of list: ");
 	scanf("%d",&length);
 	printf("Enter elements: ");
 	List* current=head;
 	head->right=NULL;
 	head->left=NULL;
 	for(int i=0;i<length;i++) {
 		int newValue;
 		scanf("%d",&newValue);
 		List* newElement=(List*)malloc(sizeof(List));
 		current->right=newElement;
 		newElement->left=current;
 		newElement->right=NULL;
 		newElement->value=newValue;
 		current=newElement;	
 	}
 	List* sortedList=(List*)malloc(sizeof(List));
 	sortedList->right=NULL;
 	sortedList->left=NULL;
 	current=head;
 	while(current->right!=NULL) {
 	 	current=current->right;
 	 	int newValue=current->value;
 	 	List* current2=sortedList;
 	 	while((current2->right!=NULL)&&((current2->right)->value < newValue)) {
 	 	 	current2=current2->right;
 	 	}
 	 	List* newElement=(List*)malloc(sizeof(List));
 	 	newElement->value=newValue;
 	 	newElement->right=current2->right;
 	 	newElement->left=current2;
 	 	if(current2->right!=NULL) {
 	 		current2->right->left=newElement;
 	 	}
 	 	current2->right=newElement;
 	}
 	current=sortedList;
 	while(current->right!=NULL) {
 	 	List* toDelete=current;
 	 	current=current->right;
 	 	printf("%d ",current->value);
 	 	free(toDelete);
 	}
 	free(current);
 	return 0;
}