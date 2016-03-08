#ifndef PRIME_H_INCLUDED
#define PRIME_H_INCLUDED
int is_prime(int a)
{
    int flag=0;
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
           flag+=1;
           break;
        }
    }
    if(flag==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


#endif // PRIME_H_INCLUDED
