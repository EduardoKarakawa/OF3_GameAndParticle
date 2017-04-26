#pragma once
#include <vector>
#include <string>
#include "ofImage.h"
#include "ofVec2f.h"
#include "ofGraphics.h"
#include "ofTrueTypeFont.h"

class MyButton
{
	private:
		std::string m_name;
		std::vector<ofImage> m_sprite;
		ofColor m_colorDefault, m_colorPressed;
		ofVec2f m_position;
		bool m_pressed;
		int m_width, m_height;
		ofTrueTypeFont m_font;
		ofColor m_fontColor;
		bool m_mousePressed;
	
	public:
		MyButton();
		MyButton(std::string name, bool value, ofVec2f &position, int width, int heigth);
		MyButton(std::string name, bool value, int x, int y, int width, int heigth);


		~MyButton();
		void SetName(std::string &name);
		void SetPosition(ofVec2f &position);
		void SetPosition(int x, int y);
		void SetColor(ofColor &colorDefault, ofColor &colorPressed);
		void SetColor(int r_D, int g_D, int b_D, int a_D, int r_P, int g_P, int b_P, int a_P);
		void SetColorDefault(ofColor &color);
		void SetColorDefault(int r, int g, int b, int a);
		void SetColorPressed(ofColor &color);
		void SetColorPressed(int r, int g, int b, int a);
		void SetSprite(ofImage &sprite);
		void SetSprite(std::string localSprite);
		void SetSprite(ofImage &spriteDefault, ofImage &spritePressed);
		void SetSprite(std::string localSpriteDefault, std::string localSpritePressed);
		void SetValue(bool newValue);
		void SetFontColor(ofColor &color);
		void SetFontColor(int r, int g, int b, int a);


		const ofVec2f & GetPosition() const;
		const bool & IsPressed()	  const;
		const std::string & GetName() const;
		void LoadFont(ofTrueTypeFont &font, ofColor &color);
		void LoadFont(std::string &font, int size, ofColor &color);
		void LoadFont(std::string &font, int size, int r, int g, int b, int a);

		void Draw();
		void Update();

	private: 
		void DrawSprite();
		void DrawSquare();
		bool MouseClickedButton();
};

