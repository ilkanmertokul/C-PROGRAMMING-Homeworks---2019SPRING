#include <stdio.h>

/**********************FUNCTION DECLARATIONS*********************/
//PART1
	void part1_starter();
	int find_f(int n,int f[50],int len_of_f);
	int next_prime(int n);
	int find_commons(int commons[50],int len_of_commons,int f1[50],int len_of_f1,int f2[50],int len_of_f2);
	int return_recursive_gcd(int commons[50],int len_of_commons);
//PART2
	void part2_starter();
	//recursive_sorter(array...); LOOK LINE #176.
//PART3
	void part3_starter();
	void recursive_formula(int n);
//PART4
	void part4_starter();
	int recursive_eq_or_not(int n,int n_of_digit,int count,int total);
	int find_pow(int digit,int n_of_digit);
	int find_remaining_digit(int n,int count);
//PART5
	void part5_starter();
	int recursive_uppercase_finder(char ch[100],int count);
/****************************************************************/

int main(){	//Main function, menu gets printed here.
	
	int choice,flag=1;

	while(flag==1){

		printf("\n\n************************************************\n");
		printf("Welcome to homework 6. Choose an action to move.\n\n");
		printf("1-) PART 1 - calculate greatest common divisor.\n");
		printf("2-) PART 2 - sort an array.\n");
		printf("3-) PART 3 - use a special recursive function.\n");
		printf("4-) PART 4 - use equal\\not equal recursive function.\n");
		printf("5-) PART 5 - find first uppercase in a string.\n\n");
		printf("6-) exit.\n");
		printf("************************************************\n");

		scanf("%d",&choice);

		switch(choice){		//I used starter functions to make main function simple.

			case 1:		part1_starter();	
				break;
			case 2:		part2_starter();
				break;
			case 3:		part3_starter();
				break;
			case 4:		part4_starter();
				break;
			case 5:		part5_starter();
				break;
			case 6:		printf("exiting...\n");
						flag=0;
				break;
			default:	printf("You entered a wrong value, exiting now.\n");
						flag=0;
		}
	}
}

//PART1 PART1 PART1//////////////////////////////////////////////////////////////////////////////////////////
void part1_starter(){

	int n1,n2;
	int f1[50],f2[50],commons[50];
	int len_of_f1=0,len_of_f2=0,len_of_commons=0;
	int gcd;

	do{
		printf("Enter two numbers ((more or equal to 2)) to find greatest common divisor.\n");
		scanf("%d",&n1);
		scanf("%d",&n2);
	}while(n1<2 || n2<2);

	printf("Factors of %d:",n1);
	len_of_f1=find_f(n1,f1,len_of_f1);

	printf("\nFactors of %d:",n2);
	len_of_f2=find_f(n2,f2,len_of_f2);

	commons[0]=1;
	len_of_commons=find_commons(commons,len_of_commons,f1,len_of_f1,f2,len_of_f2); 
	gcd=return_recursive_gcd(commons,len_of_commons);	//we get gcd recursively here.

	printf("\nGreatest common divisor:%d\n",gcd);
}

int find_f(int n,int f[50],int len_of_f){	//This function gives us the factors of a num, and returns lenght of that array.

	int prime=2;

	while(1){
		if(n%prime==0){
			f[len_of_f]=prime;	
			n=n/prime;
			printf("%d ",f[len_of_f]);
			len_of_f++;
		}	
		else		prime=next_prime(prime);	//we get the next prime number with this function. LINE 112

		if(n==1){
			break;
		}
	}
	return len_of_f;
}

int next_prime(int n){	//function to find next prime number and return, used in factor finder.

	int i,flag=1;
	n++;

	while(1){
		flag=1;
		for(i=2;i<n;i++){
			if(n%i==0){
				flag=0;
			}
		}
		if(flag==0){
			n++;
		}
		else{
			break;
		}
	}
	return n;
}

