//bluetooth.cpp

#include "bluetooth.h"

using namespace std;

int bluetooth::begin(bool* on, bool testing){
	//do not continue if testing:
	if (testing) cout << "Testing Mode: Bluetooth virtual emulation initiated" << endl;
	while (testing && *on){
		if (bluetoothOutQueue.size() > 0){
			cout << "output key: " << to_string(bluetoothOutQueue[0].codeMod) << "-"
			<< to_string(bluetoothOutQueue[0].code0) << "-" << to_string(bluetoothOutQueue[0].code1) << "-"
			<< to_string(bluetoothOutQueue[0].code2) << "-" << to_string(bluetoothOutQueue[0].code3) << "-"
			<< to_string(bluetoothOutQueue[0].code4) << "-" << to_string(bluetoothOutQueue[0].code5) << endl;
			bluetoothOutQueue.erase(bluetoothOutQueue.begin());
		}
	}
	if (testing){
		return 0;
	}
		
	cout << "Initializing Bluetooth" << endl;
	
	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_REQ);	//request socket
	
	try {
		socket.connect("tcp://localhost:5555");	//connect to server
		cout << "Connected to server." << endl;
		bluetoothOn = true;
	} catch (const zmq::error_t &e){
		cerr << "Error connecting to server: " << e.what() << endl;
		//not connected to bluetooth output loop:
		return -1;
	}
	
	while (*on){
		//output everything in the out queue
		if (bluetoothOutQueue.size() > 0){
			string message = to_string(bluetoothOutQueue[0].codeMod)
			+ "-" + to_string(bluetoothOutQueue[0].code0)
			+ "-" + to_string(bluetoothOutQueue[0].code1)
			+ "-" + to_string(bluetoothOutQueue[0].code2)
			+ "-" + to_string(bluetoothOutQueue[0].code3)
			+ "-" + to_string(bluetoothOutQueue[0].code4)
			+ "-" + to_string(bluetoothOutQueue[0].code5);
			zmq::message_t request(message.size());
			memcpy(request.data(), message.c_str(), message.size());

			if (socket.send(request, zmq::send_flags::none)){
				cout << "Message sent " << message << endl;	
				//wait for reply
				zmq::message_t reply;
				zmq::recv_result_t r = socket.recv(reply, zmq::recv_flags::none);
				cout << "Recieved Reply: " << reply.to_string() << endl;
				
			} else {
				cerr << "Message failed to send" << endl;
			}
			bluetoothOutQueue.erase(bluetoothOutQueue.begin());
		}
	}

	socket.close();
	context.shutdown();
	context.close();
	
	return 0;
}

int bluetooth::write(unsigned char modify, unsigned char key0, unsigned char key1, unsigned char key2, unsigned char key3, unsigned char key4, unsigned char key5){
	HIDreport hReport;
	hReport.codeMod = static_cast<int>(modify);	//8-bit modifier keys
	hReport.code0 = static_cast<int>(key0);
	hReport.code1 = static_cast<int>(key1);
	hReport.code2 = static_cast<int>(key2);
	hReport.code3 = static_cast<int>(key3);
	hReport.code4 = static_cast<int>(key4);
	hReport.code5 = static_cast<int>(key5);
	bluetoothOutQueue.push_back(hReport);
	return 0;
}

unsigned char bluetooth::getModSignal(bool leftCtrl, bool leftShift, bool leftAlt, bool leftMeta, bool rightCtrl, bool rightShift, bool rightAlt, bool rightMeta){
	unsigned char modifiedKeys = 0;
	modifiedKeys += (leftCtrl) ? 	0b00000001 : 0;
	modifiedKeys += (leftShift) ? 	0b00000010 : 0;
	modifiedKeys += (leftAlt) ? 	0b00000100 : 0;
	modifiedKeys += (leftMeta) ? 	0b00001000 : 0;
	modifiedKeys += (rightCtrl) ? 	0b00010000 : 0;
	modifiedKeys += (rightShift) ? 	0b00100000 : 0;
	modifiedKeys += (rightAlt) ? 	0b01000000 : 0;
	modifiedKeys += (rightMeta) ? 	0b10000000 : 0;
	return modifiedKeys;
}

