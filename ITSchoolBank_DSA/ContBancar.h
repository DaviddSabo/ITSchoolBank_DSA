#pragma once
#include<string>
#include<iostream>
enum class TipMoneda {
	RON,
	EUR,
	DOLAR
};

class ContBancar{
	std::string m_nume;
	std::string m_prenume;
	float m_sold=0;
	std::string m_IBAN;
	TipMoneda m_tipSold; //TODO:tipul soldului va trebuii sa fie modificat intr-un enum 0=RON, 1=EUR; done 
public:
	ContBancar(std::string nume, std::string prenume, std::string iban, float sold);

	std::string getNume() const;
	std::string getPrenume() const;
	std::string getIban() const;
	float getSold() const;
	void depunere(float suma);
	void retragere(float suma);
	void ChangeNume(const std::string& nume_nou) ;
	void ChangePrenume(const std::string& prenume_nou) ;


};

