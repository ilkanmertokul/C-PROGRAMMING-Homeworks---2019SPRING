#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//ILKAN MERT OKUL

//I RECCOMEND YOU TO READ WITH = TAB SIZE:4.

typedef enum { noone=0, cap, car } player_type;
typedef enum { start=0, property, tax, punish ,fortune} block_type;

/*************STRUCTS********************/

struct player{
	
	player_type type;

	int current_block_id; 		
	int owned_block_ids[11];	
	int account;		
	int turn_to_wait; 	

	char name[3];			
};

struct block{

	char name[15]; 	
	
	int block_id;	
	int price;		
	
	int rent;		
	int rent_1;
	int rent_2;
	int rent_3;

	int house_price;
	int house_count;

	struct player owner;
	block_type type;		

	struct block *next;
};

struct fortune{

	char name[15];
};

/****************************************/

void init_the_board(struct block *new){

	strcpy(new->name,"Start");
	new->block_id=0;
	new->type=start;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Esenyurt");
	new->block_id=1;
	new->price=16000;
	new->rent=800;
	new->rent_1=4000;
	new->rent_2=9000;
	new->rent_3=25000;
	new->house_price=10000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Car Park");
	new->block_id=2;
	new->type=tax;
	new->rent=1500;	

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Fortune Card");
	new->block_id=3;
	new->type=fortune;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Tuzla");
	new->block_id=4;
	new->price=16500;
	new->rent=850;
	new->rent_1=4250;
	new->rent_2=9500;
	new->rent_3=26000;
	new->house_price=12000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Arnavutkoy");
	new->block_id=5;
	new->price=17000;
	new->rent=875;
	new->rent_1=4500;
	new->rent_2=10000;
	new->rent_3=28000;
	new->house_price=12000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Wait 2 Turn");
	new->block_id=6;
	new->type=punish;
	new->rent=2;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Catalca");
	new->block_id=7;
	new->price=20000;
	new->rent=1000;
	new->rent_1=5000;
	new->rent_2=12000;
	new->rent_3=30000;
	new->house_price=13000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Beykoz");
	new->block_id=8;
	new->price=23000;
	new->rent=1100;
	new->rent_1=5500;
	new->rent_2=12500;
	new->rent_3=33000;
	new->house_price=13000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Fortune Card");
	new->block_id=9;
	new->type=fortune;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Car Fix");
	new->block_id=10;
	new->type=tax;
	new->rent=1750;	

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Maltepe");
	new->block_id=11;
	new->price=30000;
	new->rent=1350;
	new->rent_1=7000;
	new->rent_2=15000;
	new->rent_3=40000;
	new->house_price=15000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Bills");
	new->block_id=12;
	new->type=tax;
	new->rent=2000;	

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Sisli");
	new->block_id=13;
	new->price=33000;
	new->rent=1500;
	new->rent_1=8000;
	new->rent_2=16000;
	new->rent_3=42000;
	new->house_price=16000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Oil");
	new->block_id=14;
	new->type=tax;
	new->rent=2250;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Fortune Card");
	new->block_id=15;
	new->type=fortune;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Atasehir");
	new->block_id=16;
	new->price=35000;
	new->rent=1600;
	new->rent_1=8500;
	new->rent_2=17000;
	new->rent_3=45000;
	new->house_price=17000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Sariyer");
	new->block_id=17;
	new->price=40000;
	new->rent=1750;
	new->rent_1=9500;
	new->rent_2=19000;
	new->rent_3=48000;
	new->house_price=19000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Wait 1 Turn");
	new->block_id=18;
	new->type=punish;
	new->rent=1;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Kadikoy");
	new->block_id=19;
	new->price=43000;
	new->rent=1900;
	new->rent_1=11000;
	new->rent_2=21500;
	new->rent_3=55000;
	new->house_price=23000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Besiktas");
	new->block_id=20;
	new->price=60000;
	new->rent=2500;
	new->rent_1=15000;
	new->rent_2=28000;
	new->rent_3=60000;
	new->house_price=30000;
	new->house_count=0;
	new->type=property;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Fortune Card");
	new->block_id=21;
	new->type=fortune;

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Vacation");
	new->block_id=22;
	new->type=tax;
	new->rent=5000;	

	new->next=malloc(sizeof(struct block));
	new=new->next;

	strcpy(new->name,"Bebek");
	new->block_id=23;
	new->price=70000;
	new->rent=3500;
	new->rent_1=20000;
	new->rent_2=35500;
	new->rent_3=65000;
	new->house_price=35000;
	new->house_count=0;
	new->type=property;
}

