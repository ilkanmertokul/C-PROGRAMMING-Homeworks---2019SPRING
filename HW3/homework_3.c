// Code written by İlkan Mert Okul, 1801042649.

#include <stdio.h>
#include <math.h>

////////////////////DECLARATIONS//////////////////////////////////////

void start_menu();

//p1 functions

int add(int n1,int n2);
int sub(int n1,int n2);
int div(int n1,int n2);
int mtp(int n1,int n2);
int pwr(int n1,int n2);
int mod(int n1,int n2);
int doit(int (*do_something)(int nn1,int nn2),int n1,int n2);
void show_calculator();

//p2 functions

void start_menu();					
void take_grades(int arr[]);
void take_exam_grades(int arr[]);				
double calculate_homework(int arr[]);
double calculate_lab(int arr[]);
double calculate_all(double hm,int midfinal[],double lab);

//p3 function

void print_dia();

///////////////////////////PART 1 FUNCTIONS//////////////////////////

int add(int n1,int n2){
	return n1+n2;
}

int sub(int n1,int n2){
	return n2-n1;
}

int div(int n1,int n2){
	return n2/n1;
}

int mtp(int n1,int n2){
	return n1*n2;
}

int pwr(int n1,int n2){
	return pow(n2,n1);
}

int mod(int n1,int n2){
	return n2%n1;
}

int doit(int (*do_something)(int nn1,int nn2),int n1,int n2){

	int res;
	res=do_something(n1,n2);
	return res;
}

void show_calculator(){

	int flag=1;
	int number1,number2=0;	
	char choice[2];
	
	while(flag==1){

		printf("\nPress + to add\n");
		printf("Press - to substract\n");	
		printf("Press * to multiply\n");
		printf("Press / to divide\n");
		printf("Press ** to find power\n");
		printf("Press %% to find module.\n");

		scanf("%s",&choice[1]);

		printf("Enter a number, then enter a number too; if you dont want to, just enter a char for second number:\n");
		scanf("%d %d",&number1,&number2);

		switch(choice[1]){
			case '+': 	number2=doit(add,number1,number2);
				  	break;

			case '-': 	number2=doit(sub,number1,number2);
				  	break;

			case '*': 	if(choice[2]=='*')	number2=doit(pwr,number1,number2);
					else			number2=doit(mtp,number1,number2);
					break;
			
			case '/':	number2=doit(div,number1,number2);
					break;

			case '%':	number2=doit(mod,number1,number2);
					break;
	
			default:	printf("You entered a wrong value to function.Exiting.\n");
					flag=0;
		}
			if(flag==1)	printf("Current Result: %d\n",number2);
	}
}

//////////////////////////PART 2 FUNCTIONS///////////////////////////

void take_grades(int arr[]){

	int a;
	for(a=1;a<=10;a++){
		printf("%d:",a);
		scanf("%d",&arr[a]);
	}
}

void take_exam_grades(int arr[]){

	int a;
	printf("First, enter your midterm grade, then your final.\n");
	for(a=1;a<=2;a++){
		scanf("%d",&arr[a]);
	}
}

double calculate_homework(int arr[]){

	int a;
	double sum=0;

	for(a=1;a<=10;a++){
		sum=sum+arr[a];
	}
	return sum/10;
}

double calculate_lab(int arr[]){

	int a;
	double sum=0;

	for(a=1;a<=10;a++){
		sum=sum+arr[a];
	}
	return sum/10;
}

double calculate_all(double hm,int midfinal[],double lab){

	double average;

	average=((hm*10)+(lab*20)+(midfinal[1]*30)+(midfinal[2]*40))/100;

	return average;
}

////////////////////PART 3 FUNCTION/////////////////////////////

void print_dia(){

	int spaces,stars,counter=0,a; //Used for space-star balances.	
	int input;		

	int flag=1;

	while(flag==1){

		printf("Please enter an input to draw diamond filled with stars in it.");
		scanf("%d",&input);
			
		if(input<=0)	printf("\nYou cannot enter zero or negative number, try again.");
		else 		flag=0;
	}
	flag=1;	
		
	spaces=input;
	stars=0;

	while(flag==1){
		for(a=1;a<spaces;a++)	printf(" ");

		if(counter==0)	printf("/");
		else		printf("\\");

		for(a=0;a<stars;a++)	printf("*");

		if(counter==0)	printf("\\\n");
		else		printf("/\n");

		if(counter==0){
			spaces=spaces-1;
			stars=stars+2;
			if(spaces==0){
				counter=1;
				stars=stars-2;
				spaces=spaces+1;
			}
		}
		else{
			spaces=spaces+1;
			stars=stars-2;
			if(stars<=0){
				for(a=1;a<spaces;a++) printf(" ");
				if(input>1)	printf("\\/\n");
				flag=0;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////

void start_menu(){
	
	int flag=1,choice; //Used for while loop.

	int homework[10],lab[10],mid_n_fin[2]; //Used for case 2.
	double hm_average,lab_average,average_all;

	
	while(flag==1){

		printf("1- Launch calculator.\n");
		printf("2- Launch grade calculator.\n");
		printf("3- Launch diamond drawer.\n");
		printf("Press any other button to exit.\n");

		scanf("%d",&choice);

		switch ( choice ){
			case 1: //Part 1. Calculator.
				show_calculator();
				break;

			case 2:	//Part 2. Grade Calculator.
				
				printf("Enter your Homework notes:\n");
				take_grades(homework);
				printf("Enter your Lab notes:\n");
				take_grades(lab);
				printf("Enter your Midterm and Final notes:\n");
				take_exam_grades(mid_n_fin);			

				hm_average=calculate_homework(homework);
				lab_average=calculate_lab(lab);	
				average_all=calculate_all(hm_average,mid_n_fin,lab_average);

				printf("Your average is %.2f.\n",average_all);
				break;

			case 3:	//Part 3. Diamond drawer.
				print_dia();
				break;	
			
			default: flag=0;
				 printf("Bye!");
		}
	}
}

int main(){

	start_menu();
	return 0;
}