unsigned char bluetooth::getKeyCode(string output){
	unsigned char toWrite = 0;
	//if the output is only one character, then simply pass that onto the write fucntion
	if (output.length() == 1){
		return convertCharToHIDCode(output[0]);
	}
	//otherwise determine which character it is
	transform(output.begin(), output.end(), output.begin(), ::toupper);
	if (output == "RET"){
		toWrite = 0x28;
	}
	else if (output == "ESC"){
		toWrite = 0x29;
	}
	else if (output == "BACKSPACE"){
		toWrite = 0x2A;
	}
	else if (output == "TAB"){
		toWrite = 0x2B;
	}
	else if (output == "SPACE"){
		toWrite = 0x2C;
	}
	else if (output == "CAPS"){
		toWrite = 0x39;
	}
	else if (output == "F1"){
		toWrite = 0x3A;
	}
	else if (output == "F2"){
		toWrite = 0x3B;
	}
	else if (output == "F3"){
		toWrite = 0x3C;
	}
	else if (output == "F4"){
		toWrite = 0x3D;
	}
	else if (output == "F5"){
		toWrite = 0x3E;
	}
	else if (output == "F6"){
		toWrite = 0x3F;
	}
	else if (output == "F7"){
		toWrite = 0x40;
	}
	else if (output == "F8"){
		toWrite = 0x41;
	}
	else if (output == "F9"){
		toWrite = 0x42;
	}
	else if (output == "F10"){
		toWrite = 0x43;
	}
	else if (output == "F11"){
		toWrite = 0x44;
	}
	else if (output == "F12"){
		toWrite = 0x45;
	}
	else if (output == "PRT"){
		toWrite = 0x46;
	}
	else if (output == "SRC"){
		toWrite = 0x47;
	}
	else if (output == "BRK"){
		toWrite = 0x48;
	}
	else if (output == "INS"){
		toWrite = 0x49;
	}
	else if (output == "HOME"){
		toWrite = 0x4A;
	}
	else if (output == "PGUP"){
		toWrite = 0x4B;
	}
	else if (output == "DEL"){
		toWrite = 0x4C;
	}
	else if (output == "END"){
		toWrite = 0x4D;
	}
	else if (output == "PGDN"){
		toWrite = 0x4E;
	}
	else if (output == "RIGHT"){
		toWrite = 0x4F;
	}
	else if (output == "LEFT"){
		toWrite = 0x50;
	}
	else if (output == "DOWN"){
		toWrite = 0x51;
	}
	else if (output == "UP"){
		toWrite = 0x52;
	}
	else if (output == "NUM"){
		toWrite = 0x53;
	}
	else if (output == "NUM/"){
		toWrite = 0x54;
	}
	else if (output == "NUM*"){
		toWrite = 0x55;
	}
	else if (output == "NUM-"){
		toWrite = 0x56;
	}
	else if (output == "NUM+"){
		toWrite = 0x57;
	}
	else if (output == "NUMRET"){
		toWrite = 0x58;
	}
	else if (output == "NUM1"){
		toWrite = 0x59;
	}
	else if (output == "NUM2"){
		toWrite = 0x5A;
	}
	else if (output == "NUM3"){
		toWrite = 0x5B;
	}
	else if (output == "NUM4"){
		toWrite = 0x5C;
	}
	else if (output == "NUM5"){
		toWrite = 0x5D;
	}
	else if (output == "NUM6"){
		toWrite = 0x5E;
	}
	else if (output == "NUM7"){
		toWrite = 0x5F;
	}
	else if (output == "NUM8"){
		toWrite = 0x60;
	}
	else if (output == "NUM9"){
		toWrite = 0x61;
	}
	else if (output == "NUM0"){
		toWrite = 0x62;
	}
	else if (output == "NUM."){
		toWrite = 0x63;
	}
	else if (output == "F13"){
		toWrite = 0x68;
	}
	else if (output == "F14"){
		toWrite = 0x69;
	}
	else if (output == "F15"){
		toWrite = 0x6A;
	}
	else if (output == "F16"){
		toWrite = 0x6B;
	}
	else if (output == "F17"){
		toWrite = 0x6C;
	}
	else if (output == "F18"){
		toWrite = 0x6D;
	}
	else if (output == "F19"){
		toWrite = 0x6E;
	}
	else if (output == "F20"){
		toWrite = 0x6F;
	}
	else if (output == "F21"){
		toWrite = 0x70;
	}
	else if (output == "F22"){
		toWrite = 0x71;
	}
	else if (output == "F23"){
		toWrite = 0x72;
	}
	else if (output == "F24"){
		toWrite = 0x73;
	}
	else if (output == "CTRLL"){
		toWrite = 0xE0;
	}
	else if (output == "SHIFTL"){
		toWrite = 0xE1;
	}
	else if (output == "ALTL"){
		toWrite = 0xE2;
	}
	else if (output == "METAL"){
		toWrite = 0xE3;
	}
	else if (output == "CTRLR"){
		toWrite = 0xE4;
	}
	else if (output == "SHIFTR"){
		toWrite = 0xE5;
	}
	else if (output == "ALTR"){
		toWrite = 0xE6;
	}
	else if (output == "METAR"){
		toWrite = 0xE7;
	}
	else {
		toWrite = 0;
	}
	
	return toWrite;
}

