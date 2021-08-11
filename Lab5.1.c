#include <stdio.h>
#define RESULT_SIZE 2
#define NUM_STUDENTS 3

/* Structure template */
struct student
{
	char studentName[20];  //ONE String
	char course[10];    //ONE String
	int year; //one int
	float results[RESULT_SIZE]; //6 exam results
};

/* Type definition */
typedef struct student STUDENT;

/* Function Prototype */
void inputStudents(STUDENT *);
void displayAllStudent(STUDENT *);
int numberFailed(STUDENT *);
float displayAverage(int, STUDENT *);

int main()
{
	int studentIndex;
	int tempStudentIndex;
    STUDENT student1[NUM_STUDENTS];
    inputStudents(student1);
    displayAllStudent(student1);
    numberFailed(student1);
    do{
	printf("\nWhat student would you like to process to get their average marks?(input studentNumber)");
	scanf("%d", &studentIndex);
	tempStudentIndex=studentIndex-1;
	if((tempStudentIndex>NUM_STUDENTS) || (tempStudentIndex<0)){
		printf("Error - Please enter a valid StudentNumber");
	}
	}while((tempStudentIndex>NUM_STUDENTS) || (tempStudentIndex<0));
    displayAverage(tempStudentIndex, student1);
    
   
}

void inputStudents (struct student *studentArray){
	int i;
	for (i=0; i<NUM_STUDENTS; i++)
	{
	int tempYear=0;
	printf("\nEnter the name of Student %d: ", i+1);
	scanf("%s", studentArray[i].studentName);
	printf("Enter the course code of Student %d: ",i+1);
	scanf("%s", studentArray[i].course);
	do{
	printf("Enter what year Student %d is in eg(1-4): ",i+1);
	scanf("%d", &tempYear);
	if((tempYear>4) || (tempYear<1)){
		printf("Error - Please enter a valid year(1-4)....");
	}
	}while((tempYear>4) || (tempYear<1));
	studentArray[i].year = tempYear;
	int j;
	for (j = 0; j<RESULT_SIZE; j++ )
	{
		printf("Enter result %d of Student %d: ", j+1 ,i+1);
		scanf("\n%f", &studentArray[i].results[j]);
	}
	}
}

void displayAllStudent(struct student *studentArray){
	int i;
	for (i=0; i<NUM_STUDENTS; i++)
	{
		printf("\n\nStudent %d Information: ", i+1);
	printf("\nStudent Name: %s ", studentArray[i].studentName);
	printf("\nCourse: %s ", studentArray[i].course);
	printf("\nYear: %d ", studentArray[i].year);
	int j;
	for (j = 0; j<RESULT_SIZE; j++ )
	{
		printf("Result %d: %3.2f%%  ", j+1, studentArray[i].results[j]);
	}
		
	}
}

int numberFailed(struct student *studentArray){
	int i;
	printf("\n\n Students who receive under 45%% have failed their exam");
	for (i=0; i<NUM_STUDENTS; i++)
	{
	int j;
	for (j = 0; j<RESULT_SIZE; j++ )
	{
		float tempResult = studentArray[i].results[j];
		if(tempResult<45){
			printf("\nStudent %d's Result %d is a fail : Result-%3.2f%%", i+1 ,j+1, tempResult);
		}
	}
	}
}

float displayAverage (int studentIndex, struct student *studentArray){
	float tempResult;
	int j;
	for (j = 0; j<RESULT_SIZE; j++ )
	{
		tempResult = tempResult + studentArray[studentIndex].results[j];
	}
	float avg = tempResult/RESULT_SIZE;
	printf("\nStudent %d's Average Result is %3.2f%%", studentIndex + 1, avg);
}


