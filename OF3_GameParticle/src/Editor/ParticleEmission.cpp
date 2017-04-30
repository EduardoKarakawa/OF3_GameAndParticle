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

const ofVec2f ParticleEmission::GetOrigin() const { return m_positionOrigin; }
const ofVec2f ParticleEmission::GetDirection() const { return m_direction; }
const float ParticleEmission::GetOpenAngle() const { return m_openAngle; }
const float ParticleEmission::GetSpeed() const { return m_velocity; }
const float ParticleEmission::GetLifeTime() const { return m_maxLifeTime; }
const string ParticleEmission::GetSprite() const { return m_spriteLocal; }
const float ParticleEmission::GetSpawnTime() const { return m_timeSpawnParticle; }
const ofColor ParticleEmission::GetColor() const { return m_color; }
const float ParticleEmission::GetSizeParticle() const { return m_radius; }


void ParticleEmission::Setup(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, string sprite, float size)
{
	// Inicia os parametros da sistema de particula novo
	m_spriteLocal = sprite;
	m_spriteLocal = sprite;
	m_sprite.loadImage(m_spriteLocal);
	m_radius = size;
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
			// uInicializa a nova particula criada
			(m_particles.end()-1)->Setup(m_positionOrigin, m_direction, m_openAngle, m_velocity, m_maxLifeTime, m_color.a);

			m_spawnTimeCont -= m_timeSpawnParticle;
		}
	}
}


// Coloca em uma string todos os parametros do emissor de particula para salvar em um file
void ParticleEmission::SaveParticleConfig(std::string name) {

	

	/*ofstream file;
	file.open(name, std::ofstream::out);
	if (file.is_open()) {

		std::string out = "<Sprite> " + m_spriteLocal;
		out += "\n<Size> " + std::to_string(m_sprite.getWidth());
		out += "\n<Position> " + std::to_string(m_positionOrigin.x) + ' ' + std::to_string(m_positionOrigin.y);
		out += "\n<Direction> " + std::to_string(m_direction.x) + ' ' + std::to_string(m_direction.y);
		out += "\n<LifeTime> " + std::to_string(m_maxLifeTime);
		out += "\n<Velocity> " + std::to_string(m_velocity);
		out += "\n<TimeSpaw> " + std::to_string(m_spawnTimeCont);
		out += "\n<Color> " + std::to_string(m_color.r) + ' ' + std::to_string(m_color.g) + ' ' + std::to_string(m_color.b) + ' ' + std::to_string(m_color.a);

		file << out;

		file.close();
	}*/
}


//void ParticleEmission::SearchConfig(std::string father) {
//	
//}