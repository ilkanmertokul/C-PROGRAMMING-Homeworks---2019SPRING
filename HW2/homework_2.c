//İLKAN MERT OKUL, 1801042649.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int make_a_guess( int trial, int min, int max){ 

// Function to make guesses, function returns the guess.
// Flag used for unknown inputs.

	int lucky_num, flag =1, user_num;

	while( flag==1 ){

		printf("(Trials left:%d) Make a guess between %d and %d:", trial, min, max);
		scanf("%d", &user_num);
		
		if( user_num>max || user_num<min ){
			printf("You cant enter this number. Try again. \n\n");
		}
		else{
			flag =0;
		}
	}
	return user_num;
}

void show_scores(int score_human, int score_program){

// A basic function to print score.

	printf("Your score: %d Program score: %d\n", score_human, score_program);	
}

void draw_hourglass( int height){

//integer a and b is used for loops.
//space and star used to limit loops, too.

	int space, star;
	int a, b;

	space=0;
	star=height;

	while( star>0 ){
		for(a=0; a<space; a++){
			printf(" ");
		}	
		for(a=0; a<star; a++){
			printf("*");
		}

		printf("\n");
		space++;
		star = star-2;
	}
	

	space = (height-1)/2-1;
	star=3;

	while( space>=0 ){

		for(a=0;a<space;a++){
			printf(" ");
		}	
		for(a=0;a<star;a++){
			printf("*");
		}

		printf("\n");
		space--;
		star=star+2;

	}
}

void draw_mountain_road( int length, int max_radius){

// Function to draw mountain road.

	int temp_rad,space,in_or_out=2;
	int count=0,a,b=1,road_counter;

/* 

"in_or_out" used for what to draw.

"road counter" limited the biggest while loop to stop.

"temp_rad" is random radiuses for road.

"a" and "b" is for little "for" and "while" loops.
     
*/
	space=max_radius;
	road_counter=length;

		while( road_counter>0 ){

		count=0;
		temp_rad=rand()%(max_radius+1);

		if(in_or_out%2==0){
			
			while( count<=temp_rad ){
				if( space<0 ){
					printf("\n");
				}			
				else{
					for( a=0;a<space;a++ ){
						printf(" ");
					}			
					printf("/");
					printf("\n");
				}
				space--;
				count++;
			}

			if( space<0 ){
				printf("\n");
			}
			else{
				for(a=0;a<space;a++){
				printf(" ");
				}
				printf("|");
				printf("\n");
				space++;
			}

			count=0;
			while( count<=temp_rad ){
				if( space<0 ){
					printf("\n");
				}
				else{
					for(a=0;a<space;a++){
						printf(" ");
					}
					printf("\\");
					printf("\n");

				}
	
				space++;
				count++;
			}
		}
		else{
			while( count<=temp_rad ){
				if( space<0 ){
					printf("\n");
				}			
				else{
					for(a=0;a<space;a++){
						printf(" ");
					}			
					printf("\\");
					printf("\n");
				}
				space++;
				count++;
			}

			if( space<0 ){
				printf("\n");
			}
			else{
				for(a=0;a<space;a++){
				printf(" ");
				}
				printf("|");
				printf("\n");
				space--;
			}

			count=0;
			while( count<=temp_rad ){
				if( space<0 ){
					printf("\n");
				}
				else{
					for(a=0;a<space;a++){
						printf(" ");
					}
					printf("/");
					printf("\n");

				}
	
				space--;
				count++;
			}
		}
		in_or_out++; //adding +1 to "in_or_out" to change situation.
		road_counter--;
		count=0;
	}
}

