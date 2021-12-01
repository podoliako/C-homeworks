
#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H


int makeMove(int* Positions, int position, int player){
    if (Positions[position] != 0) return 0;
    else {
        Positions[position] = player;
        return 1;
    }
}

void printField(const int* Positions){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("|");
            if(Positions[i * 3 + j] == 0) printf(" ");
            else if(Positions[i * 3 + j] == 1) printf("X");
            else if(Positions[i * 3 + j] == 2) printf("O");
            printf("|");
        }
        printf("\n");
    }
}

int checkIfPlayerWon(const int* Positions, int player){
    if(((Positions[0] == player) && (Positions[1] == player) && (Positions[2] == player)) ||
       ((Positions[3] == player) && (Positions[4] == player) && (Positions[5] == player)) ||
       ((Positions[6] == player) && (Positions[7] == player) && (Positions[8] == player)) ||
       ((Positions[0] == player) && (Positions[3] == player) && (Positions[6] == player)) ||
       ((Positions[1] == player) && (Positions[4] == player) && (Positions[7] == player)) ||
       ((Positions[2] == player) && (Positions[5] == player) && (Positions[8] == player)) ||
       ((Positions[0] == player) && (Positions[4] == player) && (Positions[8] == player)) ||
       ((Positions[2] == player) && (Positions[4] == player) && (Positions[6] == player)) ) return 1;
    else return 0;
}
#endif //GAME_FUNCTIONS_H
