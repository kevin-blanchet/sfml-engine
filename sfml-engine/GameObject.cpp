#include "GameObject.h"

#include "SceneManager.h"

namespace ae {

GameObject::GameObject()
{
	this->setId(0);
	this->setType("GameObject");
	this->setPosition(0, 0);
	this->setDisplayLayer(MAX_DISPLAY_LAYER / 2);
	this->setVelocity({ 0,0 });
	this->setSpeed(0);

	SM.insertGameObject(this);
}

GameObject::~GameObject()
{
	SM.removeGameObject(this);
}

void GameObject::update()
{
}

void GameObject::fixedUpdate()
{
}

void GameObject::draw()
{
}

void GameObject::setId(int newId)
{
	this->id = newId;
}

int GameObject::getId() const
{
	return this->id;
}

void GameObject::setType(std::string newType)
{
	this->type = newType;
}

std::string GameObject::getType() const
{
	return this->type;
}

void GameObject::setPosition(Vector2 newPosition)
{
	this->position = newPosition;
}

void GameObject::setPosition(float newX, float newY)
{
	this->position.x = newX;
	this->position.y = newY;
}

Vector2 GameObject::getPosition() const
{
	return this->position;
}

int GameObject::getDisplayLayer() const
{
	return this->displayLayer;
}

int GameObject::setDisplayLayer(int newLayer)
{
	if (newLayer > MAX_DISPLAY_LAYER || newLayer < 0) return false;
	this->displayLayer = newLayer;
	return true;
}

void GameObject::setVelocity(Vector2 newVelocity) 
{
	this->velocity = newVelocity;
}

Vector2 GameObject::getVelocity()
{
	return this->velocity;
}

void GameObject::setSpeed(float newSpeed)
{
	this->speed = newSpeed;
}

float GameObject::getSpeed()
{
	return this->speed;
}

bool GameObject::eventHandler(const Event* event)
{
	//return true if handled
	return false;
}

} // namespace ae