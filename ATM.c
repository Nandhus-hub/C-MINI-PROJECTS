#include <stdio.h>
#include<string.h>
void deposit();
void withdraw();
void balance_enquiry();
void transaction_history();
void pinchange();

struct user{
  char name[20];
  char pass[6];
  int balance;
  int deposit[10];
  int withdraw[10];
}user1={"name","696969",0};


int d_i=0,w_i=0;

void deposit(){
  // system('cls');
  printf("please enter your password");
  char pin[100];
  int i=0,j=0;
  char ch;
  // while((ch=getchar())!='\r' && i<6){
  //   putchar('*');
  //   pin[i++]=ch;
  // }
  // pin[i]='\0';
  scanf("%s",pin);
  if(strcmp(pin,user1.pass)==0){
  printf("\nwelcome to deposit\n");
  int dep;
  printf("Enter the amount to deposit\n");
  scanf("%d",&dep);
  user1.balance+=dep;
  user1.deposit[d_i++]=dep;
  d_i++;
  balance_enquiry();

}
  
}


void withdraw(){
  // system('cls');
  printf("welcome to withdraw\n");
  int wd,i=0;
  printf("enter the amount to withdraw:\n");
  scanf("%d",&wd);
  
  if(user1.balance>=wd){
    user1.balance-=wd;
    user1.withdraw[w_i++]=wd;
    w_i++;
    printf("%d",user1.balance);
  }
  
  
}
void balance_enquiry(){
  printf("ACCOUNT BALANCE IS RS:%d\n",user1.balance);
}


void transaction_history(){
// intf("\n\t\tPlease enter your pin");
// 	char pin[10];
// 	int i=0;
// 	scanf("%s",pin);
// 	if(strcmp(pin,user1.pass)==0){
    int i;
		printf("\n\t\tList of Deposits");
		for(i=0;i<d_i;i++){
			printf("Deposit :%d=%d\n",i,user1.deposit[i]);
		}
		for(i=0;i<w_i;i++){
			printf("Withdrawals :%d=%d\n",i,user1.withdraw[i]);
		}
	}
// 	else{
// 		printf("Unauthorized Access");
// 		mainmenu();
// 	} 


void pinchange(){
  printf("\n\t\tPlease enter your old pin");
	char ch[10];
	scanf("%s",ch);
	if(strcmp(ch,user1.pass)==0){
		printf("\n\t\tPlease enter new pin");
		scanf("%s",ch);
		strcpy(user1.pass,ch);
		printf("PIN updated successfully");
	}
// 	else{
// 		printf("Unauthorised Access");
// 		mainmenu();
// 	}
}


int main()
{
    while(1){
      printf("*********************************\n");
      printf("\tWELCOME TO ATM\n");
      printf("*********************************\n");
      printf("\n1>DEPOSIT");
      printf("\n2>WITHDRAW");
      printf("\n3>BALANCE ENQUIRY");
      printf("\n4>TRANSACTION HISTORY");
      printf("\n5>PIN CHANGE");
      printf("\n6>EXIT");
      printf("\nPlease enter your choice\n");
      int op;
      scanf("%d",&op);
      switch(op){
        case 1:deposit();
              break;
              
        case 2:withdraw();
              break;
        case 3:balance_enquiry();
              break;
              
        case 4:transaction_history();
              break;
        case 5:pinchange();
              break;
        case 6:return 0;
      // //   default:printf("Invalid choice");
      }
      break;
    }
}