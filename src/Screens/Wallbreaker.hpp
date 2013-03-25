#ifndef WALLBREAKER_HPP
#define WALLBREAKER_HPP

#include "Screen.hpp"
#include "Core/Config.hpp"
#include "Core/ParticleSystem.hpp"
#include "Core/Level.hpp"
#include "Entities/Paddle.hpp"
#include "Gui/BitmapText.hpp"

class Wallbreaker: public Screen
{
public:
	enum Status { READY, PLAYING, PAUSED, GAME_OVER };

	Wallbreaker();
	~Wallbreaker();

	// override
	void onEvent(const sf::Event& event);

	// override
	void onFocus();

	// override
	void update(float frametime);

private:
	// override
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool loadNextLevel();

	void updateTexture();

	void updateEntities(float frametime);

	bool checkBrick(Entity& entity, int i, int j);

	void setStatus(Status status);

	// Delete all entities
	void clearEntities();

	// Create a new ball instance
	void createBall();

	static const int m_width  = NB_BRICK_COLS  * Brick::WIDTH;
	static const int m_height = NB_BRICK_LINES * Brick::HEIGHT;

	Level             m_level;
	int               m_remaining_bricks;
	ParticleSystem&   m_particles;
	BitmapText        m_info_text;
	sf::Sprite        m_hud_sprite;
	sf::Sprite        m_level_sprite;
	sf::RenderTexture m_level_texture;

	typedef std::list<Entity*> EntityList;
	EntityList m_entities;
	Paddle     m_paddle;
	Status     m_status;
	int        m_player_lives;
};

#endif // WALLBREAKER_HPP
