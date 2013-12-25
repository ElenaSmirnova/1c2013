//	tasks 1,2,3,5,6,9,10
#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 1000
typedef struct List{
  	int value;
  	List* next;
} List;
List* head;

void reverseList(List* element){
	if(element->next!=NULL) {
		reverseList(element->next);
    	(element->next)->next=element;
    }
}

void freeList(List* element){
	if(element->next!=NULL) {
	 	freeList(element->next);
	}
	free(element);
}

int main(){
	int length=-1;
	printf("Enter length of list (from 1 to %d): ",MAXLENGTH);
	while(length<1||length>MAXLENGTH) {
		scanf("%d",&length);
		if(length<1||length>MAXLENGTH) {
			printf("Unavaliable length, try again: ");
		}
	}
	printf("Enter elements of list:\n");     
	head = (List*)malloc(sizeof(List));
	head->next=NULL;
	List* current;// = (List*)malloc(sizeof(List));
	current=head;
	while(length--) {
	 	int newValue;
	 	scanf("%d",&newValue);
	 	List* newElement = (List*) malloc(sizeof(List));
	 	current->next=newElement;
	 	current=newElement;
	 	current->value=newValue;
	 	current->next=NULL;
	}
	char command=0;
	printf("p - print list\n");
	printf("f - return value by number\n");
	printf("l - count length of list\n");
	printf("r - reverse list\n");
	printf("m - find position of minimum element\n");
	printf("c - count amounts of elements\n");
	printf("d - delete all positive elements\n");
	printf("i - insert element A after element B\nq - quit\n");
	while(command!='q') {                                            
		scanf(" %c",&command);
		if(command=='p') {
		 	current=head;
		 	while(current->next!=NULL) {
		 		current=current->next;
		 		printf("%d ",current->value);
			}
			if(head->next==NULL) {
				printf("List is empty");
			}	
			printf("\n");
		} else if(command=='f'){

			//finding element, task 1

			printf("Enter position of element: ");
			int position;
			scanf(" %d", &position);
			current=head;
			if(position<1) {
            	printf("Position is out of list's bounds\n");
			} else {
				for(int i=0;i<position;i++) {
				 	current=current->next;
			 		if(current==NULL) {
						printf("Position is out of list's bounds\n");
						break;
					}	
				}
			}
			if((current!=NULL)&&(position>=1)) {
				printf("Element at position %d has value %d\n",position,current->value);
			}

		} else if (command=='l') {
			
			//counting length of array, task 2

			int listLength=0;
			current=head;
			while(current->next!=NULL) {
				current=current->next;
				listLength++;
			}
			printf("Length of list is %d\n",listLength);

		} else if (command=='r') {

			//reverse list, task 3
			current=head;
			while(current->next!=NULL) {
				current=current->next;
			}
			if(head->next!=NULL) {
				reverseList(head->next);
				printf("List reversed successfully.\n");
			}
			head->next->next=NULL;
			head->next=current;
		} else if (command=='m') {
			
			//counting position of minimum,task 5

			current=head;
			if(current->next==NULL) {
			 	printf("There aren't any elements in list.\n");
			} else {
				current=current->next;
			 	int minimum=current->value;
			 	int minimumPos=1;
			 	int position=1;
			 	while(current->next!=NULL) {
			 		position++;
			 		current=current->next;
			 		if(current->value < minimum) {
			 			minimum=current->value;
			 			minimumPos=position;	
			 	 	}	
			 	}
			 	printf("Position of minimum is %d\n",minimumPos);
			}
		} else if (command=='c') {

			//counting amount of every element, task 6

			int values[MAXLENGTH];
			int valuesCount[MAXLENGTH];
			int amountOfValues=0;
			current=head; 
			while(current->next!=NULL) {
			 	current=current->next;
			 	bool valueFound=0;
			 	for(int i=0;i<amountOfValues;i++) {
			 	 	if(values[i]==current->value) {
			 	 	 	valuesCount[i]++;
			 	 	 	valueFound=1;
			 	 	}
			 	}
			 	if(!valueFound) {
			 	 	values[amountOfValues]=current->value;
			 	 	valuesCount[amountOfValues]=1;
			 	 	amountOfValues++;
			 	}
			}
			for(int i=0;i<amountOfValues;i++) {
			 	printf("Element %d appears in list %d times\n",values[i],valuesCount[i]);
			}

		} else if (command=='d') {

			//delete all positive elements, task 9
			current=head;
			List* lastNonPositiveElement=head;
			List* nextElement=head->next;
			head->next=NULL;
			while(nextElement!=NULL) {
			 	current=nextElement;
			 	nextElement=current->next;
			 	if(current->value <= 0) {
			 		lastNonPositiveElement->next=current;
			 	 	lastNonPositiveElement=current;
			 		lastNonPositiveElement->next=NULL;
			 	} else {
			 	 	free(current);
			 	}
			}
			printf("All positive elements are deleted successfully.\n");
		} else if (command=='i') {
			//task 10, inserting elements
			int newValue,prevValue;
			printf("Enter value to add: ");
			scanf("%d",&newValue);
			printf("Enter value after which new elements will be added: ");
			scanf("%d",&prevValue);
			
			current=head;
			while(current->next!=NULL) {
				current=current->next;
				if(current->value==prevValue) {
					List* newElement=(List*)malloc(sizeof(List));
					newElement->value=newValue;
					newElement->next=current->next;
					current->next=newElement;
					current=newElement;	
				}	
			}
			printf("New elements are added successfully!\n");
		} else if (command=='q') {
		 	freeList(head);
		}
	}
	return 0;
}