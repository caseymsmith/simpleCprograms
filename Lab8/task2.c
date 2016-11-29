#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ARRAY_SIZE 100
int intArr[ARRAY_SIZE]; //global integer array
int arrSize=0;  //number of values in array

void *scoresInArr(){
    int ex=1;  //becomes -1 if the user wants to exit the loop
    int current=0;
    int i=0;
    while((i < 20) && (ex ==1)){
        printf("Please enter a test score (type -1 to stop): ");
        scanf("%i", &current);

        if(current == -1){
            ex=-1; 
        }
        else{
            intArr[i]=current;
            i++;
        }
    }
    arrSize=i;
    for(int x=0; x<arrSize; x++){
        printf("Array element: %i\n", intArr[x]);
    }

    return 0;
}

void *meanMedium(){
    float average;
    float medium; 

   for(int i=0; i<arrSize; i++){
    average=average+intArr[i];
   }
   average=average/arrSize;

   printf("The average of the test scores is: %.1f%%\n", average);


   int *intArr2=intArr; 
   //temporary array so global array is not messed up being sorted and calculated
   int current; 
   for(int k=0; k<arrSize; k++){
    int l=0;
    for(l=k+1; l<arrSize; l++){
        if((intArr2[k]>intArr2[l])){
            current=intArr2[k];
            intArr2[k]=intArr2[l];
            intArr2[l]=current;
        }
    }
   }

   if(arrSize%2==1){ //if it's an odd middle number. 
    medium=(float)intArr2[arrSize/2];
    printf("The middle number of the test scores is: %.0f\n", medium);
   }
   else if (arrSize%2==0){
    float upper, lower; 
    //placeholder for the two numbers that are both considered in the middle
    upper=(float)intArr2[(arrSize/2)-1];
    lower=(float)intArr2[arrSize/2];
    medium=(upper+lower)/2;
    printf("The middle number of the test scores is: %.2f\n", medium);
    }

    return 0;
}

void *minMax(){

   int *intArr2=intArr; 
   //temporary array so global array is not messed up being sorted and calculated
   int current; 
   for(int k=0; k<arrSize; k++){
    int l=0;
    for(l=k+1; l<arrSize; l++){
        if((intArr2[k]>intArr2[l])){
            current=intArr2[k];
            intArr2[k]=intArr2[l];
            intArr2[l]=current;
        }
    }
   }
    printf("The minimum score is: %d\n", intArr2[0]);
    printf("The maximum score is: %d\n", intArr2[arrSize-1]);

    return 0;
}

void *clear(){
    int i=0;
    while(i < 20){
        intArr[i]=0;
        i++;
    }
    arrSize=i;

    return 0;
}//while loop iterates through the array to set every element equal to 0 

int main(){

    pthread_t tid, tid2, tid3, tid4; //integer used to identify the thread in the system
    pthread_create(&tid, NULL, scoresInArr, NULL); //function to create thread
    pthread_join(tid, NULL); //makes thread 2 wait for thread 1
    pthread_create(&tid2, NULL, meanMedium, NULL); //function to create thread
    pthread_create(&tid3, NULL, minMax, NULL);
    pthread_join(tid2, NULL); //waits for the meanMedium to terminate
    pthread_join(tid3, NULL); //waits for the minMax to terminate
    pthread_create(&tid4, NULL, clear, NULL);
    pthread_join(tid4, NULL); //waits for the clear to terminate


    for(int x=0; x<arrSize; x++){
        printf("Array element: %i\n", intArr[x]);
    } //for loop to print out all 20 elements being 0

    exit(0);
}