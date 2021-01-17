// Includes for header and forward declarations
#include "Includes/Decal.h"
#include "Scene.h"
#include "Ship.h"
#include "Includes/Reticle.h"
#include "Includes/Bullet.h"
#include "Enemy.h"
#include "Vector3D.h"
#include "BulletManager.h"
#include "Includes/EnemyFactory.h"
#include "Includes/VerticalScroller.h"
#include "Includes/LifeMeterIcon.h"
#include <sstream>

Scene::Scene()
{
	sAppName = "2043 - Jacob Lawson s1901022";

	m_screenWidth = 256;
	m_screenHeight = 240;
}

// Called once at the start, so create things here
bool Scene::OnUserCreate()
{
	//Reset Highscores
	for (int i = 0; i < 4; i++)
	{
		m_highscores[i] = 0;
	}
	//Max number of lives allowed to be drawn
	m_currentLifeIcons.resize(9);
	//quit the game bool
	m_quit = false;
	//Initial Gamestate
	m_state = TITLESCREEN;
	//Player varaibles that are game wide
	playerProgress = 1;
	m_playerLives = 3;
	m_playerScore = 0;
	//Has the state been intialised
	m_stateInitialised = false;

	return true;
}

// Called once per frame
bool Scene::OnUserUpdate(float fElapsedTime)
{
	//get deltaTime
	deltaTime = fElapsedTime;
	// UPDATE
	/////////////////////////////

	// Should we quit? or has the game quit?
	if (GetKey(olc::Key::ESCAPE).bPressed || m_quit == true)
	{
		return false;
	}
	
	//Switch what the scene should do based on the game state
	//Each state must update it's relevent functions, clear and Redraw the scene
	switch (m_state)
	{
	case TITLESCREEN:
	{
		TitleScreenUpdate();
		RedrawScene();
		TitleScreenDraw();
		break;
	}
	case HIGHSCORE:
	{
		HighScoreUpdate();
		RedrawScene();
		HighScoreDraw();
		break;
	}
	case OPTIONS:
	{
		OptionsUpdate();
		RedrawScene();
		OptionsDraw();
		break;
	}
	case GAMEPLAY:
	{
		GameplayUpdate();
		RedrawScene();
		//if the player is dead we have deleted objects so we cannot draw them so break out of this
		if (m_playerLives <= 0)
		{
			break;
		}
		GameplayDraw();
		break;
	}
	case MAPSCREEN:
	{
		MapUpdate();
		RedrawScene();
		MapDraw();
		break;
	}
	default:	//default for saftey
	{
		m_quit = true;
		break;
	}
	}

	return true;
}

//Reset the Draw
void Scene::RedrawScene()
{
	// Clear the previous frame
	Clear(olc::Pixel());

	//update the backgorund colour of the scene
	UpdateBackground(bgColour);

	// Enables alpha blending
	SetPixelMode(olc::Pixel::ALPHA);
}

//Switch the background colour
void Scene::UpdateBackground(Colours a_colour)
{
	switch (a_colour)
	{
		case cBLACK:
		{
			Clear(olc::BLACK);
			break;
		}
		case cBLUE:
		{
			Clear(olc::DARK_BLUE);
			break;
		}
		case cGREEN:
		{
			Clear(olc::DARK_GREEN);
			break;
		}
		case cGREY:
		{
			Clear(olc::DARK_GREY);
			break;
		}
		case cRED:
		{
			Clear(olc::RED);
			break;
		}
	}
}

