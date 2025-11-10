#include <stdio.h>

int main(){
    int a=5,b=2;  //a -> Time Intervals , b -> No. of Sensors
    float temperatures[a][b];
    float avg[b];
    float max[a];


    for(int i=1; i<=a;i++){
            for(int j=1; j<=b;j++){
                printf("Enter %d interval Temperature Values :",i);
                scanf("%f",&temperatures[i][j]);
                printf("\n");
            }
    }

    printf("The Temperature Matrix is :\n");
    for(int i=1; i<=a;i++){
            for(int j=1; j<=b;j++){
                printf("%.2f ",temperatures[i][j]);
            }printf("\n");
    }

    for(int j=1; j<=b;j++){
            float sum=0;

            for(int i=1; i<=a;i++){
                sum += temperatures[i][j];
            }
            avg[j]= sum/a;
            printf("Avg Value of Sensor%d is %.2f\n",j, avg[j]);
    }

    printf("Avg Values: \n");
    for(int i=1; i<=b;i++){
        printf("%dSensor Value : %.2f\n",i,avg[i]);
    }
}
