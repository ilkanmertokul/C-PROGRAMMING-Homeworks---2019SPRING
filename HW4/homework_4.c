/*

ILKAN MERT OKUL, 1801042649. 

There is a part of battle function (Attacking) is missing.

*/

#include <stdio.h>

#include <time.h>
#include <stdlib.h>

typedef enum attack_type { quadratic, linear} attack_type;
typedef enum pokemon {Charmander,Pikachu,Squirtle,Balbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby} pokemon;

//////////////////////////////////////////////////////////////////////////////////
//part2, Oak's functions.

void show_Pokemons(char Pokemon_name[][11], pokemon Pokemons[], int pokemon_count){
	
	printf("\n");
	for(pokemon_count=0;pokemon_count<10;pokemon_count++){
		printf("%d - %s\n",pokemon_count,&Pokemon_name[pokemon_count][0]);
	}
	printf("\n");
}

void catch_a_pokemon(char Pokemon_name[][11], pokemon Pokemons[], pokemon my_pocket[]){

	int poke_count=0,choice;
	show_Pokemons(Pokemon_name,Pokemons,poke_count);

	while(poke_count<4){
		printf("#%d Pokemon: What pokemon do you want to choose?",poke_count+1);
		scanf("%d",&choice);

			if(my_pocket[poke_count-1]==choice){
				printf("You already catched this pokemon.\n");
			}		
			else{
				my_pocket[poke_count]=choice;
				poke_count++;
			}
	}
	printf("\nYour pokemon choices: %d %d %d %d\n",my_pocket[0],my_pocket[1],my_pocket[2],my_pocket[3]);
}

void release_a_pokemon(char Pokemon_name[][11], pokemon Pokemons[], pokemon my_pocket[]){

	int i,choice;
	printf("Which pokemon do you want to release?\n");
	
	for(i=0;i<4;i++){

		if(my_pocket[i]==15){
			printf("Number:%d) empty.\n",i);
		}		
		else{
			printf("Number:%d) %s\n",i,&Pokemon_name[my_pocket[i]][0]);
		}
	}
	scanf("%d",&choice);
	my_pocket[choice]=15;	
}

