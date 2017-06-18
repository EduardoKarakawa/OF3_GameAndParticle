#include "Particle.h"


const float& Particle::getCurrentLifeTime() const { return m_lifeTime; }

Particle::Particle()
{
	// Construtor padrao da particula
	m_position = ofVec2f(0 ,0);
	m_direction = ofVec2f(0, 0);
	m_velocity = 0;
	m_lifeTime = 0;
}
Particle::~Particle(){}

Particle::Particle(const ofVec2f& origin, const ofVec2f& direction, float openAngle, float speed, float maxLifeTime, const ofColor& initialColor, const ofColor& finalColor)
{
	// Inicia os parametros da particula, criar uma direcao aleatoria para a particula de acordo com a direcao e angulo de abertura passada.
	m_position = origin;
	float angle = atan2f(direction.y - origin.y, direction.x - origin.x) + openAngle;
	m_direction = ofVec2f(cosf(angle), sinf(angle)).normalized();
	m_velocity = speed;
	m_maxLifeTime = maxLifeTime;
	m_lifeTime = 0;
	m_color = initialColor;
	m_isDead = false;

	SetValueToAddColor(initialColor, finalColor);
}

void Particle::Update(const float & deltaTime)
{
	if (!m_isDead) {
		// Atualizar a posicao da particula
		m_position += m_direction * m_velocity * deltaTime;

		// Atualiza o tempo de vida da particula
		m_lifeTime += deltaTime;

		m_isDead = !OnScreen(ofGetWidth(), ofGetHeight()) || m_lifeTime >= m_maxLifeTime;

	}
}

bool Particle::IsLife()
{
	// Retorna um true caso o tempo de vida da particula ainda for maior que 0
	return m_lifeTime >= 0.0f;
}

void Particle::Draw(const ofImage& sprite)
{
	if (!m_isDead) {
		// Seta uma cor e define a opcidade de acordo com o tempo de vida calculado na funcao Update
			

		ofSetColor(	m_color.r + addR * m_lifeTime,
					m_color.g + addG * m_lifeTime,
					m_color.b + addB * m_lifeTime,
					m_color.a + addA * m_lifeTime);

		sprite.draw(m_position.x - sprite.getWidth() / 2.0f, m_position.y - sprite.getHeight() / 2.0f);
	}
}


bool Particle::OnScreen(const int &w, const int&h) {
	return	m_position.x >= 0 && m_position.x <= w &&
			m_position.y >= 0 && m_position.y <= h;
}



void Particle::SetValueToAddColor(const ofColor& initialCol, const ofColor& finalCol){
	addR = (finalCol.r - initialCol.r) / m_maxLifeTime;
	addG = (finalCol.g - initialCol.g) / m_maxLifeTime;
	addB = (finalCol.b - initialCol.b) / m_maxLifeTime;
	addA = (finalCol.a - initialCol.a) / m_maxLifeTime;
}