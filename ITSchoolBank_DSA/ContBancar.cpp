#include "ContBancar.h"

ContBancar::ContBancar(std::string nume, std::string prenume, std::string iban)
{
	m_nume = nume;
	m_prenume = prenume;
	m_IBAN = iban;
	m_sold = 0;
	m_tipSold = TipMoneda::RON;
}


std::string ContBancar::getNume() const
{
	return m_nume;
}


std::string ContBancar::getPrenume() const
{
	return m_prenume;
}

std::string ContBancar::getIban() const
{
	return m_IBAN;
}


float ContBancar::getSold() const
{
	return m_sold;
}

void ContBancar::depunere(float suma)
{
	m_sold += suma;
}

void ContBancar::retragere(float suma)
{
	if (suma < m_sold) 
		std::cout << "Fonduri insuficiente. " << "Valoare cont= " << m_sold << std::endl;

	else
		m_sold += suma;

	
}

void ContBancar::ChangeNume(const std::string& nume_nou) 
{
	m_nume = nume_nou;
}

void ContBancar::ChangePrenume(const std::string& prenume_nou){
	m_prenume = prenume_nou;
}


