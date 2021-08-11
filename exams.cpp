#include <stdio.h>
#define SIZE 5

/* Structure template */
struct exam
{
	char examName[20];  //ONE String
	char course[10];    //ONE String
	float results[SIZE]; //5 exam result
};

/* Type definition */
typedef struct exam EXAM;

/* Function Prototype */
void inputExam(EXAM *);
float getAverage(EXAM);

int main()
{
    EXAM anExam;
    inputExam(&anExam);
    printf("The average of %d exams are %.2f\n", SIZE, getAverage(anExam));
    getchar();
    getchar();
}


void inputExam(EXAM *theExam)
{
	printf("Enter the exam name: ");
	scanf("%s", theExam->examName);
	printf("Enter the course code: ");
	scanf("%s", theExam->course);
	
	for (int i = 0; i<SIZE; i++ )
	{
		printf("Enter the result %d: ", i+1);
		scanf("%f", &theExam->results[i]);
	}
}


float getAverage(EXAM theExam)
{
	float total = 0;
	for (int i=0; i< SIZE; i++)
		total += theExam.results[i];
	return total/SIZE;
}
