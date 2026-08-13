# include<stdio.h>

int main() {

int num=0;
int lowest=0;
printf("Enter a number: ");
scanf("%d",&num);
for(int i=0;i<=31;i++){
    if(num & (1<<i)){
        lowest=i;
        break;
    }
}
printf("Lowest order set bit in %d: %d\n", num, lowest);
return 0;
}