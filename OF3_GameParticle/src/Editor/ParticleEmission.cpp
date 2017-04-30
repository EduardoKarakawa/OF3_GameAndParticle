#include "ParticleEmission.h"

ParticleEmission::ParticleEmission(){}
ParticleEmission::~ParticleEmission(){}
ParticleEmission::ParticleEmission(std::string tag, ofVec2f * fatherPosition) {
	m_fatherPosition = fatherPosition;
	m_spriteLocal = "/sprites/particula.png";
	m_sprite.loadImage(m_spriteLocal);
	m_sprite.resize(10, 10);
	m_positionOrigin = ofVec3f(100,100);
	SetDirection(ofVec3f(-1,1));
	m_openAngle = 75;
	m_maxLifeTime = 5;
	m_velocity = 50;
	m_timeSpawnParticle = 0.1;
	m_spawnTimeCont = 0;
	m_enableParticles = true;
	m_color = ofColor(255, 255, 255);
}
void ParticleEmission::SetOrigin(ofVec2f origin)			{ m_positionOrigin = origin; }
void ParticleEmission::SetDirection(ofVec2f direction)		{ m_direction = direction; }
void ParticleEmission::SetOpenAngle(float openAngle)		{ m_openAngle = openAngle; }
void ParticleEmission::SetSpeed(float speed)				{ m_velocity = speed; }
void ParticleEmission::SetLifeTime(float lifeTime)			{ m_maxLifeTime = lifeTime; }
void ParticleEmission::SetSprite(string sprite)				{ m_sprite.loadImage(sprite); }
void ParticleEmission::SetSpawnTime(float timeSpawn)		{ m_timeSpawnParticle = timeSpawn; }
void ParticleEmission::SetColor(ofColor color)				{ m_color = color; }
void ParticleEmission::SetSizeParticle(float radius)		{ m_sprite.resize(radius, radius); }


ParticleEmission::ParticleEmission(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, string sprite, float size)
{
	// Inicia os parametros da sistema de particula novo
	m_spriteLocal = sprite;
	m_sprite.loadImage(m_spriteLocal);
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
			if (m_fatherPosition != nullptr) {
				aux->Update(*m_fatherPosition + m_positionOrigin, deltaTime);
			}
			else {
				aux->Update(m_positionOrigin, deltaTime);
			}

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
			if (m_fatherPosition == nullptr) {
				aux->Draw(m_sprite, m_color, *m_fatherPosition + m_positionOrigin);
			}
			else {
				aux->Draw(m_sprite, m_color, m_positionOrigin);
			}
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
	ofstream file;
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
	}
}



// Funcao para procurar uma configuracao de particula
ParticleEmission * ParticleEmission::SearchConfig(std::string tag, ofVec2f * fatherPosition) {
	std::string path = "particles";
	ofDirectory directory(path);

	// A variavel director so ira pegar os arquivos com extensao ".txt"
	directory.allowExt("txt");
	directory.listDir();

	// Verifica se o foi possivel abrir o directorio e se tem algum arquivo
	if (directory.isDirectory() && directory.size() > 0) {
		for (int i = 0; i < directory.size(); i++) {
			std::string location = directory.getAbsolutePath() + "\\" + directory.getName(i);
			std::ifstream file(location);
			std::string isTag, theTag;

			file >> isTag >> theTag;

			// Verifica as tags
			if (isTag == "<Tag>" && theTag == tag) {
				return new ParticleEmission(tag, fatherPosition);
			}
			else {
				std::cout << "Nao carregou" << std::endl;
			}
		}
	}

	return nullptr;
}