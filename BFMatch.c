#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int match(char *string,char *pattern){
    int i,j;
    i = 0;
    j = 0;
    while(i < strlen(string) && j < strlen(pattern)){
        if(string[i] == pattern[j]){
            i++;
            j++;
        }else
        {
            i = i-j+1;
            j = 0;
        }
    }

    if(j == strlen(pattern)){
        return i-strlen(pattern)+1;
    }
    return -1;
}

int main(){
    int postion = match("acccasdwefsadasdefw","ada");
    printf("%d",postion);
}