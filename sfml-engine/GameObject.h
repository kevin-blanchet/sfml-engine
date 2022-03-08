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
	virtual void fixedUpdate();
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

	virtual bool eventHandler(const Event* event);
private:
	int id;
	std::string type;
	Vector2 position;
	int displayLayer;
};

} // namespace ae