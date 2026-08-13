# include<stdio.h>

int main() {

int num=0;
int highest=0;
printf("Enter a number: ");
scanf("%d",&num);
for(int i=31;i>=0;i--){
    if(num & (1<<i)){
        highest=i;
        break;
    }
}
printf("Highest order set bit in %d: %d\n", num, highest);
return 0;
}