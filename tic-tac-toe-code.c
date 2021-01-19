#include <stdio.h>
#include <stdlib.h>

char board[10] = {'-','1','2','3','4','5','6','7','8','9'};


//Print the board
void print_board(){
	printf("\n %c | %c | %c\n",board[1],board[2], board[3]);
	printf(" ----------\n");
	printf(" %c | %c | %c\n", board[4],board[5],board[6]);
	printf(" ----------\n");
	printf(" %c | %c | %c\n",board[7],board[8],board[9]);
	printf("\n-=-=-=-=-=-=-=-\n");

}


//Check wins condition
int check_win(){

	//LINES
	if(board[1] == board[2] && board[2] == board[3]){
		return 1;
	}
	else if (board[4] == board[5] && board[5] == board[6]){
		return 1;
	}
	else if(board[7] == board[8] && board[8] == board[9]){
		return 1;
	}
	//COLUMNS
	else if(board[1] == board[4] && board[4] == board[7]){
		return 1;}
	else if(board[2] == board[5] && board[5] == board[8]){
		return 1;
	}
	else if(board[3] == board[6] && board[6] == board[9]){
		return 1;
	}
	//DIAGONALS
	else if(board[1] == board[5] && board[5] == board[9]){
		return 1;
	}
	else if(board[3] == board[5] && board[5] == board[7]){
		return 1;
	}
	//Keep returning -1, until no winner
	else{
		return -1;
	}
}


int main(void) {
    printf("-=-=-=-=-=-=-=-\n");
	printf(" Tic Tac Toe \n");
	printf("-=-=-=-=-=-=-=-\n");
	printf(" Player 1 = (X)\n");
	printf(" Player 2 = (O)\n");
	printf("-=-=-=-=-=-=-=-\n\n\n");

	int player = 1, i = 0 ,move, c = 0;
	char letter;

	//Runs the game as long as there is no winner
    do{
        print_board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, make your move: \n",player);
        scanf("%d", &move);

        letter = (player == 1) ? 'X' : 'O';

        if(move == 1 && board[1] == '1'){
            board[1] = letter;
        }
        else if(move == 2 && board[2] == '2'){
            board[2] = letter;
        }
        else if(move == 3 && board[3] == '3'){
            board[3] = letter;
        }
        else if(move == 4 && board[4] == '4'){
            board[4] = letter;
        }
        else if(move == 5 && board[5] == '5'){
            board[5] = letter;
        }
        else if(move == 6 && board[6] == '6'){
            board[6] = letter;
        }
        else if(move == 7 && board[7] == '7'){
            board[7] = letter;
        }
        else if(move == 8 && board[8] == '8'){
            board[8] = letter;
        }
        else if(move == 9 && board[9] == '9'){
            board[9] = letter;
        }

        else{
            printf("\nInvalid Option !\n");
            player--;
            printf("\nPlayer %d, make your move: \n",player);
            scanf("%d",&move);
        }
        i = check_win();
        player++;
        c++;
    }while(i == -1 && player < 10 && player > 0 && c < 9);

    //Show who wins
    print_board();
    if(i == 1){
        printf("\n>> PLAYER %d WINS!! =)\n", player);
    }
    if(c == 9 && i != 1){
        printf("\nTIE!! =(");
    }

    return 0;
}
