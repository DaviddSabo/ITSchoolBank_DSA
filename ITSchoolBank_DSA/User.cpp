#include "User.h"

User* User::instance = 0;

User::User() {
	m_user = "ITBank2022";
	m_password = "C++Bank2022";
}

User* User::getInstance()
{
	if (instance!=nullptr)
		return instance;
	else {
		instance=new User();
			return instance;
	}
}

std::string User::getUser()
{
	return m_user;
}

std::string User::getPassword()
{
	return m_password;
}




