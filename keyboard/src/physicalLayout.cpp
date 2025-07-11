//physicalLayout.cpp

#include "physicalLayout.h"

using namespace std;

const float keyboardWidth = 2560.0f;
const float keyboardHeight = 1440.0f;

const int keyboardWidthPhysical = 382.0f;	//mm
const int keyboardHeightPhysical = 210.0f;	//mm

vector<physicalLayout::keyRect> physicalLayout::getPhysicalKeySizes(){
	vector<physicalLayout::keyRect> keyrects;
	
	//starting from the bottom up
	float lo = (1.5f / keyboardWidthPhysical) * keyboardWidth;	//left offset
	float ho = -20.0f;	//height offset
	float keyGapH = (2.0f / keyboardHeightPhysical) * keyboardHeight;	//~13.7
	float keyGapW = (1.0f / keyboardHeightPhysical) * keyboardHeight;
	float keyGapWide = (4.0f / keyboardHeightPhysical) * keyboardHeight;
	float keyHeight = (16.0f / keyboardHeightPhysical) * keyboardHeight;
	float keyWidth = (16.0f / keyboardWidthPhysical) * keyboardWidth;
	float tabWidth = (24.5f / keyboardWidthPhysical) * keyboardWidth;
	float capsWidth = (29.0f / keyboardWidthPhysical) * keyboardWidth;
	float leftShiftWidth = (37.0f / keyboardWidthPhysical) * keyboardWidth;
	float shiftWidth = (46.0f / keyboardWidthPhysical) * keyboardWidth;
	float ctrlWidth = (20.0f / keyboardWidthPhysical) * keyboardWidth;
	float bottomFnWidth = (27.0f / keyboardWidthPhysical) * keyboardWidth;
	float backspaceWidth = (33.0f / keyboardWidthPhysical) * keyboardWidth;
	float spacebarWidth = (100.0f / keyboardWidthPhysical) * keyboardWidth;
	float verticalHeight = (34.0f / keyboardHeightPhysical) * keyboardHeight;
	float rowGapBig = (6.0f / keyboardHeightPhysical) * keyboardHeight;
	float fnKeyGap = (10.5f / keyboardWidthPhysical) * keyboardWidth;

	//row 6 main keys:
	keyrects.push_back(makeRect((lo), ((keyboardHeight - keyGapH) - keyHeight) - ho, (ctrlWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW + ctrlWidth), ((keyboardHeight - keyGapH) - keyHeight) - ho, (ctrlWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*2 + ctrlWidth*2), ((keyboardHeight - keyGapH) - keyHeight) - ho, (ctrlWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*3 + ctrlWidth*3), ((keyboardHeight - keyGapH) - keyHeight) - ho, (spacebarWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*4 + ctrlWidth*3 + spacebarWidth), ((keyboardHeight - keyGapH) - keyHeight) - ho, (ctrlWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*5 + ctrlWidth*4 + spacebarWidth), ((keyboardHeight - keyGapH) - keyHeight) - ho, (ctrlWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*6 + ctrlWidth*5 + spacebarWidth), ((keyboardHeight - keyGapH) - keyHeight) - ho, (ctrlWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*7 + ctrlWidth*6 + spacebarWidth), ((keyboardHeight - keyGapH) - keyHeight) - ho, (bottomFnWidth), (keyHeight)));
	
	//row 6 arrow keys:
	keyrects.push_back(makeRect((lo + keyGapW*7 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide), ((keyboardHeight - keyGapH) - keyHeight) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*8 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide + keyWidth), ((keyboardHeight - keyGapH) - keyHeight) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*9 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide + keyWidth*2), ((keyboardHeight - keyGapH) - keyHeight) - ho, (keyWidth), (keyHeight)));
	
	//row 6 numpad keys:
	keyrects.push_back(makeRect((lo + keyGapW*9 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*3), ((keyboardHeight - keyGapH) - keyHeight) - ho, (backspaceWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*3 + backspaceWidth), ((keyboardHeight - keyGapH) - keyHeight) - ho, (keyWidth), (keyHeight)));
	
	//row 5 main keys:
	keyrects.push_back(makeRect((lo), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (leftShiftWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW + leftShiftWidth), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*2 + leftShiftWidth + keyWidth), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*3 + leftShiftWidth + keyWidth*2), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*4 + leftShiftWidth + keyWidth*3), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*5 + leftShiftWidth + keyWidth*4), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*6 + leftShiftWidth + keyWidth*5), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*7 + leftShiftWidth + keyWidth*6), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*8 + leftShiftWidth + keyWidth*7), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*9 + leftShiftWidth + keyWidth*8), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + leftShiftWidth + keyWidth*9), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*11 + leftShiftWidth + keyWidth*10), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (shiftWidth), (keyHeight)));

	//row 5 arrow key:	
	keyrects.push_back(makeRect((lo + keyGapW*8 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide + keyWidth), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	
	//row 5 numpad keys:
	keyrects.push_back(makeRect((lo + keyGapW*9 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*3), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*4), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*11 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*5), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*12 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*6), (keyboardHeight - (keyGapH*2 + keyHeight*2)) - ho, (keyWidth), (verticalHeight)));
	
	//row 4 main keys:
	keyrects.push_back(makeRect((lo), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (capsWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW + capsWidth), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*2 + capsWidth + keyWidth), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*3 + capsWidth + keyWidth*2), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*4 + capsWidth + keyWidth*3), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*5 + capsWidth + keyWidth*4), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*6 + capsWidth + keyWidth*5), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*7 + capsWidth + keyWidth*6), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*8 + capsWidth + keyWidth*7), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*9 + capsWidth + keyWidth*8), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + capsWidth + keyWidth*9), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*11 + capsWidth + keyWidth*10), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*12 + capsWidth + keyWidth*11), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (leftShiftWidth), (keyHeight)));
	
	//row 4 numpad:
	keyrects.push_back(makeRect((lo + keyGapW*9 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*3), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*4), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*11 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*5), (keyboardHeight - (keyGapH*3 + keyHeight*3)) - ho, (keyWidth), (keyHeight)));
	
	//row 3 main keys:
	keyrects.push_back(makeRect((lo), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (tabWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW + tabWidth), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*2 + tabWidth + keyWidth), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*3 + tabWidth + keyWidth*2), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*4 + tabWidth + keyWidth*3), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*5 + tabWidth + keyWidth*4), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*6 + tabWidth + keyWidth*5), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*7 + tabWidth + keyWidth*6), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*8 + tabWidth + keyWidth*7), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*9 + tabWidth + keyWidth*8), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + tabWidth + keyWidth*9), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*11 + tabWidth + keyWidth*10), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*12 + tabWidth + keyWidth*11), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*13 + tabWidth + keyWidth*12), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (tabWidth), (keyHeight)));
	
	//row 3 island keys:
	keyrects.push_back(makeRect((lo + keyGapW*7 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*8 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide + keyWidth), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*9 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide + keyWidth*2), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	
	//row 3 numpad keys:
	keyrects.push_back(makeRect((lo + keyGapW*9 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*3), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*4), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*11 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*5), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*12 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*6), (keyboardHeight - (keyGapH*4 + keyHeight*4)) - ho, (keyWidth), (verticalHeight)));
	
	//row 2 main keys:
	keyrects.push_back(makeRect((lo), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW + keyWidth), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*2 + keyWidth*2), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*3 + keyWidth*3), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*4 + keyWidth*4), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*5 + keyWidth*5), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*6 + keyWidth*6), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*7 + keyWidth*7), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*8 + keyWidth*8), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*9 + keyWidth*9), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + keyWidth*10), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*11 + keyWidth*11), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*12 + keyWidth*12), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*13 + keyWidth*13), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (backspaceWidth), (keyHeight)));
	
	//row 2 island keys:
	keyrects.push_back(makeRect((lo + keyGapW*7 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*8 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide + keyWidth), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*9 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide + keyWidth*2), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	
	//row 2 numpad keys
	keyrects.push_back(makeRect((lo + keyGapW*9 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*3), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*4), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*11 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*5), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*12 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide*2 + keyWidth*6), (keyboardHeight - (keyGapH*5 + keyHeight*5)) - ho, (keyWidth), (keyHeight)));
	
	//row 1 escape
	keyrects.push_back(makeRect((lo), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	
	//row 1 fn keys
	keyrects.push_back(makeRect((lo + keyGapW*2 + keyWidth*2), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*3 + keyWidth*3), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*4 + keyWidth*4), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*5 + keyWidth*5), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	
	keyrects.push_back(makeRect((lo + keyGapW*5 + keyWidth*6 + fnKeyGap), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*6 + keyWidth*7 + fnKeyGap), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*7 + keyWidth*8 + fnKeyGap), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*8 + keyWidth*9 + fnKeyGap), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	
	keyrects.push_back(makeRect((lo + keyGapW*8 + keyWidth*10 + fnKeyGap*2), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*9 + keyWidth*11 + fnKeyGap*2), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*10 + keyWidth*12 + fnKeyGap*2), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*11 + keyWidth*13 + fnKeyGap*2), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	
	//row 1 island keys
	keyrects.push_back(makeRect((lo + keyGapW*7 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*8 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide + keyWidth), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((lo + keyGapW*9 + ctrlWidth*6 + spacebarWidth + bottomFnWidth + keyGapWide + keyWidth*2), (keyboardHeight - (keyGapH*5 + keyHeight*6 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	
	//row 0 fn keys:
	keyrects.push_back(makeRect((-lo + keyGapW*2 + keyWidth*2), (keyboardHeight - (keyGapH*7 + keyHeight*7 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((-lo + keyGapW*3 + keyWidth*3), (keyboardHeight - (keyGapH*7 + keyHeight*7 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((-lo + keyGapW*4 + keyWidth*4), (keyboardHeight - (keyGapH*7 + keyHeight*7 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((-lo + keyGapW*5 + keyWidth*5), (keyboardHeight - (keyGapH*7 + keyHeight*7 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	
	keyrects.push_back(makeRect((-lo + keyGapW*5 + keyWidth*6 + fnKeyGap), (keyboardHeight - (keyGapH*7 + keyHeight*7 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((-lo + keyGapW*6 + keyWidth*7 + fnKeyGap), (keyboardHeight - (keyGapH*7 + keyHeight*7 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((-lo + keyGapW*7 + keyWidth*8 + fnKeyGap), (keyboardHeight - (keyGapH*7 + keyHeight*7 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	keyrects.push_back(makeRect((-lo + keyGapW*8 + keyWidth*9 + fnKeyGap), (keyboardHeight - (keyGapH*7 + keyHeight*7 + rowGapBig)) - ho, (keyWidth), (keyHeight)));
	
	//reorganizing keys to proper layout
	vector<physicalLayout::keyRect> organizedRects;
	organizedRects.push_back(keyrects[88]);
	organizedRects.push_back(keyrects[67]);
	organizedRects.push_back(keyrects[46]);
	organizedRects.push_back(keyrects[30]);
	organizedRects.push_back(keyrects[13]);
	organizedRects.push_back(keyrects[0]);
	organizedRects.push_back(keyrects[1]);
	organizedRects.push_back(keyrects[2]);
	organizedRects.push_back(keyrects[68]);	//8
	organizedRects.push_back(keyrects[47]);
	organizedRects.push_back(keyrects[48]);
	organizedRects.push_back(keyrects[31]);
	organizedRects.push_back(keyrects[32]);
	organizedRects.push_back(keyrects[14]);
	organizedRects.push_back(keyrects[15]);
	organizedRects.push_back(keyrects[3]);
	organizedRects.push_back(keyrects[69]);	//16
	organizedRects.push_back(keyrects[70]);
	organizedRects.push_back(keyrects[71]);
	organizedRects.push_back(keyrects[49]);
	organizedRects.push_back(keyrects[50]);
	organizedRects.push_back(keyrects[33]);
	organizedRects.push_back(keyrects[34]);
	organizedRects.push_back(keyrects[16]);
	organizedRects.push_back(keyrects[104]);	//24
	organizedRects.push_back(keyrects[105]);
	organizedRects.push_back(keyrects[106]);
	organizedRects.push_back(keyrects[107]);
	organizedRects.push_back(keyrects[89]);
	organizedRects.push_back(keyrects[90]);
	organizedRects.push_back(keyrects[91]);
	organizedRects.push_back(keyrects[92]);
	organizedRects.push_back(keyrects[72]);	//32
	organizedRects.push_back(keyrects[73]);
	organizedRects.push_back(keyrects[51]);
	organizedRects.push_back(keyrects[52]);
	organizedRects.push_back(keyrects[35]);
	organizedRects.push_back(keyrects[36]);
	organizedRects.push_back(keyrects[17]);
	organizedRects.push_back(keyrects[18]);
	organizedRects.push_back(keyrects[74]);	//40
	organizedRects.push_back(keyrects[75]);
	organizedRects.push_back(keyrects[53]);
	organizedRects.push_back(keyrects[54]);
	organizedRects.push_back(keyrects[37]);
	organizedRects.push_back(keyrects[38]);
	organizedRects.push_back(keyrects[19]);
	organizedRects.push_back(keyrects[20]);
	organizedRects.push_back(keyrects[108]);	//48
	organizedRects.push_back(keyrects[109]);
	organizedRects.push_back(keyrects[110]);
	organizedRects.push_back(keyrects[93]);
	organizedRects.push_back(keyrects[94]);
	organizedRects.push_back(keyrects[95]);
	organizedRects.push_back(keyrects[111]);
	organizedRects.push_back(keyrects[96]);
	organizedRects.push_back(keyrects[76]);	//56
	organizedRects.push_back(keyrects[77]);
	organizedRects.push_back(keyrects[55]);
	organizedRects.push_back(keyrects[56]);
	organizedRects.push_back(keyrects[39]);
	organizedRects.push_back(keyrects[40]);
	organizedRects.push_back(keyrects[21]);
	organizedRects.push_back(keyrects[22]);
	organizedRects.push_back(keyrects[97]);	//64
	organizedRects.push_back(keyrects[98]);
	organizedRects.push_back(keyrects[78]);
	organizedRects.push_back(keyrects[79]);
	organizedRects.push_back(keyrects[80]);
	organizedRects.push_back(keyrects[58]);
	organizedRects.push_back(keyrects[59]);
	organizedRects.push_back(keyrects[42]);
	organizedRects.push_back(keyrects[57]);	//72
	organizedRects.push_back(keyrects[41]);
	organizedRects.push_back(keyrects[23]);
	organizedRects.push_back(keyrects[24]);
	organizedRects.push_back(keyrects[4]);
	organizedRects.push_back(keyrects[5]);
	organizedRects.push_back(keyrects[6]);
	organizedRects.push_back(keyrects[7]);
	organizedRects.push_back(keyrects[99]);	//80
	organizedRects.push_back(keyrects[100]);
	organizedRects.push_back(keyrects[81]);
	organizedRects.push_back(keyrects[60]);
	organizedRects.push_back(keyrects[25]);
	organizedRects.push_back(keyrects[8]);
	organizedRects.push_back(keyrects[9]);
	organizedRects.push_back(keyrects[10]);
	organizedRects.push_back(keyrects[101]);	//88
	organizedRects.push_back(keyrects[102]);
	organizedRects.push_back(keyrects[103]);
	organizedRects.push_back(keyrects[82]);
	organizedRects.push_back(keyrects[83]);
	organizedRects.push_back(keyrects[61]);
	organizedRects.push_back(keyrects[62]);
	organizedRects.push_back(keyrects[84]);
	organizedRects.push_back(keyrects[85]);	//96
	organizedRects.push_back(keyrects[63]);
	organizedRects.push_back(keyrects[64]);
	organizedRects.push_back(keyrects[43]);
	organizedRects.push_back(keyrects[44]);
	organizedRects.push_back(keyrects[26]);
	organizedRects.push_back(keyrects[27]);
	organizedRects.push_back(keyrects[11]);
	organizedRects.push_back(keyrects[86]);	//104
	organizedRects.push_back(keyrects[65]);
	organizedRects.push_back(keyrects[45]);
	organizedRects.push_back(keyrects[28]);
	organizedRects.push_back(keyrects[12]);
	organizedRects.push_back(keyrects[87]);
	organizedRects.push_back(keyrects[66]);
	organizedRects.push_back(keyrects[29]);
	
	return organizedRects;
}

physicalLayout::keyRect physicalLayout::makeRect(float x, float y, float w, float h){
	physicalLayout::keyRect kr;
	kr.x = static_cast<int>(x);
	kr.y = static_cast<int>(y);
	kr.w = static_cast<int>(w);
	kr.h = static_cast<int>(h);
	return kr;
}