void init_the_fortune(struct fortune f[5]){

	strcpy(f[0].name,"Free House");
	strcpy(f[1].name,"Time Travel");
	strcpy(f[2].name,"Garnishment");
	strcpy(f[3].name,"Generosity");
	strcpy(f[4].name,"Treasuse hunter");
}

void show_board(struct block *new,struct block *head,struct player player_one, struct player player_ai){

	int i,j,a,b;

	for(i=0;i<164;i++)	printf("-");
	printf("\n");
	for(i=0;i<7;i++){
		printf("|\t%8s\t",new->name);
		new=new->next;
	}
	printf("\n");
	new=head;
	for(i=0;i<7;i++){
		printf("|\t");
		if(new->type==property)		printf("%8d$\t",new->price);
		else if(new->type==tax)		printf("%8d$\t",new->rent);
		else 						printf("    \t\t");
		new=new->next;
	}
	printf("\n");
	new=head;
	for(i=0;i<7;i++){
		printf("|\t");
		if(player_one.current_block_id==new->block_id)	printf("%s\t",player_one.name);
		else 											printf("\t");

		if(player_ai.current_block_id==new->block_id)	printf("%s\t" ,player_ai.name);
		else 											printf("\t");

		new=new->next;
	}
	printf("\n");
	for(i=0;i<164;i++)	printf("-");
	printf("\n");

	a=7;
	b=23;

	for(i=0;i<5;i++){

		//name

		new=head;
		for(j=0;j<b;j++)	new=new->next;
		printf("|\t%8s\t|",new->name);
		for(j=0;j<15;j++)	printf("\t");
		new=head;
		for(j=0;j<a;j++)	new=new->next;
		printf("|\t%8s\t",new->name);	
		printf("\n");

		//price

		printf("|\t");
		new=head;
		for(j=0;j<b;j++)	new=new->next;
		if(new->type==property)	printf("%8d$\t",new->price);
		else if(new->type==tax)	printf("%8d$\t",new->rent);
		else 						printf("    \t\t");
		printf("|");
		for(j=0;j<15;j++)	printf("\t");
		printf("|\t");
		new=head;
		for(j=0;j<a;j++)	new=new->next;
		if(new->type==property)	printf("%d$\t",new->price);
		else if(new->type==tax)	printf("%d$\t",new->rent);
		else 						printf("    \t");
		printf("\n");

		//players

		printf("|\t");
		new=head;
		for(j=0;j<b;j++)	new=new->next;
		if(player_one.current_block_id==new->block_id)		printf("%s\t",player_one.name);
		else 												printf("\t");		
		if(player_ai.current_block_id==new->block_id)		printf("%s\t|",player_ai.name);
		else												printf("\t|");	

		for(j=0;j<15;j++)	printf("\t");

		printf("|\t");	
		new=head;
		for(j=0;j<a;j++)	new=new->next;
		if(player_one.current_block_id==new->block_id)		printf("%s\t",player_one.name);
		else 												printf("\t");		
		if(player_ai.current_block_id==new->block_id)		printf("%s\t",player_ai.name);
		else												printf("\t");	

		printf("\n");

		if(i!=4){	
			for(j=0;j<=24;j++)	printf("-");
			for(j=0;j<15;j++)	printf("\t");
			for(j=0;j<21;j++)	printf("-");
			printf("\n");
		}

		a++;
		b--;
	}


	for(i=0;i<164;i++)	printf("-");
	printf("\n");

	for(i=7;i>0;i--){
		new=head;
		for(j=0;j<i+11;j++)	new=new->next;
		printf("|\t%8s\t",new->name);
	}
	printf("\n");
	for(i=7;i>0;i--){

		new=head;
		for(j=0;j<i+11;j++)	new=new->next;

		printf("|\t");
		if(new->type==property)		printf("%8d$\t",new->price);
		else if(new->type==tax)		printf("%8d$\t",new->rent);
		else 						printf("    \t\t");
	}
	printf("\n");
	for(i=7;i>0;i--){

		new=head;
		for(j=0;j<i+11;j++)	new=new->next;

		printf("|\t");
		if(player_one.current_block_id==new->block_id)	printf("%s\t",player_one.name);
		else 											printf("\t");

		if(player_ai.current_block_id==new->block_id)	printf("%s\t" ,player_ai.name);
		else 											printf("\t");
	}
	printf("\n");
	for(i=0;i<164;i++)	printf("-");
	printf("\n");

	return;
}

