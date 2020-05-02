#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int count=0;
long a=201901;
long int b;	
int amt,i;
int j=0;
void create();
void display();
struct account
{
	char firstname[20];
	char lastname[20];
	int pin;
	long int accno;
	char adhar[13];
	char pan[11];
	char mob[11];
	char address[200];
	int amount;
}acc;
struct account accoun[1000];
void create()
{
	
	struct account acc;
	printf("\tENTER ACCOUNT DETAILS\n");
	printf("Enter First Name : ");
	gets(acc.firstname);
	gets(acc.firstname);
	printf("\nEnter Last Name : ");
	gets(acc.lastname);
	acc.accno=a++;
	printf("Account Number : %d",acc.accno);
	printf("\nEnter 4 digit PIN : ");
	scanf("%d",&acc.pin);
	printf("\nEnter Adhaar Number : ");
	scanf("%s",&acc.adhar);
	printf("\nEnter PAN card Number : ");
	scanf("%s",&acc.pan);
	printf("\nEnter Mobile Number : ");
	scanf("%s",&acc.mob);
	printf("\nEnter Address : ");
	gets(acc.address);
	gets(acc.address);
	condition:
		printf("\nEnter first deposit amt : ");
		scanf("%d",&acc.amount);
		if(acc.amount<1000)
		{
			printf("\nPlease enter amount more than 1000");
			goto condition;
		}
		accoun[count++]=acc;
	
}
void display(int i)
{	
/*	FILE* fptr;
	fptr=fopen("C:\bank.txt","w");*/
	
	printf("First Name :%s\n",accoun[i].firstname);
	printf("Last Name :%s\n",accoun[i].lastname);
	printf("A/c :%d\n",accoun[i].accno);
	printf("Adhaar Number :%s\n",accoun[i].adhar);
	printf("PAN Number :%s\n",accoun[i].pan);
	printf("Mobile Number : ");
	puts(accoun[i].mob);
	printf("Address :%s\n",accoun[i].address);
/*	fwrite("First Name :%s\n",accoun[i].firstname,200,fptr);
	fwrite("Last Name :%s\n",accoun[i].lastname,200,fptr);
	fwrite("A/c :%d\n",accoun[i].accno,200,fptr);
	fwrite("Adhaar Number :%s\n",accoun[i].adhar,200,fptr);
	fwrite("PAN Number :%s\n",accoun[i].pan,200,fptr);
	fwrite("Mobile Number : %s",accoun[i].mob,200,fptr);
	fwrite("Address :%s\n",accoun[i].address,200,fptr);
	fclose(fptr);*/
	
}
int main()
{
	char c;
	int password;
	FILE *fptr;
	while(1)
	{
		int c;
		printf("****MENU****\n");
		printf("1.Create Account\n2.Deposit Money\n3.Withdraw Money\n4.Balance Enquiry\n5.Account Details\n6.Exit\nEnter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				create();
				printf("You have successfully created an account\nPress any key to proceed\n");
				getch();
				system("cls");
				break;
			case 2:
				
				printf("Enter your account number\n");
				scanf("%d",&b);
				for(i=0;i<=count;i++)
				{
					if(accoun[i].accno==b)
					{
						printf("Enter Amount to be deposited\n");
						scanf("%d",&amt);
						accoun[i].amount=accoun[i].amount+amt;
						printf("Total Bal= %d\n",accoun[i].amount);
						j=1;
					}	
				}
				if(j!=1)
				{
					printf("Account Not Found\n");
					j=0;
				}
				j=0;
				printf("Press any key to proceed\n");
				getch();
				system("cls");
				break;
			case 3:
				printf("Enter your Account Number: ");
				scanf("%d",&b);
				for(i=0;i<=count;i++)
				{
					if(accoun[i].accno==b)
					{
						printf("Account Found\n");
						retry:
							printf("Please Enter your 4 digit PIN : ");
							scanf("%d",&password);
							if(accoun[i].pin==password)
							{
								printf("Enter Amount to be withdrawn\n");
								scanf("%d",&amt);
								if(accoun[i].amount>amt)
								{
									accoun[i].amount=accoun[i].amount-amt;
									printf("Amount successfully withdrawn\nCurrent Balance= %d\n",accoun[i].amount);
								}
								else
								{
									printf("You dont have sufficient balance\n");
								}
								j=1;
							}
					}
				}
				if(j!=1)
				{
					printf("Account Not Found\n");
					j=0;
				}
				printf("Please enter any key to proceed\n");
				getch();
				system("cls");
				break;
			case 4:
				printf("Enter your Account Number\n");
				scanf("%d",&b);
				for(i=0;i<=count;i++)
				{
					if(accoun[i].accno==b)
					{
						printf("Account Found\n");
						retry2:
							printf("Please Enter your 4 digit PIN : ");
							scanf("%d",&password);
							if(accoun[i].pin==password)
							{
								printf("Account Balance= %d\n",accoun[i].amount);
								j=1;
							}
							
							else
							{
								printf("Please enter correct PIN\n");
								goto retry2;
							}
					}
				}	
				
			
			if(j!=1)
			{
				printf("Account Not Found\n");
				j=0;
			}
			printf("Press any key to proceed\n");
			getch();
			system("cls");
			break;
			
			case 5:
				printf("Enter Account Number : ");
				scanf("%d",&b);
				for(i=0;i<=count;i++)
				{
					if(accoun[i].accno==b)
					{
						printf("Account Found\n");
						retry1:
							printf("Please Enter your 4 digit PIN : ");
							scanf("%d",&password);
							if(accoun[i].pin==password)
							{
								printf("Account Details are:\n\n");
								display(i);
								j=1;
							}
							else
							{
								printf("Please enter correct PIN\n");
								goto retry1;
							}
					}	
				}
				if(j!=1)
				{
					printf("Account Not Found\n");
					j=0;
				}
				printf("Press any key to proceed\n");
				getch();
				system("cls");
				break;
			case 6:
				exit(1);
		}
	}
	getch();
	return 0;	
}
