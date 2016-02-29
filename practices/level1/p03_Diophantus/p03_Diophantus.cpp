/*  father:x
    child:y

    */
    #include<stdio.h>
    int main(){
        int child = 0;
        for(int age = 10;age<200;age++){
            if(age%2==0&&age%6==0&&age%12==0&&age%7==0){
                child = age/2;
                // child+4+age/6+age/12+age/7+5=age;
                int x = age - (4+age/6+age/12+age/7+5);
                if(x==child){
                    printf("\n%d\n",age);
                }
            }
        }
    }
