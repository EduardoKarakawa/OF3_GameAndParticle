#include "BulletControl.h"

BulletControl::BulletControl()
{
	ofVec2f zero;
	zero.set(0, 0);
	bullet.push_back(new Bullet(zero, -1));
}

void BulletControl::Update(Player *gamePlayer, float deltaTime)
{
	// Verifica se o player atirou e cria um novo tiro
	if (gamePlayer->GetShooting())
	{
		gamePlayer->AddCounter();
		bullet.push_back(new Bullet(gamePlayer->GetPosition(), gamePlayer->GetArrowKey()));
	}

	// Verifica se exitem tiros para serem processados
	if (bullet.size() > 1)
	{
		// Percorre a lista de tiros para atualizar a posicao deles
		for (int i = 0; i < bullet.size(); i++)
		{
			bool bulletLife = true;
			bulletLife = bullet.at(i)->Update(deltaTime);
			// Percorre a lista de enemys para verificar a colisão com o tiro

			if (bulletLife == false) bullet.erase(bullet.begin() + i);
		}

	}

}

void BulletControl::Draw()
{
	if (bullet.size() > 1)
	{
		for (int i = 1; i < bullet.size(); i++)
		{
			bullet.at(i)->Draw();
		}
	}
}

// Elimina o tiro que colidiu com o enemy
void BulletControl::EraseBullet(int i)
{
	bullet.erase(bullet.begin() + i);
}

int BulletControl::GetVectorSize() const
{
	return bullet.size();
}

ofVec2f BulletControl::GetBulletPosition(int i) const
{
	if (i < bullet.size())
		return bullet.at(i)->GetPosition();
	else
		return ofVec2f(0, 0);
}
