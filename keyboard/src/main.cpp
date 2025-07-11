//main.cpp
//C Inkbox Software 2025

#include "keyboard.h"

int main(){
	keyboard* virtualKeyboard = new keyboard();
	return virtualKeyboard->run();
}