void Scene::TitleScreenUpdate()
{
	//Initialise the state
	if (m_stateInitialised == false)
	{
		//Check if pointer to menuselect exists
		if (p_MenuSelect != nullptr)
		{
			delete p_MenuSelect;
			p_MenuSelect = nullptr;
		}
		//Create icon for the menu item
		p_MenuSelect = new Decal(this);
		bgColour = cBLACK;
		p_MenuSelect->SetSprite(new olc::Sprite("Resources/Bomb.png"));
		p_MenuSelect->SetXScale(1.0f);
		p_MenuSelect->SetYScale(1.0f);
		//Setup menu items
		m_opitionIndex = 0;
		m_maxIndex = 3;
		m_stateInitialised = true;
	}
	switch (m_opitionIndex)
	{
		case 0:	//Play
		{
			//Move Selector sprite decal
			p_MenuSelect->SetPosition({ ((float)m_screenWidth / 2.0f) - 32.0f, (float)m_screenHeight / 2.0f });
			if (GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed)
			{
				//initialise and move to map screen
				m_stateInitialised = false;
				m_playerLives = 3;
				m_state = MAPSCREEN;
				m_stateInitialised = false;
			}
			break;
		}
		case 1:	//HighScores
		{
			//Move Selector sprite decal
			p_MenuSelect->SetPosition({ ((float)m_screenWidth / 2.0f) - 32.0f, (float)(m_screenHeight / 2.0f)+16.0f });
			if (GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed)
			{
				//initialise and move to Highscore screen
				m_stateInitialised = false;
				m_state = HIGHSCORE;
			}
			break;
		}
		case 2:	//Options
		{
			//Move Selector sprite decal
			p_MenuSelect->SetPosition({ ((float)m_screenWidth / 2.0f) - 32.0f, (float)(m_screenHeight / 2.0f) + 32.0f });
			if (GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed)
			{
				//initialise and move to Options menu
				m_state = OPTIONS;
				m_stateInitialised = false;
			}
			break;
		}
		case 3:	//Exit
		{
			//Move Selector sprite decal
			p_MenuSelect->SetPosition({ ((float)m_screenWidth / 2.0f) - 32.0f, (float)(m_screenHeight / 2.0f) + 48.0f });
			if (GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed)
			{
				//Quit the game
				m_quit = true;
			}
			break;
		}
	}
	//use directional keys to change selected index of the menu
	if (GetKey(olc::Key::UP).bPressed || GetKey(olc::Key::W).bPressed)
	{
		if (m_opitionIndex == 0)
		{
			m_opitionIndex = m_maxIndex;
		}
		else
		{
			m_opitionIndex -= 1;
		}
	}
	if (GetKey(olc::Key::DOWN).bPressed || GetKey(olc::Key::S).bPressed)
	{
		if (m_opitionIndex == m_maxIndex)
		{
			m_opitionIndex = 0;
		}
		else
		{
			m_opitionIndex += 1;
		}
	}
}

void Scene::TitleScreenDraw()
{
	//Draw Title
	DrawString((m_screenWidth / 2) - 48, (m_screenHeight / 2)-64, "-2043-", olc::WHITE, 2);
	//Draw Menu items
	p_MenuSelect->Draw(this);
	DrawString((m_screenWidth/2)-16, m_screenHeight/2, "Play", olc::WHITE, 1);
	DrawString((m_screenWidth / 2) - 16, (m_screenHeight / 2)+16, "HighScores", olc::WHITE, 1);
	DrawString((m_screenWidth / 2) - 16, (m_screenHeight / 2)+32, "Options", olc::WHITE, 1);
	DrawString((m_screenWidth / 2) - 16, (m_screenHeight / 2) + 48, "Exit", olc::WHITE, 1);
	//Draw Details
	DrawString(32, m_screenHeight - 16, "by Jacob Lawson s1901022", olc::WHITE, 1);
}

void Scene::HighScoreUpdate()
{
	if (m_stateInitialised == false)
	{
		bgColour = cBLACK;
		//Sort the highscore table in case changes have been made since last play (shouldn't happen but just being safe)
		BubbleSort();
		m_stateInitialised = true;
	}
	if (GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed)
	{
		//Move back to title screen
		m_state = TITLESCREEN;
		m_stateInitialised = false;
	}
}

void Scene::HighScoreDraw()
{
	//Draw the highscore table
	DrawString((m_screenWidth / 3) - 16, (m_screenHeight / 2) - 16, "-HIGHSCORES-", olc::WHITE, 1);
	for (int i = 0; i < 5; i++)
	{
		DrawString(m_screenWidth / 3, m_screenHeight / 2 + (i*16), std::to_string(i + 1) + "- " + std::to_string(m_highscores[i]), olc::WHITE, 1);
	}
}

