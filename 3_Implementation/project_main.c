#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include "udhaar.h"

int main(){
    
    int option;
    printf("----------- WELCOME TO UDHAAR ----------\n");

    do{
        printf("\n1.New Transaction\n");
        printf("2.Update Old Transaction\n");
        printf("3.Displlay All Transactions\n");
        printf("4.Settle Udhaar\n");
        printf("5.Exit\n");
        printf("\nEnter option: ");input(option);
        switch (option)
        {
        case 1: new_transaction(0,false);
                break;
        case 2: update_record(0);
                break;
        case 3: display();
                break;
        case 4: settle();
                break;
        case 5 : exit_program();
                    break;
        default: printf("Invalid Option! Enter Again....\n\n");
                break;
        }
    }
    while(option!=5);

    return 0;
}


