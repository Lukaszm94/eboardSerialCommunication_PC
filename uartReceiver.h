#ifndef UARTRECEIVER_H_INCLUDED
#define UARTRECEIVER_H_INCLUDED

#include <string>
#include "packet.h"
#include "packetParser.h"
#include "debug.h"

using namespace std;

const int inputBufferSize = 60;

class uartReceiver
{
public:
    uartReceiver() : buff(inputBuffer, inputBufferSize)
    {

    }

    void receiveNewChar(char newChar)
    {
        buff.append(newChar);
    }

    bool parseBuffer()
    {
        return parser.parse(&buff);
    }

    Packet getPacket()
    {
        return parser.getPacket();
    }

private:
    char inputBuffer[inputBufferSize];
    MyString buff;
    PacketParser parser;
    Packet parsedPacket;

};
#endif // UARTRECEIVER_H_INCLUDED
