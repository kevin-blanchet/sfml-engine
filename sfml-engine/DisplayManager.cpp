#include "DisplayManager.h"
#include "LogManager.h"

namespace ae {

DisplayManager& DisplayManager::getInstance()
{
	static DisplayManager* displayManager = new DisplayManager();
	return *displayManager;
}

bool DisplayManager::initialize()
{
	if (pWindow != NULL) return true;
	LM.consoleLog("initialized");
	this->pWindow = new sf::RenderWindow(sf::VideoMode(this->windowWidth, this->windowHeight), WINDOW_TITLE_DEFAULT, WINDOW_STYLE_DEFAULT);
	this->pWindow->setVerticalSyncEnabled(WINDOW_VSYNC_DEFAULT);
	this->pWindow->setFramerateLimit(WINDOW_FRAMERATE_DEFAULT);

	if (!this->defaultFont.loadFromFile(DEFAULT_FONT_FILE)) {
		LM.errorLog("failed to load font");
	}

	this->display();
	if (!Manager::initialize()) return false;
	return true;
}

void DisplayManager::terminate()
{
	this->pWindow->close();
	delete this->pWindow;
}

bool DisplayManager::drawString(Vector2 pos, std::string str, Justification just, sf::Color color) const
{
	if (pWindow == NULL) return false;

	sf::Text text(str, this->defaultFont);
	text.setFillColor(color);

	Vector2 startingPos = pos;
	switch (just)
	{
	case Justification::Center:
		startingPos.x = pos.x - text.getGlobalBounds().width/2;
		break;
	case Justification::Right:
		startingPos.x = pos.x - text.getGlobalBounds().width;
		break;
	case Justification::Left:
	default:
		break;
	}
	text.setPosition(startingPos);
	this->pWindow->draw(text);
	return true;
}

bool DisplayManager::display()
{
	if (this->pWindow == NULL) return false;
	pWindow->display();
	pWindow->clear(this->bgColor);
	return true;
}

int DisplayManager::getWidth() const
{
	return this->windowWidth;
}

int DisplayManager::getHeight() const
{
	return this->windowHeight;
}

sf::Color DisplayManager::getBgColor() const
{
	return this->bgColor;
}

void DisplayManager::setBgColor(sf::Color newColor)
{
	this->bgColor = newColor;
}

bool DisplayManager::setDefaultFont(std::string fontFile)
{
	return this->defaultFont.loadFromFile(fontFile);
}

sf::RenderWindow* DisplayManager::getWindow() const
{
	return this->pWindow;
}

DisplayManager::DisplayManager()
{
	this->setType("DisplayManager");
	this->pWindow = NULL;
	this->windowWidth = WINDOW_WIDTH_DEFAULT;
	this->windowHeight = WINDOW_HEIGHT_DEFAULT;
	this->bgColor = WINDOW_BG_COLOR_DEFAULT;
}

} // namespace ae