void Scene::OptionsUpdate()
{
	//Similar to title screen state
	if (m_stateInitialised == false)
	{
		//Set background colour
		bgColour = cBLACK;
		if (p_MenuSelect != nullptr)
		{
			delete p_MenuSelect;
			p_MenuSelect = nullptr;
		}
		p_MenuSelect = new Decal(this);
		p_MenuSelect->SetSprite(new olc::Sprite("Resources/Bomb.png"));
		p_MenuSelect->SetXScale(1.0f);
		p_MenuSelect->SetYScale(1.0f);
		m_opitionIndex = 0;
		m_maxIndex = 1;
		m_stateInitialised = true;
	}
	switch (m_opitionIndex)
	{
	case 0:	//Clear Highscores
	{
		//Move Selector sprite decal
		p_MenuSelect->SetPosition({ ((float)m_screenWidth / 2.0f) - 32.0f, (float)m_screenHeight / 2.0f });
		if ((GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed))
		{
			for (int i = 0; i < 5; i++)
			{
				m_highscores[i] = 0;
			}
			m_stateInitialised = false;
			m_state = HIGHSCORE;
		}
		break;
	}
	case 1:	//Exit back to titlescreen
	{
		//Move Selector sprite decal
		p_MenuSelect->SetPosition({ ((float)m_screenWidth / 2.0f) - 32.0f, (float)(m_screenHeight / 2.0f) + 16.0f });
		if ((GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed))
		{
			m_stateInitialised = false;
			m_state = TITLESCREEN;
		}
		break;
	}
	default:
	{
		break;
	}
	}

	if (GetKey(olc::Key::UP).bPressed || GetKey(olc::Key::W).bPressed)
	{
		if (m_opitionIndex == 0)
		{
			m_opitionIndex = m_maxIndex;
		}
		else
		{
			m_opitionIndex -= 1;
		}
	}
	if (GetKey(olc::Key::DOWN).bPressed || GetKey(olc::Key::S).bPressed)
	{
		if (m_opitionIndex == m_maxIndex)
		{
			m_opitionIndex = 0;
		}
		else
		{
			m_opitionIndex += 1;
		}
	}
}

void Scene::OptionsDraw()
{
	//Draw options menu
	p_MenuSelect->Draw(this);
	DrawString((m_screenWidth / 2) - 16, m_screenHeight / 2, "Clear Highscores", olc::WHITE, 1);
	DrawString((m_screenWidth / 2) - 16, (m_screenHeight / 2) + 16, "Back", olc::WHITE, 1);
}

void Scene::GameplayUpdate()
{
	if (m_stateInitialised == false)
	{
		for (int i = 0; i < m_playerLives ; i++)
		{
			int multiplier = i + 1;
			m_currentLifeIcons[i] = new LifeIcon();
			m_currentLifeIcons[i]->SetPosition(Vector2D{ 240.0f-(16 * multiplier),224.0f });
		}
		//Initialise game obejects
		playerShip = new Ship();
		playerReticle = new Reticle(this, playerShip);
		enemyFactory = new EnemyFactory();
		bulletManager = new BulletManager();
		verticalScroller = new VerticalScroller(this);
		//Load current level
		verticalScroller->LoadLevel(m_levelFile);

		//Set up timer
		m_gameplayTimer = 0.0f;

		m_stateInitialised = true;
	}
	//If level is not at end
	if (verticalScroller->GetScrollPosition() <= 0.0f)
	{
		ClearGameplayObjects();
		playerProgress += 1;
		m_state = MAPSCREEN;
	}
	else
	{
		//Update game objects
		playerShip->Update(this);
		playerReticle->Update(this);
		enemyFactory->Update();
		bulletManager->Update();
		verticalScroller->Update();
		playerShip->Collision(this);

		//Increment timer
		m_gameplayTimer += 1.0f * DeltaTime();
	}
}

void Scene::GameplayDraw()
{
	//Draw HUD	
	std::string scoreOutput = std::to_string(m_playerScore);	//Score
	DrawString(16, 0, "SCORE", olc::WHITE, 1);
	DrawString(16, 16, scoreOutput, olc::WHITE, 1);
	for (int i = 0; i < m_playerLives; i++)						//Lives
	{
		m_currentLifeIcons[i]->Draw();
	}
	// Draw The game objects
	if (m_state == GAMEPLAY)
	{
		playerReticle->Draw(this);
		bulletManager->Draw();
		playerShip->Draw(this);
		enemyFactory->Draw();
	}
}

