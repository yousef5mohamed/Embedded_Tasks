/**
 * @file main.c
 * @brief Application entry point and task implementation.
 * @details Contains the application or common definitions required by the project.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include<stdio.h>

/**
 * @fn main
 * @brief Application entry point.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return int Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
int main(){

int num1=0;
int num2=0;
int temp=0;
printf("Enter two numbers: ");
scanf("%d %d",&num1,&num2);
printf("Original values num1 = %d\n", num1);
printf("Original values num2 = %d\n", num2);
temp = num1;
num1 = num2;
num2 = temp;
printf("Values after swapping num1 = %d\n", num1);
printf("Values after swapping num2 = %d\n", num2);
return 0;
}
