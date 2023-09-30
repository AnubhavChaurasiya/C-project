#include<stdio.h>
#include<stdlib.h>
int main(){
	int secret_no=7;
	int guess_no;
	int i;
	int guess_limit=3;
	for(i=1;i<=guess_limit;i++)
	{
		printf("Guess number %d:",i);
		scanf("%d",&guess_no);
		if(guess_no==secret_no){
			printf("you win");
			break;
		}
	}
	if(guess_no!=secret_no){
		printf("you lost");
	}
	getch();
	return 0;
}
