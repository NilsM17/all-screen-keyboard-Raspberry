//physical layout.h
//defines the layout of the keys on the 2560x1440px screen

#include <vector>

class physicalLayout{
	
	public:
		struct keyRect{
			int x;
			int y;
			int w;
			int h;
		};
		std::vector<keyRect> getPhysicalKeySizes();
	
	private:
		keyRect makeRect(float x, float y, float w, float h);

};