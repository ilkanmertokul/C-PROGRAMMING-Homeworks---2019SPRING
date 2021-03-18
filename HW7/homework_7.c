#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Welcome to Monopoly. İlkan Mert Okul 1801042649.

typedef enum { noone=0, cap, car } player_type;
typedef enum { start=0, property, tax, punish } block_type;

struct player{

	player_type type;	//noone ,cap (1) or car (2). 

	int current_block_id; 		//start point is zero (0).
	int owned_block_ids[11];	//a player's properties.
	int account;		//Player's balance when it is below zero, you lose.
	int turn_to_wait; 	//Can hold max value of two. And it decreases by one per turn until it gets to zero.

	char *name;			//It contains to name of the player.
}; 

struct block{

	char *name; 	//Name of the property.
	
	int block_id;	//Holds the id of the block.
	int price;		//Price of the property.
	
	int rent;		//Rents of properties, 0= no house / 3= 3 houses.
	int rent_1;
	int rent_2;
	int rent_3;

	int house_price;//Bill for constructing a house.
	int house_count;//House count.

	struct player owner;	//It contains the player who owns it.
	block_type type;		//start, property, tax or punish.
};

void init_the_board(struct block board[20]){

	//PART 1.
	//The function that initializes the board information.

	//Blocks other than properties: 
	int i;

	for(i=0;i<20;i++)	board[i].name=(char*)malloc(15*sizeof(char));

	strcpy(board[0].name,"Start");
	board[0].block_id=0;
	board[0].type=start;

	strcpy(board[2].name,"Car Park");
	board[2].block_id=2;
	board[2].type=tax;
	board[2].rent=1500;

	strcpy(board[5].name,"Wait 2 Turn");
	board[5].block_id=5;
	board[5].type=punish;
	board[5].rent=2;

	strcpy(board[8].name,"Car Fix");
	board[8].block_id=8;
	board[8].type=tax;
	board[8].rent=1750;	

	strcpy(board[10].name,"Bills");
	board[10].block_id=10;
	board[10].type=tax;
	board[10].rent=2000;

	strcpy(board[12].name,"Oil");
	board[12].block_id=12;
	board[12].type=tax;
	board[12].rent=2250;

	strcpy(board[15].name,"Wait1Turn");
	board[15].block_id=15;
	board[15].type=punish;
	board[15].rent=1;

	strcpy(board[18].name,"Vacation");
	board[18].block_id=18;
	board[18].type=tax;
	board[18].rent=5000;	

	//Properties:

	board[1].block_id=1;
	strcpy(board[1].name,"Esenyurt");
	board[1].price=16000;
	board[1].rent=800;
	board[1].rent_1=4000;
	board[1].rent_2=9000;
	board[1].rent_3=25000;
	board[1].house_price=10000;
	board[1].house_count=0;
	board[1].type=property;

	board[3].block_id=3;
	strcpy(board[3].name,"Tuzla");
	board[3].price=16500;
	board[3].rent=850;
	board[3].rent_1=4250;
	board[3].rent_2=9500;
	board[3].rent_3=26000;
	board[3].house_price=12000;
	board[3].house_count=0;
	board[3].type=property;

	board[4].block_id=4;
	strcpy(board[4].name,"Arnavutkoy");
	board[4].price=17000;
	board[4].rent=875;
	board[4].rent_1=4500;
	board[4].rent_2=10000;
	board[4].rent_3=28000;
	board[4].house_price=12000;
	board[4].house_count=0;
	board[4].type=property;

	board[6].block_id=6;
	strcpy(board[6].name,"Catalca");
	board[6].price=20000;
	board[6].rent=1000;
	board[6].rent_1=5000;
	board[6].rent_2=12000;
	board[6].rent_3=30000;
	board[6].house_price=13000;
	board[6].house_count=0;
	board[6].type=property;

	board[7].block_id=7;
	strcpy(board[7].name,"Beykoz");
	board[7].price=23000;
	board[7].rent=1100;
	board[7].rent_1=5500;
	board[7].rent_2=12500;
	board[7].rent_3=33000;
	board[7].house_price=13000;
	board[7].house_count=0;
	board[7].type=property;

	board[9].block_id=9;
	strcpy(board[9].name,"Maltepe");
	board[9].price=30000;
	board[9].rent=1350;
	board[9].rent_1=7000;
	board[9].rent_2=15000;
	board[9].rent_3=40000;
	board[9].house_price=15000;
	board[9].house_count=0;
	board[9].type=property;

	board[11].block_id=11;
	strcpy(board[11].name,"Sisli");
	board[11].price=33000;
	board[11].rent=1500;
	board[11].rent_1=8000;
	board[11].rent_2=16000;
	board[11].rent_3=42000;
	board[11].house_price=16000;
	board[11].house_count=0;
	board[11].type=property;

	board[13].block_id=13;
	strcpy(board[13].name,"Atasehir");
	board[13].price=35000;
	board[13].rent=1600;
	board[13].rent_1=8500;
	board[13].rent_2=17000;
	board[13].rent_3=45000;
	board[13].house_price=17000;
	board[13].house_count=0;
	board[13].type=property;

	board[14].block_id=14;
	strcpy(board[14].name,"Sariyer");
	board[14].price=40000;
	board[14].rent=1750;
	board[14].rent_1=9500;
	board[14].rent_2=19000;
	board[14].rent_3=48000;
	board[14].house_price=19000;
	board[14].house_count=0;
	board[14].type=property;

	board[16].block_id=16;
	strcpy(board[16].name,"Kadikoy");
	board[16].price=43000;
	board[16].rent=1900;
	board[16].rent_1=11000;
	board[16].rent_2=21500;
	board[16].rent_3=55000;
	board[16].house_price=23000;
	board[16].house_count=0;
	board[16].type=property;

	board[17].block_id=17;
	strcpy(board[17].name,"Besiktas");
	board[17].price=60000;
	board[17].rent=2500;
	board[17].rent_1=15000;
	board[17].rent_2=28000;
	board[17].rent_3=60000;
	board[17].house_price=30000;
	board[17].house_count=0;
	board[17].type=property;

	board[19].block_id=19;
	strcpy(board[19].name,"Bebek");
	board[19].price=70000;
	board[19].rent=3500;
	board[19].rent_1=20000;
	board[19].rent_2=35500;
	board[19].rent_3=65000;
	board[19].house_price=35000;
	board[19].house_count=0;
	board[19].type=property;
}

