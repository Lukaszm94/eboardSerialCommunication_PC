#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

class Debug
{
public:
    inline void init()
    {

    }

    static inline void endl()
    {
        cout<<std::endl;
    }
    //int
    static inline void print(int number)
    {
        cout<<number;
    }
    static inline void println(int number)
    {
        print(number);
        endl();
    }

    //char
    static inline void print(char c)
    {
        cout<<c;
    }

    static inline void println(char c)
    {
        cout<<c;
    }

    //str
    static inline void print(char *str)
    {
        cout<<str;
    }
    static inline void println(char *str)
    {
        print(str);
        endl();
    }








};

#endif // DEBUG_H_INCLUDED
