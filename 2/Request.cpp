#include "Request.hpp"
 int Request::numberOfRequests;
Request::Request():ID(++numberOfRequests)
{
}

Request::Request(const std::string& message, const std::string& sender): ID(++numberOfRequests)
{
	this->message = message;
	name = sender;
	
	
}

std::string Request::getMessage() const
{
	return message;
}

std::string Request::getSender() const
{
	return name;
}

int Request::getCount() const
{
	return numberOfRequests;
}

int Request::getID() const
{
	return ID;
}
