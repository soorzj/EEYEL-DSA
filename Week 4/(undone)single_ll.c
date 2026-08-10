/***************************************************************
* Program to implement single linked list in C using struct    *
* Author: SOORAJ                                               *
* Date: 10-8-26                                                *
* Version: 2                                                   *
****************************************************************/
#include <stdio.h>

struct node {
    int next;
    int data;
};
int head=-1;

int main(){
    
    int choice=-1;
	printf("Menu for Single LinkedList\n");
	printf("1.Add Element at front\n2.Add Element at back\n3.Print Linked List\n4.Exit\n");
	while (choice !=4)
		{
		printf("Enter Your choice:\n");
		scanf("%d", &choice);
		switch (choice){
		    case 1:
		        int val=inputNum();
		        if(head==-1)
		            firstElement(int val);
		        else
		            add_at_first(struct *data, int head, int val);
		        break;
		     case 2:
		        int val=inputNum();
		        if(head==-1)
		            firstElement(int val);
		        else
		            add_at_last(struct *data, int head, int val);
		        break;
		     case 3:
		        print_ll();
		        break;
		     case 4:
		        printf("Exiting Program\n");
		        break;
		     default:
		        printf("Wrong choice\n");
	         }
	     }
    }

int inputNum(){
    int val;
    printf("Enter The element:\n");
	scanf("%d", &val);
	return val;
}

struct node *add_at_first(struct node *head, int inputData)
{
    struct node *new=malloc(sizeof(struct node));
    new->data= inputData;
    new->next= head;
    head=new;
    return head;
}
struct node *add_at_last(struct node *head, int inputData)
{
    struct node *new=malloc(sizeof(struct node));
    new->data= inputData;
    struct node *lastPointer=head;
    while(lastPointer->next!=NULL){
        lastPointer=lastPointer->next;
    }
    lastPointer->next=new;
    new->next=NULL;
    return head;
}

void ()