void show_pokemon(char Pokemon_name[][11],pokemon my_pocket[]){
	
	int i;
	for(i=0;i<4;i++){

		if(my_pocket[i]==15){
			printf("Number:%d) empty.\n",i);
		}		
		else{
			printf("Number:%d) %s\n",i,&Pokemon_name[my_pocket[i]][0]);
		}
	}
	printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void pokedex(char Pokemon_name[][11], int range[], attack_type type[10], int attack_power[], int stamina[]){

	char choice[15];
	int i=0,j=0,k=15,a=1,flag=1;

	//A loop to see pokedex.
	while(flag==1){
		printf("Please type name of the pokemon (type exit to close Pokedex.)\n");
		scanf("%s",choice);

		k=15;
		a=1;
		j=0;
		while(j<11){
			i=0;
			while(choice[i]==Pokemon_name[j][i] && i<11 && a==1){
				if(i==3){
					a=0;
					k=j;
				}
				i++;	
			}
		j++;
		}

		if(k>=0 && k<=10){
			printf("Name: %s\nA.type: ",&Pokemon_name[k][0]);
			if(type[k]==0)	printf("Quadratic.\n");
			else		printf("Linear.\n");
			printf("Range: %d block(s)\n",range[k]);
			printf("A. power: %d\n",attack_power[k]);
			printf("Stamina: %d\n\n",stamina[k]);
		}
		else{
			flag=0;
		}	
	}
}

void oaks_laboratory(char Pokemon_name[][11], pokemon Pokemons[], pokemon my_Pokemons[]){

	int choice,flag=1,poke_count=0,a=1;	
	while(a==1){
		printf("Welcome to Laboratory of Professor Oak. How can i help you?\n");
		printf("1) Show pokemons.\n");
		printf("2) Catch a pokemon.\n");
		printf("3) Release a pokemon.\n");
		printf("4) Show my pocket\n");
		printf("5) Back.\n");
	
		do{
			scanf("%d",&choice);
			if(choice<1 || choice>5)	printf("You can't enter this, try again:\n");
			else flag=0;
		}while(flag==1);
		
		switch(choice){
			case 1:	 show_Pokemons(Pokemon_name, Pokemons, poke_count);
				break;
			case 2:	 catch_a_pokemon(Pokemon_name, Pokemons, my_Pokemons);
				break;
			case 3:	release_a_pokemon(Pokemon_name, Pokemons, my_Pokemons);
				break;
			case 4:	show_pokemon(Pokemon_name, my_Pokemons);
				break;
			case 5: a=0;
		}
	}
}

int main_menu(){
	
	int choice,flag=1;

	printf("Please select an option to continue:\n");
	printf("1)\tOpen Pokedex\n");
	printf("2)\tGo to Oak's Laboratory\n");
	printf("3)\tEnter the tournament.\n");
		
	do{

	scanf("%d",&choice);
	if(choice<1 || choice>3)	printf("You can't enter this, try again:\n");
	else flag=0;

	}while(flag==1);
	
	return choice;
}

//The show area function for battle function.
void show_area (char Pokemon_name[][11],int area[8][8],int pokemon_staminas[]){

	int i,j;

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			printf("|");	
			if(area[i][j]!=99){
				switch(area[i][j]){
					case 0: printf(" Ch\t");
						break;
					case 1: printf(" Pi\t");
						break;
					case 2: printf(" Sq\t");
						break;
					case 3: printf(" Ba\t");
						break;
					case 4: printf(" Pd\t");
						break;
					case 5: printf(" Ra\t");
						break;
					case 6: printf(" Mu\t");
						break;
					case 7: printf(" Ca\t");
						break;
					case 8: printf(" Zu\t");
						break;
					case 9: printf(" Kr\t");
						break;
				}			
			}
			else{
				printf("   \t");
			}
		}
		printf("\n");
		for(j=0;j<8;j++){
			printf("|");
			if(area[i][j]!=99){
				printf("%d\t",pokemon_staminas[area[i][j]]);
			}
			else{
				printf("   \t");
			}
		}
		printf("\n----------------------------------------------------------------\n");
	}
}

