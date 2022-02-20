#pragma once
#include"ContBancar.h"
#include<vector>

class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	std::string CreateIban(std::string& Nume, std::string& Prenume); //TODO: metoda CreateIban trebuie sa genereze un iban unic care sa fie folosit pentru a crea cont;
public:
	void adaugareCont();

};

