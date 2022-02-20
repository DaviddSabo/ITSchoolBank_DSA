#pragma once
#include"ContBancar.h"
#include<vector>

class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	std::string CreateIban(std::string& Nume, std::string& Prenume); 
public:
	void adaugareCont();
	int GetNumarConturi();
	void printAllConturi();
	ContBancar* FindAccount();
	void choseOption();
};