int find_commons(int commons[50],int len_of_commons,int f1[50],int len_of_f1,int f2[50],int len_of_f2){	//This function finds commons and returns the lenght.

	int i,j,k;

	for(i=0;i<len_of_f1;i++){
		k=f1[i];

		for(j=0;j<len_of_f2;j++){
			if(k==f2[j]){
				commons[len_of_commons]=k;
				len_of_commons++;
				f2[j]=-1;
				break;
			}
		}
	}
	return len_of_commons;
}

int return_recursive_gcd(int commons[50],int len_of_commons){	//This is the function that finds gcd recursively.

	if(len_of_commons==1){	
		return commons[0];
	}
	else{ 
		return commons[len_of_commons-1]*return_recursive_gcd(commons,len_of_commons-1);	
	}
}

//PART2 PART2 PART2///////////////////////////////////////////////////////////////////////////////////////////
void part2_starter(){	//Part 2, is not completed.

	int array[50];
	int a_lenght;
	int i;

	printf("Enter a lenght for array to sort recursively.\n");
	scanf("%d",&a_lenght);

	for (i=0; i<a_lenght; i++){
		scanf("%d",&array[i]);
	}

	//couldnt able to do the sorting.
	//recursive_sorter(array...);
}

//PART3 PART3 PART3//////////////////////////////////////////////////////////////////////////////////////////
void part3_starter(){

	int n;

	printf("Enter a number:\n");
	scanf("%d",&n);

	printf("Output: ");
	recursive_formula(n);
}
	
void recursive_formula(int n){	//This is the recursive algorithm to use f() formula.

	printf(" %d ",n);

	if(n==0);
	else if(n==1);
	else if(n%2==1){
		recursive_formula(3*n+1);
	}
	else{
		recursive_formula(n/2);
	}
}

//PART4 PART4 PART4//////////////////////////////////////////////////////////////////////////////////////////
void part4_starter(){

	int n_of_digit=0;
	int n,total=0;
	int result;
	double i=1,j=1;

	printf("Enter a number to learn if it is equal or not with the special function.\n");
	scanf("%d",&n);

	while(i>=1){
		i=n/j;
		j=j*10;
		if(i>=1) 	n_of_digit++;
	}

	result=recursive_eq_or_not(n,n_of_digit,1,total);

	if(result==n)	printf("Equal\n");
	else	 	printf("Not Equal\n");
}

int recursive_eq_or_not(int n,int n_of_digit,int count,int total){ //this function returns the if zxc... is equal to z^n+x^n+c^n...  or not.
	
	int digit,i;

	digit=find_remaining_digit(n,count);	//finds the remaining digit accorcing to count and returns.	 LINE 246
	i=find_pow(digit,n_of_digit);			//finds the power of digit^n_of_digit and returns.	LINE 256

	if(count==n_of_digit){
		
		total=total+i;

		return total;
	}
		return i+recursive_eq_or_not(n,n_of_digit,count+1,total);
}

int find_remaining_digit(int n,int count){	

	while(count>1){
		n=n/10;
		count--;
	}

	return n%10;
}

int find_pow(int digit,int n_of_digit){

	int i,j=1;

	for(i=0;i<n_of_digit;i++){
		j=digit*j;
	}

	return j;
}

//PART5 PART5 PART5////////////////////////////////////////////////////////////////////////////////////////// 
void part5_starter(){

	char ch[100];

	int count=0,place;

	printf("Enter a string without spaces, recursive program finds the first uppercase.\n");
	scanf("%s",ch);

	place=recursive_uppercase_finder(ch,count);

	if(place==101)	printf("This string doesn't have an uppercase character.\n");
	else 			printf("#%d character: %c is uppercase.\n",place,ch[place]);
}

int recursive_uppercase_finder(char ch[100],int count){	//recursive uppercase finds and returns the location, gives an error if there is no uppercase.

	if(ch[count]>='A' && ch[count]<='Z')	return count;
	else{
			if(ch[count]=='\0') return 101;
			return recursive_uppercase_finder(ch,count+1);
	}								
}





//end.




