/**************************************************************/
/*                                                            */
/*   Program to demonstrate the implmentation of a simple     */
/*   linked list of numbers with a delete function.								  */
/*                                                            */
/**************************************************************/

#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Preprocessor Variable
#define SIZE 3

//Stucture template for data part of the linked list
 struct data {
 	int num;
 };

//Stucture template for one node
struct LinearNode {
     struct data *element;
	struct LinearNode *next;
};


// Function prototypes
void addNodes();  //adding nodes to front of the list
void deleteNode(int); // delete a specific node
void viewAllNodes();
bool isEmpty();
void addNodesToEnd(int);
bool duplicate();

// Global Variables
struct LinearNode *list = NULL; //front of list

struct LinearNode *last = NULL; //pointer to last node in list



/**************MAIN FUNCTION*******************/ 
int main() {
	int delNum;
    char delay;
    bool dup=false;
	addNodes();
	viewAllNodes();

	printf("Please enter the number of the node to delete : ");
	scanf("%d", &delNum);
	deleteNode(delNum);
	viewAllNodes();
	dup = duplicate();
	printf("Did we find Duplicate numbers: %s",dup ? "true" : "false");
}
	
	
	
/**********ADD THREE NODES TO THE LIST******************/
// Each new node is added to the front of the list

void addNodes() {	
	int i;
	int aNumber;
	struct LinearNode *aNode;
	struct data *anElement;

	// add SIZE nodes to the list
	for (i=0; i<SIZE; i++) {
		printf("Enter a number for node %d: ", i+1);
		scanf("%d", &aNumber);
 
         //create space for new data element
         anElement = (struct data *)malloc(sizeof(struct data));
         
		// create space for new node
		aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

         //add aNumber to data node
         anElement->num = aNumber;
     
		if (aNode == NULL)
			printf("Error - no space for the new node\n");
		else { // add data part to the node
		 	aNode->next = NULL;
		 	aNode->element = anElement;

			//add node to front of the list
			if (isEmpty())  
			{
				list = aNode;
				last = aNode;
		    }
			else {
				aNode->next = list;
				list = aNode;
			} //end else
		}//end else
	}//end for
} //end addNodes
 		
void addNodesToEnd(int num)
{
    struct LinearNode *newNode, *temp;

    newNode = (struct LinearNode*)malloc(sizeof(struct LinearNode));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->element->num = num; // Link the data part
        newNode->next = NULL; 

        temp = list;

        // Traverse to the last node
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; // Link address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}	

void viewAllNodes() {
	struct LinearNode *current;

	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
			current = list;
			while (current != NULL) {
				printf("Node value is %d\n", current->element->num);
				current=current->next;
			} //end while
    }//end else
} //end viewAllNodes

bool duplicate() { 
	struct LinearNode *current;
	current=list;
    while (current->next != NULL) 
    { 
        // Starting from the next node 
        LinearNode *ptr = current->next; 
        while (ptr != NULL) 
        { 
            // If some duplicate node is found 
            if (current->element->num== ptr->element->num) 
            { 
                return true;
                break; 
            } 
            ptr = ptr->next; 
        } 
        current = current->next; 
    } 
    // Return the count of duplicate nodes 
    return false; 
} 
void deleteNode(int aNumber) {
	struct LinearNode *current, *previous;
	bool notFound = true;

	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else  {
			current = previous = list;

			while (notFound && current != NULL) {
				if (aNumber == current->element->num)
					notFound = false;
				else {
						previous = current;
						current = current->next;
				}//end else
			} //end while

			if (notFound)
				printf("Error - there is not such node with value %d\n", aNumber);
			else  {
				if (current == list) {
					list = list->next;
					free(current);
				} //end else
				else {
						previous ->next= current->next;
						free(current);
				} //end else
				printf("Node with value %d has been deleted\n", aNumber);
			}//end else
		}//end else
}// end deleteNode


bool isEmpty() {
	if (list == NULL)
		return true;
	else
		return false;
}
