#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include "udhaar.h"

struct transaction *trans_dat = NULL ;
int file_size = 0; 

int read_file(){

    FILE * df = fopen("Udhar.text","r");
    if(df == NULL) return 0;

    struct transaction all_trans;
    int count=0,i=0;char c;
    while ((c = fgetc(df))!=EOF)if(c=='\n')count++;
    fseek(df,0,SEEK_SET);
    file_size =count;

    trans_dat = (struct transaction*)malloc(file_size*sizeof(struct transaction));

     while(fscanf(df,"%39s %39s %lld %lf %lf %lf %d %d %d %d %d %d",all_trans.fname,
    all_trans.lname,
        &all_trans.contact,
        &all_trans.loan_given,
        &all_trans.loan_taken,
        &all_trans.total_transaction_state,
        &all_trans.day_updated,
        &all_trans.mon_updated,
        &all_trans.yr_updated,
        &all_trans.hr_updated,
        &all_trans.min_updated,
        &all_trans.sec_updated)!=EOF){
            trans_dat[i] = all_trans;
            i++; 
        }
    fclose(df);
    return 1;
}
int write_file(){

    FILE * df = fopen("Udhar.text","w");
    if (df==NULL)return 0;

    for(int i=0;i<file_size;i++){
    fprintf(df,"%s %s %lld %lf %lf %lf %d %d %d %d %d %d\n",
        trans_dat[i].fname,
        trans_dat[i].lname,
        trans_dat[i].contact,
        trans_dat[i].loan_given,
        trans_dat[i].loan_taken,
        trans_dat[i].total_transaction_state,
        trans_dat[i].day_updated,
        trans_dat[i].mon_updated,
        trans_dat[i].yr_updated,
        trans_dat[i].hr_updated,
        trans_dat[i].min_updated,
        trans_dat[i].sec_updated);
    }
    fclose(df);
    return 1;
}
int search_contact(ll target_contact){
    
    int i=0,pos=-1;
    while(i<file_size){
        // printf("%d", i);
        if(trans_dat[i].contact == target_contact){
            pos = i;
            break;
        }
        i++;
    }
    // printf("%d",pos);
    return pos;
}
int update_time_stamp(int pos){

    if(pos == -1)return 0;

    struct tm* timedata;
    time_t t; time(&t);
    timedata = localtime(&t);
    trans_dat[pos].day_updated = timedata->tm_mday;
    trans_dat[pos].mon_updated = timedata->tm_mon;
    trans_dat[pos].yr_updated = timedata->tm_year+1900;
    trans_dat[pos].hr_updated = timedata->tm_hour;
    trans_dat[pos].min_updated = timedata->tm_min;
    trans_dat[pos].sec_updated = timedata->tm_sec;

    return 1;
}
int new_transaction(ll contact,bool from_update){

    if(file_size==0){
        read_file();
    }

    struct tm* timedata;
    struct transaction new_trans;
    int ynoption;
    if(from_update) new_trans.contact = contact;
    else{
        printf("\nEnter Contact of New Transactee: ");inputll(new_trans.contact);
        int pos = search_contact(new_trans.contact);
        // printf("%d", pos); 
        if(pos!= -1){
                printf("\nRecord Already Exists! Do you want to update record? [1 for Yes/0 for No] : ");
                input(ynoption);
                if(ynoption == 1)update_record(new_trans.contact);
                return 2;
        }
    }
    
    printf("\nEnter First Name of New Transactee: ");inputstr(new_trans.fname);
    printf("\nEnter Last Name of New Transactee: ");inputstr(new_trans.lname);
    printf("\nEnter Amount of Udhaar Taken from New Transactee: ");inputdb(new_trans.loan_taken);
    printf("\nEnter Amount of Udhaar Given to New Transactee: ");inputdb(new_trans.loan_given);
    
    new_trans.total_transaction_state = new_trans.loan_given - new_trans.loan_taken;
    
    time_t t; time(&t);
    timedata = localtime(&t);
    new_trans.day_updated = timedata->tm_mday;
    new_trans.mon_updated = timedata->tm_mon;
    new_trans.yr_updated = timedata->tm_year+1900;
    new_trans.hr_updated = timedata->tm_hour;
    new_trans.min_updated = timedata->tm_min;
    new_trans.sec_updated = timedata->tm_sec;

    int temp_size = file_size+1;
    struct transaction temp_vector[temp_size];
    for(int i=0;i<file_size;i++){
        temp_vector[i] = trans_dat[i];
    }
    //printf("%d", temp_size);
    temp_vector[temp_size-1] = new_trans;
    free(trans_dat);
    trans_dat = (struct transaction*)malloc(temp_size*sizeof(struct transaction));
    for(int i=0;i<temp_size;i++){
        trans_dat[i] = temp_vector[i];
    }
    file_size = temp_size;
    printf("\nRecord Added Successfully!\n");
    return 1;
}
int display(){
    if(file_size==0){
        read_file();
    }
    char h1[] = "Sr";
    char h2[] = "First_Name";
    char h3[] = "Last_Name";
    char h4[] = "Contact";
    char h5[] = "Loan_Given";
    char h6[] = "Loan_Taken";
    char h7[] = "Current_State";
    char h8[] = "Last_Updated";
    printf("\n%s. %-11s  %-12s %-11s\t %-10s \t%-10s \t%-10s   %s\n",h1,h2,h3,h4,h5,h6,h7,h8);
    for(int i=0;i<file_size;i++){
        if(trans_dat[i].total_transaction_state<0){
        printf("%d.  %-12s %-12s %lld\t %-10.3lf \t%-10.3lf \t\033[;31m%-10.3lf      \033[0m%d/%d/%d @ %d:%d:%d\n",
            i+1,
            trans_dat[i].fname,
            trans_dat[i].lname,
            trans_dat[i].contact,
            trans_dat[i].loan_given,
            trans_dat[i].loan_taken,
            trans_dat[i].total_transaction_state,
            trans_dat[i].day_updated,
            trans_dat[i].mon_updated,
            trans_dat[i].yr_updated,
            trans_dat[i].hr_updated,
            trans_dat[i].min_updated,
            trans_dat[i].sec_updated);
        }
        else {
            printf("%d.  %-12s %-12s %lld\t %-10.3lf \t%-10.3lf \t\033[;32m%-10.3lf      \033[0m%d/%d/%d @ %d:%d:%d\n",
        i+1,
        trans_dat[i].fname,
        trans_dat[i].lname,
        trans_dat[i].contact,
        trans_dat[i].loan_given,
        trans_dat[i].loan_taken,
        trans_dat[i].total_transaction_state,
        trans_dat[i].day_updated,
        trans_dat[i].mon_updated,
        trans_dat[i].yr_updated,
        trans_dat[i].hr_updated,
        trans_dat[i].min_updated,
        trans_dat[i].sec_updated);
        }
         
    }
    printf ("\n");
    return 1 ;
}