void Scene::MapUpdate()
{
	if (m_stateInitialised == false)
	{
		bgColour = cBLACK;
		m_transitionTimer = 0;
		m_mapTransition = false;

		//Avoid memory leaks on repeated map visits
		if (p_MapEarth != nullptr)
		{
			delete p_MapEarth;
			p_MapEarth = nullptr;
		}
		if (p_MapSpaceFleet != nullptr)
		{
			delete p_MapSpaceFleet;
			p_MapSpaceFleet = nullptr;
		}
		if (p_MapMoon != nullptr)
		{
			delete p_MapMoon;
			p_MapMoon = nullptr;
		}
		if (p_MapMars != nullptr)
		{
			delete p_MapMars;
			p_MapMars = nullptr;
		}
		//Sprites for Map
		p_MapEarth = new Decal(this);
		p_MapEarth->SetSprite(new olc::Sprite("Resources/Map_Earth.png"));
		p_MapEarth->SetPosition({ 32.0f, 172.0f });
		p_MapEarth->SetXScale(1.0f);
		p_MapEarth->SetYScale(1.0f);

		p_MapSpaceFleet = new Decal(this);
		p_MapSpaceFleet->SetSprite(new olc::Sprite("Resources/Map_SpaceFleet.png"));
		p_MapSpaceFleet->SetPosition({ 64.0f, 128.0f });
		p_MapSpaceFleet->SetXScale(1.0f);
		p_MapSpaceFleet->SetYScale(1.0f);

		p_MapMoon = new Decal(this);
		p_MapMoon->SetSprite(new olc::Sprite("Resources/Map_Moon.png"));
		p_MapMoon->SetPosition({ 96.0f, 164.0f });
		p_MapMoon->SetXScale(1.0f);
		p_MapMoon->SetYScale(1.0f);

		p_MapMars = new Decal(this);
		p_MapMars->SetSprite(new olc::Sprite("Resources/Map_Mars.png"));
		p_MapMars->SetPosition({ 128.0f, 112.0f });
		p_MapMars->SetXScale(1.0f);
		p_MapMars->SetYScale(1.0f);

		m_opitionIndex = 0;
		//Setup what levels can be accessed based on number of levels beat
		if (playerProgress == 1)
		{
			m_maxIndex = 0;
		}
		else if (playerProgress == 2)
		{
			m_maxIndex = 2;
		}
		else if (playerProgress == 3)
		{
			m_maxIndex = 3;
		}
		else if (playerProgress > 3) 	//End the game
		{
			//Sort high scores and return to title screen reseting the game for next playthrough
			m_stateInitialised = false;
			if (m_playerScore > m_highscores[4])
			{
				m_highscores[4] = m_playerScore;
			}
			BubbleSort();	
			m_playerScore = 0;
			m_playerLives = 3;
			playerProgress = 1;
			m_state = TITLESCREEN;
		}
		
		m_stateInitialised = true;
	}
	switch (m_opitionIndex)
	{
	case 0:	//Level 1 - Earth
	{
		m_CurrentMissionString = "Defend Earth";
		if ((GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed) || m_mapTransition == true)
		{
			//allow for the zoom transition effect to work
			m_mapTransition = true;
			//if transition is over
			if (m_transitionTimer > 5.0f)
			{
				//load level
				m_levelFile = "../RetroGame/Resources/levels/LevelOne.map";
				//Setup level colour
				bgColour = cGREEN;
				//move to gameplay state
				m_state = GAMEPLAY;
				m_stateInitialised = false;
			}
			m_transitionTimer += 1.0f * DeltaTime();
			
			//Movement and scaling for transition sprite zoom
			p_MapEarth->MoveTowards({ 0.0f, 0.0f}, 32.0f);
			p_MapEarth->SetXScale(m_transitionTimer+(2.0f * m_transitionTimer));
			p_MapEarth->SetYScale(m_transitionTimer+(2.0f * m_transitionTimer));
			MapDraw();
		}
		break;
	}
	case 1:	//Level 2A - Space Fleet
	{
		m_CurrentMissionString = "Destroy Space Fleet";
		if ((GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed) || m_mapTransition == true)
		{
			m_mapTransition = true;
			if (m_transitionTimer > 5.0f)
			{
				m_levelFile = "../RetroGame/Resources/levels/LevelTwo.map";
				bgColour = cBLACK;
				m_state = GAMEPLAY;
				m_stateInitialised = false;
			}
			m_transitionTimer += 1.0f * DeltaTime();
			p_MapSpaceFleet->MoveTowards({ 0.0f, 0.0f }, 32.0f);
			p_MapSpaceFleet->SetXScale(m_transitionTimer + (2.0f * m_transitionTimer));
			p_MapSpaceFleet->SetYScale(m_transitionTimer + (2.0f * m_transitionTimer));
			MapDraw();
		}
		break;
	}
	case 2:	//Level 2B - Moon Base
	{
		m_CurrentMissionString = "Attack the Moonbase";
		if ((GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed) || m_mapTransition == true)
		{
			m_mapTransition = true;
			if (m_transitionTimer > 5.0f)
			{
				m_levelFile = "../RetroGame/Resources/levels/LevelThree.map";
				bgColour = cGREY;
				m_state = GAMEPLAY;
				m_stateInitialised = false;
			}
			m_transitionTimer += 1.0f * DeltaTime();
			p_MapMoon->MoveTowards({ 0.0f, 0.0f }, 32.0f);
			p_MapMoon->SetXScale(m_transitionTimer + (2.0f * m_transitionTimer));
			p_MapMoon->SetYScale(m_transitionTimer + (2.0f * m_transitionTimer));
		}
		break;
	}
	case 3:	//Level 3 Mars
	{
		m_CurrentMissionString = "Eliminate Mars";
		if ((GetKey(olc::Key::ENTER).bPressed || GetKey(olc::Key::SPACE).bPressed) || m_mapTransition == true)
		{
			m_mapTransition = true;
			if (m_transitionTimer > 5.0f)
			{
				m_levelFile = "../RetroGame/Resources/levels/LevelFour.map";
				bgColour = cRED;
				m_state = GAMEPLAY;
				m_stateInitialised = false;
			}
			m_transitionTimer += 1.0f * DeltaTime();
			p_MapMars->MoveTowards({ 0.0f, 0.0f }, 32.0f);
			p_MapMars->SetXScale(m_transitionTimer + (2.0f * m_transitionTimer));
			p_MapMars->SetYScale(m_transitionTimer + (2.0f * m_transitionTimer));
		}
		break;
	}
	default:
	{
		//Default is just a safety in case a different case is given (shouldn't happen)
		break;
	}
	}

	//use directional keys to change selected index of the menu
	if (GetKey(olc::Key::UP).bPressed || GetKey(olc::Key::W).bPressed)
	{
		if (m_opitionIndex == 0)
		{
			m_opitionIndex = m_maxIndex;
		}
		else
		{
			m_opitionIndex -= 1;
		}
	}
	if (GetKey(olc::Key::DOWN).bPressed || GetKey(olc::Key::S).bPressed)
	{
		if (m_opitionIndex == m_maxIndex)
		{
			m_opitionIndex = 0;
		}
		else
		{
			m_opitionIndex += 1;
		}
	}
	
}

