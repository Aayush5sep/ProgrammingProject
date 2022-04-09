#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "fns.h"

typedef struct usersdb{
    int uid;
    char username[20],password[50],fname[20],lname[20],phone[10];
    char store[10][20];
}usersdb;

int logged=-1;


int login(){
    int status=-1;
    char uname[20],pwd[20];
    printf("    Enter your Username :  ");
    scanf("%s",uname);
    int uid = usercheck(uname);
    if(uid!=(-1)){
        printf("    Enter your Password :  ");
        scanf("%s",pwd);
        if(pwdcheck(uname,pwd)==1){
            status=uid;
            printf("\n\tLogin Successful");
        }
        else{
            printf("\n\tLogin Failed");
        }
    }
    else{
        printf("\n\tLogin Failed. No such username");
    }
    logged=status;
    return 0;
}

int logout(){
    logged=-1;
    printf("    Logged Out Successfully");
}

int newaccnt(){
    FILE *fp;
    fp = fopen("userdata.bin","ab");
    if(fp == NULL){
        printf("\tError! opening file");
        return 0;
    }
    usersdb nuser;
    nuser.uid = (nrecords()+1);
    int unid = nuser.uid;
    printf("    Enter your Username :  ");
    scanf("%s", nuser.username);
    printf("    Enter your Password :  ");
    // scanf("%s", nuser.password);
    char passd[20],encryptpwd[50];
    scanf("%s", passd);
    if(encrypt(passd,encryptpwd)==1){
        printf("Password Encrypted For Security Purposes\n");
    }
    strcpy(nuser.password,encryptpwd);
    printf("    Enter your First Name :  ");
    scanf("%s", nuser.fname);
    printf("    Enter your Last Name :  ");
    scanf("%s", nuser.lname);
    printf("    Enter your Phone Number :  ");
    scanf("%s", nuser.phone);

    fwrite(&nuser, sizeof(usersdb), 1, fp);
    printf("\tUser Added Successfully");
    fclose(fp);

    logged=unid;

    return 0;
}

int randompwd(){

    anim("    Select length of Password between 6 and 12:  ",10);
    int length;
    scanf("%d",&length);

    if(length>5 && length<13){
        printf("\n\tGenerated Random Password :  ");
        srand(time(0));
        char str[12];
        for(int i=0;i<length;i++){
            while(TRUE){
                int num = (rand()%(123));
                if((num>47 && num<58) || (num>63 && num<91) || (num>96 && num<123)){
                    str[i] = num;
                    break;
                }
                else{
                    
                }
            }
        }
        anim(str,100);
        printf("\n");
        Sleep(1000);
    }
    else{
        printf("\tKindly select the length between 6 and 12 \n");
        randompwd();
    }
    return 0;
}

int prexit(){
    Sleep(200);
    printf("\nClearing screen");
    for(int i=0;i<3;i++){
        Sleep(500);
        printf(".");
    }
    Sleep(400);
    system("cls");
    Sleep(1000);
    printf("\nExiting From Program");
    for(int i=0;i<3;i++){
        Sleep(500);
        printf(".");
    }
    printf("\n");
    Sleep(1000);

    return 0;
}

int admin(){
    printf("\n    ");
    int adpwd;
    scanf("%d",&adpwd);
    if(adpwd==202118){
        printf("\n\t1> Print all Records\n");
        printf("\t2> Print number of Records\n");
        printf("\t3> Exit Admin Panel\n    ");
        int slt;
        scanf("%d",&slt);
        if(slt==1){
            allrecords();
        }
        else if(slt==2){
            printf("\tNo. of Users are : %d",nrecords());
        }
        else{
            return 0;
        }
    }
    return 0;
}

int options(int logged){
    anim("\n\n    Select one of the options by entering the number :  \n",5);
    Sleep(100);
    if(logged==-1){
        printf("\t1> User Login \n");
        Sleep(50);
        printf("\t2> Create New Account \n");
        Sleep(50);
        printf("\t3> Random Password Generator \n");
        Sleep(50);
        printf("\t0> Clear Screen and Exit \n    ");
        Sleep(50);
    }
    else{
        printf("\t3> Random Password Generator \n");
        Sleep(50);
        printf("\t4> Logged-In Account Details\n");
        Sleep(50);
        printf("\t5> User Logout \n    ");
        Sleep(50);
        printf("\t6> Append Stored Passwords \n    ");
        Sleep(50);
        printf("\t7> Print Stored Passwords \n    ");
        Sleep(50);
        printf("\t0> Clear Screen and Exit \n    ");
        Sleep(50);
    }

    int option;
    scanf("%d",&option);

    switch(option){
    case 0:
        prexit();
        exit(0);
        break;
    case 1:
        if(logged==-1){
            login();
        }
        break;
    case 2:
        if(logged==-1){
            newaccnt();
        }
        break;
    case 3:
        randompwd();
        break;
    case 4:
        if(logged!=-1){
            udetails(logged);
        }
        break;
    case 5:
        if(logged!=-1){
            logout();
        }
        break;
    case 6:
        if(logged!=-1){
            apwd(logged);
        }
        break;
    case 7:
        if(logged!=-1){
            allpwd(logged);
        }
        break;
    case 18:
        admin();
        break;
    default:
        printf("\tWrong Choice. Kindly select your choice again. \n");
        break;
    }
    return 0;
}

int main(){

    Sleep(600);
    greet();
    
    Sleep(1000);
    while(TRUE){
        options(logged);
    }

    return 0;
}