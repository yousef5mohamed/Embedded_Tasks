#include<stdio.h>

int main(){

int num=0;
printf("Enter a number: ");
scanf("%d",&num);
printf("Original number: %d(in decimal)\n", num);
for(int i=0; i<=31 ; i++){
    num = num ^ (1<<i);
}
printf("Number after bits flipped: %d(in decimal)\n", num);
return 0;
}