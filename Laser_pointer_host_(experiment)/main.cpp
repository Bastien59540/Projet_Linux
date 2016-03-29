#include <iostream>
#include <unistd.h>
#include "SerialPort.h"
#include "protocol.h"


using namespace std;

int main()
{
    SerialPort serial;
	Message *msg=new Message;
    unsigned char *buffer=new unsigned char[100], *output;
    int x,y;
    unsigned int index=0,byteNumber=0;
    char *port="//dev//ttyUSB0";


    while(1)
    {
        while(!serial.connect(port))// while no serial port
            usleep(5000);

        usleep(500);
        byteNumber=serial.getArray(buffer,100);

		msg=ReadFrame(buffer, 100);
        if(msg.mode != Protocol::NACK && msg.mode != Protocol::ACK)
        { 
			if(msg.mode == Protocol::MODE_TRACKING && msg.data_size == 2)// tracking
            {
            	x=(msg.data[0]*1000000)/180;
                y=(msg.data[1]*1000000)/180;
                // --> to pwm
                //--------------------------------------------------------
                // <--
                msg.mode=Protocol::ACK;
				output=ApplyProtocol(msg);
				serial.sendArray(output,7);
			}
            else if(msg.mode == Protocol::MODE_AUTO && msg.data_size == 1)// auto
            {
            	switch ((unsigned int)msg.data[0]) {
                	case 40:
                    	// do carré
                        break;
                    case 41:
                        // do cercle
                        break;
                    case 42:
                        // do triangle
                        break;
                    default:
                        msg.mode=Protocol::NACK;
						output=ApplyProtocol(msg);
						serial.sendArray(output,6);
                        break;
                }
             }
             else
             {
             	msg.mode=Protocol::NACK;
				output=ApplyProtocol(msg);
				serial.sendArray(output,msg.data_size+5);
             }
         }
     }

    return 0;
}