int total_value(struct block *new,struct block *head,struct player current){

	int total=0,i,j;

	for(i=0;i<11;i++){
		if(current.owned_block_ids[i]!=99){

			new=head;
			for(j=0;j<current.owned_block_ids[i];j++)	new=new->next;
			total+=(new->price+(new->house_count*new->house_price))/2;
		}
	}
	return total+=current.account;
}

void sell_property(struct block *new,struct block *head, struct player* current_player){

	int i,sell_price,choice,j;

	printf("You will get half of the money you bought.\n");

	for(i=0;i<11;i++){
		if(current_player->owned_block_ids[i]!=99){
			
			new=head;
			for(j=0;j<current_player->owned_block_ids[i];j++)	new=new->next;
			printf("%s - ",new->name);
			sell_price=(new->price+(new->house_count*new->house_price))/2;
			printf("If you sell you will get : %d $.\n",sell_price);

			printf("Press 1 to sell, press 2 to move to next property, 3 to exit.\n");
			printf("Current balance: %d\n",current_player->account);
			scanf("%d",&choice);

			if(choice==1){
				current_player->account+=sell_price;
				current_player->owned_block_ids[i]=99;
			}
			else if(choice==2)	printf("Next:\n");
			else i=12;
		}
	}
	new=head;
	return;
}

void show_properties(struct block *new, struct block *head){

	int i, choice;

	new=head;
	for(i=0;i<24;i++){
		if(new->type==property) printf("%d %s\n",i,new->name);
		new=new->next;
	}

	printf("Enter an id to check a property deeds.\n");
	do{
		scanf("%d",&choice);
		new=head;
		for(i=0;i<choice;i++)	new=new->next;
		if(new->type==property)	break;
		else	printf("You entered a wrong value.\n");
	}while(1);

	for(i=0;i<33;i++)	printf("-");
	printf("\n|\t\t%s\t\t\n",new->name);
	for(i=0;i<33;i++)	printf("-");
	printf("\n|\tRent\t\t%d$\t|\n",new->rent);	
	printf("|\tRent 1 H\t%d$\t|\n",new->rent_1);	
	printf("|\tRent 2 H\t%d$\t|\n",new->rent_2);	
	printf("|\tRent 3 H\t%d$\t|\n",new->rent_3);	
	for(i=0;i<33;i++)	printf("-");
	printf("\n");


	return; 
}

void buy_property(struct block *new, struct block *head, struct player* current_player){

	int i;

	if  (new->type==property){
							
		if(current_player->account-new->price>0){
		for(i=0;i<11;i++){
			if(current_player->owned_block_ids[i]==0){
				current_player->owned_block_ids[i]=new->block_id;
				current_player->account-=new->price;
				printf("Succesfully bought %s! New account: %d\n",new->name,current_player->account);
				i=12;
				}
			}
		}					
		else	printf("You can't buy this!\n");	
	}
	else	printf("It is not a property.\n");

	return;	
}

