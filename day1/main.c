#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp (const void * elem1, const void * elem2) 
{
     int a = *(int*) elem1;  
    int b = *(int*) elem2;  
    if(a > b)  
    {  
        return 1;  
    }  
    else if(a < b)  
    {  
        return -1;  
    }  
    return 0;  
}

int main() {
    FILE *list = fopen("input_list1.txt","r");
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
           //printf("%d %d\n",val1,val2);
            input_list_1[i++]=val1;
            input_list_2[j++]=val2;
              
        }
    }
    printf("before sorting");
    qsort(input_list_1,i,sizeof(int),comp);
    qsort(input_list_2,j,sizeof(int),comp);
    printf("%d %d",i,j);    

    long long sum = 0;

    for ( int k =0; k<j;k++){
        sum+=(labs(input_list_1[k]-input_list_2[k]));
        printf("%d\n",sum);
    }
    fclose(list);
    printf("finished accessing the file");

    return 0;

}
