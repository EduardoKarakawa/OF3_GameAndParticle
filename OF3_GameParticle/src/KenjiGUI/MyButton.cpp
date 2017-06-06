#include "MyButton.h"


// Geters para pegar informacoes do botao
const bool & MyButton::IsPressed()		const { return m_pressed; }
const std::string & MyButton::GetText() const { return m_name; }
const ofVec2f & MyButton::GetPosition() const { return m_position; }
const ofVec2f & MyButton::GetStringSize(std::string text) const { return ofVec2f(m_font.stringWidth(text), m_font.stringHeight(text)); }


// Seters para alterar algum parametro do botao
void MyButton::SetPosition(ofVec2f &position)		{ m_position.set(position); }
void MyButton::SetPosition(int x, int y)			{ m_position.set(x, y); }
void MyButton::SetToggleValue(bool newValue)		{ m_pressed = newValue; }
void MyButton::SetText(std::string name)			{ m_name = name; }
void MyButton::SetSize(int w, int h)				{ 
	m_width = w; 
	m_height = h;
	SetFontPosition(m_textPosition, m_textMargin);
}

void MyButton::SetColorDefault(ofColor &color)				{ m_colorDefault.set(color); }
void MyButton::SetColorDefault(int r, int g, int b, int a)	{ m_colorDefault.set(r, g, b, a); }
void MyButton::SetColorPressed(ofColor &color)				{ m_colorPressed.set(color); }
void MyButton::SetColorPressed(int r, int g, int b, int a)	{ m_colorPressed.set(r, g, b, a); }

void MyButton::SetColor(ofColor &colorDefault, ofColor &colorPressed) { 
	m_colorDefault.set(colorDefault); 
	m_colorPressed.set(colorPressed); 
}

void MyButton::SetColor(int r_D, int g_D, int b_D, int a_D, int r_P, int g_P, int b_P, int a_P){
	m_colorDefault.set(r_D, g_D, b_D, a_D);
	m_colorPressed.set(r_P, g_P, b_P, a_P);

}

void MyButton::SetSprite(ofImage &sprite) { 
	m_sprite.clear();
	m_sprite.push_back(sprite); 
}

void MyButton::SetSprite(std::string localSprite)	{ 
	m_sprite.clear();
	m_sprite.push_back(ofImage(localSprite));
}

void MyButton::SetSprite(ofImage &spriteDefault, ofImage &spritePressed) {
	m_sprite.clear();
	m_sprite.push_back(spriteDefault);
	m_sprite.push_back(spritePressed);
}

void MyButton::SetSprite(std::string localSpriteDefault, std::string localSpritePressed) {
	m_sprite.clear();
	m_sprite.push_back(ofImage(localSpriteDefault));
	m_sprite.push_back(ofImage(localSpritePressed));
}


void MyButton::SetFontColor(ofColor &color) { m_fontColor.set(color); }

void MyButton::SetFontColor(int r, int g, int b, int a) { m_fontColor.set(r, g, b, a); }

void MyButton::SetFontPosition(int position, float margin) {
	switch (position)
	{
	case FONT_LEFT:
		m_fontPosition.set(	m_position.x - margin - m_font.stringWidth(m_name),
							m_position.y + m_height / 2.0f + m_font.stringHeight(m_name) / 2.0f);
		break;
	case FONT_RIGHT:
		m_fontPosition.set(	m_position.x + m_width + margin,
							m_position.y + m_height / 2.0f + m_font.stringHeight(m_name) / 2.0f);
		break;
	default:
		m_fontPosition.set(m_position.x + m_width / 2.0f - m_font.stringWidth(m_name) / 2.0f,
			m_position.y + m_height / 2.0f + m_font.stringHeight(m_name) / 2.0f);
		break;
	}
}


void MyButton::LoadFont(ofTrueTypeFont &font, ofColor &color) {
	m_font = font;
	m_fontColor.set(color);
}

void MyButton::LoadFont(std::string &font, int size, ofColor &color) {
	m_font.load(font, size);
	m_fontColor.set(color);
}

