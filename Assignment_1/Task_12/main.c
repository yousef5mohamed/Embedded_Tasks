#include<stdio.h>

int main(){

int num=0;
int shift_num=0;
int num_left=0;
int num_right=0;
printf("Enter a number: ");
scanf("%d",&num);
num_left = num;
num_right = num;
printf("Enter number of rotations: ");
scanf("%d",&shift_num);
for(int i=0; i<shift_num; i++){
    
    num_left = (num_left << 1) | (num_left >> 31);
    num_right = (num_right >> 1) | (num_right << 31);
}
printf("%d after left rotation: %d\n", num, num_left);
printf("%d after right rotation: %d\n", num, num_right);
return 0;
}