void menu(){

	int choice,flag=1,a=1,b;

	// Choice is user input.
	// Flag is used for wrong inputs.
	// "a" and "b" used for while loop and exiting.

	int trial,min,max;
	int lucky_num,user_num,distance;
	int mechpoint=0,userpoint=0;

	// ^^^ Integer used up here is for guessing game ^^^

	int height;

	// "height" used for hourglass. 

	int length,max_radius;			

	// ^^ used for mountain road imputs ^^

	while( a==1 ){

		printf(" ***** MENU ***** \n");
		printf("1. Play Lucky Number\n");
		printf("2. Draw Hourglass\n");
		printf("3. Draw Mountain Road\n");
		printf("4. Exit\nChoice:");
	
		scanf("%d",&choice);

		printf("\n\n\n\n\n");

		while( flag==1 ){
			if( choice<0 || choice>4 ){
				printf("This is an invalid choice. Try again!\n");
				scanf("%d",&choice);
			}	
			else{
				flag = 0;
			}
		}	

		flag=1;

		switch(choice){ //switch case for menu.

			case 1: trial=10;
				min=0;
				max=1024;
				b=1;

				lucky_num=rand()%(max-min)+1;
				lucky_num=lucky_num+min;

				while( b==1 ){
					
					user_num = make_a_guess(trial,min,max);
									

/////////////////////////////////-CASE-1-MAKE-A-GUESS-ALGORITHM///////////////////////////

					if(user_num-lucky_num>=512 ||lucky_num-user_num>=512){
						distance=10;
					}		
					else if(user_num-lucky_num>=256 ||lucky_num-user_num>=256){
						distance=9;
					}
					else if(user_num-lucky_num>=128 ||lucky_num-user_num>=128){
						distance=8;
					}
					else if(user_num-lucky_num>=64 ||lucky_num-user_num>=64){
						distance=7;
					}
					else if(user_num-lucky_num>=32 ||lucky_num-user_num>=32){
						distance=6;
					}
					else if(user_num-lucky_num>=16 ||lucky_num-user_num>=16){
						distance=5;
					}
					else if(user_num-lucky_num>=8 ||lucky_num-user_num>=8){
						distance=4;
					}
					else if(user_num-lucky_num>=4 ||lucky_num-user_num>=4){
						distance=3;
					}
					else if(user_num-lucky_num>=2 ||lucky_num-user_num>=2){
						distance=2;
					}
					else if(user_num-lucky_num>=1 ||lucky_num-user_num>=1){
						distance=1;
					}
					else{
						distance=0;}
				
////////////////////////////////////////////////////////////////////////////////////

					printf("Distance:%d\n",distance);
					if(distance==0){
						if(trial>0){
							printf("You win!");
							userpoint++;
						}
						else{
							mechpoint++;
						}
						show_scores(userpoint,mechpoint);
						b=0;
					}
					else{
						if(lucky_num>user_num){
							min=user_num;
						}
						else{
							max=user_num;
						}
					}

					trial=trial-1;

					if(b==1 && trial==0){
						printf("You are out of trials, machine won. The lucky number was: %d\n",lucky_num);
						b=0;
						mechpoint++;
						show_scores(userpoint,mechpoint);
					}
				}
				break;
			
			case 2:	while(flag==1){

					printf("Enter an odd positive number to draw a hourglass.");
					scanf("%d",&height);
			
					if(height%2==0 || height<=0){
						printf("You cant enter this number. Try again. \n\n");
					}
					else{
						flag=0;
					}
				}
				flag=1;

				draw_hourglass(height);

			break;
			
			case 3: while( flag==1 ){

					printf("Enter length of the mountain road.");
					scanf("%d",&length);
			
					if(length<=0){
						printf("You cant enter this number. Try again. \n\n");
					}
					else{
						flag=0;
					}
				}
				flag=1;

				while( flag==1 ){

					printf("Enter the max radius for mountain road.");
					scanf("%d",&max_radius);
			
					if(max_radius<=0){
						printf("You cant enter this number. Try again. \n\n");
					}
					else{
						flag=0;
					}
				}
				flag=1;

				draw_mountain_road(length,max_radius);
	
				break;
		
			case 4:	a=0;
				break;
		}

	}

}

int main(){

	srand(time(NULL));	
	
	menu();
	
	printf("Program closed.");
	return 0;

}





