#include<stdio.h>
#include<stdlib.h>
int noRik=0,noBike=0,noBus=0,noCar=0,noCyl=0,amount=0,count=0;

void main(){
	
	while(1){
		switch(Menu()){
		case 1:Bus();
		break;
		case 2:Car();
			break;
		case 3:Cycle();
			break;
		case 4:Bike();
			break;
		case 5:Riksha();
			break;
		case 6:ShowDetail();
			break;
		case 7:	Delete();
		break;
		case 8:
			exit(0);
		default:
		printf("\n Invalid choice");	
	}
	getch();
	}
}
int Menu(){
	int ch;
	printf("\n1. enter bus");
	printf("\n2. enter car");
	printf("\n3. enter cycle");
	printf("\n4. enter bike");
	printf("\n5. enter riksha");
	printf("\n6. show status.");
	printf("\n7. delete data:");
	printf("\n8. exit program:");
	printf("\nEnter your choice\n");
	scanf("%d",&ch);
	return(ch);
}
void Delete(){
	noRik=0;
	noBike=0;
	noBus=0;
	noCar=0;
	noCyl=0;
	amount=0;
	count=0;
}
void ShowDetail(){
	printf("\n number of bus=%d",noBus);
	printf("\n number of car=%d",noCar);
	printf("\n number of cycle=%d",noCyl);
	printf("\n number of bike=%d",noBike);
	printf("\n number of riksha=%d",noRik);
	printf("\n total number of vehical=%d",count);
	printf("\n total gain amount=%d",amount); 
}
void Riksha(){
	printf("\nEntery successful");
	noRik++;
	amount=amount+20;
	count++;
}
void Car(){
	printf("\nEntery successful");
	noCar++;
	amount=amount+80;
	count++;
}
void Cycle(){	
	printf("\nEntery successful");
	noCyl++;
	amount=amount+10;
	count++;	
}
void Bike(){
	printf("\nEntery successful");
	noBike++;
	amount=amount+50;
	count++;	
}
void Bus(){	
	printf("\nEntery successful");
	noBus++;
	amount=amount+100;
	count++;
}
