# include<stdio.h>

int main() {

int num=0;
int nth=0;
printf("Enter a number: ");
scanf("%d", &num);
printf("Enter nth bit to clear (0-31): ");
scanf("%d", &nth);
printf("Bit cleared successfully\n");
printf("Number before clearing %d bit: %d (in decimal)\n", nth, num);
num = num & ~(1 << nth);
printf("Number after clearing %d bit: %d (in decimal)\n", nth, num);
return 0;
}