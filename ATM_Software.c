#include<stdio.h>
#include<stdlib.h>
int main(){
	int pin,pin1=5555;
	int c=1,ch,amt,balance=5000;
	printf("Welcome to SBI Bank\n");
	start:
	printf("Enter the pin number:");
	scanf("%d",&pin);
	if(pin==pin1){
	printf("Please select your choice\n");
	printf("1.deposite \n2.withdraw \n3.checkbalance \n4.changepin \n");
	scanf("%d",&ch);
	switch(ch){
		case 1:printf("Enter the deposite amount\n ");
		       scanf("%d",&amt);
		       if(amt<=20000){
		        balance=balance+amt;
		       	printf("%d",balance);
		       	printf("\n");
			   }
			   else{
			   	printf("max limit of withdraw is 20K\n");
			   }
			break;
		case 2:printf("Enter the deposite amount\n ");
		       scanf("%d",&amt);
		       if(amt<=20000){
		       	if(amt<=balance){
		       	    balance=balance-amt;
		       	    printf("after deductin %d, current balance=%d\n",amt,balance);
				   }
				   else{
				   	printf("insufficient balance:");
				   }
			   }
			   else{
			   	printf("max limit for withdraw is 20K");
			   }
			break;
		case 3:printf("your balance=%d\n",balance);
			break;
		case 4:
			printf("Enter the new pin number");
			scanf("%d",&pin1);
			printf("your pin number is updated succesfully ...!\nlogin again\n");
			goto start;
			break;
	}
	}
	else{
		printf("Please enter the valid pin number\n");
		if(c<3){
			c++;
			goto start;
		}
	}
		
	printf("press 1 to continue...\n");
	scanf("%d",&ch);
	if(ch==1)
	goto start;
	printf("thanks for using SBI ATM");
}
	

