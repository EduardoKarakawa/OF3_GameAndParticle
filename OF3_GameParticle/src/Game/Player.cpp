#include "Player.h"

// Construtor do player
Player::Player(std::string tag, int width, int height, float speed)
{
	m_tag = tag;
	m_radius = 25;
	m_keyArrow = false;
	m_keyRight = false;
	m_keyLeft = false;
	m_keyUp = false;
	m_keyDown = false;
	m_keySpace = false;
	m_keyZ = false;
	m_keyW = false;
	m_keyS = false;
	m_keyA = false;
	m_keyD = false;
	m_position.set(width, height);
//	m_particle = ParticleEmission().SearchConfig(m_tag, &m_position);
	
	// Velocidade do personagem
	m_speed = speed;
	
	// Cooldown para o player poder atirar
	m_cooldownShooting = 0;

	// Criando o primeiro tiro
	ofVec2f zero;
	zero.set(0, 0);
	bullets.push_back(new Bullet(zero, -1));
}


void Player::AddCounter()
{
	m_keyArrow = 2;
}


void Player::Update(float &deltaTime)
{
	// Atualiza a contagem de tempo para o cooldown de tiro
	if (m_cooldownShooting <= MAX_TIME_SHOOTING) {
		m_cooldownShooting += deltaTime;
	}


	if (m_particle != nullptr) {
		m_particle->Update(deltaTime);
	}

	// Calcula uma velocidade pegando o produto do speed e deltaTime para que o player ande igual em qualquer pc
	float tmpVelocity = m_speed * deltaTime;

	// Verica qual tecla esta precionada e adiciona ou subtrai a posicao do player
	if (m_keyW == true)
	{
		m_position.y -= tmpVelocity;
	}
	if (m_keyS == true)
	{
		m_position.y+= tmpVelocity;
	}
	if (m_keyD == true)
	{
		m_position.x+= tmpVelocity;
	}
	if (m_keyA == true)
	{
		m_position.x-= tmpVelocity;
	}


	// Verifica se o player atirou e cria um novo tiro
	if (this->GetShooting())
	{
		this->AddCounter();
		bullets.push_back(new Bullet(this->GetPosition(), this->GetArrowKey()));
	}

	// Verifica se exitem tiros para serem processados
	if (bullets.size() > 1)
	{
		// Percorre a lista de tiros para atualizar a posicao deles
		for (int i = 0; i < bullets.size(); i++)
		{
			bool bulletLife = true;
			bulletLife = bullets.at(i)->Update(deltaTime);
			// Percorre a lista de enemys para verificar a colisão com o tiro

			if (bulletLife == false) this->EraseBullet(i);
		}

	}

}


// Desenha o Player
void Player::Draw()
{

	// Verifica se o player esta dentro da tela e desenha ele
	if (OnScreen()) 
	{
		// Desenha o Player
		ofSetColor(0,0,0);
		ofDrawCircle(m_position.x, m_position.y, m_radius);

		if (m_particle != nullptr) {
			m_particle->Draw();
		}
	}

	// Desenha os tiros

	if (bullets.size() > 1)
	{
		for (int i = 1; i < bullets.size(); i++)
		{
			bullets.at(i)->Draw();
		}
	}
}


// Armazena as teclas que estao precionandas
void Player::Press(int a)
{
	switch (a)
	{
	case 0:
		m_keyUp = true;
		m_keyArrow++;
		break;
	case 1:
		m_keyDown = true;
		m_keyArrow++;
		break;
	case 2:
		m_keyRight = true;
		m_keyArrow++;
		break;
	case 3:
		m_keyLeft = true;
		m_keyArrow++;
		break;
	case 4:
		m_keyW = true;
		break;
	case 5:
		m_keyS = true;
		break;
	case 6:
		m_keyD = true;
		break;
	case 7:
		m_keyA = true;
		break;
	case 8:
		m_keyZ = true;
		break;
	case 9:
		m_keySpace = true;
		break;
	}
}


// Muda para falso as tecla que nao estiverem sendo precionada
void Player::Release(int a)
{
	switch (a)
	{
	case 0:
		m_keyUp = false;
		m_keyArrow = 0;
		break;
	case 1:
		m_keyDown = false;
		m_keyArrow = 0;
		break;
	case 2:
		m_keyRight = false;
		m_keyArrow = 0;
		break;
	case 3:
		m_keyLeft = false;
		m_keyArrow = 0;
		break;
	case 4:
		m_keyW = false;
		break;
	case 5:
		m_keyS = false;
		break;
	case 6:
		m_keyD = false;
		break;
	case 7:
		m_keyA = false;
		break;
	case 8:
		m_keyZ = false;
		break;
	case 9:
		m_keySpace = false;
		break;
	}
}


// Retorna um id se uma seta estiver sendo precionada, se nao tiver retorna -1
int Player::GetArrowKey() const
{
	if (m_keyUp)
		return 0;
	if (m_keyDown)
		return 1;
	if (m_keyLeft)
		return 2;
	if (m_keyRight)
		return 3;

	return -1;
}


// Retorna verdadeiro se o player ja poder atirar
bool Player::GetShooting()
{
	// m_cooldownShooting eh uma varivel de contagem de tempo,  se ela for maior que MAX_TIME_SHOOTING e m_keyArrow for verdadeiro
	// a funcao returna true indicando que pode criar outro tiro e a contagem eh resetadas
	if (m_keyArrow && m_cooldownShooting >= MAX_TIME_SHOOTING) {
		m_cooldownShooting = 0;
		return true;
	}
	return false;
}

void Player::EraseBullet(int i)
{
	bullets.erase(bullets.begin() + i);
}

int Player::GetVectorBulSize() const
{
	return bullets.size();
}

ofVec2f Player::GetBulletPosition(int i) const
{
	if (i < bullets.size())
		return bullets.at(i)->GetPosition();
	else
		return ofVec2f(0, 0);
}
