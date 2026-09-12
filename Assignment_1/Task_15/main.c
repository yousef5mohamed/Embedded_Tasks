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
printf("Enter a number: ");
scanf("%d",&num);
printf("converted binary of %d: ", num);
for( int i=31; i>=0; i--){
    if(num & (1<<i)){
     printf("1");
    }
    else{
     printf("0");
    }
}
return 0;
}
