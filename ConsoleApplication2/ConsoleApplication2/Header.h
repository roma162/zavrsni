#ifndef HEADER_H
#define HEADER_H

void lozinka();
void dodajRadnika();
void sviRadnici();
void traziRadnika();
void izmjeniRadnika();
void obrisiRadnika();
void izlaz();

struct datum {
	int dan;
	int mjesec;
	int godina;
};

struct podatci {
	int oib;
	char ime[20];
	char prezime[20];
	float placa;
	struct datum datumRodjenja;
};

#endif