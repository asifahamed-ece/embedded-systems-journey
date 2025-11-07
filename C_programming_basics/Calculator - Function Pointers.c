#include <stdio.h>

//Operations
int add(int x, int y){return x+y;}
int sub(int x, int y){return x-y;}
int mul(int x, int y){return x*y;}
int div(int x, int y){if(y==0){printf("Error! Cannot Divide by '0'\n");}return y!=0 ? x/y:0 ;}

int main(){

    int choice;
    int (*calculator[]) (int, int) = {add, sub, mul, div};
    char *operations[] = {"Add", "Subtract", "Multiply", "Divide"};

    label1:
    printf("0: Add \n1: Sub \n2: Multiply \n3: Divide: \nEnter Your Choice : ");

    scanf("%d", &choice);

    if(choice >=0 && choice <4){
        int a; int b;
        printf("Enter 2 Numbers: ");
        scanf("%d %d",&a,&b);

        int result = calculator[choice](a, b);
        printf("%s Computation Result : %d", operations[choice], result);

        }
        else{printf("Invalid Choice!\nEnter Choice between 0 to 3\n");
        printf("\n");
        goto label1;
        }


    return 0;
}
