#pragma once
#include "ParticleEmission.h"
#include "Storage.h"


ParticleEmission::~ParticleEmission() {}
void ParticleEmission::SetOrigin(ofVec2f origin)						{ m_position = origin; }
void ParticleEmission::SetDirection(ofVec2f direction)					{ m_direction = direction; }
void ParticleEmission::SetOpenAngle(float openAngle)					{ m_openAngle = openAngle; }
void ParticleEmission::SetSpeed(float speed)							{ m_velocity = speed; }
void ParticleEmission::SetLifeTime(float lifeTime)						{ m_maxLifeTime = lifeTime; }
void ParticleEmission::SetSpawnTime(float timeSpawn)					{ m_timeSpawnParticle = timeSpawn; }
void ParticleEmission::SetParticleProcess(bool process)					{ m_enableParticles = process; }
void ParticleEmission::SetFatherTag(std::string fatherTag)				{ m_fatherTag = fatherTag; }
void ParticleEmission::SetEnable(bool value)							{ m_enableParticles = value; }
void ParticleEmission::SetTotalOfSpawnParticle(int total)				{ m_totalByTime = total; }
void ParticleEmission::SetRandomDirection(bool value)					{ m_randomDirection = value; }
void ParticleEmission::SetInitialColor(const ofColor& initialColor )	{ m_initialColor = initialColor; }
void ParticleEmission::SetFinalColor(const ofColor& finalColor)			{ m_finalColor = finalColor; }

// Getters pra poder pegar os valores e salvar

const ofVec2f& ParticleEmission::GetOrigin() const				{ return m_position; }
const bool& ParticleEmission::IsRamdomSpawn() const				{ return m_randomDirection; }
const ofVec2f& ParticleEmission::GetDirection() const			{ return m_direction; }
const float& ParticleEmission::GetOpenAngle() const				{ return m_openAngle; }
const float& ParticleEmission::GetSpeed() const					{ return m_velocity; }
const float& ParticleEmission::GetLifeTime() const				{ return m_maxLifeTime; }
const std::string& ParticleEmission::GetSprite() const			{ return m_spriteLocal; }
const float& ParticleEmission::GetSpawnTime() const				{ return m_timeSpawnParticle; }
const float& ParticleEmission::GetSizeParticle() const			{ return m_radius; }
const std::string& ParticleEmission::GetFatherTag() const		{ return m_fatherTag; }
const bool& ParticleEmission::IsEnable() const					{ return m_enableParticles; }
const int& ParticleEmission::GetTotalOfSpawnParticle() const	{ return m_totalByTime; }
const ofColor& ParticleEmission::GetInialColor() const			{ return m_initialColor; }
const ofColor& ParticleEmission::GetFinalColor() const			{ return m_finalColor; }

void ParticleEmission::SetSprite(std::string sprite) {
	m_spriteLocal = sprite;
	m_chageSize = true;
}

void ParticleEmission::SetSizeParticle(float radius) {
	m_radius = radius;
	m_chageSize = true;
}


ParticleEmission::ParticleEmission(){
	// Inicia os parametros da sistema de particula novo
	m_fatherPosition = nullptr;
	m_fatherTag = "";
	m_spriteLocal = "/sprites/particula.png";
	m_sprite.loadImage(m_spriteLocal);
	m_radius = 10;
	m_sprite.resize(m_radius, m_radius);
	m_position = ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
	m_direction.set(m_position.x, m_position.y);
	m_openAngle = 45;
	m_maxLifeTime = 10;
	m_velocity = 10;
	m_timeSpawnParticle = 0.2f;
	m_spawnTimeCont = 0;
	m_enableParticles = true;
	m_initialColor = m_finalColor = ofColor(255, 255, 255);
	m_particles.clear();
	m_particlesDead.clear();
	m_timeCountSweep = 0;
	m_totalByTime = 1;
	m_chageSize = false;
}

ParticleEmission::ParticleEmission(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, std::string sprite, float size)
{
	// Inicia os parametros da sistema de particula novo
	m_fatherPosition = nullptr;
	m_fatherTag = "";
	m_spriteLocal = sprite;
	m_sprite.loadImage(m_spriteLocal);
	m_radius = size;
	m_sprite.resize(m_radius, m_radius);
	m_position = ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
	m_direction.set(m_position.x, m_position.y);
	m_direction.set(direction);
	m_openAngle = openAngle;
	m_maxLifeTime = lifeTime;
	m_velocity = speed;
	m_timeSpawnParticle = timeSpawn;
	m_spawnTimeCont = 0;
	m_enableParticles = true;
	m_initialColor = m_finalColor = ofColor(255, 255, 255);
	m_particles.clear();
	m_particlesDead.clear();
	m_timeCountSweep = 0;
	m_totalByTime = 1;
	m_chageSize = false;
}

