//bluetooth.h

#include <stdio.h>
#include <iostream>
#include <zmq.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

class bluetooth {
	public:
		int begin(bool* on, bool testing = false);
		int write(unsigned char modify, unsigned char key0, unsigned char key1, unsigned char key2, unsigned char key3, unsigned char key4, unsigned char key5);

		unsigned char getModSignal(bool leftCtrl, bool leftShift, bool leftAlt, bool leftMeta, bool rightCtrl, bool rightShift, bool rightAlt, bool rightMeta);
		unsigned char getKeyCode(std::string output);

	private:			
		unsigned char convertCharToHIDCode(char out);
			
		struct HIDreport {
			unsigned char codeMod;
			unsigned char code0;
			unsigned char code1;
			unsigned char code2;
			unsigned char code3;
			unsigned char code4;
			unsigned char code5;
		};
		bool bluetoothOn = false;
		std::vector<HIDreport> bluetoothOutQueue;
};