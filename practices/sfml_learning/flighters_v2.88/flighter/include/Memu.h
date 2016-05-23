/**
 * Project Untitled
 */


#ifndef _MEMU_H
#define _MEMU_H

class Memu {
public: 
    
    void load();
    
    static void instance();
private: 
    Memu* _instance;
};

#endif //_MEMU_H