int update_record(ll target_contact){
    if(file_size==0){
        read_file();
    }
    int option;
    if(target_contact == 0){
        printf("\nEnter Contact of transactee to update loan info : ");inputll(target_contact);
    }
    int pos=search_contact(target_contact);
    if(pos != -1){
        printf("\nUpdate 1.Loan_Given or 2.Loan_Taken: ");input(option);
        if(option == 1){
            double t;
            printf("\nCurrent Loan given amount = %lf\n",trans_dat[pos].loan_given);
            printf("\nUpdate Loan_Given. Enter New Amount Given to %s %s:",trans_dat[pos].fname,trans_dat[pos].lname);
            inputdb(t);
            trans_dat[pos].loan_given += t;
        }
        else if (option == 2){
            double t;
            printf("\nCurrent Loan given amount = %lf\n",trans_dat[pos].loan_taken);
            printf("\nUpdate Loan_Taken. Enter New Amount Taken from %s %s : ",trans_dat[pos].fname,trans_dat[pos].lname);
            inputdb(t);
            trans_dat[pos].loan_taken += t;
            }
    }
    else{
            printf("\nRecord Does Not Exist! Do you want to add new record ? [1 for Yes / 0 for No] ");
            input(option);
            if(option == 1)new_transaction(target_contact,true);
            return 2;
    }
    trans_dat[pos].total_transaction_state = trans_dat[pos].loan_given - trans_dat[pos].loan_taken ;
    update_time_stamp(pos);
    printf("\nRecord Updated Successfully!\n");
    return 1;
}


int settle(){
    ll contact;
    printf("\nEnter Contact to Settle Udhaar with: ");inputll(contact);
    int option=0;int pos = search_contact(contact);
    if(pos!=-1){
        printf("\nAre you sure you want to settle your Udhaars with %s %s? [1 for Yes / 0 for No]:",trans_dat[pos].fname,trans_dat[pos].lname);
        input(option);
        if(option == 1){
            trans_dat[pos].loan_taken = 0;
            trans_dat[pos].loan_given = 0;
            trans_dat[pos].total_transaction_state = 0;
            update_time_stamp(pos);
            printf("\nCongratulations! Udhaar Settled!\n");
        }
    }
    else {
        printf("\nRecord Does Not Exist! Do you want to add new record ? [1 for Yes / 0 for No]: ");
        input(option);
        if(option == 1)new_transaction(contact,true);
        return 2 ;
    }
    return 1;
}

int exit_program(){
    write_file();
    free(trans_dat);
    trans_dat = NULL;
    printf("\nSaving Changes..... GoodBye!\n");
    return 1;
}