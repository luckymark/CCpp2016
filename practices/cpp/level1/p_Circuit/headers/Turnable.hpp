#ifndef TURNABLE_HPP__
#define TURNABLE_HPP__

class Turnable {
private:
    bool m_on = false;
public:
    virtual void turn_on() { m_on = true; }
    virtual void turn_off() { m_on = false; }
    virtual bool is_on() { return m_on; }
    virtual ~Turnable() {}
};

// 然后用三个类继承这个类，既然这三个类一摸一样……还是不写了吧

#endif
