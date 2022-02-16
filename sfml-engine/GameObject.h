#pragma once

#include <string>

#include "Vector2.h"
#include "Event.h"

namespace ae {

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void update();
	virtual void draw();

	void setId(int newId);
	int getId() const;

	void setType(std::string newType);
	std::string getType() const;

	virtual void setPosition(Vector2 newPosition);
	virtual void setPosition(float newX, float newY);
	Vector2 getPosition() const;

	int getDisplayLayer() const;
	int setDisplayLayer(int newLayer);

	void setVelocity(Vector2 newVelocity);
	Vector2 getVelocity();

	void setSpeed(float newSpeed);
	float getSpeed();

	virtual bool eventHandler(const Event* event);
private:
	int id;
	std::string type;
	Vector2 position;
	int displayLayer;

	Vector2 velocity;
	float speed;
};

} // namespace ae