#include "HFolder.h"

void CE_LOOP_TEXT_(int intLocalTimes_,std::string sLocalText)
{
	for (int i = 0; i < intLocalTimes_; i++) {
		std::cout << sLocalText << std::endl;
	}

}

bool CE_CURS_WHILE()
{

	std::cout << "Mai acceleram? :" << " Da (1) " << "Nu (2)" << std::endl;

	int input;
	std:: cin >> input;
	bool rezultat;

	switch (input) {
	case 1:
		rezultat = true;
		break;
	case 2:
		rezultat = false;
		break;
	default:
		rezultat = false;
		break;
	}
	return rezultat;

}

void CE_THROTTLE_()
{
	while (CE_CURS_WHILE()) {
		std::cout << " SPEEEEEED" << std::endl;
	}
}

void CE_CURS_DO_WHILE_()
{

	do 
	{
		std::cout << " Do this " << std::endl;
	} while (false);

}


// TEME // 


void CE_TEMA_01_(int intLocalTimer)
{
	for (int i = intLocalTimer; i > 0; i--)
	{
		std::cout << i << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		if (i == 1) {
			std::cout << "Lansare!" << std::endl;
		}
	}
}

void CE_TEMA_02_(int intLocalNumber)
{
	int intRezultat_ = 0;

	for (int i = 1; i <= intLocalNumber; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(75));
		std::cout << i;

		intRezultat_ = intRezultat_ + i;

		if (i == intLocalNumber) {
			std::cout << " = " << intRezultat_ << std::endl;
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(75));
			std::cout << " + ";
		}
	}
}

void CE_TEMA_03_(int intLocalLines)
{
	for (int i = 1; i <= intLocalLines; i++)
	{
		// Afiseaza spatiile pentru aliniere în partea stanga
		for (int s = 0; s < intLocalLines - i; s++) {
			std::cout << "  ";
		}

		// Afiseaza stelele pentru partea stanga a piramidei
		for (int k = 0; k < i; k++) {
			std::cout << "* ";
		}

		// Afiseaza stelele pentru partea dreapta a piramidei
		for (int k = i - 2; k >= 0; k--) {
			std::cout << "* ";
		}
		std::cout << std::endl;
	}
}

int CE_TEMA_04_(int intLocalA, int intLocalB)
{
		int intLocalC;

		while (intLocalB)
		{
			intLocalC = intLocalA % intLocalB;
			intLocalA = intLocalB;
			intLocalB = intLocalC;
		}
		return intLocalA;
}

bool CE_CHECK_PRIME_NUM_(int intLocalNumber) {
	if (intLocalNumber <= 1) {
		return false;  // Numerele mai mici sau egale cu 1 nu sunt prime
	}

	int i = 2;
	while (i * i <= intLocalNumber) {
		if (intLocalNumber % i == 0) {
			return false;  // Daca gasim un divizor, numarul nu este prim
		}
		++i;
	}

	return true;  // Daca nu gasim divizori, numarul este prim
}

void CE_TEMA_05_()
{
	int intNumarAles = 0;
	std::cout << "Introduceti un numar: ";
	std::cin >> intNumarAles;
	std::cout << std::endl;
	
	if (CE_CHECK_PRIME_NUM_(intNumarAles)) {
		std::cout << intNumarAles << " este un numar prim" << std::endl;
	}
	else {
		std::cout << intNumarAles << " nu este un numar prim" << std::endl;
	}

}

void CE_TEMA_06_()
{
	int intNumarDecimal = 0;

	// Citim numărul în sistemul decimal de la utilizator
	std::cout << "Introduceti un numar in sistemul decimal: ";
	std::cin >> intNumarDecimal;

	// Verificam cazul particular pentru numarul 0
	if (intNumarDecimal == 0) {
		std::cout << "Reprezentarea binara a numarului 0 este: 0" << std::endl;
	}
	else {
		// Convertim numarul in sistemul binar utilizând o bucla while
		std::bitset<32> bitiBinary;  // Folosim 32 de biti pentru a acoperi un int standard
		int index = 0;

		while (intNumarDecimal > 0) {
			bitiBinary[index] = intNumarDecimal % 2;
			intNumarDecimal /= 2;
			++index;
		}

		// Afisam rezultatul
		std::cout << "Reprezentarea binara a numarului este: ";

		// Afisam bitii in ordine inversa, de la cel mai semnificativ la cel mai putin semnificativ
		for (int i = index - 1; i >= 0; --i) {
			std::cout << bitiBinary[i];
		}
	}
	std::cout << std::endl;
}


bool CE_CHECK_MAGIC_NUMBER_(int intLocalMagicNumber, int intLocalAINumber)
{
	if (intLocalMagicNumber == intLocalAINumber) {
		std::cout << "Bravo ai gasit numarul magic !" << std::endl;
		return false;
	} else {
		std::cout << "Mai incearca, numarul nu este " << intLocalMagicNumber << std::endl;
		return true;
	}
}

void CE_TEMA_07_()
{
	int intUserNumber = 0;
	int intUserTryes = 0;
	std::random_device rd;
	std::uniform_int_distribution<int> distribution(1, 3);
	unsigned short intAIChoice = distribution(rd);

	do
	{
		std::cout << "Introdu numarul: ";
		std::cin >> intUserNumber;
		std::cout << std::endl;
		intUserTryes++;
	}
	while (CE_CHECK_MAGIC_NUMBER_(intUserNumber, intAIChoice));
	

	std::cout << "Numarul era " << intAIChoice << ", incercari: " << intUserTryes << std::endl;
}

void CE_TEMA_08_()
{
	char cContinua;
	float fNumar1, fNumar2;
	char cOperator;

	do {
		// Citirea numerelor și a operatorului
		std::cout << "Introduceti primul numar: ";
		std::cin >> fNumar1;

		std::cout << "Introduceti al doilea numar: ";
		std::cin >> fNumar2;

		std::cout << "Introduceti operatorul (+, -, *, /): ";
		std::cin >> cOperator;

		// Calculul si afisarea rezultatului
		switch (cOperator) {
		case '+':
			std::cout << fNumar1 <<" + " << fNumar2 << " = " << fNumar1 + fNumar2 << std::endl;
			break;
		case '-':
			std::cout << fNumar1 << " - " << fNumar2 << " = " << fNumar1 - fNumar2 << std::endl;
			break;
		case '*':
			std::cout << fNumar1 << " * " << fNumar2 << " = " << fNumar1 * fNumar2 << std::endl;
			break;
		case '/':
			if (fNumar2 != 0)
				std::cout << fNumar1 << " / " << fNumar2 << " = " << fNumar1 / fNumar2 << std::endl;
			else
				std::cout << "Impartirea la zero nu este permisa." << std::endl;
			break;
		default:
			std::cout << "Operator invalid." << std::endl;
		}

		// Verificare pentru continuarea operatiilor
		std::cout << "Doriti sa efectuati o noua operatie? (Da/D/Nu): ";
		std::cin >> cContinua;
	} while (cContinua == 'D' || cContinua == 'd');

}

void CE_TEMA_09_()
{
	int intNumar;

	do {
		std::cout << "Introduceti un numar intre 1 si 100: ";
		std::cin >> intNumar;

		// Validarea inputului
		if (intNumar < 1 || intNumar > 100) {
			std::cout << "Numarul introdus nu este in intervalul specificat. Va rugam sa reintroduceti." << std::endl << std::endl;
		}
	} while (intNumar < 1 || intNumar > 100);

	std::cout << "Ati introdus un numar valid: " << intNumar << std::endl << std::endl;
}