//
//  safe_array.hpp
//  stack
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#ifndef safe_array_hpp
#define safe_array_hpp

template <class T>

class Safe_array
{
public:
    Safe_array(int capbility){
        data = new T[capbility];
        all = capbility;
    };
    ~Safe_array()
    {
        delete data;
    }
    void set(int n, T value)
    {
        check_index(n);
        data[n] = value;
        std::cout<<"赋值成功!"<<std::endl;
    }
    void get(int n)
    {
        check_index(n);
        std::cout<<"值为"<<data[n]<<std::endl;
    }
    void check_index(int n)
    {
        if (n>=all || n<0)
            throw "数组访问越界！";
    }
    T &operator[](int a)
    {
        check_index(a);
        return data[a];
    }
private:
    int all;
    T *data;
};
#endif /* safe_array_hpp */
