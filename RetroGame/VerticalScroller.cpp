#include "Includes\VerticalScroller.h"
#include "Includes/Scene.h"
#include "Includes/EnemyFactory.h"
#include <cmath>


VerticalScroller::VerticalScroller(Scene* a_Scene)
{
	//Initialise variables
	m_scene = a_Scene;
	m_mapHeight = 8;
	m_scrollSpeed = 0.1f;
	m_lowerScrollPos = 16.0f * (15.0f * m_mapHeight);
	m_upperScrollPos = 16.0f * (15.0f * (m_mapHeight - 1.0f));
}

VerticalScroller::~VerticalScroller()
{
	m_scene = nullptr;
}

bool VerticalScroller::LoadLevel(const char* a_filename)
{
	//If Level is not null then delete it to free up memory and allow new one to be loaded
	if (m_map != nullptr)
	{
		delete[] m_map;
		m_map = nullptr;
	}

	//open the Level map from file
	std::fstream levelFile;
	levelFile.open(a_filename, std::ios_base::in | std::ios_base::binary);
	//test to see if the file has opened correctly
	if (levelFile.is_open())
	{
		levelFile.ignore(std::numeric_limits<std::streamsize>::max());
		std::streamsize fileSize = levelFile.gcount();
		levelFile.clear();
		levelFile.seekg(0, std::ios_base::beg);
		if (fileSize == 0)
		{
			levelFile.close();
			return false;
		}
		//read in the width and Height of the level map
		levelFile >> m_mapWidth >> m_mapHeight;
		levelFile.ignore(1); //ignore end of line marker
		//allocate memory to hold all map data
		m_map = new int[m_mapWidth * m_mapHeight];
		int index = 0;
		//read each line of the file to get one row worth of map data
		//use getline to read in each line of the file
		for (std::string currentMapLine; std::getline(levelFile, currentMapLine);)
		{
			//convert string from getline into stringstram and use comma separator to break into chuncks and store values in map
			std::istringstream ss{ currentMapLine };
			int val = 0;
			while (ss >> val)
			{	
				//if there is still data to read store int value temporarily then static cast to u8 otherwise we read vaues as char
				m_map[index] = (int)(val);
				++index;
				if ((ss >> std::ws).peek() == ',') // std::ws ignores the white space and commas
				{
					ss.ignore();
				}
			}
		}
		//close the file
		levelFile.close();

		return true;
	}
	return false;
}

void VerticalScroller::SpawnEntityRow(bool UpperMarker)
{
	//Spawn Enemies that come down from top of screen
	int RowEnd = m_upperScrollPos;
	int rowStart = RowEnd - 15;
	for (int i = 0; i < 16; i++)	//Search the row for enemies to spawn
	{
		if (m_map[rowStart + i] == 1)	//Spawn Enemy based on integer value - Enemy numerical List stored in header
		{
			m_scene->GetEnemyFactory()->CreateEnemy(Parent, m_scene, { 0.0f + (i * 16), 0.0f });
		}
		if (m_map[rowStart + i] == 3)
		{
			m_scene->GetEnemyFactory()->CreateEnemy(CrosserR, m_scene, { 0.0f + (i * 16), 0.0f });
		}
		if (m_map[rowStart + i] == 4)
		{
			m_scene->GetEnemyFactory()->CreateEnemy(CrosserL, m_scene, { 0.0f + (i * 16), 0.0f });
		}
		if (m_map[rowStart + i] == 5)
		{
			m_scene->GetEnemyFactory()->CreateEnemy(FighterD, m_scene, { 0.0f + (i * 16), 0.0f });
		}
		if (m_map[rowStart + i] == 7)
		{
			m_scene->GetEnemyFactory()->CreateEnemy(Missile, m_scene, { 0.0f + (i * 16), 0.0f });
		}
		if (m_map[rowStart + i] == 8)
		{
			m_scene->GetEnemyFactory()->CreateEnemy(Scatter, m_scene, { 0.0f + (i * 16), 0.0f });
		}
		if (m_map[rowStart + i] == 9)
		{
			m_scene->GetEnemyFactory()->CreateEnemy(PlayerPowerup, m_scene, { 0.0f + (i * 16), 0.0f });
		}
		if (m_map[rowStart + i] == 10)
		{
			m_scene->GetEnemyFactory()->CreateEnemy(GroundTurret, m_scene, { 0.0f + (i * 16), 0.0f });
		}
	}

	//Spawn Enemies that come up from bottom of screen
	RowEnd = m_lowerScrollPos;
	rowStart = RowEnd - 15;
	for (int i = 0; i < 16; i++)	//Search the row for enemies to spawn
	{
		if (m_map[rowStart + i] == 2)	//Spawn Enemy based on integer value - Enemy numerical List stored in header
		{
			m_scene->GetEnemyFactory()->CreateEnemy(Upwards, m_scene, { 0.0f + (i * 16), 200.0f });
		}
		if (m_map[rowStart + i] == 6)
		{
			m_scene->GetEnemyFactory()->CreateEnemy(FighterU, m_scene, { 0.0f + (i * 16), 200.0f });
		}
	}
}

void VerticalScroller::Update()
{
	//Spawn enemies based on position of scroll markers on map
	float test = fmodf(m_upperScrollPos, 16.0f);
	if (test == 0.0f)
	{
		SpawnEntityRow(true);
	}
	m_lowerScrollPos -= m_scrollSpeed;
	m_upperScrollPos -= m_scrollSpeed;
	//Make sure position of markers are precisely accurate or enemies will not spawn
	m_lowerScrollPos = ceil(m_lowerScrollPos * 20.0f) / 20.0f;
	m_upperScrollPos = ceil(m_upperScrollPos * 20.0f) / 20.0f;
	if (m_upperScrollPos <= 0)
	{
		m_scrollSpeed = 0;
	}
}
