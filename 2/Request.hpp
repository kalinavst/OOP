#pragma once
#include <string>

class Request {
public:
	Request();
	Request(const std::string& message, const std::string& sender);
	std::string getMessage() const;
	std::string getSender() const;
	int getCount()const;
	int getID() const;
protected:
	std::string message;
	std::string name;
	static int numberOfRequests;
	int ID;


};