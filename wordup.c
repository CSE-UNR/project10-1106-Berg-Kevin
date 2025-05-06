//Kevin Berg
//Project 10

#include <stdio.h>
#define FILE_NAME "mystery.txt"
#define SIZE 6
#define SIZE1 12
#define SIZE2 6
void errormsg();
void errorcheck(int size0, char g0[], int check);
void capitolset(int size1, char g1[], int size7, char c2[]);
void upcheck(int size2, char g2[], int size6, char c1[], int g, char b[][size2]);
void twodprint(int size3r, int size3c, char g[][size3c]);
int correct(int size4, char g3[], int size5, char c0[],int size4r, int size4c, char g1[][size4c], int water, int guess);


int main(){
	char board[SIZE1][SIZE2];
	char guess0[SIZE];
	char guess1[SIZE];
	int i;
	int j;
	int another;
	another = 0;
	int guess;
	int water;
//variables
	FILE *flopn;
	flopn = fopen(FILE_NAME, "r");
	if(flopn == NULL){
		printf("Can't open file");
		return 0;
	}
	fscanf(flopn, "%s", guess0);
//opens file
do{
	printf("GUESS 1! Enter your guess:");
	guess = 1;
	scanf("%s", guess1);
		errorcheck(SIZE, guess1, 0);
	printf("================================\n");
		capitolset(SIZE, guess0, SIZE, guess0);
		capitolset(SIZE, guess1, SIZE, guess0);
		water = correct(SIZE, guess1, SIZE, guess0, SIZE1, SIZE2, board, 0, guess);
	if(water == 1){
	return 0;
	}
		upcheck(SIZE, guess1, SIZE, guess0, 1, board);
	for(int h = 0; h<SIZE; h++){
		board[0][h] = guess1[h];
	}
		twodprint(SIZE1, SIZE2, board); 
//guess1
	printf("GUESS 2! Enter your guess:");
	guess = 2;
	for(j=0; j<SIZE; j++){
		guess1[j] = ' ';
	}
	scanf("%s", guess1);
	printf("================================\n");
		capitolset(SIZE, guess1, SIZE, guess0);
		water = correct(SIZE, guess1, SIZE, guess0, SIZE1, SIZE2, board, 0, guess);
	if(water == 1){
	return 0;
	}
		errorcheck(SIZE, guess1, 0);
		upcheck(SIZE, guess1, SIZE, guess0, 3, board);
	for(int m = 0; m<SIZE; m++){
		board[2][m] = guess1[m];
	}
		twodprint(SIZE1, SIZE2, board); 
//guess 2
	printf("GUESS 3! Enter your guess:");
	guess = 3;
	for(j=0; j<SIZE; j++){
		guess1[j] = ' ';
	}
	scanf("%s", guess1);
	printf("================================\n");
		capitolset(SIZE, guess1, SIZE, guess0);
		water = correct(SIZE, guess1, SIZE, guess0, SIZE1, SIZE2, board, 0, guess);
	if(water == 1){
	return 0;
	}
		errorcheck(SIZE, guess1, 0);
		upcheck(SIZE, guess1, SIZE, guess0, 5, board);
	for(int m = 0; m<SIZE; m++){
		board[4][m] = guess1[m];
	}
		twodprint(SIZE1, SIZE2, board); 
//guess 3
	printf("GUESS 4! Enter your guess:");
	guess = 4;
	for(j=0; j<SIZE; j++){
		guess1[j] = ' ';
	}
	scanf("%s", guess1);
	printf("================================\n");
		capitolset(SIZE, guess1, SIZE, guess0);
		water = correct(SIZE, guess1, SIZE, guess0, SIZE1, SIZE2, board, 0, guess);
	if(water == 1){
	return 0;
	}
		errorcheck(SIZE, guess1, 0);
		upcheck(SIZE, guess1, SIZE, guess0, 7, board);
	for(int m = 0; m<SIZE; m++){
		board[6][m] = guess1[m];
	}
		twodprint(SIZE1, SIZE2, board); 
//guess 4
	printf("GUESS 5! Enter your guess:");
	guess = 5;
	for(j=0; j<SIZE; j++){
		guess1[j] = ' ';
	}
	scanf("%s", guess1);
	printf("================================\n");
		capitolset(SIZE, guess1, SIZE, guess0);
		water = correct(SIZE, guess1, SIZE, guess0, SIZE1, SIZE2, board, 0, guess);
	if(water == 1){
	return 0;
	}
		errorcheck(SIZE, guess1, 0);
		upcheck(SIZE, guess1, SIZE, guess0, 9, board);
	for(int m = 0; m<SIZE; m++){
		board[8][m] = guess1[m];
	}
		twodprint(SIZE1, SIZE2, board);  
//guess 5
	printf("GUESS 6! Your final guess:");
	guess = 6;
	for(j=0; j<SIZE; j++){
		guess1[j] = ' ';
	}
	scanf("%s", guess1);
	printf("================================\n");
		capitolset(SIZE, guess1, SIZE, guess0);
		water = correct(SIZE, guess1, SIZE, guess0, SIZE1, SIZE2, board, 0, guess);
	if(water == 1){
	return 0;
	}
	printf("You failed to guess the correct word.\n");
	printf("You guessed:\n");
	for(int q = 0; q<SIZE; q++){
		board[10][q] = guess1[q];
	}
		twodprint(SIZE1, SIZE2, board);
	printf("The correct answer was 'SOUND', Thank you for playing \n");
	another = 1;
//guess 6
}while(another == 0);
fclose(flopn);	
return 0;
}
int correct(int size4, char g3[], int size5, char c0[],int size4r, int size4c, char g1[][size4c], int water, int guess){
	int l;
	int check0;
	check0 = 0;	
	int check1;
	check1 = 1;
	for(l=0; l<SIZE-1; l++){
		if(g3[l] == c0[l]){
		check0 = 1;	
		}
		else{
		check1 = 0;
		}
	
	}
	if(check0 == 1 && check1 != 0){
		for(size4r = 0; size4r < SIZE1; size4r++){
		for(size4c = 0; size4c < SIZE2; size4c++){
			printf("%c", g1[size4r][size4c]);
		}
		printf("\n");
		}	
			printf("	SOUND\n");
			printf("You won in %d guesses!\n", guess);
			printf("	Amazing!");
			printf("\n");
			water = 1;	
		
	}
return water;
}
void upcheck(int size2, char g2[], int size6, char c1[], int g, char b[][size2]){
int k;
for(k=0; k<4; k++){
	if(g2[k] == c1[0]){
		b[g][k] = '^';
	}
	else if(g2[k] == c1[1]){
		b[g][k] = '^';
	}
	else if(g2[k] == c1[2]){
		b[g][k] = '^';
	}
	else if(g2[k] == c1[3]){
		b[g][k] = '^';
	}
	else if(g2[k] == c1[4]){
		b[g][k] = '^';
	}
	else{
		b[g][k] = ' ';
	}
	if(g2[0] == c1[0]){
		b[g][k] = ' ';
	}
	else if(g2[1] == c1[1]){
		b[g][k] = ' ';
	}
	else if(g2[2] == c1[2]){
		b[g][k] = ' ';
	}
	else if(g2[3] == c1[3]){
		b[g][k] = ' ';
	}
	else if(g2[4] == c1[4]){
		b[g][k] = ' ';
	}
	}
}
void errorcheck(int size0, char g0[], int check){
	int j;
	for(j=0; g0[j] != '\0'; j++){
	if(g0[j] >= '0' && g0[j] <= '9'){
		check = 1;
	}
	else{
	check = 0;
	}
	}
//	printf("%d", j);
	if(j-1 != 4){
		check = 1;
	}
	if(check == 1){
		errormsg();
		for(int k=0; k<SIZE; k++){
		scanf("%c", &g0[k]);
		}
	}
}
void errormsg(){
	printf("Your guess must be 5 letters long. Your guess must contain only letters.\n");
	printf("Please try again\n");
}
void capitolset(int size1, char g1[], int size7, char c2[]){
	if(g1[0] == c2[0]+32){
	g1[0] = g1[0] - 32;
	}
	else if(g1[1] == c2[1]+32){
	g1[1] = g1[1] - 32;
	}
	else if(g1[2] == c2[2]+32){
	g1[2] = g1[2] - 32;
	}
	else if(g1[3] == c2[3]+32){
	g1[3] = g1[3] - 32;
	}
	else if(g1[4] == c2[4]+32){
	g1[4] = g1[4] - 32;
	}
}
void twodprint(int size3r, int size3c, char g[][size3c]){
	for(size3r = 0; size3r < SIZE1; size3r++){
		for(size3c = 0; size3c < SIZE2; size3c++){
			printf("%c", g[size3r][size3c]);
		}
	printf("\n");
	}
}
