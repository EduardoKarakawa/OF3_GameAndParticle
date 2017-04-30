#include "Bullet.h"
// Construtor do Bullet
Bullet::Bullet(ofVec2f position, int tecla)
{
	// Define uma direcao para o tiro de acordo com a tecla precionada
	// Essas teclas sao definidas no ofApp.cpp em KeyPressed e KeyRelease, depois sao armazenadas no Player
	switch (tecla)
	{
		case -1:
			m_direction.set(0, 0);
			break;
		case 0:
			m_direction.set(0,-1);
			break;
		case 1:
			m_direction.set(0,1);
			break;
		case 2:
			m_direction.set(-1,0);
			break;
		case 3:
			m_direction.set(1,0);
			break;
	}
	// Seta a posicao inicial
	m_position = position;

	// Seta o tamanho do tiro
	m_radius = 10;

	// Seta o speed
	m_speed = BULLET_SPEED;
		
	// Define as cores do tiro
	color.set(0.8f, 0.2f, 0.2f);
}


// Update para atualizar a posicao do tiro
bool Bullet::Update(float &deltaTime)
{
	// A posicao é somada com o produto da direcao vezes a velocidade vezes o deltaTime
	// Isso permite a bala ter o mesmo mover na mesma velocidade para qualquer computador
	// Speed eh o total de pixel por segundo que sera percorrido
	m_position += m_direction * m_speed * deltaTime;

	//Se a bala sair da tela, ela será apagada no ofApp
	if (m_position.x > ofGetWidth() || m_position.x < 0 || m_position.y > ofGetHeight() || m_position.y < 0)
		return false;

	return true;
}

// Desenha o tiro
void Bullet::Draw()
{
	// Verifica se o tiro esta dentro da tela usando OnScreen() que eh uma funcao que esta na classe GameObject
	// e desenha ela
	ofSetColor(color);
	ofDrawCircle(m_position.x, m_position.y, m_radius);

}
