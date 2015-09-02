#ifndef PACKETPARSER_H_INCLUDED
#define PACKETPARSER_H_INCLUDED

#include "packet.h"
#include "myString.h"
#include "debug.h"

class PacketParser
{
public:

    bool correctInputBuffer(MyString *buff)
    {
        int startCharPosition = buff->find('s');
        if(startCharPosition < 0) {
            return false;
        }
        Debug::print("Trying to correct input buffer, shift left by: ");
        Debug::println(startCharPosition);

        buff->shiftLeft(startCharPosition);
        return true;
    }

    bool parse(MyString *buff)
    {
        if(buff->size() > minPackLength && buff->at(0) != 's') {
            if(!correctInputBuffer(buff)) {
                cout<<"ERROR: COULD NOT CORRECT BUFFER!!"<<endl;
                return false;
            }
        }

        int endCharacterPosition = buff->find('E');
        if((endCharacterPosition > 0) && buff->at(0) == 's' && (buff->size() > endCharacterPosition + 1 )) {
            parsedPacket = coreParse(buff);
            return true;
        }
        return false;
    }



    Packet getPacket()
    {
        return parsedPacket;
    }

private:
    Packet parsedPacket;

    Packet coreParse(MyString *buff)
    {
        int textLength = buff->size(), integer = 0, frac = 0;

        char* inputBuffer = buff->toCstr();
        char* currentIndex = NULL;
        //Ia
        currentIndex = shiftToDigit(inputBuffer);
        currentIndex = extractInt(currentIndex, &integer);
        currentIndex = shiftToDigit(inputBuffer);
        currentIndex = extractInt(currentIndex, &frac);
        parsedPacket.Ia = sFloat(integer, frac);

        //Ib
        //TODO create getNextsFloat function
    }

    char* shiftToDigit(char* str)
    {
        //TODO
    }

    char* extractInt(char* str, int *number)
    {
        //TODO
    }

};

#endif // PACKETPARSER_H_INCLUDED
