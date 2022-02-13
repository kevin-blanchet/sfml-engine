#pragma once
#include "Event.h"

#include <string>

namespace ae {

class Manager
{
public:
	Manager();
	virtual ~Manager();

	virtual bool initialize();
	virtual void terminate();

	std::string getType() const;
	bool isStarted() const;

	int onEvent(const Event* pEvent) const;

protected:
	void setType(std::string newType);

private:
	std::string type;
	bool bStarted;
};

} // namespace ae