ParticleEmission::ParticleEmission(ofVec2f position, ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, std::string sprite, float size, ofColor& color)
{
	// Inicia os parametros da sistema de particula novo
	m_fatherPosition = nullptr;
	m_fatherTag = "";
	m_spriteLocal = sprite;
	m_sprite.loadImage(m_spriteLocal);
	m_radius = size;
	m_sprite.resize(m_radius, m_radius);
	m_position = position;
	m_direction.set(m_position.x, m_position.y);
	m_direction.set(direction);
	m_openAngle = openAngle;
	m_maxLifeTime = lifeTime;
	m_velocity = speed;
	m_timeSpawnParticle = timeSpawn;
	m_spawnTimeCont = 0;
	m_enableParticles = true;
	m_initialColor = m_finalColor = color;
	m_particles.clear();
	m_particlesDead.clear();
	m_timeCountSweep = 0;
	m_totalByTime = 1;
	m_chageSize = false;
}

ParticleEmission::ParticleEmission(ofVec2f position, ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, std::string sprite, float size, ofColor& initialColor, ofColor& finalColor)
{
	// Inicia os parametros da sistema de particula novo
	m_fatherPosition = nullptr;
	m_fatherTag = "";
	m_spriteLocal = sprite;
	m_sprite.loadImage(m_spriteLocal);
	m_radius = size;
	m_sprite.resize(m_radius, m_radius);
	m_position = position;
	m_direction.set(m_position.x, m_position.y);
	m_direction.set(direction);
	m_openAngle = openAngle;
	m_maxLifeTime = lifeTime;
	m_velocity = speed;
	m_timeSpawnParticle = timeSpawn;
	m_spawnTimeCont = 0;
	m_enableParticles = true;
	m_initialColor = initialColor;
	m_finalColor = finalColor;
	m_particles.clear();
	m_particlesDead.clear();
	m_timeCountSweep = 0;
	m_totalByTime = 1;
	m_chageSize = false;
}

void ParticleEmission::Update(const float &deltaTime)
{

	if (m_chageSize) {
		m_sprite.loadImage(m_spriteLocal);
		m_sprite.resize(m_radius, m_radius);
		m_chageSize = false;
	}
	// Atualiza a lista de particulas do sistema de particula, chama o DestroyParticle se a particula atingiu o tempo maximo de vida
	// cria uma nova particula caso o tempo ultrapasse o tempo de spawn
	m_spawnTimeCont += deltaTime;
	m_timeCountSweep += deltaTime;

	// Percorre a lista de particulas atualizando a posicao das que estao vivas
	if (m_particles.size() > 0) {
		ofVec2f windowSize(ofGetWidth(), ofGetHeight());
		// Verifica as particulas que ultrapassaram o tempo maximo de vida e exclui eles do vetor
		for (int i = 0; i < m_particles.size(); i++) {

			// Atualiza a particula a particula que estiver viva
			if (m_particles[i].IsLife() && m_particles[i].OnScreen(windowSize.x, windowSize.y)) {
				m_particles[i].Update(deltaTime);
			}
			else {
				bool adicinar = true;
				for (int j : m_particlesDead) {
					if (j == i) {
						adicinar = false;
					}
				}
				if (adicinar) m_particlesDead.push_back(i);
			}
		}
	}
	ListSweeping(false);

	if (m_enableParticles) {
		CreateParticle();
	}

}

void ParticleEmission::Update(const float &deltaTime, ofVec2f *fatherPosition) {

	if (m_chageSize) {
		m_sprite.loadImage(m_spriteLocal);
		m_sprite.resize(m_radius, m_radius);
		m_chageSize = false;
	}
	// Atualiza a lista de particulas do sistema de particula, chama o DestroyParticle se a particula atingiu o tempo maximo de vida
	// cria uma nova particula caso o tempo ultrapasse o tempo de spawn
	m_spawnTimeCont += deltaTime;
	m_timeCountSweep += deltaTime;

	m_fatherPosition = fatherPosition;

	ofVec2f position = *fatherPosition + m_position;
	// Percorre a lista de particulas atualizando a posicao das que estao vivas
	if (m_particles.size() > 0) {
		ofVec2f windowSize(ofGetWidth(), ofGetHeight());


		// Verifica as particulas que ultrapassaram o tempo maximo de vida e exclui eles do vetor
		for (int i = 0; i < m_particles.size(); i++) {

			// Atualiza a particula a particula que estiver viva
			if (m_particles[i].IsLife() && m_particles[i].OnScreen(windowSize.x, windowSize.y)) {
				m_particles[i].Update(deltaTime);

			}
			else {
				bool adicinar = true;
				for (int j : m_particlesDead) {
					if (j == i) {
						adicinar = false;
					}
				}
				if (adicinar) m_particlesDead.push_back(i);
			}
		}
	}
	ListSweeping(false);

	if (m_enableParticles) {
		CreateParticle(*fatherPosition);
	}

}

