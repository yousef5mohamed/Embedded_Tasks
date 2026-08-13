#include<stdio.h>

int main() {

int num=0;
int count=0;
int i=31;
printf("Enter a number: ");
scanf("%d",&num);
while((num & (1<<i))==0){
i--;
count++;
}
printf("Total number of leading zeros in %d: %d\n", num, count);
return 0;
}