void Scene::MapDraw()
{
	//Title
	DrawString(16, 16, "Mission Map", olc::WHITE, 1);
	DrawString(16, 32, "Current: " + m_CurrentMissionString, olc::WHITE, 1);
	if (playerProgress >= 2)
	{
		DrawString(16, 48, "Select Route", olc::WHITE, 1);
	}
	//Selection
	
	//Mission Icons
	if (playerProgress  > 0)
	{
		p_MapEarth->Draw(this);
	}
	if (playerProgress > 1)
	{
		p_MapSpaceFleet->Draw(this);
		p_MapMoon->Draw(this);
	}
	if (playerProgress > 2)
	{
		p_MapMars->Draw(this);
	}
}

void Scene::PlayerDeath()
{
	//Destroy the game objects to avoid a memory leak
	ClearGameplayObjects();

	//if the player is out of lives then gameover.
	if (m_playerLives <= 0)
	{
		//check to see if highscore is worth putting into highscore array
		if (m_playerScore > m_highscores[4])
		{
			m_highscores[4] = m_playerScore;
		}
		//Sort highscore array
		BubbleSort();
		m_playerScore = 0;
		m_state = TITLESCREEN;
	}
	else
	{
		//Reset scene and try level again
		GameplayUpdate();
	}
}

//Simply sorts the high score array
void Scene::BubbleSort()
{
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = 0; j < 5 - i - 1; j++)
		{
			if (m_highscores[j] < m_highscores[j + 1])
			{
				int temp = m_highscores[j];
				m_highscores[j] = m_highscores[j + 1];
				m_highscores[j + 1] = temp;
			}			
		}
	}
}

//Destroys the gameplay objects
void Scene::ClearGameplayObjects()
{
	delete playerReticle;
	playerReticle = nullptr;
	delete playerShip;
	playerShip = nullptr;
	int enemiesToClear = enemyFactory->getEnemyCount();
	for (int i = 0; i < enemiesToClear; i++)
	{
		if (enemyFactory->getEnemies(i) != nullptr)
		{
			enemyFactory->DestroyEnemy(i);
		}
	}
	delete enemyFactory;
	enemyFactory = nullptr;
	int bulletsToClear = bulletManager->getBulletCount();
	for (int i = 0; i < bulletsToClear; i++)
	{
		if (bulletManager->getBullet(i) != nullptr)
		{
			bulletManager->DestroyBullet(i);
		}
	}
	delete bulletManager;
	bulletManager = nullptr;
	m_stateInitialised = false;
	delete verticalScroller;
	verticalScroller = nullptr;
}
