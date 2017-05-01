#include "ParticleEmission.h"


ParticleEmission::~ParticleEmission(){}
void ParticleEmission::SetOrigin(ofVec2f origin)			{ m_positionOrigin = origin; }
void ParticleEmission::SetDirection(ofVec2f direction)		{ m_direction = direction; }
void ParticleEmission::SetOpenAngle(float openAngle)		{ m_openAngle = openAngle; }
void ParticleEmission::SetSpeed(float speed)				{ m_velocity = speed; }
void ParticleEmission::SetLifeTime(float lifeTime)			{ m_maxLifeTime = lifeTime; }
void ParticleEmission::SetSprite(string sprite)				{ m_sprite.loadImage(sprite); }
void ParticleEmission::SetSpawnTime(float timeSpawn)		{ m_timeSpawnParticle = timeSpawn; }
void ParticleEmission::SetColor(ofColor color)				{ m_color = color; }
void ParticleEmission::SetSizeParticle(float radius)		{ m_radius = radius; }



//criei metodos getters pra poder pegar os valores e salvar

const ofVec2f ParticleEmission::GetOrigin() const { return m_positionOrigin; }
const ofVec2f ParticleEmission::GetDirection() const { return m_direction; }
const float ParticleEmission::GetOpenAngle() const { return m_openAngle; }
const float ParticleEmission::GetSpeed() const { return m_velocity; }
const float ParticleEmission::GetLifeTime() const { return m_maxLifeTime; }
const string ParticleEmission::GetSprite() const { return m_spriteLocal; }
const float ParticleEmission::GetSpawnTime() const { return m_timeSpawnParticle; }
const ofColor ParticleEmission::GetColor() const { return m_color; }
const float ParticleEmission::GetSizeParticle() const { return m_radius; }
const std::string ParticleEmission::GetFatherTag() const { return m_fatherTag; }


ParticleEmission::ParticleEmission(std::string tag, ofVec2f * fatherPosition) {
	m_fatherPosition = fatherPosition;
	m_fatherTag = tag;
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
	m_particles.clear();
	m_particlesDead.clear();
	m_timeCountSweep = 0;
}


ParticleEmission::ParticleEmission(){
	// Inicia os parametros da sistema de particula novo
	m_spriteLocal = "/sprites/particula.png";
	m_sprite.loadImage(m_spriteLocal);
	m_radius = 10;
	m_sprite.resize(m_radius, m_radius);
	m_positionOrigin.set(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
	m_direction.set(m_positionOrigin.x - 1, m_positionOrigin.y);
	m_openAngle = 45;
	m_maxLifeTime = 10;
	m_velocity = 10;
	m_timeSpawnParticle = 0.2f;
	m_spawnTimeCont = 0;
	m_enableParticles = true;
	m_color = ofColor(255, 255, 255);
	m_particles.clear();
	m_particlesDead.clear();
	m_timeCountSweep = 0;
}


ParticleEmission::ParticleEmission(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, string sprite, float size)
{
	// Inicia os parametros da sistema de particula novo
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
	m_particles.clear();
	m_particlesDead.clear();
	m_timeCountSweep = 0;
}


void ParticleEmission::Update(float deltaTime)
{
	m_sprite.resize(m_radius, m_radius);

	if (m_enableParticles) {
		// Atualiza a lista de particulas do sistema de particula, chama o DestroyParticle se a particula atingiu o tempo maximo de vida
		// cria uma nova particula caso o tempo ultrapasse o tempo de spawn
		m_spawnTimeCont += ofGetLastFrameTime();
		m_timeCountSweep += ofGetLastFrameTime();

		// Percorre a lista de particulas atualizando a posicao das que estao vivas
		if (m_particles.size() > 0) {

			// Verifica as particulas que ultrapassaram o tempo maximo de vida e exclui eles do vetor
			for (int i = 0; i < m_particles.size(); i++) {

				// Atualiza a particula a particula que estiver viva
				if (m_particles[i].IsLife()) {
					m_particles[i].Update(m_positionOrigin, deltaTime);
				}		
				else {
					bool adicinar = true;
					for (int j : m_particlesDead) {
						if (j == i) {
							adicinar = false;
						}
					}
					if(adicinar) m_particlesDead.push_back(i);
				}
			}
		}
		ListSweeping(false);
		CreateParticle();
	}

}


void ParticleEmission::Draw()
{
	ofDrawBitmapString("Tamanho do Vector de Particle: " + ofToString(m_particles.size()), 30, 500);
	ofDrawBitmapString("Particulas Mortas para Resetar: " + ofToString(m_particlesDead.size()), 30, 530);
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
		int tmp = m_spawnTimeCont / m_timeSpawnParticle;

		if (m_particlesDead.size() > 0) {
			//std::cout << m_particlesDead.size()  << "  "  << tmp << std::endl;
			for (int i = 0; i < m_particlesDead.size(); i++) {
				/*std::cout << "Resetou uma particula" << std::endl;*/
				// Inicializa a particula que esta morta
				if (tmp > 0) {
					m_particles[m_particlesDead[i]] = Particle(m_positionOrigin, m_direction, m_openAngle, m_velocity, m_maxLifeTime, m_color.a);
					m_particlesDead.erase(m_particlesDead.begin() + i);
					tmp--;
					m_spawnTimeCont -= m_timeSpawnParticle;
				}
				else {
					break;
				}
			}
		}
		else{
			 //Se nao particulas mortas, entao tem que ser criada uma
			for (int i = 0; i < tmp; i++) {
				//std::cout << "Criou uma particula nova" << std::endl;
				m_particles.push_back(Particle(m_positionOrigin, m_direction, m_openAngle, m_velocity, m_maxLifeTime, m_color.a));
				m_spawnTimeCont -= m_timeSpawnParticle;
			}
		}
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


//// Funcao para procurar uma configuracao de particula
//ParticleEmission * ParticleEmission::SearchConfig(std::string tag, ofVec2f * fatherPosition) {
//	std::string path = "particles";
//	ofDirectory directory(path);
//
//	// A variavel director so ira pegar os arquivos com extensao ".txt"
//	directory.allowExt("txt");
//	directory.listDir();
//
//	// Verifica se o foi possivel abrir o directorio e se tem algum arquivo
//	if (directory.isDirectory() && directory.size() > 0) {
//		for (int i = 0; i < directory.size(); i++) {
//			std::string location = directory.getAbsolutePath() + "\\" + directory.getName(i);
//			std::ifstream file(location);
//			std::string isTag, theTag;
//
//			file >> isTag >> theTag;
//
//			// Verifica as tags
//			if (isTag == "<Tag>" && theTag == tag) {
//				return new ParticleEmission(tag, fatherPosition);
//			}
//			else {
//				std::cout << "Nao carregou" << std::endl;
//			}
//		}
//	}
//
//	return nullptr;
//}