void gameplay(struct block *new,struct block *head,struct player player_one, struct player player_ai){

	struct fortune f[5];
	int i,j,i_max,b_max;
	int game_flag=1,turn_flag=1;
	int menu_choice,y_r_n,property_flag=1,buy_flag;
	int price_to_pay,t_value,fortune_card,dice,h_c,property_count,ave,counter_property,total_property;

	printf("Welcome to Monopoly!\n");
	printf("You are the car!, Ai is cap!\n");

	init_the_fortune(f);

	while(game_flag==1){

		new=head;
		show_board(new,head,player_one,player_ai);
		new=head;
		printf("%d$ , total value you have :%d\n",player_one.account,total_value(new,head,player_one));

		printf("It's your turn.\n");
		turn_flag=1;

		while(turn_flag==1){

			//USER

			if(player_one.turn_to_wait>0){
				printf("You need to wait %d more turns, Your turn will end right now.\n",player_one.turn_to_wait);
				menu_choice=-1;
				player_one.turn_to_wait--;
				turn_flag=0;
			}
			else{
				printf("1-) Roll the dice.(Ends the current turn.)\n");
				printf("2-) Show my account.\n");
				printf("3-) Show my properties.\n");
				printf("4-) Show property deeds.\n");
				printf("5-) Buy property\n");
				printf("6-) Buy house\n");
				printf("7-) Sell porperty\n");

				scanf("%d",&menu_choice);
			}

			new=head;
			for(i=0;i<player_one.current_block_id;i++)	new=new->next;

			switch(menu_choice){

				case 1: //THROW DICE.

						dice=rand()%6+1;
						player_one.current_block_id=player_one.current_block_id+dice;
						if(player_one.current_block_id>23){
							player_one.current_block_id=player_one.current_block_id%24;
							player_one.account+=10000;
						}

						printf("You landed on : ");
						new=head;
						while(new->block_id!=player_one.current_block_id)	new=new->next;
						printf("%s (Block_id : %d )!\n",new->name,new->block_id);

						if(new->type==fortune){

							fortune_card=rand()%5;

							printf("%s!\n",f[fortune_card].name);

							switch(fortune_card){
								case 0:	printf("Build a house on one of your properties for free.\n");

										for(i=0;i<11;i++){

											if(player_one.owned_block_ids[i]!=99){
												new=head;
												while(new->block_id!=player_one.owned_block_ids[i])	new=new->next;

												printf("Do you want to build a house to %s? \n",new->name);
												printf("1-YES 2-move to next property you have.\n");
												scanf("%d",&y_r_n);

												if(y_r_n==1){

													if(new->house_count==3)	printf("You have max amount of house there.\n");
													else{	
														printf("Succesfully bought.\n");
														new->house_count++;
														i=12;
													}
												}
											}
										}
										break;

								case 1: printf("Roll a dice. If result is 1-3, move 2 foward. Else, move 2 backward.\n");
										dice=rand()%6+1;

										if(dice>3){
											printf("You rolled %d. You will move 2 backward \n",dice);
											player_one.current_block_id-=2;
										}
										else{
											printf("You rolled %d. You will move 2 foward\n",dice);
											player_one.current_block_id+=2;
										}
										break;

								case 2: printf("Pay 5000$ to the bank.\n");

										if(player_one.account>=5000){
											player_one.account-=5000;
											printf("You succesfully paid. New balance: %d\n",player_one.account);
										}
										else{
											printf("You don't have money to pay. \n");
											t_value=total_value(new,head,player_one);

											if(t_value<5000){
												printf("Bankrupt! Computer won the game..\n");
												return;
											}
											else{
												printf("You need to sell your properties.\n");

												while(player_one.account<5000)	sell_property(new,head,&player_one);
												player_one.account-=5000;
											}
										}
										break;

								case 3: printf("Give 10000$ to the opponent.\n");

										if(player_one.account>=10000){
											player_one.account-=10000;
											player_ai.account+=10000;
											printf("You succesfully paid. New balance: %d\n",player_one.account);
										}
										else{
											printf("You don't have money to pay. \n");
											t_value=total_value(new,head,player_one);

											if(t_value<10000){
												printf("Bankrupt! Computer won the game..\n");
												return;
											}
											else{
												printf("You need to sell your properties.\n");

												while(player_one.account<10000)	sell_property(new,head,&player_one);
												player_one.account-=10000;
												player_ai.account+=10000;
											}
										}
										break;

								case 4: printf("Take 20000$ from the bank.\n");

										player_one.account+=20000;

										break;
							}
						}//IF-FORTUNE'S

						new=head;
						while(new->block_id!=player_one.current_block_id)	new=new->next;

						//

						if(new->type==property){	
							property_flag=1;

							for(i=0;i<11;i++){
								if(player_one.current_block_id==player_one.owned_block_ids[i]){

									printf("You already own %s.",new->name);
									property_flag=0;
								}
							}

							for(i=0;i<11;i++){	
								if(player_one.current_block_id==player_ai.owned_block_ids[i]){
									printf("%s is owned by computer.\n",new->name);

									if(new->house_count==0)			price_to_pay=new->rent;
									else if(new->house_count==1)	price_to_pay=new->rent_1;
									else if(new->house_count==2)	price_to_pay=new->rent_2;
									else 							price_to_pay=new->rent_3;

									if(player_one.account>=price_to_pay){
										printf("You paid %d\n",price_to_pay);
										player_one.account-=price_to_pay;
										player_ai.account+=price_to_pay;
									}
									else{
										printf("You need to pay %d but you dont have that much money.\n",price_to_pay);

										t_value=total_value(new,head,player_one);

										if(t_value>=price_to_pay){
											printf("You need to sell your properties.\n");

											while(player_one.account<price_to_pay)	sell_property(new,head,&player_one);
											player_one.account-=price_to_pay;
											player_ai.account+=price_to_pay;

										}
										else{
											printf("Bankrupt! Computer won the game..\n");
											return;
										}
									}
									property_flag=0;
								}
							}

							if(property_flag==1){

								printf("Do you want to buy it? 1- YES 2 -NO\n");
								scanf("%d",&y_r_n);

								if(y_r_n==1){
									new=head;
									while(new->block_id!=player_one.current_block_id)	new=new->next;
									if(player_one.account>=new->price){
										printf("Succesfully bought!\n");
										player_one.account-=new->price;

										for(i=0;i<11;i++){
											if(player_one.owned_block_ids[i]==99){
												player_one.owned_block_ids[i]=new->block_id;
												i=12;
											}
										}
									}
									else printf("You cant buy, you dont have %d\n",new->price);
								}
								else	printf("You did not wanted to buy there.\n");
							}
						}//IF-PROPERTY'S						
						else if(new->type==tax){

							price_to_pay=new->rent;

							if(player_one.account>=price_to_pay){
								printf("You paid %d $.\n",price_to_pay);
								player_one.account-=price_to_pay;
							}
							else{
								t_value=total_value(new,head,player_one);

								if(t_value>=price_to_pay){
									printf("You need to sell your properties.\n");

									while(player_one.account<price_to_pay)	sell_property(new,head,&player_one);
									player_one.account-=price_to_pay;
								}
								else{
									printf("Bankrupt! Computer won the game..\n");
									return;
								}
							}
						}//IF-TAX'S
						else if(new->type==punish){

							printf("You need to wait %d turns now!\n",new->rent);
							player_one.turn_to_wait=new->rent;
						}//IF-PUNISH'S

						new=head;
						turn_flag=0;
						break;

				case 2: //BALANCE
						
						printf("Your account: %d \n Coumputer's account: %d \n",player_one.account,player_ai.account);
						break;

				case 3: //OWNED BLOCKS			

						for(i=0;i<11;i++){
							new=head;
							if(player_one.owned_block_ids[i]!=99){
							for(j=0;j<player_one.owned_block_ids[i];j++)	new=new->next;
							printf("%s\n",new->name);
							}
						}
						break;

				case 4:	//SHOW ALL PROPERTIES
				
						show_properties(new,head);
						break;	

				case 5: //BUY A PROPERTY

						buy_flag=1;
						for(i=0;i<11;i++){
							if(player_one.owned_block_ids[i]==player_one.current_block_id)	buy_flag=0;
							if(player_ai.owned_block_ids[i]==player_one.current_block_id)	buy_flag=0;
						}

						if(buy_flag==0)	printf("You can't buy there!\n");	
						else 			buy_property(new,head,&player_one);
						break;		

				case 6: //BUILD A HOUSE 		

						for(i=0;i<11;i++){
							if(player_one.owned_block_ids[i]==new->block_id){
								printf("Each house price is %d for %s.\n",new->house_price,new->name);
								printf("How much do you want to buy?\n");
								scanf("%d",&h_c);

								if(h_c*-new->house_price<=player_one.account){

										if(h_c+new->house_count<=3){
											player_one.account-=h_c*new->house_price;
											new->house_count+=h_c;
										}
										else printf("You cant build more than 3 houses in total.\n");
									}
									else	printf("Not enough balance.\n");
									i=12;
							}
						}
						break;

				case 7:		sell_property(new,head,&player_one);

				case -1:	break;

				default:	printf("You entered a wrong value..\n");

			}//SWITCH-MENUCHOICE'S

		}//WHILE-TURNFLAG'S

			//COMPUTER-

			new=head;

			if(player_ai.turn_to_wait<1){
				dice=rand()%6+1;

				player_ai.current_block_id=player_ai.current_block_id+dice;
				if(player_ai.current_block_id>23){
					player_ai.current_block_id=player_ai.current_block_id%24;
					player_ai.account+=10000;
				}

				new=head;
				while(new->block_id!=player_ai.current_block_id)	new=new->next;
				printf("Computer rolled %d and landed on %s\n",dice,new->name);

				if(new->type==fortune){

					fortune_card=rand()%5;
					printf("%s!\n",f[fortune_card].name);

					switch(fortune_card){
							case 0:	printf("Computer builds a house.\n");

									for(i=0;i<11;i++){

										if(player_ai.owned_block_ids[i]!=99){
										new=head;
										while(new->block_id!=player_ai.owned_block_ids[i])	new=new->next;

										if(new->house_count==3);
										else{	
											new->house_count++;
											i=12;
											}
										}
									}
									break;

							case 1: printf("Computer rolls a dice. If result is 1-3, move 2 foward. Else, move 2 backward.\n");
									dice=rand()%6+1;

									if(dice>3){
										printf("Rolled %d. You will move 2 backward \n",dice);
										player_ai.current_block_id-=2;
									}
									else{
										printf("Rolled %d. You will move 2 foward\n",dice);
										player_ai.current_block_id+=2;
									}
									break;

							case 2: printf("Computer pays 5000$ to the bank.\n");

									if(player_ai.account>=5000){
										player_ai.account-=5000;
									}
									else{
										t_value=total_value(new,head,player_ai);

										if(t_value<5000){
											printf("Bankrupt! You won the game!!\n");
											return;
										}
										else{
											while(player_ai.account<5000){

												i_max=-1;
												b_max=-1;
												for(i=0;i<11;i++){
													if(player_ai.owned_block_ids[i]!=99){
														if(b_max<player_ai.owned_block_ids[i]){
															b_max=player_ai.owned_block_ids[i];
															i_max=i;
														}
													}

													if(i_max!=-1){
														player_ai.owned_block_ids[i_max]=99;
														new=head;
														while(new->block_id!=player_ai.owned_block_ids[i_max])	new=new->next;
														player_ai.account=player_ai.account+(new->price+new->house_count*new->house_price)/2;
													}
												}
											}
											player_ai.account-=5000;
										}
									}
									break;

							case 3: printf("Computer gives 10000$ to you.\n");

									if(player_ai.account>=10000){
										player_ai.account-=10000;
										player_one.account+=10000;
									}
									else{
										t_value=total_value(new,head,player_ai);
										if(t_value<10000){
											printf("Bankrupt! You won the game!!\n");
											return;
										}
										else{
											while(player_ai.account<10000){

												i_max=-1;
												b_max=-1;
												for(i=0;i<11;i++){
													if(player_ai.owned_block_ids[i]!=99){
														if(b_max<player_ai.owned_block_ids[i]){
															b_max=player_ai.owned_block_ids[i];
															i_max=i;
														}
													}

													if(i_max!=-1){
														player_ai.owned_block_ids[i_max]=99;
													
														new=head;
														while(new->block_id!=player_ai.owned_block_ids[i_max])	new=new->next;
														player_ai.account=player_ai.account+(new->price+new->house_count*new->house_price)/2;
													}
												}
											}
											player_ai.account-=10000;
											player_one.account+=10000;
											}
										}
									break;

							case 4: printf("Computer takes 20000$ from the bank.\n");

									player_ai.account+=20000;

									break;
					}
				}//IF FORTUNE'S COMPUTER

				new=head;
				while(new->block_id!=player_ai.current_block_id)	new=new->next;

				if(new->type==property){

					property_flag=1;

					new=head;
					while(new->block_id!=player_ai.current_block_id)	new=new->next;

					for(i=0;i<11;i++){
						if(player_ai.current_block_id==player_ai.owned_block_ids[i]){
							if(new->house_count<3){

								property_count=0;
								for(j=0;j<11;j++){
									if(player_ai.owned_block_ids[j]!=99)	property_count++;
								}

								if(property_count>=4 && rand()%2==0){

									if(player_ai.account>=new->house_price){
										printf("Computer bought a house for %s\n",new->name);
										new->house_count++;
										player_ai.account-=new->house_price;
									}
								}
							}
							property_flag=0;
						}
					}

					new=head;
					while(new->block_id!=player_ai.current_block_id)	new=new->next;

					for(i=0;i<11;i++){

						if(player_ai.current_block_id==player_one.owned_block_ids[i]){
							printf("%s is owned by you!\n",new->name);

							if(new->house_count==0)			price_to_pay=new->rent;
							else if(new->house_count==1)	price_to_pay=new->rent_1;
							else if(new->house_count==2)	price_to_pay=new->rent_2;
							else 							price_to_pay=new->rent_3;

							if(player_ai.account>=price_to_pay){
								printf("Computer paid you %d.\n",price_to_pay);
								player_ai.account-=price_to_pay;
								player_one.account+=price_to_pay;
							}
							else{

								t_value=total_value(new,head,player_ai);

								if(t_value<price_to_pay){
									printf("Bankrupt! You won the game!!\n");
									return;
								}
								else{
									printf("Computer paid you %d.\n",price_to_pay);
									while(player_ai.account<price_to_pay){

										i_max=-1;
										b_max=-1;

										
										for(i=0;i<11;i++){
											if(player_ai.owned_block_ids[i]!=99){
												if(b_max<player_ai.owned_block_ids[i]){
													b_max=player_ai.owned_block_ids[i];
													i_max=i;
												}
											}
										
											if(i_max!=-1){
												player_ai.owned_block_ids[i_max]==99;
												new=head;
												while(new->block_id!=player_ai.owned_block_ids[i_max])	new=new->next;
												player_ai.account=player_ai.account+(new->price+new->house_count*new->house_price)/2;
											}
										}
									}
									player_ai.account-=price_to_pay;
									player_one.account+=price_to_pay;
								}
							}
							property_flag=0;
						}
					}

					if(property_flag==1){

						new=head;
						counter_property=0;
						total_property=0;

						while(new->next!=NULL){
							if(new->type==property){
								total_property+=new->price;
								counter_property++;
							}
							new=new->next;
						}

						ave=total_property/counter_property;

						new=head;
						while(new->block_id!=player_ai.current_block_id)	new=new->next;

						if(ave>new->price){
							if(player_ai.account>=new->price){
								for(i=0;i<11;i++){
									if(player_ai.owned_block_ids[i]==99){
										printf("Computer bought %s\n",new->name);
										player_ai.owned_block_ids[i]=new->block_id;
										player_ai.account-=new->price;
										i=12;
									}
								}
							}
						}
						else{
							if(rand()%2==0){
								if(player_ai.account>=new->price){
									for(i=0;i<11;i++){
										if(player_ai.owned_block_ids[i]==99){
											printf("Computer bought %s\n",new->name);
											player_ai.owned_block_ids[i]=new->block_id;
											player_ai.account-=new->price;
											i=12;
										}
									}
								}
							}
						}
					}

					new=head;
					while(new->block_id!=player_ai.current_block_id)	new=new->next;
				}//IF-PROPERTY-COMPUTER'S
				else if(new->type==tax){

					price_to_pay=new->rent;

					printf("Computer pays %d$ to the bank.\n",price_to_pay);

					if(player_ai.account>=price_to_pay){
						player_ai.account-=price_to_pay;
					}
					else{
						t_value=total_value(new,head,player_ai);

						if(t_value<price_to_pay){
							printf("Bankrupt! You won the game!!\n");
							return;
						}
						else{
							while(player_ai.account<price_to_pay){

								i_max=-1;
								b_max=-1;
								for(i=0;i<11;i++){
									if(player_ai.owned_block_ids[i]!=99){
										if(b_max<player_ai.owned_block_ids[i]){
											b_max=player_ai.owned_block_ids[i];
											i_max=i;
										}
									}

									if(i_max!=-1){
										player_ai.owned_block_ids[i_max]=99;
										new=head;
										while(new->block_id!=player_ai.owned_block_ids[i_max])	new=new->next;
										player_ai.account=player_ai.account+(new->price+new->house_count*new->house_price)/2;
									}
								}
							}
							player_ai.account-=price_to_pay;
						}
					}
				}//IF-TAX-COMPUTER'S
				else if(new->type==punish){
					player_ai.turn_to_wait=new->rent;
					printf("Computer punished! Needs to wait %d turn.\n",new->rent);
				}
			}//WHOLE COMPUTER'S IF
			else{
				player_ai.turn_to_wait--;
				printf("Computer has to wait.\n");
			}


	}//WHILE-GAMEFLAG'S

}//whole FUNCTION'S 

int main(){

	struct block *head;
	struct block *new;
	struct player player_one;
	struct player player_ai;

	int i;

	head=malloc(sizeof(struct block));
	new=malloc(sizeof(struct block));

	head=new;
	init_the_board(new);
	new=head;

	player_one.current_block_id=0;
	strcpy(player_one.name,"car");
	player_one.turn_to_wait=0;
	player_one.account=100000;

	for(i=0;i<11;i++)	player_one.owned_block_ids[i]=99;
	for(i=0;i<11;i++)	player_ai.owned_block_ids[i]=99;	

	player_ai.current_block_id=0;
	strcpy(player_ai.name,"cap");
	player_ai.turn_to_wait=0;
	player_ai.account=100000;


	srand(time(NULL));

	gameplay(new,head,player_one,player_ai);


	printf("Program ended.\n");
	return 0;
}
