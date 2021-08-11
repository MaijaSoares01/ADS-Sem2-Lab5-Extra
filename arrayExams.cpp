#include <stdio.h>
#define RESULT_SIZE 5
#define NUM_EXAMS 3

/* Structure template */
struct exam
{
	char examName[20];  //ONE String
	char course[10];    //ONE String
	float results[RESULT_SIZE]; //5 exam results
};

/* Type definition */
typedef struct exam EXAM;

/* Function Prototype */
void inputExams(EXAM *);
void display(EXAM *);

int main()
{
    EXAM semester1Exams[NUM_EXAMS];
    
    inputExams(semester1Exams);
    display(semester1Exams);
    
   
}

void inputExams(EXAM *theExams)
{
	printf("\nInputting %d exams...\n", NUM_EXAMS);
	
	for (int i=0; i<NUM_EXAMS; i++)
	{
	
	printf("\nEnter the exam name for exam %d: ", i+1);
	scanf("%s", theExams[i].examName);
	printf("Enter the course code: ");
	scanf("%s", theExams[i].course);
	
	for (int j = 0; j<RESULT_SIZE; j++ )
	{
		printf("Enter  result %d: ", j+1);
		scanf("%f", &theExams[i].results[j]);
	}
	}
}

void display(EXAM *theExams)
{
	printf("\nDisplaying %d exams...\n", NUM_EXAMS);
	
	for (int i=0; i<NUM_EXAMS; i++)
	{
	printf("\n\n The exam name for exam %d: %s\n ", i+1, theExams[i].examName);
	printf("The course code: %s\n", theExams[i].course);
	
	for (int j = 0; j<RESULT_SIZE; j++ )
	{
		printf("Result %d: %3.2f%%  ", j+1, theExams[i].results[j]);
	}
		
	}
}

