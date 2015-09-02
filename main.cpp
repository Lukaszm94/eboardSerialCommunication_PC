#include <iostream>
#include "uartSender.h"
#include "uartReceiver.h"
#include "myString.h"
#include "debug.h"
#include "testUnit.h"


void printPacket(Packet pack)
{


}


int main()
{
    if(!Tester::performTest()) {
        Debug::println("MyString test failed!");
    }


    uartReceiver rx;
    uartSender tx;
    Packet packet;
    packet.setRandomValues();

    cout<<"Sending: ";
    printPacket(packet);

    char* packetStr = tx.getPacketCharString(packet);
    cout<<"packetStr: "<<packetStr<<endl;
    Packet receivedPacket;

    for(int i = 0, packetLength = strlen(packetStr); i < packetLength; i++) {
        cout<<packetStr[i]<<" ";
        rx.receiveNewChar(packetStr[i]);
        if(rx.parseBuffer()) {
            receivedPacket = rx.getPacket();
            cout<<"New packet received!"<<endl;
        }
    }
    cout<<endl;
    cout<<"Received: ";
    printPacket(receivedPacket);

    return 0;
}