void show_board(struct block board[20], struct player player_one, struct player player_two){

	//PART 2.
	//The function that prints us the board information.

	int i,j;
	int a,b;

	for(i=0;i<100;i++)	printf("-");
	printf("\n");
	for(i=0;i<6;i++)	printf("|    %s\t",board[i].name);
	printf("\n");	
	for(i=0;i<6;i++){
		printf("|    ");
		if(board[i].type==property)	printf("%d$\t",board[i].price);
		else if(board[i].type==tax)	printf("%d$\t",board[i].rent);
		else 						printf("    \t");
	}
	printf("\n");
	for(i=0;i<6;i++){
		printf("|     ");
		if(player_one.current_block_id==board[i].block_id)	printf("%s   ",player_one.name);
		else 												printf("\t");

		if(player_two.current_block_id==board[i].block_id)	printf("%s\t",player_two.name);
		else 												printf("\t");
	}
	printf("\n");
	for(i=0;i<100;i++)	printf("-");
	printf("\n");

	a=6;
	b=19;

	for(i=0;i<4;i++){

		printf("|    %s\t|",board[b].name);
		for(j=0;j<8;j++)	printf("\t");
		printf("|    %s\t",board[a].name);	
		printf("\n");

		printf("|    ");
		if(board[b].type==property)	printf("%d$\t",board[b].price);
		else if(board[b].type==tax)	printf("%d$\t",board[b].rent);
		else 						printf("    \t");
		printf("|");
		for(j=0;j<8;j++)	printf("\t");
		printf("|    ");
		if(board[a].type==property)	printf("%d$\t",board[a].price);
		else if(board[a].type==tax)	printf("%d$\t",board[a].rent);
		else 						printf("    \t");

		printf("\n");
		printf("|     ");
		if(player_one.current_block_id==board[b].block_id)	printf("%s   ",player_one.name);
		else 												printf("\t");
		if(player_two.current_block_id==board[b].block_id)	printf("%s\t|",player_two.name);
		else												printf("\t|");			 
		for(j=0;j<8;j++)	printf("\t");
		printf("|     ");
		if(player_one.current_block_id==board[a].block_id)	printf("%s   ",player_one.name);
		else 												printf("\t");
		if(player_two.current_block_id==board[a].block_id)	printf("%s\t",player_two.name);
		else												printf("\t");

		printf("\n");
		if(i!=3)	for(j=0;j<=16;j++)	printf("-");
		if(i!=3)	for(j=0;j<8;j++)	printf("\t");
		if(i!=3)	for(j=0;j<20;j++)	printf("-");
		if(i!=3)	printf("\n");

		a++;
		b--;	
	}

	for(i=0;i<100;i++)	printf("-");
	printf("\n");
	for(i=15;i>9;i--)	printf("|    %s\t",board[i].name);
	printf("\n");	
	for(i=15;i>9;i--){
		printf("|    ");
		if(board[i].type==property)	printf("%d$\t",board[i].price);
		else if(board[i].type==tax)	printf("%d$\t",board[i].rent);
		else 						printf("    \t");
	}
	printf("\n");
	for(i=15;i>9;i--){
		printf("|     ");
		if(player_one.current_block_id==board[i].block_id)	printf("%s   ",player_one.name);
		else 												printf("\t");

		if(player_two.current_block_id==board[i].block_id)	printf("%s\t",player_two.name);
		else 												printf("\t");
	}
	printf("\n");
	for(i=0;i<100;i++)	printf("-");
	printf("\n");

	return;
}

