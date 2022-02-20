#include "ManagerConturi.h"

std::string ManagerConturi::CreateIban(std::string& Nume, std::string& Prenume)
{
	std::string Iban="ROITBANK0000";
	int random_number;

	int max = 888888889;
	srand(time(0));
	random_number = (rand() % max)+111111111;
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