unsigned char bluetooth::convertCharToHIDCode(char out){
	unsigned char o = 0;
	switch (out){
		case 0:
			o = 0;
			break;
		case 'A':
		case 'a':
			o = 0x04;
			break;
		case 'B':
		case 'b':
			o = 0x05;
			break;
		case 'C':
		case 'c':
			o = 0x06;
			break;
		case 'D':
		case 'd':
			o = 0x07;
			break;
		case 'E':
		case 'e':
			o = 0x08;
			break;
		case 'F':
		case 'f':
			o = 0x09;
			break;
		case 'G':
		case 'g':
			o = 0x0A;
			break;
		case 'H':
		case 'h':
			o = 0x0B;
			break;
		case 'I':
		case 'i':
			o = 0x0C;
			break;
		case 'J':
		case 'j':
			o = 0x0D;
			break;
		case 'K':
		case 'k':
			o = 0x0E;
			break;
		case 'L':
		case 'l':
			o = 0x0F;
			break;
		case 'M':
		case 'm':
			o = 0x10;
			break;
		case 'N':
		case 'n':
			o = 0x11;
			break;
		case 'O':
		case 'o':
			o = 0x12;
			break;
		case 'P':
		case 'p':
			o = 0x13;
			break;
		case 'Q':
		case 'q':
			o = 0x14;
			break;
		case 'R':
		case 'r':
			o = 0x15;
			break;
		case 'S':
		case 's':
			o = 0x16;
			break;
		case 'T':
		case 't':
			o = 0x17;
			break;
		case 'U':
		case 'u':
			o = 0x18;
			break;
		case 'V':
		case 'v':
			o = 0x19;
			break;
		case 'W':
		case 'w':
			o = 0x1A;
			break;
		case 'X':
		case 'x':
			o = 0x1B;
			break;
		case 'Y':
		case 'y':
			o = 0x1C;
			break;
		case 'Z':
		case 'z':
			o = 0x1D;
			break;
		case '1':
		case '!':
			o = 0x1E;
			break;
		case '2':
		case '@':
			o = 0x1F;
			break;
		case '3':
		case '#':
			o = 0x20;
			break;
		case '4':
		case '$':
			o = 0x21;
			break;
		case '5':
		case '%':
			o = 0x22;
			break;
		case '6':
		case '^':
			o = 0x23;
			break;
		case '7':
		case '&':
			o = 0x24;
			break;
		case '8':
		case '*':
			o = 0x25;
			break;
		case '9':
		case '(':
			o = 0x26;
			break;
		case '0':
		case ')':
			o = 0x27;
			break;
		//return/escape = 0x28
		//escape = 0x29
		//delete = 0x2A
		//tab = 0x2B
		//spacebar = 0x2C
		case '-':
		case '_':
			o = 0x2D;
			break;
		case '=':
		case '+':
			o = 0x2E;
			break;
		case '[':
		case '{':
			o = 0x2F;
			break;
		case ']':
		case '}':
			o = 0x30;
			break;
		case '\\':
		case '|':
			o = 0x31;
			break;
		//non-us # and ~2
		case ';':
		case ':':
			o = 0x33;
			break;
		case '\'':
		case '\"':
			o = 0x34;
			break;
		case '`':
		case '~':
			o = 0x35;
			break;
		case ',':
		case '<':
			o = 0x36;
			break;
		case '.':
		case '>':
			o = 0x37;
			break;
		case '/':
		case '?':
			o = 0x38;
			break;
		//caps lock = 0x39
		//F1-F12 = 0x3A-0x45
		//print screen = 0x46
		//scroll lock = 0x47
		//pause = 0x48
		//instert = 0x49
		//home = 0x4A
		//page up = 0x4B
		//delete forward = 0x4C
		//end = 0x4D
		//page down = 0x4E
		//right arrow = 0x4F
		//left arrow = 0x50
		//down arrow = 0x51
		//up arrow = 0x52
		//keypad numlock = 0x53
		//keypad1 = 0x54
		//keypad* = 0x55
		//keypad- = 0x56
		//keypad+ = 0x57
		//keypadEnter = 0x58
		//keypad1-keypad0 = 0x59-0x62
		//keypad .and del = 0x63
		//F13-F24 = 0x68-0x73

		//...much more in documentation
		
		//left control = 0xE0
		//left shift = 0xE1
		//left alt = 0xE2
		//left GUI = 0xE3
		//right control = 0xE4
		//right shift = 0xE5
		//right alt = 0xE6
		//right GUI = 0xE7
		//E8-FF reserved		
		
		default:
			o = 0;
			break;
	}
	return o;
}
