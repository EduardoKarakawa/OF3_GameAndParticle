#include "Player.h"

void Player::EraseBullet(int i) { m_bullets.erase(m_bullets.begin() + i); }
int Player::GetVectorBulSize() const { return m_bullets.size(); }
void Player::SetMousePosition(const int &x, const int &y) { m_mousePosition.set(x, y); }



// Construtor do player
Player::Player(std::string tag, int width, int height, float speed)
{
	m_radius = 25;
	m_position.set(width, height);

	// Velocidade do personagem
	m_speed = speed;

	// Cooldown para o player poder atirar
	m_cooldownShooting = 0;

	m_particle.SearchParticleConfig(tag);

	m_moving = false;
}

// Construtor do player
Player::Player(){
	m_radius = 25;
	m_position.set(0, 0);


	// Velocidade do personagem
	m_speed = 0;

	// Cooldown para o player poder atirar
	m_cooldownShooting = 0;

	m_particle.SearchParticleConfig("");

	m_moving = false;
}

void Player::Update(const float &deltaTime)
{
	m_mousePosition.set(ofGetMouseX(), ofGetMouseY());
	m_position += m_direction * m_speed * deltaTime;


	// Atualiza a contagem de tempo para o cooldown de tiro
	if (m_cooldownShooting < MAX_TIME_SHOOTING) {
		m_cooldownShooting += deltaTime;
	}


	// Verifica se exitem tiros para serem processados
	if (m_bullets.size() > 0)
	{
		// Percorre a lista de tiros para atualizar a posicao deles
		for (int i = 0; i < m_bullets.size(); i++)
		{
			bool bulletLife = true;
			bulletLife = m_bullets.at(i).Update(deltaTime);
			// Percorre a lista de enemys para verificar a colisão com o tiro

			if (bulletLife == false) this->EraseBullet(i);
		}

	}

	m_particle.Update(deltaTime, m_position);
}

// Desenha o Player
void Player::Draw()
{
	m_particle.Draw();
	
	// Verifica se o player esta dentro da tela e desenha ele
	if (OnScreen()) 
	{
		// Desenha o Player
		ofSetColor(0,0,0);
		ofDrawCircle(m_position.x, m_position.y, m_radius);
	}

	// Desenha os tiros

	if (m_bullets.size() > 0)
	{
		for (int i = 0; i < m_bullets.size(); i++)
		{
			m_bullets.at(i).Draw();
		}
	}
}

void Player::SetDirectionX(int x) { m_direction.x = x; }
void Player::SetDirectionY(int y) { m_direction.y = y; }

// Retorna verdadeiro se o player ja poder atirar
void Player::Shooting()
{
	// m_cooldownShooting eh uma varivel de contagem de tempo,  se ela for maior que MAX_TIME_SHOOTING e m_keyArrow for verdadeiro
	// a funcao returna true indicando que pode criar outro tiro e a contagem eh resetadas
	if (m_cooldownShooting >= MAX_TIME_SHOOTING) {
		
		ofVec2f direction = (m_mousePosition - m_position ).normalized();
		m_bullets.push_back(Bullet(m_position, direction));
		m_cooldownShooting -= MAX_TIME_SHOOTING;
	}
}

// Passa o valor da posição de um determinado tiro
ofVec2f Player::GetBulletPosition(int i) const
{
	if (i < m_bullets.size())
		return m_bullets.at(i).GetPosition();
	else
		return ofVec2f(0, 0);
}

Player::~Player() {
}