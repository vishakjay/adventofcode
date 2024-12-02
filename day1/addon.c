#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *list = fopen("input.txt","r");
    char list_l [20];
    int input_list_1[1000];
    size_t list_size_1=sizeof(input_list_1)/sizeof(input_list_1[0]);
  
    int i=0;
    int j=0;
    int input_list_2[1000];
      size_t list_size_2=sizeof(input_list_2)/sizeof(input_list_2[0]);
    if (list==NULL){
        printf("Unable to open file please check again.");
        exit(1);
    }
    else{
        while(fgets(list_l,20,list)!=NULL){
           
           char str1[6];
           char str2[6];
           strncpy(str1,list_l,6);
           strncpy(str2,list_l+8,6);
           str1[5]='\0';
           str2[5]='\0';
           int val1=atoi(str1);
           int val2=atoi(str2);
           //printf(%d %d\n",val1,val2);
            input_list_1[i++]=val1;
            input_list_2[j++]=val2;
              
        }
    }

    int sim_score_1=0;
    for(int k=0;k<1000;k++){
        int count=0;
        for(int x=0;x<1000;x++){
            if(input_list_2[x]==input_list_1[k]){
                count++;
            }
        }
        sim_score_1+=(input_list_1[k]*count);

    printf("%d %d\n",sim_score_1,input_list_1[k]); 
    }
    fclose(list);
    printf("finished accessing the file");

    return 0;
}