void show_properties(struct block board[20]){

	//PART 3.
	//The function that shows us the details of player's properties.
	int i, choice;
	printf("f\n");

	for(i=0;i<20;i++){
		if(board[i].type==property) printf("%d %s\n",i,board[i].name);
	}

	printf("Enter an id to check a property deeds.\n");
	do{
		scanf("%d",&choice);
		if(board[choice].type==property)	break;
		else	printf("You entered a wrong value.\n");
	}while(1);

	for(i=0;i<33;i++)	printf("-");
	printf("\n|\t\t%s\t\t|\n",board[choice].name);
	for(i=0;i<33;i++)	printf("-");
	printf("\n|\tRent\t\t%d$\t|\n",board[choice].rent);	
	printf("|\tRent 1 H\t%d$\t|\n",board[choice].rent_1);	
	printf("|\tRent 2 H\t%d$\t|\n",board[choice].rent_2);	
	printf("|\tRent 3 H\t%d$\t|\n",board[choice].rent_3);	
	for(i=0;i<33;i++)	printf("-");
	printf("\n");


	return; 
}

void buy_property(struct block *current_block, struct player* current_player){

	//PART 4.
	//The function that buys the property for the current player.
	int i;

	if  (current_block->type==property){
							
		if(current_player->account-current_block->price>0){
		for(i=0;i<11;i++){
			if(current_player->owned_block_ids[i]==0){
				current_player->owned_block_ids[i]=current_block->block_id;
				current_player->account-=current_block->price;
				printf("Succesfully bought %s! New account: %d\n",current_block->name,current_player->account);
				i=12;
				}
			}
		}					
		else	printf("You can't buy this!\n");	
	}
	else	printf("It is not a property.\n");

	return;
}

void sell_property(struct block board[20], struct player* current_player){

	//PART 5.
	//The function that sells the property for the current player.

	int i,sell_price,choice;

	printf("You will get half of the money you bought.\n");

	for(i=0;i<11;i++){
		if(current_player->owned_block_ids[i]!=0){
			printf("%d - %s : Sell price:",current_player->owned_block_ids[i],board[current_player->owned_block_ids[i]].name);
			sell_price=(board[current_player->owned_block_ids[i]].price+(board[current_player->owned_block_ids[i]].house_count*board[current_player->owned_block_ids[i]].house_price))/2;
			printf("%d\n",sell_price);

			printf("Press 1 to sell, press 2 to move to next property, 3 to exit.\n");
			printf("Current balance: %d\n",current_player->account);
			scanf("%d",&choice);

			if(choice==1){
				current_player->account+=sell_price;
				current_player->owned_block_ids[i]=0;
			}
			else if(choice==2)	printf("Next:\n");
			else i=12;
		}
	}
	return;
}

