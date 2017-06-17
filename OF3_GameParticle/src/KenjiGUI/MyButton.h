#pragma once
#include <vector>
#include <string>
#include "ofImage.h"
#include "ofVec2f.h"
#include "ofGraphics.h"
#include "ofTrueTypeFont.h"



class MyButton
{
	protected:
		std::string m_name;
		std::vector<ofImage> m_sprite;
		ofColor m_colorDefault, m_colorPressed;
		ofVec2f m_position;
		int m_width, m_height;
		ofTrueTypeFont m_font;
		ofVec2f m_fontPosition;
		ofColor m_fontColor;
		bool m_mousePressed;
		bool m_pressed;
		int m_textPosition;
		float m_textMargin;
	
	public:
		enum FontPosition {
			FONT_RIGHT,
			FONT_CENTER,
			FONT_LEFT
		};

		MyButton();
		MyButton(std::string name, int textPosition, float margin, bool value, ofVec2f &position, int width, int heigth);
		MyButton(std::string name, int textPosition, float margin, bool value, int x, int y, int width, int heigth);


		~MyButton();
		void SetText(std::string name);
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
		void SetToggleValue(bool newValue);
		void SetFontColor(ofColor &color);
		void SetFontColor(int r, int g, int b, int a);
		void SetFontPosition();
		void SetFontPosition(int position, float margin);
		void SetSize(int w, int h);
		
		const ofVec2f & GetStringSize(std::string text) const;
		const ofVec2f & GetPosition() const;
		const bool & IsPressed()	  const;
		const std::string & GetText() const;
		void LoadFont(ofTrueTypeFont font, ofColor &color);
		void LoadFont(std::string font, int size, ofColor &color);
		void LoadFont(std::string font, int size, int r, int g, int b, int a);

		virtual void Draw();
		virtual void Update();

	protected: 
		void DrawSprite();
		void DrawSquare();
		bool MouseClickedButton();

};

