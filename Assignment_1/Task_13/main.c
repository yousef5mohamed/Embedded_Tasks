#include<stdio.h>

int main(){

int num1=0;
int num2=0;
int temp=0;
printf("Enter two numbers: ");
scanf("%d %d",&num1,&num2);
printf("Original values num1 = %d\n", num1);
printf("Original values num2 = %d\n", num2);
temp = num1;
num1 = num2;
num2 = temp;
printf("Values after swapping num1 = %d\n", num1);
printf("Values after swapping num2 = %d\n", num2);
return 0;
}