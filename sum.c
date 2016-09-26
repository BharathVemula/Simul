#include <stdio.h>
#include <stdlib.h>

#define limit 10000000 /*size of integers array*/

int main(){
    int i,j;
    int *nums,n,sum=0;
    double start_t,end_t;
    struct timeval tv;
    gettimeofday(&tv, 0);
    start_t = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;

    //printf("Enter number of numbers required : ");
    //scanf("%d",&n);
    n = limit;
    nums = (int *)malloc(n*(sizeof(int)));
    //printf("\nEnter the numbers: \n");
    
    for(i=0;i<n;i++)
        nums[i] = rand()%3;

    #pragma omp parallel for reduction(+:sum)
        for(i=0;i<n;i++)
            sum += nums[i];
    printf("\nsum: %d",sum);

    gettimeofday(&tv, 0);
    end_t = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
    end_t = end_t - start_t;
         
return 0;
}
