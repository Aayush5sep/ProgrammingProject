#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fns.h"

typedef struct usersdb{
    int uid;
    char username[20],password[50],fname[20],lname[20],phone[10];
    char store[10][20];
}usersdb;

int usercheck(char* uname){
    FILE *fp;
    usersdb userdb;
    fp = fopen("userdata.bin","rb");
    if (fp == NULL){
        printf("\tError! opening file");
        return(0);
    }
    while(fread(&userdb, sizeof(usersdb), 1, fp)){
        if(strcmp(uname,userdb.username)==0){
            int id=userdb.uid;
            fclose(fp);
            return id;
        }
    }
    fclose(fp);
    return -1;
}

int pwdcheck(char* uname,char* pwd){
    FILE *fp;
    usersdb userdb;
    fp = fopen("userdata.bin","rb");
    if (fp == NULL){
        printf("\tError! opening file");
        return(0);
    }
    while(fread(&userdb, sizeof(usersdb), 1, fp)){
        if(strcmp(uname,userdb.username)==0){
            char str[20];
            decrypt(userdb.password,str);
            if(strcmp(str,pwd)==0){
                fclose(fp);
                return 1;
            }
            // if(strcmp(userdb.password,pwd)==0){
            //     fclose(fp);
            //     return 1;
            // }
        }
    }
    fclose(fp);
    return 0;
}

int udetails(int logged){
    FILE *fp;
    usersdb userdb;
    fp = fopen("userdata.bin","rb");
    if (fp == NULL){
        printf("\tError! opening file");
        return(0);
    }
    while(fread(&userdb, sizeof(usersdb), 1, fp)){
        if(userdb.uid==logged){
            printf("\tUsername: %s\n",userdb.username);
            printf("\tName : %s %s\n",userdb.fname,userdb.lname);
            printf("\tPhone : %s\n",userdb.phone);
            
        }
    }
    fclose(fp);
    return 0;
}