/*********************************************************************************/
/*  Welcome to pokemon creator. This creator done by Ilkan Mert Okul, 1801042649 */
/*********************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h> //For random number generator for power, i needed to include stdlib and time libraries.
#include <time.h>

#define pi 3		

double CreateBody(int shape){	//Function for creating body.

	int radius,flag;		 
	double size;
	flag=1;

	while(flag==1){				//A basic while loop used for making sure that user entered a positive number. 
		
		printf("Please enter positive number for the radius:");
		scanf("%d",&radius);
		
		if(radius<0){
			printf("The radius that you entered is negative.\n");
		}
		else{
			flag=0;
		}
	}

	switch (shape){				//Size calculator used for different shape cases.
		case 1: size =  pow(radius,2);
				break;
		case 2: size =  radius*5;
				break;
		case 3: size =  radius*radius*pi;
				break;
		}

	return size;

}

int SetColor(int color){ 	//Function to set color of Pokemon.

	if(color>1000 || color<0){
		color=1;
		}			
	else{
		color=color%5;
		}

	return color;			
}

double LoadMoves(int shape,double size_of_body){ //Function to set Pokemon's move.

	double move,radius;

	switch(shape){
		case 1: move =sqrt(size_of_body)*4;
			break;
		case 2: radius =size_of_body/5;
			move= 2*(radius+5);
			break;
		case 3: radius=sqrt(size_of_body/pi);
			move=2*pi*radius;
			break;
		}	
	return move;
}

int SetAttackPower(int lower_bound, int upper_bound){ //We used to set power of Pokemon.

	int attackpow,between;
	srand(time(NULL));	
	between=upper_bound-lower_bound;
	
	attackpow=rand();
	attackpow=attackpow%between;
	attackpow=attackpow+lower_bound;

	return attackpow;

}

void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power){

	int a,b,flag; //a and b used for count "for" loops, and flag is for an
		     	 //algorithm in circular print.

	double radius,anti_radius;

	switch(shape){

		case 1: radius =sqrt(body_size); 
			for(a=0;a<radius;a++){
				for(b=0;b<radius;b++){
					printf("X");
				}
				printf("\n");
			}	
			printf("Name : Square Pokemon\n");	
			break;

		case 2: radius =body_size/5; 
			for(a=0;a<5;a++){
				for(b=0;b<radius;b++){
					printf("X");
				}
				printf("\n");
			}
			printf("Name : Rectangular Pokemon\n");
			break;

		case 3: radius =radius=sqrt(body_size/pi);
			anti_radius=1;
			flag=1;

			if(radius==1){
				flag=0;
			}
			for(a=0;a<radius;a++){
				printf(" ");
			}

			printf("x\n");	
			radius--;


			while(radius>0){
				for(a=0;a<radius;a++){
					printf(" ");
				}

				printf("x");

				for(a=0;a<anti_radius;a++){
					printf(" ");	
				}

				printf("x\n");	
				radius--;
				anti_radius=anti_radius+2;	
			}

			radius=radius+2;
			anti_radius=anti_radius-4;

			while(anti_radius>0){
				for(a=0;a<radius;a++){
					printf(" ");
				}

				printf("x");
	
				for(a=0;a<anti_radius;a++){
					printf(" ");
				}
	
				printf("x\n");
				radius++;
				anti_radius=anti_radius-2;
			}

			for(a=0;a<radius;a++){
				printf(" ");
			}

			if(flag==1){
				printf("x\n");
			}
			else{
				printf("\n");
			}

			printf("Name : Circular Pokemon\n");
			break;
	}

	printf("Size : %.3f\n",body_size);
	
	switch (color){
		case 0: printf("Color: Red\n");
			break;
		case 1: printf("Color: Yellow\n");
			break;
		case 2: printf("Color: Blue\n");
			break;
		case 3:	printf("Color: Black\n");
			break;
		case 4: printf("Color: White\n");
			break;
	}

	printf("Move : %.1f\n",move_length);
	printf("Power: %d\n",attack_power);

}


int main(){

	int shape, color, attack_power;
	double size_of_body, move_length;
		shape = 1; // ---1=Square --- 2=Rectangular --- 3=Circular ---
		size_of_body = CreateBody (shape);
		color = 798;
		color = SetColor(color);
		move_length = LoadMoves(shape, size_of_body);
		attack_power = SetAttackPower (0, 150);
		ShowPokemon(shape, size_of_body, color, move_length, attack_power);

	return 0;
}


