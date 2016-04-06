#include<stdio.h>
#include<time.h>
void swap(int &x,int &y);
void bubbleSort(int a[],int length);

int main(){
    int arr[]={5,8,2,6,9,7,10,200,1,2,23,44,55,32,89,4,6,5};
    int length = sizeof(arr)/sizeof(arr[0]);
    double time1 =(double)clock()/CLOCKS_PER_SEC;
    bubbleSort(arr,length);
    double time2 =(double)clock()/CLOCKS_PER_SEC;
    double ftime = time2-time1;
    for(int i = 0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTime used = %.10f\n",ftime);
    return 0;
}

void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

void bubbleSort(int a[],int length){
    for(int i = length-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
