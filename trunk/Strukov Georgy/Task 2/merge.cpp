// task 8
#include <stdio.h>
#include <stdlib.h>
typedef struct List{
	List* next;
	int value;
} List;

int length1,length2;
List* head1=(List*)malloc(sizeof(List));
List* head2=(List*)malloc(sizeof(List));
int main(){
	printf("Enter length of first list: ");
	scanf("%d",&length1);
	printf("Enter elements of first list: ");
	List* current;
	head1->next=NULL;
	head2->next=NULL;
	current=head1;
	for(int i=0;i<length1;i++) {
		int newValue;
		scanf("%d",&newValue);
		List* newElement=(List*)malloc(sizeof(List));
		current->next=newElement;
		newElement->next=NULL;
		newElement->value=newValue;
		current=newElement;
	}
	printf("Enter length of second list: ");
	scanf("%d",&length2);
	printf("Enter elements of second list: ");
	current=head2;
	for(int i=0;i<length2;i++) {
		int newValue;
		scanf("%d",&newValue);
		List* newElement=(List*)malloc(sizeof(List));
		current->next=newElement;
		newElement->next=NULL;
		newElement->value=newValue;
		current=newElement;
	}
	List* head12=(List*)malloc(sizeof(List));
	head12->next=NULL;
	List* current1=head1->next;
	List* current2=head2->next;
	current=head12;
	while((current1!=NULL)||(current2!=NULL)){
		List* newElement=(List*)malloc(sizeof(List));
		List* addedElement;
		if(current1==NULL) {
			addedElement=current2;	
			current2=current2->next;
		} else if (current2==NULL) {
		    addedElement=current1;
		    current1=current1->next;
		} else {
		    if(current1->value < current2->value) {
		     	addedElement=current1;
		     	current1=current1->next;
		    } else {
				addedElement=current2;
				current2=current2->next;
		    }
		}
		current->next=newElement;
		current=newElement;
		current->value=addedElement->value;
		current->next=NULL;
		free(addedElement);
	}
	current=head12;
	while(current->next!=NULL) {
		List* toDelete=current;
	 	current=current->next;
	 	printf("%d ",current->value);
		free(toDelete);
	}
	return 0;
}