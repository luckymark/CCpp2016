#include<stdio.h>
#include<time.h>
void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}
void bubbleSort(int a[],int length){
    for(int j = length-1;j>0;j--){
        for(int i=0;i<j;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
    }
}
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