void MyButton::LoadFont(std::string &font, int size, int r, int g, int b, int a) {
	m_font.load(font, size);
	m_fontColor.set(r, g, b, a);
}



// Construtor para o botao
MyButton::MyButton()
{
	m_pressed = false;
	m_position.set(0, 0);
	m_width = 0;
	m_height = 0;
	m_colorDefault.set(255, 255, 255);
	m_colorPressed.set(255, 255, 255);
	m_fontColor.set(255, 255, 255);
	m_mousePressed = false;
	m_font.load("C:/Windows/Fonts/arial.ttf", 12);
}


// Construtor para o botao
MyButton::MyButton(std::string name, int textPosition, float margin, bool value, ofVec2f &position, int width, int heigth) {
	m_pressed = value;
	m_position.set(position);
	m_width = width;
	m_height = heigth;
	m_name = name;
	m_font.load("C:/Windows/Fonts/arial.ttf", 12);
	m_mousePressed = false;	
	m_textMargin = margin;
	m_textPosition = textPosition;
	SetFontPosition(textPosition, margin);

}


// Construtor para o botao
MyButton::MyButton(std::string name, int textPosition, float margin, bool value, int x, int y, int width, int heigth) {
	m_pressed = value;
	m_position.set(x, y);
	m_width = width;
	m_height = heigth;
	m_name = name;
	m_font.load("C:/Windows/Fonts/arial.ttf", 12);
	m_mousePressed = false;
	m_textMargin = margin;
	m_textPosition = textPosition;
	SetFontPosition(textPosition, margin);
}


MyButton::~MyButton()
{
	m_sprite.clear();
}


// Update para atulizar o estado do botao
void MyButton::Update() {
	// Muda o valor de m_pressed se o botao for pressionado
	m_pressed = MouseClickedButton() ? !m_pressed : m_pressed;
}


// Desenha o botao
void MyButton::Draw() {
	// Desenha o botao de acordo com a sprite se nao desenha um retangulo padrao
	if (m_sprite.size() >= 1) {
		DrawSprite();
	}
	else {
		DrawSquare();
	}
}



void MyButton::DrawSprite() {
	// Muda a cor se estiver precionado ou nao e desenha o fundo do botao
	m_pressed ? ofSetColor(m_colorPressed) : ofSetColor(m_colorDefault);
	
	if (m_sprite.size() == 1) {

		m_sprite[0].draw(m_position, m_width, m_height);
	
	}

	else if (m_sprite.size() > 1) {

		m_sprite[m_pressed].draw(m_position, m_width, m_height);

	}

	ofSetColor(m_fontColor);
	m_font.drawString(m_name, m_fontPosition.x, m_fontPosition.y);
}


// Desenha um quadrado quando nao tiver sido passa sprites
void MyButton::DrawSquare() {
	// Muda a cor se estiver precionado ou nao e desenha o fundo do botao
	m_pressed ? ofSetColor(m_colorPressed) : ofSetColor(m_colorDefault);
	ofDrawRectangle(m_position, m_width, m_height);

	ofSetColor(m_fontColor);
	m_font.drawString(m_name, m_fontPosition.x, m_fontPosition.y);

}


// Funcao para verificar se o Button foi precionado, tambem evita de ficar alternando o valor enquando o mouse tiver sendo precionado
// So retora verdadeiro quando o botao do mouse for solto e se ele estiver emcima do botao
bool MyButton::MouseClickedButton() {

	// Verifica se o botao esquerdo do mouse esta precionado e define o m_mousePressed como true e retorna falso
	if (ofGetMousePressed(OF_MOUSE_BUTTON_1)) {
		m_mousePressed = true;
		return false;
	}

	// Se nao se m_mousePressed eh verdadeiro verifica se o mouse esta sobre o botao, se sim retorna verdadeiro
	//indicando que foi pressionado o Button
	else if (m_mousePressed) {
		// Pega a posicao do mouse
		ofVec2f mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
		m_mousePressed = false;

		return	(mousePos.x >= m_position.x && mousePos.x <= m_position.x + m_width) &&
				(mousePos.y >= m_position.y && mousePos.y <= m_position.y + m_height); 
	}
	return false;

}













