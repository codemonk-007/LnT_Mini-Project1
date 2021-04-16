/** 
* @file udhaar.h
* UDHAAR application to store all udhaar transactions of a user
*
*/
#ifndef __UDHAAR_H__
#define __UDHAAR_H__
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#define ll long long 
#define input(x) scanf("%d",&x)
#define inputll(x) scanf("%lld",&x)
#define inputc(x) scanf("%c",&x)
#define inputstr(x) scanf("%s",x);
#define inputdb(x) scanf("%lf",&x);
#define and &&
#define or ||

/**
 * @brief error enumerations for unit testing
 * 
 */

// typedef enum error_t{
//     SUCCESS = 0, 
//     FILE_DOES_NOT_EXIST =1,
//     STR_PTR_UNINIT = 2,
// }error_t;

/**
 * @brief  Structure for the transaction details of UDHAAR
 */
typedef struct transaction{
    char fname[40];
    char lname[40];
    ll contact;
    double loan_taken;
    double loan_given;
    double total_transaction_state;
    int day_updated;
    int mon_updated;
    int yr_updated;
    int hr_updated;
    int min_updated;
    int sec_updated;
}transaction;

/**
*  @brief reads data file of the UDHAAR
* @return 0 if file does not exist else 1;
*/
int read_file();

/**
*  @brief writes UDHAAR data into main file 
* @return 0 if file does not exist else 1
*/
int write_file();

/**
*  @brief searches contact in the struct pointer 
* @param[in] target_contact  
* @return 0 if file does not exist else returns 
*/
int search_contact(ll target_contact);


/**
* @brief updates time_stamp of specified record
* @param[in] position of contact to update time_stamp
* @returns returns -1 if record not found else 1
*/
int update_time_stamp(int pos);

/**
 * @brief creates new transaction of UDHAAR
 * @param[in] target_contact
 * @param[in] redirection_from_update
 * @returns 2 if contact exists else returns 1
 */
int new_transaction(ll contact, bool from_update);

/**
 * @brief updates existing udhaar transaction
 * @param[in] target_contact
 * @returns 2 if contact does not exist else returns 1
 */
int update_record(ll target_cntact);

/**
 * @brief displays all record in file
 * @return 1 always
 */
int display();

/**
 * @brief settles udhaar with contact
 * @returns 2 if contact does not exist else reutrns 1 
 */
int settle();

/**
 * @brief saves all data in file , frees memory pointer 
 * @returns 1 always.
 */
int exit_program();
#endif  /* #define __CALCULATOR_OPERATIONS_H__ */