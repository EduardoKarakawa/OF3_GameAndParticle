#include "EnemyControl.h"

EnemyControl::EnemyControl()
{
	lastTime = 0;
}

void EnemyControl::Update(int time, float deltaTime, ofVec2f playerPos, BulletControl *bullet)
{
	//Verfica se está no momento para criar novos inimigos
	if (time % 6 == 0 && time != lastTime)
	{
		lastTime = time;
		enemy.push_back(new Enemy(playerPos));
	}

	//Verifica se existem enemys para serem processados
	if (enemy.size() > 0)
	{
		// Percorre a lista de inimigos para atualizar a posição deles
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy.at(i)->Update(playerPos, deltaTime);
		}
	}

	//Percorre a lista de tiros
	for (int i = 0; i < bullet->GetVectorSize(); i++)
	{
		//Verifica se o tiro "i" colidiu com algum enemy
		for (int j = 0; j < enemy.size(); j++)
		{
			if (enemy.at(j)->enemyLife(bullet->GetBulletPosition(i)) == false)
			{
				//Se colidiu, elimina o inimigo e o tiro
				enemy.erase(enemy.begin() + j);
				bullet->EraseBullet(i);
			}
		}
	}
}

void EnemyControl::Draw()
{

	// Desenha os Inimigos
	if (enemy.size() > 0)
	{
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy.at(i)->Draw();
		}
	}
}
