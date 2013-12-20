#include "PowerUp.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "Core/Resources.hpp"
#include "Core/SoundSystem.hpp"
#include "Screens/Wallbreaker.hpp"
#include "Utils/Math.hpp"

#define POWERUP_WIDTH 20
#define POWERUP_HEIGHT 10

PowerUp* PowerUp::createRandom()
{
	return new PowerUp((Type) math::rand(0, SPEED_RESET));
}


PowerUp::PowerUp(Type type):
	m_type(type)
{
	int x = (type % 4) * POWERUP_WIDTH;
	int y = (type / 4) * POWERUP_HEIGHT;

	setTextureRect({x, y, POWERUP_WIDTH, POWERUP_HEIGHT});
	setTexture(Resources::getTexture("power-ups.png"));
}


void PowerUp::onPaddleHit(Paddle& paddle)
{
	switch (m_type)
	{
		case SMALL_PADDLE:
			paddle.shrink();
			break;
		case LARGE_PADDLE:
			paddle.grow();
			break;
		case STICKY_PADDLE:
			paddle.activeSticky();
			break;
		case LASER_PADDLE:
			paddle.activeLaser();
			break;
		case TRIPLE_BALL:
			getManager()->createBall();
			getManager()->createBall();
			break;
		case POWER_BALL:
			getManager()->applyOnEachBall(&Ball::enablePowerBall);
			break;
		case EXTRA_LIFE:
			getManager()->addPlayerLife();
			break;
		case SPEED_RESET:
			getManager()->applyOnEachBall(&Ball::resetSpeed);
			break;
	}
	kill();
	SoundSystem::playSound("power-up.ogg");
}


void PowerUp::onUpdate(float frametime)
{
	move(0, 50 * frametime);
}
