#pragma once

#include <string>

namespace ae {

class Event
{
public:
	Event();
	virtual ~Event();

	void setType(std::string newEventType);
	std::string getType() const;
private:
	std::string eventType;
};

} // namespace ae