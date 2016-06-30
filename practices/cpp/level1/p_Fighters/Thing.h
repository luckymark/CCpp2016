#ifndef THING_H
#define THING_H
class Thing

{
public:
    virtual void build()=0;
    virtual void draw_myself()=0;
    virtual void move()=0;
    int heartlife=0;
};


#endif // THING_H
