#include <stdio.h>

int main(){

int num = 0 ;
int count = 0;
printf("Enter a number :");
scanf("%d", &num);
for(int i=0; i<=31; i++){
    if(!(num & (1<<i))){
        count++;
    }
}
printf("Number of zeros bits in %d: %d\n", num, count);
return 0;
}