#include "Bullet.h"
// Construtor do Bullet
Bullet::Bullet(const ofVec2f &position, const ofVec2f &direction)
{
	// Define uma direcao para o tiro de acordo com a tecla precionada
	// Essas teclas sao definidas no ofApp.cpp em KeyPressed e KeyRelease, depois sao armazenadas no Player
	// Seta a posicao inicial
	m_position = position;
	m_direction = direction;

	LoadNewAnimation("Bullet");

	// Seta o speed
	m_speed = BULLET_SPEED;
		
	// Define as cores do tiro
	color.set(0.8f, 0.2f, 0.2f);
}


// Update para atualizar a posicao do tiro
bool Bullet::Update(const float &deltaTime)
{
	// A posicao é somada com o produto da direcao vezes a velocidade vezes o deltaTime
	// Isso permite a bala ter o mesmo mover na mesma velocidade para qualquer computador
	// Speed eh o total de pixel por segundo que sera percorrido
	m_position += m_direction * m_speed * deltaTime;

	//Se a bala sair da tela, ela será apagada no ofApp
	if(OnScreen())
		return false;

	return true;
}

// Desenha o tiro
void Bullet::Draw()
{
	// Verifica se o tiro esta dentro da tela usando OnScreen() que eh uma funcao que esta na classe GameObject
	// e desenha ela
	this->DrawAnimation();

}
