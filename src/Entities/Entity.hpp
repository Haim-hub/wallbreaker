#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics/Sprite.hpp>

class Ball;
class Paddle;
class Brick;
class Wallbreaker;

/**
 * Base class for game entities
 */
class Entity: public sf::Sprite
{
public:
	Entity();
	virtual ~Entity();

	void setManager(Wallbreaker* parent);
	Wallbreaker* getManager();

	bool isAlive() const;

	void kill();

	bool collidesWith(const Entity& other) const;

	// casts -------------------------------------------------------------------

	virtual Ball* toBall();

	// callbacks ---------------------------------------------------------------

	virtual void onInit() {};
	virtual void onUpdate(float frametime) = 0;

	virtual void onBrickHit(Brick& brick, const sf::Vector2f& previous_pos) {};
	virtual void onPaddleHit(Paddle& paddle) {}

	virtual void onCeilHit() {}
	virtual void onWallHit() {}

	// position helpers --------------------------------------------------------

	inline float getX() const { return getPosition().x; }
	inline float getY() const { return getPosition().y; }
	inline void setX(float x) { setPosition(x, getPosition().y); }
	inline void setY(float y) { setPosition(getPosition().x, y); }
	sf::Vector2f getCenter() const;

	// size helpers ------------------------------------------------------------

	float getWidth() const;
	float getHeight() const;
	sf::IntRect getCollisionRect() const;

private:
	Wallbreaker* m_parent;
	bool         m_alive;
};

#endif // ENTITY_HPP
