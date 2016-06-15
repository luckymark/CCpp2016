#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
    public:
        virtual int getArea(){
            return 0;
        };
        int getType(){
            return type;
        }
    protected:
        int type;
    private:
};

#endif // SHAPE_H