void battle(char Pokemon_name[][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]){

	int i,j,k=0;
	int flag=1,flag2=1;
	int area[8][8];
	int current_staminas[10];

	int choicex[8],choicey[8],temp,pokechoose,move;
	
	//This 2 for loops assings staminas and areas as "standart"
	for(i=0;i<10;i++){
		current_staminas[i]=stamina[i];
	}

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			area[i][j]=99;	//99 means "standart" for me. İf the value is 99, it is empty place.
		}
	}

	//A location picker for user. It starts from x=0-7 and y=0-7.
	for(i=0;i<4;i++){
		printf("Enter your #%d pokemons location:\n",i);
		printf("First enter your y-location (0 or 1)\n");
		printf("After that, enter x-location (0 to 7)\n");
		
		while(flag==1){
			scanf("%d",&temp);
			choicey[i]=temp;
			scanf("%d",&temp);
			choicex[i]=temp;

			if(choicey[i]>1 ||choicey[i]<0 ||choicex[i]<0 ||choicex[i]>7 || area[choicey[i]][choicex[i]]!=99){
				printf("You cannot enter this values.\n"); //this gives the error mesage.
			}
			else{
				flag=0;
			}			
		}	
		flag=1;
		area[choicey[i]][choicex[i]]=user_Pokemons[i];
	}

	//same location picker, but for AI. It also picks 4 non-user pokemons.
	for(i=4;i<8;i++){

		while(flag==1){
			choicex[i]=rand()%8;
			choicey[i]=rand()%2+6;
			if(area[choicey[i]][choicex[i]]!=99);
			else{
				flag=0;
			}
		}
		flag=1;

		while (flag==1){
			area[choicey[i]][choicex[i]]=rand()%10;		
			k=0;
			for(j=0;j<4;j++){
				if(area[choicey[i]][choicex[i]]!=user_Pokemons[j]){
					k++;
				}
			}
			if(k==4)	flag=0;
		}
		flag=1;
	}

	//Whole battle loop to move and attack. Unfortunately i couldn't able to make battle function.
	while(flag==1){
		show_area(Pokemon_name,area,current_staminas);
		printf("What pokemon do you want to move?\n");
		for(i=0;i<4;i++)	printf("#%d) %s\n",i,&Pokemon_name[user_Pokemons[i]][0]);

		do{
			scanf("%d",&pokechoose);
			if(pokechoose<0||pokechoose>3)	printf("You cannot enter this values.\n");
			else	flag2=0;

		}while(flag2==1);
		flag2=1;
	
		printf("Press (4,2,6,8) to move.\n");

		do{
			scanf("%d",&move);
			
			switch(move){
				case 4:	if(choicex[pokechoose]!=0){
						if(area[choicey[pokechoose]][choicex[pokechoose]-1]!=99){
							printf("You are unable to move there.\n");	
						}
						else{
							area[choicey[pokechoose]][choicex[pokechoose]-1]=user_Pokemons[pokechoose];
							area[choicey[pokechoose]][choicex[pokechoose]]=99;							
							choicex[pokechoose]--;
							flag2=0;
						}
					}
					else printf("You are unable to move there.\n");
					break;
				case 2:	if(choicex[pokechoose]!=0){
						if(area[choicey[pokechoose]+1][choicex[pokechoose]]!=99){
							printf("You are unable to move there.\n");	
						}
						else{
							area[choicey[pokechoose]+1][choicex[pokechoose]]=user_Pokemons[pokechoose];
							area[choicey[pokechoose]][choicex[pokechoose]]=99;							
							choicey[pokechoose]++;
							flag2=0;
						}
					}
					else printf("You are unable to move there.\n");
					break;
				case 6:	if(choicex[pokechoose]!=0){
						if(area[choicey[pokechoose]][choicex[pokechoose]+1]!=99){
							printf("You are unable to move there.\n");	
						}
						else{
							area[choicey[pokechoose]][choicex[pokechoose]+1]=user_Pokemons[pokechoose];
							area[choicey[pokechoose]][choicex[pokechoose]]=99;							
							choicex[pokechoose]++;
							flag2=0;
						}
					}
					else printf("You are unable to move there.\n");
					break;
				case 8:	if(choicex[pokechoose]!=0){
						if(area[choicey[pokechoose]-1][choicex[pokechoose]]!=99){
							printf("You are unable to move there.\n");	
						}
						else{
							area[choicey[pokechoose]-1][choicex[pokechoose]]=user_Pokemons[pokechoose];
							area[choicey[pokechoose]][choicex[pokechoose]]=99;							
							choicey[pokechoose]--;
							flag2=0;
						}
					}
					else printf("You are unable to move there.\n");
					break;
				default:	printf("You entered a wrong value");			
			}
		}while(flag2==1);
		flag2=1;
				
		/*

		Battle function should have been there. But i could not write that, sorry. :(
		Battle function should have been there. But i could not write that, sorry. :(
		Battle function should have been there. But i could not write that, sorry. :(

		*/
	}

}

//Main function to call main functions like pokedex, oak's lab and battle.
int main(){

	int choice;

	char pokemon_name[10][11]={"Charmander","Pikachu","Squirtle","Balbasaur","Pidgeotto","Ratata","Mug","Caterpie","Zubat","Krabby"};
	int range[10]={1,3,4,3,2,2,1,2,3,2};
	int attack_power[10]={500,350,300,400,250,250,350,200,350,300};
	int stamina[10]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};
	enum attack_type type[10]={0,1,1,1,0,1,0,0,1,1};
	enum pokemon pokemons[10]={0,1,2,3,4,5,6,7,8,9};
	enum pokemon my_pokemons[4]={15,15,15,15};


	srand(time(NULL)); //to make rand() working.
	

	while(1){	
		choice=main_menu();

		switch(choice){
			case 1:	pokedex(pokemon_name,range,type,attack_power,stamina);
				break;
			case 2: oaks_laboratory(pokemon_name,pokemons,my_pokemons);
				break;
			case 3: battle(pokemon_name,range,type,attack_power,stamina,my_pokemons);
				break;
			default: printf("hi");
		}	
	}

	return 0;
}

