#include <iostream>
#include "Person.h"
#include "date.h"
#include "Student.h"
#include "Teacher.h"
#include "StuTech.h"
using namespace std;
int main()
{
    Person p("xionglinlin","511126199610190018",19,0,date(1996,10,19));
    cout<<p.getName()<<endl;
    Student s("xionglinlin","511126199610190018",19,0,date(1996,10,19),"2015060202014",100);
    cout<<s.getStuID()<<endl;
    Teacher t("liubisen","511126198810181234",45,0,date(1988,10,18),"Professor");
    cout<<t.getTitle()<<endl;
    StuTech st("wangyu","5111261996100180123",19,1,date(1996,10,8),"2015060202014",98,"assistant");
    cout<<st.getScore()<<' '<<st.getTitle()<<endl;
    return 0;
}
