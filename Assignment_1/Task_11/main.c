#include<stdio.h>

int main(){

int num=0;
int zeros=0;
int ones=0;
printf("Enter a number: ");
scanf("%d",&num);
for(int i=0; i<=31; i++){
    if(num & (1<<i)){
        ones++;
    }
    else{
        zeros++;
    }
}
printf("Total zero bits: %d\n", zeros);
printf("Total one bits: %d\n", ones);
return 0;
}