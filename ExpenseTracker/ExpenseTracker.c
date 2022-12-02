#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * returnString(char *str ,char *oldWord , char *newWord){
    char *generatedString;
    int i,count=0;
    int oldWordLength=strlen(oldWord);
    int newWordLength=strlen(newWord);
    for(i=0;*(str+i)!='\0';i++){
        if(strstr(&str[i],oldWord)==&str[i]){
            count++;
            i+=oldWordLength;
        }
    }
    generatedString=(char *)malloc(i+ count * (newWordLength-oldWordLength) + 1);  
    i=0;  
    while(*str){
        if(strstr(str,oldWord)==str){
            strcpy(&generatedString[i],newWord);
            i+=newWordLength;
            str+= oldWordLength;
        }
        else{
            generatedString[i]=*str;
            i++;
            str+=1;
        }
    }
generatedString[i]='\0';
return generatedString;
}
int main(int argc , char *argv[]){
    FILE *fptr;
    char str[300];
    char * newString;
    fptr=fopen("Expense.txt","r");
    while(fgetc(fptr)!=EOF){
        fgets(str,90,fptr);
    }
    fclose(fptr);
    newString = returnString(str,"{s.no}",argv[1]) ;
    newString = returnString(newString,"{date}",argv[2]) ;
    newString = returnString(newString,"{amount}",argv[3]) ;
    newString = returnString(newString,"{s.amount}",argv[4]) ;
    newString = returnString(newString,"{item}",argv[5]) ;
    fptr=fopen("Output.txt","a");
    fseek(fptr,0,SEEK_END);
    fputs(newString,fptr);
    fputs("\n",fptr);
    fclose(fptr);
    return 0;
}
