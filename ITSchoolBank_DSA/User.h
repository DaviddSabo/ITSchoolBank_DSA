#pragma once
#include<iostream>

class User
{
	//constructorul este private deoarece vrem sa controlom instantierea
	User();
	std::string m_user;
	std::string m_password;
	static User* instance; //pointer catre instanta obiectului
public:
	
	static User* getInstance(); //metoda ce returneaza instanta a singletonului
	std::string getUser();
	std::string getPassword();
};

