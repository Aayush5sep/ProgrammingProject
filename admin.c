#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "fns.h"

typedef struct usersdb{
    int uid;
    char username[20],password[50],fname[20],lname[20],phone[10];
    char store[10][20];
}usersdb;

int nrecords(){
    FILE *fp;
    usersdb userdb;
    fp = fopen("userdata.bin","rb");
    if (fp == NULL){
        printf("\tError! opening file");
        return(0);
    }
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(usersdb);
    printf("\n");
    fclose(fp);

    return n;
}

int allrecords(){
    Sleep(500);
    FILE *fp;
    fp = fopen("userdata.bin","rb");
    if (fp == NULL){
        printf("\tError! opening file");
        return(0);
    }
    printf("\n Contents of File:\n");
    char c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);
    printf("\n");
    usersdb userdb;
    fp = fopen("userdata.bin","rb");
    if (fp == NULL){
        printf("\tError! opening file");
        return(0);
    }
    while(fread(&userdb, sizeof(usersdb), 1, fp)){
        printf("\tusername: %s\n",userdb.username);
        printf("\tEncrypted: %s\n",userdb.password);
        char str[100];
        printf("\tDecrypted Password: %s\n",decrypt(userdb.password,str));
        printf("\tfname: %s\n",userdb.fname);
        printf("\tlname: %s\n\n",userdb.lname);
    }
    fclose(fp);
    return 0;
}
