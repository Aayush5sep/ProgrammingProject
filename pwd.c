#include <stdio.h>
#include <stdlib.h>
#include "fns.h"

typedef struct usersdb{
    int uid;
    char username[20],password[50],fname[20],lname[20],phone[10];
    char store[10][20];
}usersdb;

int apwd(int logged){

    printf("    Select the website to change the stored password for : \n");
    printf("\t1> Google\n");
    printf("\t2> Facebook\n");
    printf("\t3> Twitter\n");
    printf("\t4> Instagram\n");
    printf("\t5> LinkedIn\n");
    printf("\t6> Discord\n");
    printf("\t7> Codeforces\n");
    printf("\t8> Leetcode\n    ");

    int x;
    scanf("%d",&x);

    FILE *fp,*fpr;
    usersdb userdb;
    fp = fopen("userdata.bin","rb");
    fpr = fopen("temp.bin","wb");
    if (fp == NULL){
        printf("\tError! opening file");
        return(0);
    }
    while(fread(&userdb, sizeof(usersdb), 1, fp)){
        if(userdb.uid==logged){
            printf("    Type your New Password :    ");
            scanf("%s",&userdb.store[x-1]);
            printf("    Password Changed Successfully");
        }
        fwrite(&userdb, sizeof(usersdb), 1, fpr);
    }
    fclose(fp);
    fclose(fpr);

    fp = fopen("userdata.bin","wb");
    fpr = fopen("temp.bin","rb"); 
    if (fpr == NULL){
        printf("\tError! opening file");
        return(0);
    }
    while(fread(&userdb, sizeof(usersdb), 1, fpr)){
        fwrite(&userdb, sizeof(usersdb), 1, fp);
    }
    fclose(fp);
    fclose(fpr);

    return 0;
}

int allpwd(int logged){

    FILE *fp;
    usersdb userdb;
    fp = fopen("userdata.bin","rb");
    if (fp == NULL){
        printf("\tError! opening file");
        return(0);
    }
    while(fread(&userdb, sizeof(usersdb), 1, fp)){
        if(userdb.uid==logged){
            printf("\t1> Google :  %s\n",userdb.store[0]);
            printf("\t2> Facebook :  %s\n",userdb.store[1]);
            printf("\t3> Twitter :  %s\n",userdb.store[2]);
            printf("\t4> Instagram :  %s\n",userdb.store[3]);
            printf("\t5> LinkedIn :  %s\n",userdb.store[4]);
            printf("\t6> Discord :  %s\n",userdb.store[5]);
            printf("\t7> Codeforces :  %s\n",userdb.store[6]);
            printf("\t8> Leetcode :  %s\n    ",userdb.store[7]);
        }
    }
    fclose(fp);

    return 0;
}