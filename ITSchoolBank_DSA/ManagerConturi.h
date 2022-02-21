#pragma once
#include"ContBancar.h"
#include<vector>



class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	std::string CreateIban(std::string& Nume, std::string& Prenume); 
	ContBancar* FindAccount();
public:
	void adaugareCont();
	int GetNumarConturi();
	void printAllConturi();
	void PrintAccount();
	void choseOption();
	void EraseAccount();
	void Eliberare_Depunere();
	void ChangeAccount();
};

