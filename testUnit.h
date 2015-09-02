#ifndef TESTUNIT_H_INCLUDED
#define TESTUNIT_H_INCLUDED

class Tester
{
public:
    static bool performTest()
    {
        bool result = true;
        char temp[10];
        MyString buff(temp, 10);
        buff.append("Hello");
        buff.shiftLeft(5);
        if(strcmp(temp, "\0") != 0) {
            result = false;
        }
        buff.append("Foo");
        if(strcmp(temp, "Foo") != 0) {
            result = false;
        }
        return result;
    }
};


#endif // TESTUNIT_H_INCLUDED
