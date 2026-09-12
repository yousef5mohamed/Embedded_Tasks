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
