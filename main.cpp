#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <string>
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
// application reads from the specified serial port and reports the collected data
int main(int argc, _TCHAR* argv[])
{
	printf("Welcome to the serial test app!\n\n");

	Serial* port = new Serial("\\\\.\\COM3");    // adjust as needed

	if (port->IsConnected())
		cout << "We are connected!" << endl;
	
	char incomingData[256] = "";			// don't forget to pre-allocate memory
											//printf("%s\n",incomingData);
	int dataLength = 255;
	int readResult = 0;

	while (port->IsConnected())
	{
		const char * send = "1\n";
		if (port->WriteData(send, 3)) {
			cout << "true" << endl;
		};
		Sleep(5000);
		readResult = port->ReadData(incomingData, dataLength);
		// printf("Bytes read: (0 means no data available) %i\n",readResult);
		incomingData[readResult] = 0;

		printf("%s", incomingData);

		Sleep(500);
	}
	return 0;
}