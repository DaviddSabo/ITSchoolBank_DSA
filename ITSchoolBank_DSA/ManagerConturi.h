#pragma once
#include"ContBancar.h"
#include<vector>
#include "FileManager.h"


class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	std::string CreateIban(std::string& Nume, std::string& Prenume); 
	ContBancar* FindAccount();
	FileManager* m_fileManager;
public:
	void adaugareCont();
	int GetNumarConturi();
	void printAllConturi();
	void PrintAccount();
	void choseOption();
	void EraseAccount();
	void Eliberare_Depunere();
	void ChangeAccount();
	ManagerConturi();
	~ManagerConturi();
};

