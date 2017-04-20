#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct number{
	int num;
	struct number *next;
};

struct number *creatorNumber(){
	struct number *newNumber;
	newNumber=(struct number *)malloc(sizeof(struct number));
	newNumber->next=NULL;
	return newNumber;
}

struct number *inverted(struct number *head){
	struct number *previous=NULL,*current=head,*preceding=head->next;
	while (preceding != NULL) {
        current->next = previous;      // 把current->next轉向
        previous = current;            // previous往後挪
        current = preceding;           // current往後挪
        preceding = preceding->next;   // preceding往後挪
    } 
    current->next = previous;          // 此時current位於最後一個node, 將current->next轉向
    head = current; 
    return head;
}

void print(struct number *ptr){
	while(ptr!=NULL){
    	printf("%d",ptr->num);
    	ptr=ptr->next;
	}
	printf("\n");
}

struct number *createlist(char ch[]){
	int i;
	struct number *head=NULL,*temp,*newNumber;
	for(i=strlen(ch)-1;i>=0;i--){
		newNumber=creatorNumber();
		newNumber->num=ch[i]-48;
		if(head==NULL){
			head=temp=newNumber;
		}else{
			temp->next=newNumber;
			temp=newNumber;
		}
	}
	return head;
}

struct number *addition(struct number *ptr1,struct number *ptr2){
	struct number *head=NULL,*temp=NULL,*newNumber=NULL;
	int add=0;
	while(ptr1!=NULL || ptr2!=NULL){
		int p1=0,p2=0;
		newNumber=creatorNumber();
		p1=ptr1!=NULL?ptr1->num:0;
		p2=ptr2!=NULL?ptr2->num:0;
		newNumber->num=(p1+p2+add)%10;
		add=(p1+p2+add)>=10==1?1:0;
		
		if(head==NULL){
			head=newNumber;
			temp=newNumber;
		}else{
			temp->next=newNumber;
			temp=newNumber; 
		}
		ptr1=ptr1!=NULL?ptr1->next:NULL;
		ptr2=ptr2!=NULL?ptr2->next:NULL;
	}
	if(add==1){
	   newNumber=creatorNumber();	
	   newNumber->num=1;
	   temp->next=newNumber;
	   temp=newNumber; 
	}
	return head;
}

void listing(struct number *ptr1,struct number *ptr2,struct number *ptr3){
	ptr1=inverted(ptr1);
	print(ptr1);
	ptr2=inverted(ptr2);
	print(ptr2);
	ptr3=inverted(ptr3);
	print(ptr3);
}

int main(int argc, char *argv[]) {
	struct number *ptr1,*ptr2,*ptr3;
	char ch[100];

	
	printf("輸入第一串數字:");
	scanf("%s",ch);
	ptr1=createlist(ch);
        printf("輸入第二串數字:");
	scanf("%s",ch);
	ptr2=createlist(ch);
	ptr3=addition(ptr1,ptr2);
	
	listing(ptr1,ptr2,ptr3);



	return 0;
}
