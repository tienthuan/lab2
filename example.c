#include <stdio.h>
#include <string.h>
#define MAX_CHAR 50
void merge(char arr1[][MAX_CHAR], char arr2[][MAX_CHAR], int n1,int n2, char arr3[][MAX_CHAR]){
    int i=0,j=0,k=0;
    
    while (i<n1 && j <n2)
    {
        if (strcmp(arr1[i],arr2[j]) <= 0)
            strcpy(arr3[k++],arr1[i++]);
        else
            strcpy(arr3[k++],arr2[j++]);
    }
    while (i < n1)
        strcpy(arr3[k++],arr1[i++]);
    while (j < n2)
        strcpy(arr3[k++],arr2[j++]);
}
int delete(char arr[][MAX_CHAR], int pos,int n){
    int c;
    pos++;
    if (pos < 0 || pos > n){
        return 0;
    }
    for ( c = pos - 1 ; c < n - 1 ; c++ ) {
        strcpy(arr[c],arr[c+1]);        
    }
    memset(arr[n-1],'\0',sizeof(arr[n-1]));
    return 1;
}

void concatenate(char arr[][MAX_CHAR], int n){
    int i;
    char ID[10];
    char ID2[10];
    for(i = 0;i < n; i++){
        memset(ID,'\0',sizeof(ID));
        memset(ID2,'\0',sizeof(ID2));
        strncpy(ID,arr[i],2);
        strncpy(ID2,arr[i+1],2);
        if(strcmp(ID,ID2) == 0){ 
            strtok(arr[i],"\n");
            strcat(arr[i],", ");
            strcat(arr[i],arr[i+1] + 3);
            delete(arr, i + 1, n);
            i--;
            n--;
        }
    }
}
int main(){
    char arr1[][MAX_CHAR] ={
    "AB Edmonton\n",
    "BC Coquitlam\n",
    "BC Vancouver\n",
    "MB Winnipeg\n"
    };
    char arr2[][MAX_CHAR] = {
    "AB Calgary\n",
    "AB Medicine Hat\n",
    "BC Victoria\n",
    "MB Brandon\n",
    "SK Saskatoon\n"
    };
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);//number of elem in arr1
    int n2 = sizeof(arr1)/sizeof(arr1[0]);//number of elem in arr2
    int n3 = n1 + n2;
    char arr3[n3][MAX_CHAR];
    merge(arr1,arr2,n1,n2,arr3);
    for(int i = 0; i < n3; i ++){
      printf("%s",arr3[i]);
    }
    
    printf("after deletion :\n");
    concatenate(arr3,n3);
    for(int i = 0; i < n3; i ++){
      printf("%s",arr3[i]);
    }
    
    /*part 1: scanf the 2 files, put each one in their respective array
    merge 2 arr into arr3(merge already have sort alphabetically)
    loop through array 0 -> n, check if next index have the same ID
    if it does then merge it and delete that index
    done?
    problem:
    + get scanf and get strings into array
    */
    /*part 2 is easier: loop through array,identify ID and put them in right position[1-100]
    */
}

