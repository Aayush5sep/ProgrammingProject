#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include "fns.h"

int decrypt(char* str,char* decrypt){
    int i=0,j=0;
    while(str[i]){
        decrypt[j]=str[i]-15;
        i+=2;
        j++;
    }
return 0;
}

int encrypt(char* str,char* encrypt){
    int i=0,j=0;
    while(str[j]){
        if(i%2==0){
            encrypt[i]=str[j]+15;
            j++;
        }
        else{
            while(1==1){
                srand(time(0));
                int num = (rand()%(123));
                if((num>47 && num<58) || (num>63 && num<91) || (num>96 && num<123)){
                    encrypt[i] = num;
                    break;
                }
            }
        }
        
        i++;
    }
    return 1;
return 0;
}
