#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000

int main() {

    //printf("opening file\n");
    //int reports[MAXSIZE][MAXSIZE]={0};
    FILE* matrix=fopen("input.txt","r");
    char *list_l=NULL;
    size_t len=0;
    size_t read;
    int safe=0;
    //int reports [1000][1000];
    //char str1[]="";
    // dont try to strcpy(str1,list_l);
    // when str1 is char *str1="";
    // apparently the above makes it immutable 

    //printf("hello world\n");

    if(matrix==NULL){
        printf("Unable to open file");
        exit(1);
    }
    else{
       
           int c=0;
        while((read = getline(&list_l, &len, matrix)) != -1){
     
        char* token = strtok(list_l, " \t\n"); 
       
        int reports[1000];
        int count=0;
        while (token != NULL) {

            int num = atoi(token);
            
            
            ;
            reports[count]=num;
            count++;
            
            token = strtok(NULL, " \t\n"); 
             
        }
        // operate on the report array here
        int increasing=0,decreasing=0;
        //45 47 48 51 54 56 54
        //69 67 66 67 70 71 74 75
        int flag=0;
        int i;
     
        for( i=1;i<count;i++){
            //printf("%d ",reports[i-1]);
           if(reports[i-1]<reports[i] ){
             if(decreasing!=0){
                    flag=1;
                    break;
             }
             if(decreasing==0){
                    if(reports[i]-reports[i-1]>=1 && reports[i]-reports[i-1]<=3){
                        increasing=1;
                         //printf("array is increasing \n");

                    }
                    else{
                        flag=1;
                        break;
                    }
             }
           }
           else if(reports[i-1]>reports[i] ){
               if(increasing==0){
                    if(reports[i-1]-reports[i]>=1 && reports[i-1]-reports[i]<=3){
                        decreasing=1;
                       // printf("array is either increasing or decreasing\n");
                    }
                    else{
                        flag=1;
                        break;
                    }
               }
               if(increasing!=0){
                    flag=1;
                    break;
               }
           }
           else if(reports[i-1]==reports[i]){
            flag=1;
            break;
           }
           
        }
        //printf("flag = %d ",flag);
        //c++;
        if(flag==0){
            safe++;
        }
    
        }

       
    }

    printf("\n%d",safe);
    fclose(matrix);
    return 0;
}
