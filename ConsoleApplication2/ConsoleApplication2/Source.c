#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"

int main()
{
	lozinka();
	int x;
	while (1)
	{
		system("cls");
		printf("\n");
		printf("\t||||||||||IZBORNIK||||||||||\n\n");
		printf("\t|  1. Dodaj radnika:       |\n\n");
		printf("\t|  2. Prikazi sve radnike: |\n\n");
		printf("\t|  3. Pronadji radnika:    |\n\n");
		printf("\t|  4. Izmjeni radnika:     |\n\n");
		printf("\t|  5. Izbrisi radnika:     |\n\n");
		printf("\t|  6. Izlaz iz sustava:    |\n\n");
		printf("\t|||||||||||||||||||||||||||\n");
		printf("\n");

		printf("\nUnesite vas odabir:\t");
		scanf("%d", &x);

		switch (x)
		{
		case 1:
			dodajRadnika();
			break;
		case 2:
			sviRadnici();
			break;
		case 3:
			traziRadnika();
			break;
		case 4:
			izmjeniRadnika();
			break;
		case 5:
			obrisiRadnika();
			break;
		case 6:
			izlaz();
			break;
		}
	}

	return 0;
}
