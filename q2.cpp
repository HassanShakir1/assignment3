#include<stdio.h>

struct Player{
	int ballScores[12];
	char playerName[50];
	int totalScore;
};

int validateScore(int score){
	if(score <=6 && score >=0){
		return 1;
	}
	return 0;
}

void playGame(struct Player *player){
	printf("\n Add Details For Player");
	printf("\n Add Player Name : ");
	scanf("%s",player->playerName);
	int total=0;
	for(int i=0;i<12;i++){
		printf("\n Enter Score for ball %d of Player : ",i+1);
		scanf("%d",&player->ballScores[i]);
		int k =validateScore(player->ballScores[i]);
		if(k ==0){
			player->ballScores[i]=0;
		}
		total+=player->ballScores[i];
	}
	player->totalScore=total;
}

void findWinner(struct Player *player1,struct Player *player2){
	if((player1->totalScore)>(player2->totalScore)){
		 printf("\n Player 1 is winner ");
	}else if((player1->totalScore)==(player2->totalScore)){
	    printf("\n Equal Score Match Draw");
	}else{
	printf("\n Player 2 is winner ");	
	}
}

void displayMatchScoreboard(struct Player *player1,struct Player *player2){
	printf("\n Summary of Player 1 ....... : ");
	printf("\n Player 1 Name : %s ",player1->playerName);
	for(int i=0;i<12;i++){
		printf("\n ball : %d Score : %d ",i+1,player1->ballScores[i]);
	}
	printf("\n Player 1 Average : %.2f",(float)(player1->totalScore)/12);
	printf("\n Player 1 totalScore : %d ",player1->totalScore);
	printf("\n Summary of Player 2 ....... : ");
	printf("\n Player 2 Name : %s ",player2->playerName);
	for(int i=0;i<12;i++){
		printf("\n ball : %d Score : %d ",i+1,player2->ballScores[i]);
	}
	printf("\n Player 2 Average : %.2f",(float)(player2->totalScore)/12);
	printf("\n Player 2 totalScore : %d ",player2->totalScore);
}

int main(void){
	struct Player p[2];
	playGame(&p[0]);
	playGame(&p[1]);
	displayMatchScoreboard(&p[0],&p[1]);
	findWinner(&p[0],&p[1]);
}