void ParticleEmission::Draw()
{

	if (m_particles.size() > 0) {
		ofVec2f windowSize(ofGetWidth(), ofGetHeight());
		// Percorre a lista de particular desenhando elas
		std::vector<Particle>::iterator aux;	// Iterator para percorrer a lista de particles
		for (aux = m_particles.begin(); aux != m_particles.end(); aux++) {
			if (aux->OnScreen(windowSize.x, windowSize.y)) {
				aux->Draw(m_sprite);
			}
		}
	}


}

void ParticleEmission::CreateParticle()
{
	// Cria uma particula se ja tiver passado o tempo necessario para criar uma
	if (m_spawnTimeCont > m_timeSpawnParticle) {
		int tmp = m_randomDirection ? (m_spawnTimeCont / m_timeSpawnParticle) * m_totalByTime : m_totalByTime;

		
		float auxAngle = tmp > 1 ? (m_openAngle / tmp) * PI / 180.0f : 0;
		float auxCont = -auxAngle * (tmp - 1) / 2.0f;
		
		if (m_particlesDead.size() > 0) {
			for (int i = 0; i < m_particlesDead.size(); i++) {
				// Inicializa a particula que esta morta
				if (tmp > 0) {
					if (m_randomDirection) {
						auxAngle = (-m_openAngle / 2.0f + rand() % (int)m_openAngle) * PI / 180.0f;
						m_particles[m_particlesDead[i]] = Particle(m_position, m_direction, auxAngle, m_velocity, m_maxLifeTime, m_initialColor, m_finalColor);
					}
					else {
						m_particles[m_particlesDead[i]] = Particle(m_position, m_direction, auxCont, m_velocity, m_maxLifeTime, m_initialColor, m_finalColor);
					}
					m_particlesDead.erase(m_particlesDead.begin() + i); 
					auxCont += auxAngle;
					tmp--;
				}
				else {
					m_spawnTimeCont = 0;
					break;
				}
			}
		}	
			 //Se nao particulas mortas, entao tem que ser criada uma
		while (tmp > 0) {
			if (m_randomDirection) {

				auxAngle = (-m_openAngle / 2.0f + rand() % (int)m_openAngle) * PI / 180.0f;
				m_particles.push_back(Particle(m_position, m_direction, auxAngle * tmp, m_velocity, m_maxLifeTime, m_initialColor, m_finalColor));
			}
			else {
				m_particles.push_back(Particle(m_position, m_direction, auxCont, m_velocity, m_maxLifeTime, m_initialColor, m_finalColor));
			}
			auxCont += auxAngle;
			auxCont *= -1;
			tmp--;
		}
		m_spawnTimeCont = 0;
	}

}

void ParticleEmission::CreateParticle(ofVec2f const &fatherPosition) {

	// Cria uma particula se ja tiver passado o tempo necessario para criar uma
		if (m_spawnTimeCont > m_timeSpawnParticle) {
			int tmp = m_randomDirection ? (m_spawnTimeCont / m_timeSpawnParticle) * m_totalByTime : m_totalByTime;

			float auxAngle = tmp > 1 ? (m_openAngle / tmp) * PI / 180.0f : 0;
			float auxCont = -auxAngle * (tmp - 1) / 2.0f;

			ofVec2f direction = m_direction + m_position + fatherPosition;
			ofVec2f position = m_position + fatherPosition;

			if (m_particlesDead.size() > 0) {
				for (int i = 0; i < m_particlesDead.size(); i++) {
					// Inicializa a particula que esta morta
					if (tmp > 0) {
						if (m_randomDirection) {
							auxAngle = (-m_openAngle / 2.0f + rand() % (int)m_openAngle) * PI / 180.0f;
							m_particles[m_particlesDead[i]] = Particle(position, direction, auxAngle, m_velocity, m_maxLifeTime, m_initialColor, m_finalColor);
						}
						else {
							m_particles[m_particlesDead[i]] = Particle(position, direction, auxCont, m_velocity, m_maxLifeTime, m_initialColor, m_finalColor);
						}
						m_particlesDead.erase(m_particlesDead.begin() + i);
						auxCont += auxAngle;
						tmp--;
					}
					else {
						m_spawnTimeCont = 0;
						break;
					}
				}
			}
			//Se nao particulas mortas, entao tem que ser criada uma
			while (tmp > 0) {
				if (m_randomDirection) {

					auxAngle = (-m_openAngle / 2.0f + rand() % (int)m_openAngle) * PI / 180.0f;
					m_particles.push_back(Particle(position, direction, auxAngle * tmp, m_velocity, m_maxLifeTime, m_initialColor, m_finalColor));
				}
				else {
					m_particles.push_back(Particle(position, direction, auxCont, m_velocity, m_maxLifeTime, m_initialColor, m_finalColor));
				}
				auxCont += auxAngle;
				auxCont *= -1;
				tmp--;
			}
			m_spawnTimeCont = 0;
		}

}

