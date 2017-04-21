#include "Particle.h"

Particle::Particle()
{
	// Construtor padrao da particula
	m_position = ofVec2f(0 ,0);
	m_direction = ofVec2f(0, 0);
	m_velocity = 0;
	m_lifeTime = 0;
	m_opacity = 0;
}
Particle::~Particle(){}

void Particle::Setup(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float startOpacity)
{
	// Inicia os parametros da particula, criar uma direcao aleatoria para a particula de acordo com a direcao e angulo de abertura passada.
	m_position = origin;
	float tmp = (-openAngle / 2.0f + rand() % (int)openAngle) * PI / 180.0f;
	float angle = atan2f(direction.y - origin.y, direction.x - origin.x) + tmp;
	m_direction = ofVec2f(cosf(angle), sinf(angle)).normalized();
	m_velocity = speed;
	m_lifeTime = lifeTime;
	m_startOpacity = startOpacity;
	m_opacity = startOpacity;
}

void Particle::Update(ofVec2f origin, float deltaTime)
{
	// Atualizar a posicao da particula
	m_position += m_direction * m_velocity * deltaTime;
	
	// Atualiza o tempo de vida da particula
	m_lifeTime -= deltaTime;

	// Decrementa a opacidade de acordo com o tempo de vida da particula
	m_opacity -= m_opacity < 0 ? 0 : m_startOpacity / m_lifeTime * deltaTime;

}

bool Particle::IsLife()
{
	// Retorna um true caso o tempo de vida da particula ainda for maior que 0
	return m_lifeTime > 0.0f;
}

void Particle::Draw(ofImage sprite, ofColor color, ofVec2f origin)
{
	// Seta uma cor e define a opcidade de acordo com o tempo de vida calculado na funcao Update
	ofSetColor(color, m_opacity);
	
	// Desenha a particula apartir da posicao de origem, no caso onde a orgem da particula estiver + a posicao da particula atual
	//sprite.draw(m_position.x - sprite.getWidth() / 2.0f, m_position.y - sprite.getHeight() / 2.0f);
	sprite.draw(m_position.x - sprite.getWidth() / 2.0f, m_position.y - sprite.getHeight() / 2.0f);
}


