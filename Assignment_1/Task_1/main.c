#include<stdio.h>

int main() {

int num=0;
int lsb=0;
printf("Enter a number:");
scanf("%d", &num);
lsb= num & 1;
printf("the LSB of %d is %d\n", num, lsb);
return 0;
}