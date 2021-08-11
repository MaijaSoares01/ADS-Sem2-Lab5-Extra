#include <stdio.h>
#define SIZE 10

//Global Structure - note this does NOT declare a structuee
struct point {
       int x;
       int y;
}; 

int main ()
{
    char pause;
    struct point p[SIZE];
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter x and y for point %d ", (i+1));
        scanf("%d", &p[i].x);
        scanf("%d", &p[i].y);
    }//end for
    
    printf("\nDisplaying the %d values\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("x = %d and y = %d for point %d \n", p[i].x, p[i].y, (i+1));
    }
  
   
}
