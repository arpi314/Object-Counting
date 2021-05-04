#include<stdio.h>

int neighborCheck(int n, int m, int i, int j, int arr[n][m]);

int main(){

    int i, j , n, m, num, objects = 0;

    //scans the size of the array

    scanf("%i", &n);

    scanf("%i", &m);

    int arr[n][m];

    //user enters the contents of the array
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            
            do{
                scanf("%i", &num);
            }while(num < 0 || num > 1);

            arr[i][j] = num;
        }
    }
    
    
    //starts the search for neighbors
    for(i=0; i<n;i++){
        for(j=0; j<m; j++){
            if(arr[i][j] == 1){
                if(neighborCheck(n, m,i, j, arr) == 1){
                    objects++;
                }
            }
        }
    }
    
    printf("%i",objects);

    return 0;
}

//recursively goes through the array and replacing a pixel and its neighbors to 0 (or mark it as an object) 
int neighborCheck(int n, int m, int i, int j, int arr[n][m]){
    if(i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == 0){
        return 0;
    }else{
        arr[i][j] = 0; 
        neighborCheck(n, m, i+1, j, arr); //N
        neighborCheck(n, m, i-1, j, arr); //S
        neighborCheck(n, m, i, j+1, arr); //E
        neighborCheck(n, m, i, j-1, arr); //W
        neighborCheck(n, m, i+1, j+1, arr); //NE
        neighborCheck(n, m, i+1, j-1, arr); //NW
        neighborCheck(n, m, i-1, j+1, arr); //SE
        neighborCheck(n, m, i-1, j-1, arr); //SW
        return 1;
    }
}
