#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
void input(struct Node *head);
void display(struct Node *head);
struct Node  *insert(struct Node *head);
struct Node  *deletion(struct Node *head);

int main()
{
	struct Node *head; int P;
	head =  (struct Node *)malloc(sizeof(struct Node));
	input(head);
	printf("type I to insertion or type D for deletion an item\n");
	scanf("%d", &P);
	switch(P){
		
	case 1 : head = insert(head);break;
	case 2 :head = deletion(head);break;
	default: printf("Wrong input");}
	display(head);
}

void input(struct Node *practice)
{
	printf("write the dtaa if to stop write -0001 \n");
	scanf("%d",&practice->data);
	if(practice->data == -0001)
	practice->next = NULL;
	else{
		practice->next =  (struct Node *)malloc(sizeof(struct Node));
		input(practice->next);
	}
}


void display(struct Node *prac)
{
	while(prac->next != NULL)
	{
		printf(" The element is : %d \n",prac->data);
		prac = prac->next;
	}
}
struct Node  *insert(struct Node *prac)
{
	struct Node * ptr, *p;
	ptr = (struct Node*)malloc(sizeof(struct Node));
	p = prac->next;
	int index;
	printf(" The element to insert :  \n");
	scanf("%d",&ptr->data);
	printf(" The Index to insert :  \n");
	scanf("%d",&index);
	if(index == 1)
	{
		ptr->next = prac;
		return(ptr);
	}
 else if(index > 1){
	for(int l = 2 ; l <= index - 1; l++){
		p = p->next;
	}
	if(p->next != NULL){
	ptr->next = p->next;
	p->next = ptr;

	return(prac);}
	}
	else
	{
		ptr->next = NULL;
		p->next = ptr;
		return(prac);


	}
}


struct Node  *deletion(struct Node *prac){
	struct Node  *p, *k;
	p = prac->next;
	k = prac;
	int index;
	printf(" The Index to delete :  \n");
	scanf("%d",&index);
		if(index == 1)
	{
		
	free(prac);
		return(p);
	}
 else if(index > 1){
	for(int l = 2 ; l <= index-1; l++){
		p = p->next;
		k = k->next;
	}
	if(p->next != NULL){
	k->next = p->next;
	free(p);
	return(prac);}
	}
	else
	{
		k->next = NULL;
		free(p);
		return(prac);

}
}

