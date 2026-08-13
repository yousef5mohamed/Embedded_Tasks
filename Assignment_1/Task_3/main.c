#include<stdio.h>

int main() {

int num=0;
int nth=0;
int result=0;
printf("Enter a number: ");
scanf("%d", &num);
printf("Enter nth bit to check(0-31): ");
scanf("%d", &nth);
result = (num >> nth) & 1;
printf("The %d bit is set to %d\n", nth, result);
return 0;
}