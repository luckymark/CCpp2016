//
// Created by Administrator on 2016/4/18.
//

#include "Queue.h"

void Queue::append( int item ){
    data[ head ] = item;
    head = (head+1) % 100;
}
int Queue::pop(){
    tail = ( tail + 1 ) % 100 ;
    return data[ tail-1 ] ;
}
bool Queue::isEmpty(){
    return (head == tail);
};
bool Queue::isFull(){
    return ((head+1)%100 == tail);
};