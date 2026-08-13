#include<stdio.h>

int main() {

int num=0;
int MSB=0;
printf("Enter a number: ");
scanf("%d", &num);
MSB = (num >> 31) & 1;
printf("The MSB of %d is: %d\n", num, MSB);
return 0;
}