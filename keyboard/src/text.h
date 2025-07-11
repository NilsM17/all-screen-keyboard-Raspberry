//text.h

#include <vector>
#include <string>

class text{
	public:
		text(const char* inputString, int x, int y, float newSize, int r, int g, int b, int a);
		void updateText(const char* updateString);
		void updateLocation(int x, int y);
		void updateSize(int newSize);
		void updateColor(int r, int g, int b, int a);
		
		float locationX, locationY, size;	//top left coordinate location	
		struct color{
			float r, g, b, a;
		};
		color c;
		
		const char* getText();
		
	private:
			std::string outputString;
};