// This is a program which demonstrates the use of structures and shows how they can be passed as 
//parameters

#include <stdio.h>
#include <string.h>


/* function prototypes */
int inputOrder (struct order *);
void displayOrder(struct order );


/* structure template. This can be declared as a global template or local to main() */
struct order
	{
		int orderNum;
		char productName[20];
		int quantity;
		float price;
	};


/* OR if I want to declare a global variable to be of type order

 struct order
	{
		int orderNum;
		char productName[20];
		int quanity;
		float price;
	}order1;
*/

typedef struct order Order;

int main()
{
	int theOrderNum;
   
	Order theOrder;  // declare an instance of the order record
	

	// input the order details. As I want the function to change the content of
	// theOrder variable, then I have to pass the variable using a "call by reference"
	// parameter passing mechanism. This means that I pass the ADDRESS of theOrder into
	// the function so any changes that I make to theOrder are permament. This function then
	// returns the new order number.
	theOrderNum = inputOrder(&theOrder);

	printf ("\n\nThe new order number is %d\n\n\n", theOrderNum);

	// In this function, I only want to view the contents of the order. Therefore I make a copy of the
	// order and pass it over. This is "call by value". It is by far the most common way of passing 
	// parameters.
	displayOrder(theOrder);


	printf ("\nThe total price of the order is %5.2f euro(s)\n", theOrder.price * theOrder.quantity);

}


int inputOrder (struct order *anOrder)
{
	printf("Enter order number : ");
	scanf("%d", &anOrder->orderNum);
	printf("Enter product name : ");
	scanf("%s", anOrder->productName);
	printf("Enter order quantity : ");
	scanf("%d", &anOrder->quantity);
	printf("Enter price of product : ");
	scanf("%f", &anOrder->price);
	return (*anOrder).orderNum;
	// return anOrder->orderNum;
}


void displayOrder(struct order anOrder)
{
	printf("ORDER DETAILS \n=============\n");
	printf("The order number is : %d\n", anOrder.orderNum);
	printf("The product name is : %s\n", anOrder.productName);
	printf("The  quantity is : %d\n", anOrder.quantity);
	printf("The price is : %5.2f\n", anOrder.price);
}