int total_value(struct block board[20],struct player current){

	int total=0,i;

	for(i=0;i<11;i++){
		if(current.owned_block_ids[i]!=0){
			total+=(board[current.owned_block_ids[i]].price+(board[current.owned_block_ids[i]].house_count*board[current.owned_block_ids[i]].house_price))/2;
		}
	}
	return total+=current.account;
}

void gameplay (struct block board[20], struct player player_one, struct player player_two){

	//PART 6.
	//The function that shows options for the game.

	int i;
	char current_player_name[3];
	int game_flag=1,dice_flag=0,buy_flag=1,house_flag;
	int a=0,dice,menu_choice,turn=1,h_c,total,price_to_pay;

	printf("Welcome to Monopoly!\n");
	printf("First player, do you want to be 1-)car or 2-)cap?\n");
	scanf("%d",&menu_choice);

	if(menu_choice==1){
		strcpy(player_one.name,"car");
		strcpy(player_two.name,"cap");
		player_one.type=car;
		player_two.type=cap;
	}
	else{
		strcpy(player_one.name,"cap");
		strcpy(player_two.name,"car");
		player_one.type=cap;
		player_two.type=car;	
	}

	printf("Second player is %s.\n",player_two.name);

	while(game_flag==1){

		show_board(board,player_one,player_two);

		if(a%2==0)	strcpy(current_player_name,player_one.name);
		else		strcpy(current_player_name,player_two.name);
		printf("Its %s's turn.\n",current_player_name);

		while(turn==1){
			if(dice_flag==0)	printf("Dice is not rolled yet.\n\n");
			else 				printf("Dice is rolled, it is %d.\n\n",dice);

			printf("1-) Roll the dice.\n");
			printf("2-) Show my account.\n");
			printf("3-) Show my properties.\n");
			printf("4-) Show property deeds.\n");
			printf("5-) Buy property\n");
			printf("6-) Buy house\n");
			printf("7-) Sell porperty\n");
			if(dice_flag==1)	printf("8-) End the turn\n");

			scanf("%d",&menu_choice);

			switch(menu_choice){
				case 1:
						//DICE 

						if(dice_flag==1)	printf("You already rolled the dice, it is %d\n",dice);
						else{
							dice=(rand()%6+1)+(rand()%6+1);
							printf("You rolled %d!\n",dice);
							dice_flag=1;

							if(a%2==0){
								
								if(player_one.turn_to_wait==0){
										player_one.current_block_id=(dice+player_one.current_block_id);	
										if(player_one.current_block_id>=20)	player_one.account+=10000;
										player_one.current_block_id=player_one.current_block_id%20;

										if(board[player_one.current_block_id].type==punish)	player_one.turn_to_wait=board[player_one.current_block_id].rent;		
										else if(board[player_one.current_block_id].type==tax){

											if(player_one.account<board[player_one.current_block_id].rent){
												printf("You landed on %s, You dont have %d$ to pay\n",board[player_one.current_block_id].name,board[player_one.current_block_id].rent);

												total=total_value(board,player_one);

												if(total<board[player_one.current_block_id].rent){
													printf("You bankrupted. %s won!\n",player_two.name);
													return;
												}	
												else{
													printf("You need to sell some properties.\n");

													while(player_one.account<board[player_one.current_block_id].rent){
														sell_property(board,&player_one);
														player_one.account-=board[player_one.current_block_id].rent;
													}
												}
											}
											else{
												printf("You landed on %s, -%d$ \n",board[player_one.current_block_id].name,board[player_one.current_block_id].rent);
												player_one.account-=board[player_one.current_block_id].rent;
											}
										}
										else{
											for(i=0;i<11;i++){
											
												if(player_two.owned_block_ids[i]==board[player_one.current_block_id].block_id){	

													printf("You landed on %s.",board[player_one.current_block_id].name);
													if(board[player_one.current_block_id].house_count==0)		price_to_pay=board[player_one.current_block_id].rent;
													else if(board[player_one.current_block_id].house_count==1)	price_to_pay=board[player_one.current_block_id].rent_1;
													else if(board[player_one.current_block_id].house_count==2)	price_to_pay=board[player_one.current_block_id].rent_2;
													else														price_to_pay=board[player_one.current_block_id].rent_3;

													if(player_one.account<price_to_pay){
														printf("You dont have %d money to pay.\n",price_to_pay);
														
														total=total_value(board,player_one);

														if(total<price_to_pay){
															printf("You bankrupted. %s won!\n",player_two.name);
															return;
														}
														else{
															printf("You need to sell some properties.\n");
															while(player_one.account<price_to_pay){
																sell_property(board,&player_one);
																player_one.account-=price_to_pay;
																player_two.account+=price_to_pay;
															}
														}
													}
													else{
														printf("You paid %d\n",price_to_pay);
														player_one.account-=price_to_pay;
														player_two.account+=price_to_pay;
													}
													i=12;
												}
											}
										}	
								}
								else{	
									printf("You need to wait %d more turn to play.\n",player_one.turn_to_wait);
									player_one.turn_to_wait--;
									dice_flag=2;
								}
							}	/////////
							else{
								
								if(player_two.turn_to_wait==0){
										player_two.current_block_id=(dice+player_two.current_block_id);	
										if(player_two.current_block_id>=20)	player_two.account+=10000;
										player_two.current_block_id=player_two.current_block_id%20;

										if(board[player_two.current_block_id].type==punish)	player_two.turn_to_wait=board[player_two.current_block_id].rent;		
										else if(board[player_two.current_block_id].type==tax){

											if(player_two.account<board[player_two.current_block_id].rent){
												printf("You landed on %s, You dont have %d$ to pay\n",board[player_two.current_block_id].name,board[player_two.current_block_id].rent);

												total=total_value(board,player_two);

												if(total<board[player_two.current_block_id].rent){
													printf("You bankrupted. %s won!\n",player_one.name);
													return;
												}	
												else{
													printf("You need to sell some properties.\n");

													while(player_two.account<board[player_two.current_block_id].rent){
														sell_property(board,&player_two);
														player_two.account=board[player_two.current_block_id].rent;
													}
												}
											}
											else{
												printf("You landed on %s, -%d$ \n",board[player_two.current_block_id].name,board[player_two.current_block_id].rent);
												player_two.account-=board[player_two.current_block_id].rent;
											}
										}
										else{
											for(i=0;i<11;i++){
											
												if(player_one.owned_block_ids[i]==board[player_two.current_block_id].block_id){	

													printf("You landed on %s.",board[player_two.current_block_id].name);
													if(board[player_two.current_block_id].house_count==0)		price_to_pay=board[player_two.current_block_id].rent;
													else if(board[player_two.current_block_id].house_count==1)	price_to_pay=board[player_two.current_block_id].rent_1;
													else if(board[player_two.current_block_id].house_count==2)	price_to_pay=board[player_two.current_block_id].rent_2;
													else														price_to_pay=board[player_two.current_block_id].rent_3;

													if(player_two.account<price_to_pay){
														printf("You dont have %d money to pay.\n",price_to_pay);
														
														total=total_value(board,player_two);

														if(total<price_to_pay){
															printf("You bankrupted. %s won!\n",player_one.name);
															return;
														}
														else{
															printf("You need to sell some properties.\n");
															while(player_two.account<price_to_pay){
																sell_property(board,&player_two);
																player_two.account-=price_to_pay;
																player_one.account+=price_to_pay;
															}
														}
													}
													else{
														printf("You paid %d\n",price_to_pay);
														player_two.account-=price_to_pay;
														player_one.account+=price_to_pay;
													}
													i=12;
												}
											}
										}	
								}
								else{	
									printf("You need to wait %d more turn to play.\n",player_two.turn_to_wait);
									player_two.turn_to_wait--;
									dice_flag=2;
								}
							}
							show_board(board,player_one,player_two);
						}
						break;	
				case 2:
						//ACCOUNT/BALANCE

						if(a%2==0)	printf("Balance: %d\n",player_one.account);
						else		printf("Balance: %d\n",player_two.account);
						break;
				case 3:
						//OWNED PROPERTIES
						
						for(i=0;i<4;i++){
							if(a%2==0){
								if(player_one.owned_block_ids[i]!=0)	printf("%s\n",board[player_one.owned_block_ids[i]].name);
							}
							else{
								if(player_two.owned_block_ids[i]!=0)	printf("%s\n",board[player_two.owned_block_ids[i]].name);
							}
						}
						break;
				case 4:
						//PROPERTY DEEDS
						show_properties(board);
						break;
				case 5:	
						//BUY

						if(a%2==0){
							for(i=0;i<11;i++){
									if(player_one.owned_block_ids[i]==player_one.current_block_id)	buy_flag=0;
									if(player_two.owned_block_ids[i]==player_one.current_block_id)	buy_flag=0;
								}

							if(buy_flag==0)	printf("You can't buy there!\n");	
							else	buy_property(&board[player_one.current_block_id],&player_one);
						}
						else{
							for(i=0;i<11;i++){
									if(player_one.owned_block_ids[i]==player_two.current_block_id)	buy_flag=0;
									if(player_two.owned_block_ids[i]==player_two.current_block_id)	buy_flag=0;
								}

							if(buy_flag==0)	printf("You can't buy there!\n");	
							else	buy_property(&board[player_two.current_block_id],&player_two);
						}
						buy_flag=1;

						break;
				case 6:	

						if(a%2==0){
							if(board[player_one.current_block_id].type==property){

								house_flag=0;

								for(i=0;i<11;i++){
									if(player_one.owned_block_ids[i]==player_one.current_block_id)	house_flag=1;
								}

								if(house_flag==1){
									printf("Each house price is %d for %s.\n",board[player_one.current_block_id].house_price,board[player_one.current_block_id].name);
									printf("How much do you want to buy?\n");
									scanf("%d",&h_c);

									if(h_c*board[player_one.current_block_id].house_price<=player_one.account){

										if(h_c+board[player_one.current_block_id].house_count<=3){
											player_one.account-=h_c*board[player_one.current_block_id].house_price;
											board[player_one.current_block_id].house_count+=h_c;
										}
										else printf("You cant build more than 3 houses in total.\n");

									}
									else	printf("Not enough balance.\n");
								}
							}
							else printf("You cant buy a house there.\n");
						}
						else{
							if(board[player_two.current_block_id].type==property){

								house_flag=0;

								for(i=0;i<11;i++){
									if(player_two.owned_block_ids[i]==player_two.current_block_id)	house_flag=1;
								}

								if(house_flag==1){
									printf("Each house price is %d for %s.\n",board[player_two.current_block_id].house_price,board[player_two.current_block_id].name);
									printf("How much do you want to buy?\n");
									scanf("%d",&h_c);

									if(h_c*board[player_two.current_block_id].house_price<=player_two.account){

										if(h_c+board[player_two.current_block_id].house_count<=3){
											player_two.account-=h_c*board[player_two.current_block_id].house_price;
											board[player_two.current_block_id].house_count+=h_c;
										}
										else printf("You cant build more than 3 houses in total.\n");

									}
									else	printf("Not enough balance.\n");
								}
							}
							else printf("You cant buy a house there.\n");
						}
						break;
				case 7:	
						//SELL
						if(a%2==0)	sell_property(board,&player_one);
						else		sell_property(board,&player_two);

						break;
				case 8:	turn=0;
						break;
				default:	printf("wrong Input\n");
			}
		}
		dice_flag=0;
		turn=1;
		a++;
	}
	return;
}

int main(){
	//Main function.
	
	int i;

	struct block board[20];
	struct player player_one;
	struct player player_two;

	player_one.name=(char*)malloc(5*sizeof(char));
	player_two.name=(char*)malloc(5*sizeof(char));

	player_one.current_block_id=0;
	player_two.current_block_id=0;

	player_one.turn_to_wait=0;
	player_two.turn_to_wait=0;

	player_one.account=100000;
	player_two.account=100000;

	for(i=0;i<11;i++)	player_one.owned_block_ids[i]=0;
	for(i=0;i<11;i++)	player_two.owned_block_ids[i]=0;

	srand(time(NULL));

	init_the_board(board);
	gameplay(board,player_one,player_two);

	for(i=0;i<20;i++)	free(board[i].name);
	free(player_one.name);
	free(player_two.name);


	printf("\nexiting.\n");
	return 0;
}