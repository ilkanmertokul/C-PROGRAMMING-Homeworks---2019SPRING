#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYSIZE 20

typedef struct stack{
	int data;
	struct stack * next;
}stack;

typedef struct node{
	int data;	
	struct node *next;
}node;

typedef struct queue{
	node *first;
	node *last;
}queue;

typedef struct bst{
	int data;
	struct bst *right,*left;
}bst;

/*HELPER FUNCTIONS I USED*/

//for stack:
void push_stack(stack ** stack_, int data);
void print_stack(stack * stack_);

//for queue;
struct queue * make_queue(queue * queue_, int data[ARRAYSIZE]);
void add_queue(queue * queue_, int data);
void print_queue(queue * queue_);
void sort_queue(node * qnode);

//for bst;
struct bst * add_bst(bst * bst_, int data);
void print_bst(bst * bst_);
int find_bst(bst * bst_, int val_to_search, int count);

/***********************/

//STACK

void push_stack(stack ** stack_, int data){

	stack * node = (struct stack*)malloc(sizeof(struct stack));
	node->data = data;
	node->next=NULL;

	node->next=*stack_;
	*stack_=node;
}

void print_stack(stack * stack_){

	int i;
	stack * temp=stack_;

	for(i=0;i<ARRAYSIZE;i++){
		printf(" %d ",temp->data);
		temp=temp->next;
	}
}

//QUEUE

struct queue * make_queue(queue * queue_, int data[ARRAYSIZE]){

	int i;

	queue_=malloc(sizeof(queue));

	queue_->first=NULL;
	queue_->last=NULL;

	for(i=0;i<ARRAYSIZE;i++) add_queue(queue_,data[i]);

	return queue_;
}

void add_queue(queue * queue_, int data){

	node * temp=malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;

	if(queue_->first==NULL)	queue_->first=queue_->last=temp;
	else{
		queue_->last->next=temp;
		queue_->last=temp;
	}
}

void print_queue(queue * queue_){

	int i;
	node * temp=queue_->first;

	for(i=0;i<ARRAYSIZE;i++){
		printf(" %d ",temp->data);
		temp=temp->next;
	}
}

void sort_queue(node * qnode){

	int i,flag=1,temp;
	node *p1,*p2;

	p2=NULL;

	while(flag!=0){

		flag=0;
		p1=qnode;

		while(p1->next!=p2){
			if(p1->data > p1->next->data){
				temp=p1->data;
				p1->data=p1->next->data;
				p1->next->data=temp;
				flag=1;
			}
			p1=p1->next;
		}
		p2=p1;
	}
}

//BINARY SEARCH TREE

struct bst * add_bst(bst * bst_, int data){

	if(bst_==NULL){
	
		bst_=malloc(sizeof(bst));
		bst_->data=data;
		bst_->right=NULL;
		bst_->left=NULL;
	
		return bst_;
	}
	else{

		if(bst_->data > data)		bst_->right = add_bst(bst_->right,data);
		else if(bst_->data < data)	bst_->left  = add_bst(bst_->left,data);
	}

	return bst_;
}

void print_bst(bst * bst_){

	if(bst_->left!=NULL)	print_bst(bst_->left);
	printf("% d ",bst_->data);
	if(bst_->right!=NULL)	print_bst(bst_->right);
}

int find_bst(bst * bst_, int val_to_search, int count){

	if(val_to_search==bst_->data)	return count;
	else{
		if(bst_->data < val_to_search)	find_bst(bst_->left,val_to_search,count+1);
		else							find_bst(bst_->right,val_to_search,count+1);
	}
}

int go_to_max(bst * bst_){

	int flag=0;
	int i;

	while(bst_->right!=NULL && bst_->right->data!=-1){
		bst_=bst_->right;
		flag=1;
	}
	
	if(flag==0){
		while(bst_->left!=NULL && bst_->left->data!=-1){
			bst_=bst_->left;
			while(bst_->right!=NULL && bst_->right->data!=-1)		bst_=bst_->right;
		}
	}

	i=bst_->data;
	bst_->data=-1;

	return i;
}

int go_to_min(bst * bst_){

	int flag=0;
	int i;

	while(bst_->left!=NULL && bst_->left->data!=-1){
		bst_=bst_->left;
		flag=1;
	}		

	if(flag==0){
		while(bst_->right!=NULL && bst_->right->data!=-1){
			bst_=bst_->right;
			while(bst_->left!=NULL && bst_->left->data!=-1)		bst_=bst_->left;
		}
	}

	i=bst_->data;
	bst_->data=-1;

	return i;
}

