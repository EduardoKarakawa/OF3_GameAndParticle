#include "EnemyControl.h"

EnemyControl::EnemyControl()
{
	m_timeCount = 0;
}

void EnemyControl::Update( float &deltaTime, Player &player, GameStats &gameS)
{
	m_timeCount += m_timeCount < TIME_SPAWN ? deltaTime : 0;

	//Verfica se está no momento para criar novos inimigos
	if (m_timeCount > TIME_SPAWN)
	{
		m_timeCount -= TIME_SPAWN;
		enemy.push_back(Enemy(player.GetPosition()));
	}

	//Verifica se existem enemys para serem processados
	if (enemy.size() > 0)
	{
		// Percorre a lista de inimigos para atualizar a posição deles
		for (int i = 0; i < enemy.size(); i++)
		{

			enemy.at(i).Update(player.GetPosition(), deltaTime);

			// Verifica se o enemy colidiu com o player
			ofVec2f enePos = enemy.at(i).GetPosition();
			if (enePos.distance(player.GetPosition()) < 30)
			{

				gameS.ChangeStats(0);

			}

		}


		// Verifica colisao da chama do player com os inimigos
		ParticleEmission flame = player.GetShotParticle();
		if (flame.IsEnable()) {
			//Verifica se o tiro "i" colidiu com algum enemy
			for (int j = 0; j < enemy.size(); j++)
			{
				if (flame.CollidedWith(enemy.at(j).GetPosition(), 13.5f))
				{
					//Se colidiu, elimina o inimigo e o tiro
					enemy.erase(enemy.begin() + j);
					j--;
				}
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
			enemy.at(i).Draw();
		}
	}
}

int EnemyControl::GetVectorSize() const
{
	return enemy.size();
}

ofVec2f EnemyControl::GetEnemyPos(int i) const
{
	return enemy.at(i).GetPosition();
}
