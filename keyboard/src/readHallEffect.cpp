#include "readHallEffect.h"
using namespace std;

#define hallEffectSensorMax 112

bool hallEffectReader::initSPI(int chanel, int speed, int GPIO1, int GPIO2, int GPIO3, int GPIO4){
	//initialize wiringOP
	wiringPiSetup(); 
	//Chip select 3 pins:
	chipSelPin0 = GPIO1;
	chipSelPin1 = GPIO2;
	chipSelPin2 = GPIO3;
	chipSelPin3 = GPIO4;
	pinMode(chipSelPin0, OUTPUT);	//GPIO pin1 set as output
	pinMode(chipSelPin1, OUTPUT);	//GPIO pin2 set as output
	pinMode(chipSelPin2, OUTPUT);	//GPIO pin3 set as output
	pinMode(chipSelPin3, OUTPUT);	//GPIO pin4 set as output

	//SPI settup
	SPIchannel = chanel;
	int fdSPI;	//SPI file descriptor
	if (wiringPiSPISetup(SPIchannel, speed) < 0){
		printf("SPI Setup failed");
		return false;
	}
	return true;
}

int hallEffectReader::readHallEffectSensor(int numberSensor){
	//check range:
	if (numberSensor >= hallEffectSensorMax){
		return -1;
	}
	//calculate which chip the sensor is on:
	int chipNumber;	//which ADC chip is it?
	int index;	//which index 0-7 is it?
	
	chipNumber = numberSensor / 8;
	index = numberSensor % 8;

	unsigned char buffer[3];
	buffer[0] = 0x01;
	buffer[1] = 0x80 | (index << 4);
	buffer[2] = 0x00;

	//deselect chip:
	deselectChipNumber(chipNumber);
		//may need to insert wait here if clock too slow
	//select chip:
	selectChipNumber(chipNumber);
	if (wiringPiSPIDataRW(SPIchannel, buffer, 3) == -1){
		return -1;	
	}
	deselectChipNumber(chipNumber);

	int ADCval = ((buffer[1] & 0x03) << 8) | buffer[2];
	return ADCval;
}

void hallEffectReader::selectChipNumber(int chipNumber){
	//break into three bits
	int A0 = chipNumber & 0x01;
	int A1 = chipNumber & 0x02;
	int A2 = chipNumber & 0x04;
	int A3 = chipNumber & 0x08;
	
	digitalWrite(chipSelPin0, A0);
	digitalWrite(chipSelPin1, A1);
	digitalWrite(chipSelPin2, A2);
	digitalWrite(chipSelPin3, A3);
	//usleep(10000);	//sleep for 1ms to settle internal multiplexer
}

void hallEffectReader::deselectChipNumber(int chipNumber){
	//break into three bits
	int A0 = ~(chipNumber & 0x01);
	int A1 = ~(chipNumber & 0x02);
	int A2 = ~(chipNumber & 0x04);
	int A3 = ~(chipNumber & 0x08);
	//use inverse to guarentee that a different chip number is selected	

	digitalWrite(chipSelPin0, A0);
	digitalWrite(chipSelPin1, A1);
	digitalWrite(chipSelPin2, A2);
	digitalWrite(chipSelPin3, A3);
}
