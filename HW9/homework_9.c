#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define char_len 20

struct person{

	char name[char_len];
	char surname[char_len];
	char musical_work[char_len];
	int age;

	struct person *next;

}*top;

struct person *person_list=NULL;
struct person *top=NULL;

void print_stack(){	//function to print stack.

	while(1){
		if(person_list!=NULL){

			printf("Name: %s\n",person_list->name);
			printf("Surname: %s\n",person_list->surname);
			printf("Creation: %s\n",person_list->musical_work);
			printf("Age: %d\n",person_list->age);

			if(person_list->next!=NULL){
				printf("---------------\n");
				person_list=person_list->next;
			}
			else break;
		}
		else{
			printf("Stack is empty right now.\n");
			break;
		}	
	}

	person_list=top;
}

void addNode(char name[],char surname[],char creation[],int age){ //fundtion to add node.

	struct person *new_person=malloc(sizeof(struct person));

	strcpy(new_person->name,name);
	strcpy(new_person->surname,surname);
	strcpy(new_person->musical_work,creation);
	new_person->age=age;

	new_person->next=person_list;
	person_list=new_person;

	top=person_list;
}

void deleteNode(){	//function to delete node.

	if(person_list==NULL)	printf("Stack is already empty.\n");
	else{
		printf("%s is getting deleted\n",person_list->name);
		person_list=person_list->next;

		top=person_list;

		print_stack();
	}
}

void Sort_Alphabetically(int stack_len){ //alphabetically sorter.

	int age[stack_len];
	char surname[stack_len][char_len];
	char musical_work[stack_len][char_len];
	char name[stack_len][char_len];

	int i,j,max=0,temp;
	char temp_c[char_len];

	while(person_list!=NULL){ //First, all elements goes to an array.

		age[max]=person_list->age;

		strcpy(name[max],person_list->name);
		strcpy(surname[max],person_list->surname);
		strcpy(musical_work[max],person_list->musical_work);

		person_list=person_list->next;

		max++;
	}

	person_list=top;


	for(i=0;i<=max;i++){	//Sorts the array.

	    for(j=0;j<(max-i-1); j++){

	        if(strcmp(name[j],name[j+1])>0){

	           	temp = age[j];
	           	age[j]= age[j+1];
	           	age[j+1]=temp;

	           	strcpy(temp_c,name[j]);
	           	strcpy(name[j],name[j+1]);
	           	strcpy(name[j+1],temp_c);

	           	strcpy(temp_c,surname[j]);
	           	strcpy(surname[j],surname[j+1]);
	           	strcpy(surname[j+1],temp_c);

	           	strcpy(temp_c,musical_work[j]);
	           	strcpy(musical_work[j],musical_work[j+1]);
	           	strcpy(musical_work[j+1],temp_c);
	        }
		}  
	}
	
	while(person_list!=NULL){

		person_list=person_list->next;
		top=person_list;
	}

	for(i=max-1;i>=0;i--){	//gives the sorted array.

		addNode(name[i],surname[i],musical_work[i],age[i]);
	}

	printf("Your stack is sorted now.\n");
	print_stack();

}

void Sort_Increasingly(int stack_len){

	int age[stack_len];
	char surname[stack_len][char_len];
	char musical_work[stack_len][char_len];
	char name[stack_len][char_len];

	int i,j,max=0,temp;
	char temp_c[char_len];

	while(person_list!=NULL){	//First, all elements goes to an array.

		age[max]=person_list->age;

		strcpy(name[max],person_list->name);
		strcpy(surname[max],person_list->surname);
		strcpy(musical_work[max],person_list->musical_work);

		person_list=person_list->next;

		max++;
	}

	person_list=top;


	for(i=0;i<=max;i++){	//Sorts the array.

	    for(j=0;j<(max-i-1); j++){

	        if(age[j] < age[j+1]){

	           	temp = age[j];
	           	age[j]= age[j+1];
	           	age[j+1]=temp;

	           	strcpy(temp_c,name[j]);
	           	strcpy(name[j],name[j+1]);
	           	strcpy(name[j+1],temp_c);

	           	strcpy(temp_c,surname[j]);
	           	strcpy(surname[j],surname[j+1]);
	           	strcpy(surname[j+1],temp_c);

	           	strcpy(temp_c,musical_work[j]);
	           	strcpy(musical_work[j],musical_work[j+1]);
	           	strcpy(musical_work[j+1],temp_c);
	        }
		}  
	}
	
	while(person_list!=NULL){

		person_list=person_list->next;
		top=person_list;
	}

	for(i=0;i<max;i++){	//gives the sorted array.

		addNode(name[i],surname[i],musical_work[i],age[i]);
	}

	printf("Your stack is sorted now.\n");
	print_stack();
}

void menu(){

	int loop=1;
	int choice,stack_len;

	char temp;
	char name[char_len];
	char surname_input[char_len];
	char creation_input[char_len];
	int age_input;


	printf("Welcome to homework 9.\n");

	while(loop==1){

		printf("\n****MENU****\n");
		printf("1- Add a Person to the Stack\n");
		printf("2- Pop a Person from the Stack\n");
		printf("3- Sort Alphabetical Order\n");
		printf("4- Sort Age in Increasing Order\n");
		printf("5- Exit menu\n");

		scanf("%d",&choice);

		switch(choice){

			case 1:

				printf("Enter these inputs->\n");
				printf("Name:\n");
					scanf("%c",&temp); //makes scanf with spaces work.
					scanf("%[^\n]",name);

				printf("Surname:\n");
					scanf("%c",&temp); //makes scanf with spaces work.
					scanf ("%[^\n]", surname_input);

				printf("Creation:\n");
					scanf("%c",&temp); //makes scanf with spaces work.
					scanf ("%[^\n]", creation_input);

				printf("Age:\n");
					scanf("%c",&temp); //makes scanf with spaces work.
					scanf("%d",&age_input);

				addNode(name,surname_input,creation_input,age_input);

				printf("%s's information is succesfully pushed into the stack\n\n",person_list->name);
				print_stack();

				break;
			
			case 2:

				deleteNode();
				break;
			
			case 3:

				stack_len=1;

				if(person_list==NULL) printf("Your stack is empty.\n");
				else{
					while(person_list->next!=NULL){
						person_list=person_list->next;
						stack_len++;
					}

					person_list=top;
					printf("%d\n",stack_len);

					Sort_Alphabetically(stack_len);
				}
				break;
			
			case 4:

				stack_len=1;

				if(person_list==NULL) printf("Your stack is empty.\n");
				else{
					while(person_list->next!=NULL){
						person_list=person_list->next;
						stack_len++;
					}

					person_list=top;
					printf("%d\n",stack_len);

					Sort_Increasingly(stack_len);
				}
				break;
			
			case 5:
				loop=0;
				break;
			
			default:	
				printf("You entered a wrong value.\n");

		}//switch-case
	}//while-loop
}//function

int main(){

	menu();

	if(person_list!=NULL){
		while(person_list->next!=NULL){
			free(person_list);
			person_list=person_list->next;
		}
	}

	printf("Exiting.\n");
	return 0;
}
