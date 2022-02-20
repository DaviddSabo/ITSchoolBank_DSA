#include "ManagerConturi.h"

std::string ManagerConturi::CreateIban(std::string& Nume, std::string& Prenume)
{
	std::string Iban="ROITBANK0000";
	int random_number;

	int max = 888888889;
	srand(time(0));
	random_number = (rand() % max)+111111110;
	Iban = Iban + (std::to_string(random_number)) + Prenume[0] +Nume[0] + Nume[1];
	return Iban;
}


void ManagerConturi::adaugareCont()
{
	std::string nume, prenume, iban;
	std::cout << "Introduceti numele persoanei: \n";
	std::cin >> nume;
	std::cout << "Introduceti prenumele persoanei: \n";
	std::cin >> prenume;

	iban=CreateIban(nume, prenume);  
	std::cout << iban << std::endl;

	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_listaConturi.push_back(cont);

	system("cls");
}



int ManagerConturi::GetNumarConturi()
{
	int numar_Conturi = m_listaConturi.size();
	return numar_Conturi;
}



void ManagerConturi::printAllConturi()
{
	for (auto& it: m_listaConturi) {
		std::cout<<"Nume: "<<it->getNume()<<std::endl;
		std::cout << "Prenume: " << it->getPrenume()<<std::endl;
		std::cout<<"IBAN: "<<it->getIban()<<std::endl;
		std::cout << "Sold: " << it->getSold() << std::endl;
	}
	std::cout << "Apasati orice tasta pentru a va intoarce la meniu\n";
	char back;
	std::cin >> back;
	system("cls");
}
