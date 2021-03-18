#include<stdio.h>
#include<stdlib.h>

#include <time.h> // we need this to generate random chars.

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18

///////////////////GIVEN FUNCTIONS//////////////////////////////
int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}
///////////////////////////////////////////////////////////////

char rand_char(){	//returns a random character.

	return 'a'+rand()%26;
}

void print_area(char random[15][15]){ //prints the area.

	int i,j;

	printf("\t");
	for (int i = 0; i < 15; i++)	printf(" %d ",i%10);	
		
	printf("\n\n");
	
	for (int i = 0; i < 15; ++i){
		printf("%d\t",i);	

		for (int j = 0; j < 15; ++j){

			printf(" %c ",random[i][j]);
		}

		printf("\n");
	}
}

void assing_ch(char random[15][15],char *dict[],int coord[DICT_SIZE][4]){	//assigns the dictionary chars

	int i,j;

	int x_result,y_result;
	//x_result and y_result helps us to find the direction.

	for (int i = 0; i < 15; ++i){	
		for (int j = 0; j < 15; ++j){
			random[i][j]=rand_char();
		}
	}

	for(i=0;i<DICT_SIZE;i++){

		y_result=coord[i][2]-coord[i][0];
		x_result=coord[i][3]-coord[i][1];

		if(y_result==0 && x_result!=0){

			if(x_result<0) x_result *=-1;

			for(j=0;j<=x_result;j++){

				random[coord[i][0]][coord[i][1]+j]=dict[i][j];
			}
		}
		else if(x_result==0 && y_result>0){

			if(y_result<0) y_result *=-1;

			for (j=0;j<=y_result;j++){

				random[coord[i][0]+j][coord[i][1]]=dict[i][j];

			}
		}
		else if(y_result>0 && x_result>0){

			for(j=0;j<=y_result;j++){

				random[coord[i][0]+j][coord[i][1]+j]=dict[i][j];
			}
		}
		else if(y_result<0 && x_result<0){

			y_result *=-1;

			for(j=0;j<=y_result;j++){

				random[coord[i][0]-j][coord[i][1]-j]=dict[i][j];
			}
		}
		else if(y_result>0 && x_result<0){

			for(j=0;j<=y_result;j++){

				random[coord[i][0]+j][coord[i][1]-j]=dict[i][j];
			}
		}
		else if(y_result<0 && x_result>0){

			y_result *=-1;

			for(j=0;j<=y_result;j++){

				random[coord[i][0]-j][coord[i][1]+j]=dict[i][j];
			}
		}
	}
}

int string_compare(char guess[], char exit[]){  //finds out if user typed exit game or not. 

	int ctr=0;
    while(guess[ctr]==exit[ctr])
    {
        if(guess[ctr]=='\0'||exit[ctr]=='\0')
            break;
        ctr++;
    }
    if(guess[ctr]=='\0' && exit[ctr]=='\0')
        return 0;
    else
        return 1;	
}

int main(){
	char *dict[DICT_SIZE]; 	
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
    char random_char[15][15];
    int i,j;
    int choice_y,choice_x,do_while_flag=1,while_flag=1,guess_num=99;
    char guess[15];
    int x_result,y_result;
    char exit[10]="exit";
    int word_left=DICT_SIZE;

	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}

	fclose(fp);

/////////////////////////////////////////////////////////////////////////////////////////

    srand(time(NULL));
	assing_ch(random_char,dict,coord);
	print_area(random_char);
	
	while(while_flag==1 && word_left>0){

		printf("\nWord(s) left to be found: %d\n",word_left);

		do{
			printf("Enter a y(row) coordinate first:\n");
			scanf("%d",&choice_y);
			printf("Enter a x(column) coordinate:\n");
			scanf("%d",&choice_x);

			if (choice_x<0 ||choice_x>14 ||choice_y<0 ||choice_y>14)	printf("Wrong input.\n");		
			else														do_while_flag=0;

		}while(do_while_flag==1);
		do_while_flag=1;

		printf("Enter your word guess, enter \"exit game\" to exit\n");
		scanf("%s",guess);

		guess_num=99;

		for(i=0;i<DICT_SIZE;i++){
			if(guess[0]==dict[i][0]){
				if(guess[1]==dict[i][1]){
					if(guess[2]==dict[i][2]){
						guess_num=i;
					}
				}
			}
		}

		if((coord[guess_num][0]==choice_y && coord[guess_num][1]==choice_x) || (coord[guess_num][2]==choice_y && coord[guess_num][3]==choice_x)){

			y_result=coord[guess_num][2]-coord[guess_num][0];
			x_result=coord[guess_num][3]-coord[guess_num][1];

			if(y_result==0 && x_result!=0){

				if(x_result<0) x_result *=-1;

				for(j=0;j<=x_result;j++){

					random_char[coord[guess_num][0]][coord[guess_num][1]+j]=dict[guess_num][j]-32;
				}
			}
			else if(x_result==0 && y_result>0){

				if(y_result<0) y_result *=-1;

				for (j=0;j<=y_result;j++){

					random_char[coord[guess_num][0]+j][coord[guess_num][1]]=dict[guess_num][j]-32;
				}
			}/////////////////////////////////////////////////////
			else if(y_result>0 && x_result>0){

				for(j=0;j<=y_result;j++){

					random_char[coord[guess_num][0]+j][coord[guess_num][1]+j]=dict[guess_num][j]-32;
				}
			}
			else if(y_result<0 && x_result<0){

				y_result *=-1;

				for(j=0;j<=y_result;j++){

					random_char[coord[guess_num][0]-j][coord[guess_num][1]-j]=dict[guess_num][j]-32;

				}
			}
			else if(y_result>0 && x_result<0){

				for(j=0;j<=y_result;j++){

					random_char[coord[guess_num][0]+j][coord[guess_num][1]-j]=dict[guess_num][j]-32;
				}
			}
			else if(y_result<0 && x_result>0){

				y_result *=-1;

				for(j=0;j<=y_result;j++){

					random_char[coord[guess_num][0]-j][coord[guess_num][1]+j]=dict[guess_num][j]-32;
				}
			}
			word_left--;
		}

		while_flag=string_compare(guess,exit);

		if(while_flag==0) 	printf("Exiting.\n");
		else				print_area(random_char);	
		}		
	
		
	return 0;
}