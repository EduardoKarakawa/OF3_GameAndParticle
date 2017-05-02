#include "EnemyControl.h"

EnemyControl::EnemyControl()
{
	lastTime = 0;
}

void EnemyControl::Update(int time, float deltaTime, Player *player, GameStats *gameS)
{
	//Verfica se está no momento para criar novos inimigos
	if (time % 6 == 0 && time != lastTime)
	{
		lastTime = time;
		enemy.push_back(new Enemy(player->GetPosition()));
	}

	//Verifica se existem enemys para serem processados
	if (enemy.size() > 0)
	{
		// Percorre a lista de inimigos para atualizar a posição deles
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy.at(i)->Update(player->GetPosition(), deltaTime);

			// Verifica se o enemy colidiu com o player
			ofVec2f enePos = enemy.at(i)->GetPosition();
			if (enePos.distance(player->GetPosition()) < 30)
			{
				gameS->changeStats(3);
			}
		}
	}

	//Percorre a lista de tiros
	for (int i = 0; i < player->GetVectorBulSize(); i++)
	{
		//Verifica se o tiro "i" colidiu com algum enemy
		for (int j = 0; j < enemy.size(); j++)
		{
			if (enemy.at(j)->enemyLife(player->GetBulletPosition(i)) == false)
			{
				//Se colidiu, elimina o inimigo e o tiro
				enemy.erase(enemy.begin() + j);
				player->EraseBullet(i);
				i--;
				j--;
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

int EnemyControl::GetVectorSize() const
{
	return enemy.size();
}

ofVec2f EnemyControl::GetEnemyPos(int i) const
{
	return enemy.at(i)->GetPosition();
}
