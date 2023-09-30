#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Add();
void Sub();
void Mul();
void Div();
void Rem();
void Square();
void Cube();
void Root();
int main(){
	
	int choice;
	start:
	printf("calculater\n\n");
	printf("enter your choice:\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Maltiplication\n");
	printf("4. Divition\n");
	printf("5. Remainder\n");
	printf("6. square \n");
	printf("7. cube \n");
	printf("8. square root \n");
	printf("9. Exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			Add();
			break;
		case 2:
			Sub();
			break;	
		case 3:
			Mul();
			break;
		case 4:
			Div();
			break;
		case 5:
			Rem();
			break;	
		case 6:
			Square();
			break;
		case 7:
			Cube();
			break;
		case 8:
			Root();
			break;
		case 9:
			exit(0);
			break;	
		default:
			printf("Invalid input:");
	}
	printf("\n");
		goto start;
	return 0;
}
 void Add(){
	int x,y,z;
	printf("Enter two number:");
	scanf("%d%d",&x,&y);
	z=x+y;
	printf("%d",z);
}
void Sub(){
	int x,y,z;
	printf("Enter two number:");
	scanf("%d%d",&x,&y);
	z=x-y;
	printf("%d",z);
}
void Mul(){
	int x,y,z;
	printf("Enter two number:");
	scanf("%d%d",&x,&y);
	z=x*y;
	printf("%d",z);
}
void Div(){
	int x,y,z;
	printf("Enter two number:");
	scanf("%d%d",&x,&y);
	z=x/y;
	printf("%d",z);
}
void Rem(){
	int x,y,z;
	printf("Enter two number:");
	scanf("%d%d",&x,&y);
	z=x%y;
	printf("%d",z);
}
void Square(){
	int x,z;
	printf("Enter a number:");
	scanf("%d",&x);
	z=x*x;
	printf("%d",z);
}
void Cube(){
	int x,z;
	printf("Enter a number:");
	scanf("%d",&x);
	z=x*x*x;
	printf("%d",z);
}
void Root(){
	int x;
	float z;
	printf("Enter a number:");
	scanf("%d",&x);
	z=sqrt(x);
	printf("%.4f",z);
}


