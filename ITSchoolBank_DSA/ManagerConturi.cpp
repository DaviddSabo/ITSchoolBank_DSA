#include "ManagerConturi.h"


std::string ManagerConturi::CreateIban( std::string& Nume, std::string& Prenume)
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
	m_fileManager->WriteToCSV(nume,prenume,iban,cont->getSold());

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
}

void ManagerConturi::PrintAccount()
{
	std::cout << "Tastati numele titularului de cont exact cum este scris in contul bancar\n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Tastati prenumele titularului de cont exact cum este scris in contul bancar\n";
	std::string prenume;
	std::cin >> prenume;

	int n = m_listaConturi.size();
	for (auto& cont : m_listaConturi)
	{
		if (cont->getNume() == nume && cont->getPrenume() == prenume)
		{
			std::cout << "Nume: " << cont->getNume() << std::endl;
			std::cout << "Prenume: " << cont->getPrenume() << std::endl;
			std::cout << "IBAN: " << cont->getIban() << std::endl;
			std::cout << "Sold: " << cont->getSold() << std::endl;
		}
		else 
			std::cout << "Datele introduse nu sunt corecte, contul nu exista\n";
	};	
}



void ManagerConturi::choseOption()
{
	std::cout << "Daca doriti sa afisati toate conturile apasati tasta 1\n";
	std::cout << "Daca doriti sa afisati un anumit cont apasati tasta 2\n";
	int n;
	std::cin >> n;
	switch (n) {
	case 1:
		std::cout<<"Ati ales sa afisati toate conturile\n";
		printAllConturi();
		break;
	case 2:
		std::cout << "Daca doriti sa aafisati un anumit cont\n";
		PrintAccount();
		break;
	default:
		std::cout << "Optiunea aleasa nu exista\n";
	}
	std::cout << "Apasati orice tasta pentru a va intoarce la meniu\n";
	char back;
	std::cin >> back;
	system("cls");
}


ContBancar* ManagerConturi::FindAccount()
{
	std::cout << "Numele titularului: \n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Prenumele titularului: \n";
	std::string prenume;
	std::cin >> prenume;
	std::cout << "IBAN-ul titularului: \n";
	std::string iban;
	std::cin >> iban;

	for (auto& cont : m_listaConturi) {
		if (cont->getNume() == nume && cont->getPrenume() == prenume && iban==cont->getIban() )
			return cont;
		else {
			std::cout << "Titularul nu a fost gasit\n";
			return nullptr;
		}
	}
}

void ManagerConturi::EraseAccount()
{
	std::cout << "Introduceti datele pentru contul ce urmeaza sa fie sters\n";
	ContBancar* cont= FindAccount();
	std::vector<ContBancar*>::iterator it = std::find(m_listaConturi.begin(), m_listaConturi.end(), cont);
	m_listaConturi.erase(it);
	delete cont;
}

void ManagerConturi::Eliberare_Depunere()
{
	ContBancar* cont = FindAccount();
	if (cont != nullptr)
	{
		std::cout << "Tastati suma pe care doriti sa o depuneti sau sa o retrageti (+ adaugare, - retragere)\n";

		float valoare;
		std::cin >> valoare;
		if (valoare >= 0)
			cont->depunere(valoare);
		else
			cont->retragere(valoare);
	}
	else
		std::cout << "Contul este inexistent\n";
}

void ManagerConturi::ChangeAccount()
{
	ContBancar* cont = FindAccount();
	if (cont != nullptr) {
		std::cout << "Daca doriti sa modificati numele apasat tasta 1, daca doriti sa modifciati prenumele apasati tasta 2 si 0 pentru a iesi\n";
		int tasta;
		std::cin >> tasta;

		switch (tasta) {
		case 1: {
				std::string name;
				std::cout << "Introduceti Numele nou\n";
				std::cin >> name;
				cont->ChangeNume(name);
				break;}
		case 2: {
			std::string last_name;
			std::cout << "Introduceti prenumele nou\n";
			std::cin >> last_name;
			cont->ChangePrenume(last_name);
			break; }
		case 0:
			break;
		default:
			std::cout << "Optiunea aleasa nu exista\n";
			std::cout << "Apasati tasta 0 pentru a va intoarce la meniul principal\n";
			std::cin >> tasta;
		}
	}
	else
		std::cout << " Contul nu exista\n";
}

ManagerConturi::ManagerConturi()
{ 
	m_fileManager = new FileManager;
	//populam lista conturi cu ce se afla in CSV
	m_listaConturi = m_fileManager->ReadContBancarFromCSV();

}

ManagerConturi::~ManagerConturi()
{
	delete m_fileManager;
}

