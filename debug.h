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

    static inline void print(int number)
    {
        cout<<number;
    }

    static inline void print(char *str)
    {
        cout<<str;
    }

    static inline void println(char *str)
    {
        print(str);
        endl();
    }

    static inline void println(int number)
    {
        print(number);
        endl();
    }


};

#endif // DEBUG_H_INCLUDED