void ParticleEmission::ListSweeping(bool speegin) {
	// A cada x segundos eh feito uma limpeza nos vectors de particula
	// Essa funcao tbm sera usada na GUI.cpp para limpar
	if (m_timeCountSweep > 30.0f || speegin) {
		for (int i = 0; i < m_particles.size(); i++) {
			if (!m_particles[i].IsLife()) {
				m_particles.erase(m_particles.begin() + i);
			}
		}
		m_particlesDead.clear();
		m_timeCountSweep = 0;
	}

}

// Funcao para procurar uma configuracao de particula
void ParticleEmission::SearchParticleConfig(std::string tag) {
	std::string path = "particles";
	ofDirectory directory(path);

	// A variavel director so ira pegar os arquivos com extensao ".txt"
	directory.allowExt("xml");
	directory.listDir();

	// Verifica se o foi possivel abrir o directorio e se tem algum arquivo
	if (directory.isDirectory() && directory.size() > 0) {
		for (int i = 0; i < directory.size(); i++) {
			std::string location = directory.getAbsolutePath() + "\\" + directory.getName(i);
			ofXml file(location);

			// Verifica as tags e carrega os parametros
			if (file.getValue<string>("Father") == tag) {
				if (file.getName() == "EMITTER") {
					if (file.exists("Father")) {
						SetFatherTag(file.getValue<string>("Father"));
					}
					if (file.exists("Sprite")) {
						SetSprite(file.getValue<string>("Sprite"));
					}
					if (file.exists("Size")) {
						SetSizeParticle(file.getValue<float>("Size"));
					}
					if (file.exists("TotalSpawn")) {
						SetTotalOfSpawnParticle(file.getValue<int>("TotalSpawn"));
					}
					if (file.exists("RandomSpawn")) {
						SetRandomDirection(file.getValue<bool>("RandomSpawn"));
					}
					if (file.exists("Position")) {
						SetOrigin(file.getValue<ofVec2f>("Position"));
					}
					if (file.exists("Direction")) {
						SetDirection(file.getValue<ofVec2f>("Direction"));
					}
					if (file.exists("OpenAngle")) {
						SetOpenAngle(file.getValue<float>("OpenAngle"));
					}
					if (file.exists("Lifetime")) {
						SetLifeTime(file.getValue<float>("Lifetime"));
					}
					if (file.exists("Velocity")) {
						SetSpeed(file.getValue<float>("Velocity"));
					}
					if (file.exists("TimeSpawn")) {
						SetSpawnTime(file.getValue<float>("TimeSpawn"));
					}
					if (file.exists("InitialColor")) {
						SetInitialColor(file.getValue<ofColor>("InitialColor"));
					}
					if (file.exists("FinalColor")) {
						SetFinalColor(file.getValue<ofColor>("FinalColor"));
					}
				}
				break;
			}
		}
	}

}

// Verifica colisao de um objeto com o a area do cone de emissao de particula
const bool& ParticleEmission::CollidedWith(const ofVec2f &other, float size) const {
	bool collided = false;
	float baseDistance = m_velocity * m_maxLifeTime / 2.0f;
	float angleOther, angleDir, midopen;

	// Calculo para emissor que depende de outro objeto
	if (m_fatherPosition != nullptr) {
		// Verifica a distancia
		if (other.distance(*m_fatherPosition + m_position) <= baseDistance + size) {

			angleOther = atan2f((m_fatherPosition->y + m_position.y) - other.y,
								(m_fatherPosition->x + m_position.x) - other.x) * 180 / PI + 180;

			angleDir = atan2f(	(m_fatherPosition->y + m_position.y) - (m_fatherPosition->y + m_direction.y),
								(m_fatherPosition->x + m_position.x) - (m_fatherPosition->x + m_direction.x)) * 180 / PI + 180;

			midopen = m_openAngle / 2.0f;
			collided = angleOther >= (angleDir - midopen) && angleOther <= (angleDir + midopen);
		}
	}
	// Calculo para emissor que nao depende de outro objeto 
	else {
		if (other.distance(m_position) <= baseDistance + size) {
			angleOther = atan2f(m_position.y - other.y, m_position.x - other.x) * 180 / PI;
			angleDir = atan2f(m_position.y - m_direction.y, m_position.x - m_direction.x) * 180 / PI;
			midopen = m_openAngle / 2.0f;
			collided = angleOther >= (angleDir - midopen) && angleOther <= (angleDir + midopen);
		}
	}
	return collided;
}