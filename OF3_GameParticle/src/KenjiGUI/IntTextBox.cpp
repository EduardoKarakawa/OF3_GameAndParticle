#include "IntTextBox.h"

int IntTextBox::GetValue() const { return _value; }
void IntTextBox::SetValue(int value) { _value = value; }

void IntTextBox::SetFontPosition(ofVec2f& position) {
	m_fontPosition = position;
}


IntTextBox::IntTextBox()
{
	SetPosition(0, 0);
	SetColor(ofColor(255, 255, 255), ofColor(245, 245, 245));
	SetFontColor(ofColor(0, 0, 0));
	SetToggleValue(false);
	m_textMargin = 0;
	m_textPosition = 0;
	_value = 0;
	_timeCont = 0;
	_drawLineEdit = false;
}

IntTextBox::IntTextBox(std::string name, int textPosition, float margin, ofVec2f &position, int defaultValue, ofColor &defaultColor, ofColor &pressedColor, ofColor &fontColor)
{
	SetPosition(position);
	SetText(name);
	SetColor(defaultColor, pressedColor);
	SetFontColor(fontColor);
	MyButton::SetFontPosition(textPosition, margin);
	m_textMargin = margin;
	m_textPosition = textPosition;
	_value = defaultValue;
	_timeCont = 0;
	_drawLineEdit = false;
}

IntTextBox::IntTextBox(std::string name, ofVec2f& fontPosition, float margin, ofVec2f &position, int defaultValue, ofColor &defaultColor, ofColor &pressedColor, ofColor &fontColor) {
	SetPosition(position);
	SetText(name);
	SetColor(defaultColor, pressedColor);
	SetFontColor(fontColor);
	SetFontPosition(fontPosition);
	m_textMargin = margin;
	//m_textPosition = textPosition;
	_value = defaultValue;
	_timeCont = 0;
	_drawLineEdit = false;
}


void IntTextBox::Update()
{
	if (_timeCont < TIME_TO_GET_KEY) {
		_timeCont += ofGetLastFrameTime();
	}

	// Muda o valor de m_pressed se o botao for pressionado
	if (!m_pressed) {
		m_pressed = MouseClickedButton() ? !m_pressed : m_pressed;
	}
	else {
		_drawLineEdit += ofGetLastFrameTime();
		for (int i = '0'; i <= '9'; i++) {
			if (_timeCont > TIME_TO_GET_KEY && ofGetKeyPressed(i)){
				_value = 45648978 - abs(_value) > (i - '0') ? ((_value * 10) + (i - '0')) :
																					_value;

				_timeCont = 0;
				break;

			}
		}
		if (_timeCont > TIME_TO_GET_KEY && ofGetKeyPressed('-')) {
			_value *= _value > 0 ? -1 : 1;

		}
		else if (_timeCont > TIME_TO_GET_KEY && ofGetKeyPressed('+')) {
			_value *= _value < 0 ? -1 : 1;

		}
		else if (_timeCont > TIME_TO_GET_KEY && ofGetKeyPressed(OF_KEY_BACKSPACE)) {
			int aux = (_value / 10.0f);
			aux = abs(aux) > abs(_value / 10.0f) ? aux - 1 : aux;
			_value = aux;
			_timeCont = 0;

		}
		else if (ofGetKeyPressed(OF_KEY_RETURN)) {
			m_pressed = false;
			_drawLineEdit = 0;

		}
	}
}


void IntTextBox::Draw() {
	// Desenha o botao de acordo com a sprite se nao desenha um retangulo padrao
	if (m_sprite.size() >= 1) {
		DrawSprite();
	}
	else {
		DrawSquare();
	}
	//_valuePosition.set(m_position.x + 5, m_position.y + m_height / 2.0f + m_font.stringHeight(ofToString(_value)) / 2.0f);
	_valuePosition.set(m_position.x + 5,
						m_position.y + m_height / 2.0f + m_font.stringHeight("0") / 2.0f);

	m_font.drawString(ofToString(_value), _valuePosition.x, _valuePosition.y);

	if (_drawLineEdit > 0.5f && m_pressed) {
		ofSetColor(m_fontColor);

		// cria uma margin baseando na altura do background do botao com a altura da font
		float margin = abs((m_height - m_font.stringHeight("0")) / 2.0f);
		ofDrawLine(	_valuePosition.x + m_font.stringWidth(ofToString(_value)) + 2, m_position.y + 5,
					_valuePosition.x + m_font.stringWidth(ofToString(_value)) + 2, _valuePosition.y);
		
		if (_drawLineEdit > 0.8f) _drawLineEdit = 0;
	}

	
}

IntTextBox::~IntTextBox()
{
}