void bst_special(bst * bst_){

	int i=0,x;
	bst * head=bst_;

	while(head->data!=-1){

		bst_=head;

		x=go_to_max(bst_);
		printf("%d ",x);

		bst_=head;

		x=go_to_min(bst_);
		printf("%d ",x);

		i++;
	}
}

//

void fill_structures( stack ** stack_, queue ** queue_, bst ** bst_, int data[ARRAYSIZE]){

	int i;
	clock_t start, stop;

	double s_time, q_time, b_time;

	/*********STACK***************/

	start = clock();
	for(i=0;i<ARRAYSIZE;i++)	push_stack(stack_,data[i]);
	stop = clock();

	s_time=((double)(stop-start))/10;

	/********QUEUE****************/

	start = clock();
	*queue_=make_queue(*queue_,data);
	stop = clock();

	q_time=((double)(stop-start))/10;

	/**BINARY**SEARCH***TREE******/

	start = clock();
	for(i=0;i<ARRAYSIZE;i++)	*bst_=add_bst(*bst_,data[i]);
	stop = clock();

	b_time=((double)(stop-start))/10;

	//Printing the results:
	printf("Time magnitude of filling: (miliseconds)\n");
	printf("STACK\tQUEUE\tBST\n");
	printf("%.3f\t%.3f\t%.3f \n\n",s_time,q_time,b_time);
}

void ordered_print(stack * stack_, queue * queue_, bst * bst_){

	clock_t start, stop;

	double q_sort_time;
	double s_time, q_time, b_time;

	//Sorts:

	printf("Ordering data types..\n");

	start = clock();
	sort_queue(queue_->first);
	stop = clock();
	
	q_sort_time=((double)(stop-start))/10;

	/*
		README:

		For some reason i couldn't make ordered STACK.
		Bst cannot be ordered, while it is already placed ordered and printed.
	*/

	//Prints:
	
	start = clock();
	printf("Printing stack:");
	print_stack(stack_);	
	stop = clock();

	s_time=((double)(stop-start))/10;

	start = clock();
	printf("\nPrinting queue:");
	print_queue(queue_);
	stop = clock();

	q_time=((double)(stop-start))/10;
	
	start = clock();
	printf("\n  Printing bst:");
	print_bst(bst_);
	stop = clock();
	printf("\n\n(Same values did not got into bst)\n");
	b_time=((double)(stop-start))/10;

	printf("Time magnitude of ordering: (miliseconds)\n");
	printf("STACK\tQUEUE\tBST\n");
	printf("%.3f\t%.3f\t%.3f \n\n",0.000,q_sort_time,0.000);

	printf("Time magnitude of printing: (miliseconds)\n");
	printf("STACK\tQUEUE\tBST\n");
	printf("%.3f\t%.3f\t%.3f \n\n",s_time,q_time,b_time);
}

void search(stack * stack_, queue * queue_, bst * bst_,int val_to_search){

	int count;
	clock_t start, stop;

	double s_time, q_time, b_time;

	stack * stemp=stack_;
	node * qtemp=queue_->first;

	printf("Searching %d.\n",val_to_search);

	//stack:
	start = clock();
	count=1;
	while(stemp!=NULL){
		if(stemp->data==val_to_search)	break;
		else{
			stemp=stemp->next;
			count++;
		}
	}
	printf("Found in %dth step for stack.\n",count);
	stop = clock();

	s_time=((double)(stop-start))/10;

	//queue

	start = clock();
	count=1;
	while(qtemp!=NULL){
		if(qtemp->data==val_to_search)	break;
		else{
			qtemp=qtemp->next;
			count++;
		}
	}
	printf("Found in %dth step for queue.\n",count);	
	stop = clock();

	q_time=((double)(stop-start))/10;

	//bst

	start = clock();
	count=1;
	count=find_bst(bst_,val_to_search,count);
	printf("Found in %dth step for bst\n",count);
	stop = clock();

	b_time=((double)(stop-start))/10;

	printf("\nTime magnitude of searching %d: (miliseconds)\n",val_to_search);
	printf("STACK\tQUEUE\tBST\n");
	printf("%.3f\t%.3f\t%.3f \n\n",s_time,q_time,b_time);
}

void special_traverse(stack * stack_, queue * queue_, bst * bst_){
	
	printf("Welcome to special traverse printer.\n");


	bst_special(bst_);


}


int main(){
	
	int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17, 8, 23, 4};

	bst * bst_;
	queue * queue_;
	stack * stack_;

	fill_structures(&stack_, &queue_, &bst_, data);
	ordered_print(stack_, queue_, bst_);
	search(stack_, queue_, bst_, 5);
	special_traverse(stack_, queue_, bst_);

	return 0;
}