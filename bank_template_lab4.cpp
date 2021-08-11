#define bool int
#define false 0
#define true (!false)

#include <stdio.h>
#include <string.h>
#define SIZE 3

struct bank_customer
	{
     long accountNumber;
	 char name[20];
	 float balance;
    };

//function prototypes
void inputCustomers(struct bank_customer *);
bool overDrawn(struct bank_customer );//return false if there are no accounts overdrawn
void displayCustomer(long, struct bank_customer *);



int main()
{
    long accNum;
    struct bank_customer bank[SIZE];
   
	//1. Input customers

	//2. For each customer in the array, 
	//display names of those that are overdrawn by calling overDrawn()
	//in a loop

	//3. Ask user to input an account number, then call displayCustomer()
	//which passes in the account number and array and searches
	//and displays the account details if it finds it
    
}



