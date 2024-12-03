#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000

int is_safe(int *reports, int count){
    int increasing = 0, decreasing = 0;
            // 45 47 48 51 54 56 54
            // 69 67 66 67 70 71 74 75
            int flag = 0;
            int i;

            for (i = 1; i < count; i++)
            {
                // printf("%d ",reports[i-1]);
                if (reports[i - 1] < reports[i])
                {
                    if (decreasing != 0)
                    {
                       return 0 ;
                    }
                    if (decreasing == 0)
                    {
                        if (reports[i] - reports[i - 1] >= 1 && reports[i] - reports[i - 1] <= 3)
                        {
                            increasing = 1;
                            // printf("array is increasing \n");
                        }
                        else
                        {
                          return 0; 
                        } 
                    }
                }
                else if (reports[i - 1] > reports[i])
                {
                    if (increasing == 0)
                    {
                        if (reports[i - 1] - reports[i] >= 1 && reports[i - 1] - reports[i] <= 3)
                        {
                            decreasing = 1;
                            // printf("array is either increasing or decreasing\n");
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    if (increasing != 0)
                    {
                     return 0;   
                    }
                }
                else if (reports[i - 1] == reports[i])
                {
                    return 0;
                }
            }
            return 1;
}
int find_peak_index(int *reports, int count) {
    for (int i = 1; i < count - 1; i++) {
        
        if ((reports[i] > reports[i-1]) && (reports[i] > reports[i+1])) {
            return i;
        }
       
        if ((reports[i] < reports[i-1]) && (reports[i] < reports[i+1])) {
            return i;
        }
    }
    return -1;  
}

int main()
{

    // printf("opening file\n");
    // int reports[MAXSIZE][MAXSIZE]={0};
    FILE *matrix = fopen("input.txt", "r");
    char *list_l = NULL;
    size_t len = 0;
    size_t read;
    int safe = 0;
    // int reports [1000][1000];
    // char str1[]="";
    //  dont try to strcpy(str1,list_l);
    //  when str1 is char *str1="";
    //  apparently the above makes it immutable

    // printf("hello world\n");

    if (matrix == NULL)
    {
        printf("Unable to open file");
        exit(1);
    }
 

        while ((read = getline(&list_l, &len, matrix)) != -1)
        {

            char *token = strtok(list_l, " \t\n");

            int reports[1000];
            int count = 0;
            while (token != NULL)
            {

                int num = atoi(token);

                ;
                reports[count] = num;
                count++;

                token = strtok(NULL, " \t\n");
            }
            // operate on the report array here
            if(is_safe(reports,count)){
                safe++;
                continue;
            }
            // printf("flag = %d ",flag);
            // c++;
            for(int k=0;k<count;k++){
                int temp_report[1000];
                int temp_count=0;

                for(int j=0;j < count ;j++){
                    if(j!=k){
                        temp_report[temp_count++]=reports[j];
                    }
                }
                if(is_safe(temp_report,temp_count)){
                    safe++;
                    break;
                }
            }
            
    
        }
    

    printf("\n%d", safe);
    fclose(matrix);
    return 0;
}
