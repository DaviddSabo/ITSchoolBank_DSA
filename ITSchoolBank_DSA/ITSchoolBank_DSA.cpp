#include <iostream>
#include"ManagerConturi.h"
#include"User.h"

/*Banca Proiect.
ITSchoolBank

1. O clasa cont bancar ce trebuie sa aibe atribute precum nume, prenume, sold, tip de cont(valuta sau lei) IBAN
Un cont trebuie neaparat sa aibe un nume, prenume si un IBAN care trebuie sa fie unic

2.in maine se afla terminalul principal al bancii in care trebuie sa avem urmatoarele optiunii
2.1 numar de conturi-- > ce ne da numarul de conturi inregistrate in banca
2.2 creare cont-- > cu aceasta optiune se poate crea un cont nou
2.2.1 -- > ar trebui un scrren diferit si un set de optiuni in care
operatorul bancii sa introduca datele pentru crearea contului.(trebuie ca aceasta procedura sa verifice daca exista deja contul ce
    se doreste creat iar daca da sa anunte opreatorul)
    2.2.2 -- > o optiune de return la main screen(ecranul cu optiunie principale)
    2.3 O optiune de modificare cont->in care operatorul poate sa modifice date despre cont(ex schimbare nume, schimbare sume etc)
    2.4 O optiune prin care un cont se poate sterge din sistemul bancii
    2.5 O optiune prin care un cont poate sa extraga sume - > vrei sa adaugi sau sa extragi o suma de bani
    2.6 O optiune prin care un cont sa vada care este suma din cont
    Trebuie cautat contul intordus iar daca exista se poate vizualiza
    Daca nu exista putem incepe o procedura de creare cont

    3. Un sistem in care putem sa salvam datele acestea intr - un fisier local(CSV file)*/

int main()
{
    int incercari = 3;
    do {
    std::cout << "Introduceti userul\n";
    std::string user;
    std::cin >> user;
    std::cout << "Introduceti parola\n";
    std::string parola;
    std::cin >> parola;
    User* U = U->getInstance();
    
      
        if (user == U->getUser() && parola == U->getPassword()) {

            ManagerConturi manager;
            int optiune;
            do {

                std::cout << "Alege una din urmatoarele optiuni\n";
                std::cout << "\n";

                std::cout << "1-> Numar conturi\n";
                std::cout << "2-> Creare cont\n";
                std::cout << "3-> Modificare cont\n";// TODO:TEMA, POATE SCHIMBA NUME, PRENUME
                std::cout << "4-> Stergere cont\n";
                std::cout << "5-> Eliberare\Depunere\n";
                std::cout << "6-> Detalii cont\n";
                std::cout << "0-> EXIT\n";
                std::cout << "\n";

                std::cout << "Selectati operatiunea aleasa\n";
                std::cin >> optiune;
                std::cout << "\n";

                switch (optiune) {
                case 1:
                    system("cls");
                    std::cout << "Ati ales optiunea 1\n";
                    std::cout << "Numarul total de conturi este: " << manager.GetNumarConturi() << std::endl;
                    break;
                case 2:
                    std::cout << "Ati ales optiunea 2\n";
                    system("cls");
                    manager.adaugareCont();
                    break;

                case 3:
                    std::cout << "Ati ales optiunea 3\n";
                    manager.ChangeAccount();
                    break;

                case 4:
                    std::cout << "Ati ales optiunea 4\n";
                    manager.EraseAccount();
                    break;

                case 5:
                    std::cout << "Ati ales optiunea 5\n";
                    manager.Eliberare_Depunere();
                    break;

                case 6:
                    system("cls");
                    std::cout << "Ati ales optiunea 6\n\n";
                    manager.choseOption();
                    break;
                case 0:
                    std::cout << "Multumim, la revedere\n";
                    break;
                default:
                    std::cout << "Optiune invalida\n";
                    break;
                }

            } while (optiune != 0);
            break;
            
        }
        else {
            --incercari;
            system("cls");
            std::cout << "User sau parola incorecta.\n" << "Mai aveti " << incercari << " incercari\n";
            
        }
    } while (incercari > 0);
}

