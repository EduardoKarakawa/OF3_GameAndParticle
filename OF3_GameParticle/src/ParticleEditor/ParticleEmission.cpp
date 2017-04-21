#include "ParticleEmission.h"

ParticleEmission::ParticleEmission(){}
ParticleEmission::~ParticleEmission(){}
void ParticleEmission::SetOrigin(ofVec2f origin)			{ m_positionOrigin = origin; }
void ParticleEmission::SetDirection(ofVec2f direction)		{ m_direction = direction; }
void ParticleEmission::SetOpenAngle(float openAngle)		{ m_openAngle = openAngle; }
void ParticleEmission::SetSpeed(float speed)				{ m_velocity = speed; }
void ParticleEmission::SetLifeTime(float lifeTime)			{ m_maxLifeTime = lifeTime; }
void ParticleEmission::SetSprite(string sprite)				{ m_sprite.loadImage(sprite); }
void ParticleEmission::SetSpawnTime(float timeSpawn)		{ m_timeSpawnParticle = timeSpawn; }
void ParticleEmission::SetColor(ofColor color)				{ m_color = color; }
void ParticleEmission::SetSizeParticle(float radius)		{ m_sprite.resize(radius, radius); }

void ParticleEmission::Setup(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, string sprite, float size)
{
	// Inicia os parametros da sistema de particula novo
	m_sprite.loadImage(sprite);
	m_sprite.resize(size, size);
	m_positionOrigin = origin;
	SetDirection(direction);
	m_openAngle = openAngle;
	m_maxLifeTime = lifeTime;
	m_velocity = speed;
	m_timeSpawnParticle = timeSpawn;
	m_spawnTimeCont = 0;
	m_enableParticles = true;
	m_color = ofColor(255, 255, 255);
}

void ParticleEmission::Update(float deltaTime)
{
	if (m_enableParticles) {
		// Atualiza a lista de particulas do sistema de particula, chama o DestroyParticle se a particula atingiu o tempo maximo de vida
		// cria uma nova particula caso o tempo ultrapasse o tempo de spawn
		m_spawnTimeCont += ofGetLastFrameTime();

		// Cria uma particula
		CreateParticle();
	}

	if (m_particles.size() > 1) {
		// Verifica as particulas que ultrapassaram o tempo maximo de vida e exclui eles do vetor
		std::vector<Particle>::iterator aux;	// Iterator para percorrer a lista de particles

		for (aux = m_particles.begin(); aux < m_particles.end(); aux++) {
			// Atualiza a particula
			aux->Update(m_positionOrigin, deltaTime);

			// Verifica se a particle ultrapassou o tempo de vida, se sim ela eh destruida
			if (!aux->IsLife()) {
				aux = m_particles.erase(aux);
			}
		}
	}

}


void ParticleEmission::Draw()
{
	if (m_particles.size() > 0) {
		// Percorre a lista de particular desenhando elas
		std::vector<Particle>::iterator aux;	// Iterator para percorrer a lista de particles
		for (aux = m_particles.begin(); aux != m_particles.end(); aux++) {
			aux->Draw(m_sprite, m_color, m_positionOrigin);
		}
	}
}

void ParticleEmission::CreateParticle()
{
	// Cria uma particula se ja tiver passado o tempo necessario para criar uma
	if (m_spawnTimeCont > m_timeSpawnParticle) {
		int tmp =  m_spawnTimeCont / m_timeSpawnParticle;
		for (int i = 0; i < tmp; i++) {
			m_particles.push_back(Particle());
			// Inicializa a nova particula criada
			(m_particles.end()-1)->Setup(m_positionOrigin, m_direction, m_openAngle, m_velocity, m_maxLifeTime, m_color.a);

			m_spawnTimeCont -= m_timeSpawnParticle;
		}
	}
}

