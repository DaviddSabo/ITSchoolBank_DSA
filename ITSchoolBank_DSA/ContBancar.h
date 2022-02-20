#pragma once
#include<string>
enum class TipMoneda {
	RON,
	EUR,
	DOLAR
};
class ContBancar{
	std::string m_nume;
	std::string m_prenume;
	float m_sold;
	std::string m_IBAN;
	TipMoneda m_tipSold; //TODO:tipul soldului va trebuii sa fie modificat intr-un enum 0=RON, 1=EUR; done 
public:
	ContBancar(std::string nume, std::string prenume, std::string iban);
	std::string getNume() const;


};
