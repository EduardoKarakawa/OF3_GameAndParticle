#include "GameObject.h"

GameObject::GameObject()
{
	frameIndex = 0;
	m_iFrame = frameIndex;
	m_sequenceFPS = 12;
}


// Carrega uma nova imagem
void GameObject::LoadNewImage(string folder, string image)
{
	m_image.load(folder + "/" + image);
	std::cout << "Load image: " << image << std::endl;
}


// Carrega uma animacao
void GameObject::LoadNewAnimation(string folder)
{
	//Pega o tatal de imagens na pasta
	int nImage = m_dir.listDir(folder);

	if (nImage) {
		// Percorre o diretorio acrescentando as imagens no vector de imagens
		for (int i = 0; i < m_dir.size(); i++) {
			string filePath = m_dir.getPath(i);
			m_images.push_back(ofImage());
			m_images.back().load(filePath);
		}

		std::cout << "Load folder: " << folder << std::endl;

	}
	// Se nImage
	else ofLog(OF_LOG_WARNING) << "Could not find folder " << folder;

}


// Desenha na posicao atual
void GameObject::DrawImage()
{
	m_image.draw(m_position.x, m_position.y, m_width, m_height);
}


// Desenha a imagem em uma posicao passada por parametro
void GameObject::DrawImage(int x, int y)
{
	m_position.set(x, y);
	m_image.draw(m_position.x, m_position.y, m_width, m_height);
}


// Desenha um sprite na posicao atual
// baseando no tempo decorrido 
void GameObject::DrawAnimation()
{
	if ((int)m_images.size() <= 0) {
		ofSetColor(255);
		ofDrawBitmapString("No Images...", 150, ofGetHeight() / 2);
	}

	m_iFrame = (int)(ofGetElapsedTimef() * m_sequenceFPS) % m_images.size();
	m_images[m_iFrame].draw(m_position.x, m_position.y, m_width, m_height);
}


// Desenha um sprite em uma posicao passada por parametro
// baseando no tempo decorrido 
void GameObject::DrawAnimation(int x, int y)
{
	if ((int)m_images.size() <= 0) {
		ofSetColor(255);
		ofDrawBitmapString("No Images...", 150, ofGetHeight() / 2);
	}

	m_iFrame = (int)(ofGetElapsedTimef() * m_sequenceFPS) % m_images.size();
	m_images[m_iFrame].draw(x, y, m_width, m_height);
}

// Desenha um sprite em uma posicao e com um tamanho passada por parametro
// baseando no tempo decorrido 
void GameObject::DrawAnimation(int x, int y, int w, int h)
{
	if ((int)m_images.size() <= 0) {
		ofSetColor(255);
		ofDrawBitmapString("No Images...", 150, ofGetHeight() / 2);
	}

	m_iFrame = (int)(ofGetElapsedTimef() * m_sequenceFPS) % m_images.size();
	m_images[m_iFrame].draw(x, y, w, h);
}

// Desenha um sprite passando o index por parametro
void GameObject::DrawAnimationFrame(int frame)
{
	m_images[frame].draw(m_position.x, m_position.y, m_width, m_height);
}


// Funcao para pegar a posicao atual do gameObject
ofVec2f GameObject::GetPosition() const {
	return m_position;
}

// Funcao para alterar a posicao atual do gameOmbject
void GameObject::SetPosition(ofVec2f &position) {
	m_position = position;
}


// Verifica se o GameObject esta dentro da tela
bool GameObject::OnScreen() {
	return m_position.x <= ofGetWidth() && m_position.x >= 0 && m_position.y <= ofGetHeight() && m_position.y >= 0;
}