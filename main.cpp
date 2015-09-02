#include <iostream>
#include "uartSender.h"
#include "uartReceiver.h"
#include "myString.h"
#include "debug.h"
#include "testUnit.h"


void printPacket(Packet pack)
{
    Debug::print("Ia: ");
    Debug::print(pack.Ia.toString());
    Debug::print(", Ib: ");
    Debug::print(pack.Ib.toString());
    Debug::print(", .... , Tf: ");
    Debug::print(pack.Tf.toString());
    Debug::endl();
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
    packet.Ia = sFloat(12, 3);
    packet.Ib = sFloat(8, 7);
    packet.Tf = sFloat(98, 5);


    cout<<"Sending: ";
    printPacket(packet);

    char* packetStr = tx.getPacketCharString(packet);
    cout<<"packetStr: "<<packetStr<<endl;
    Packet receivedPacket;

    for(int i = 0, packetLength = strlen(packetStr); i < packetLength; i++) {
        rx.receiveNewChar(packetStr[i]);
        if(rx.parseBuffer()) {
            receivedPacket = rx.getPacket();
        }
    }
    cout<<endl;
    cout<<"Received: ";
    printPacket(receivedPacket);

    return 0;
}
