#include <stdio.h>
#include <string.h>
#define SIZE 100

struct bank_customer
{
	long account_num;
	char name[30];
	float balance;
};

int getBankSize();
void inputCustomers(int, struct bank_customer *);
void displayNegativeCustomers(int, struct bank_customer *);
int getTotal(int, struct bank_customer *);

int main() { 
	struct bank_customer bank[SIZE]; 
	float total=0.0; 
	int numCustomers; 
	
	numCustomers=getBankSize(); 
	inputCustomers(numCustomers, bank); 
	displayNegativeCustomers(numCustomers, bank); 
	total=getTotal(numCustomers, bank); 
	printf("Total balance in bank = %5.2f Euros\n", total); 
} //end main

int getBankSize()
{
	int sizeOfBank;
	do {
		printf("Enter the number of bank customers (<100)");
		scanf("%d",&sizeOfBank);
	}while (sizeOfBank < 0 || sizeOfBank > SIZE);
	return (sizeOfBank);
} //end getBankSize

void inputCustomers(int num, struct bank_customer *bank)
{
	printf("Inputting %d customers...\n", num);
	for (int index=0; index<num; index++)
	{
		printf("Enter account number for customer %d: \n", index+1);
		scanf("%ld",&bank[index].account_num);
		printf("Enter customer name : ");
		scanf("%s",bank[index].name);
		printf("Enter account balance: " );
		scanf("%f",&bank[index].balance);

	} //end for
} //end inputCustomers

void displayNegativeCustomers(int num, struct bank_customer *bank)
{
	printf("\nDisplaying %d bank customers with a negative balance...\n", num);
	for (int i=0; i < num; i++) {
		if (bank[i].balance < 0) {
			printf("Account Num : %ld\n", bank[i].account_num);
			printf("Name : %s\n", bank[i].name);
			printf("Balance : %5.2f\n", bank[i].balance);
		} //end if
	} //end for
} // end displayCustomer

int getTotal(int num, struct bank_customer *bank) { 
	float total = 0.0; 
	for (int index=0; index<num; index++) 
		total+=bank[index].balance; 
		
	return total; 
} //end getTotal


