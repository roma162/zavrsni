#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"

char sustav[] = { "radnik.dat" };

void lozinka() {
	int a, j = 3;
	printf("Unesite lozinku:(1111)\nImate samo 3 pokusaja!!!\t");
	for (int i = 0; i < 4; i++) {
		scanf("%d", &a);
		if (a == 1111) {
			printf("Otvaranje sustava...\n");
			break;
		}
		else {
			j--;
			if (j == 0) {
				printf("Zatvaranje programa...");
				exit(1);
			}
			printf("Pogresna lozinka! Ponovite unos!\nBroj pokusaja: %d\n", j);
		}
	}
	system("pause");
}

void dodajRadnika() {
	FILE* fp;
	struct podatci radnik;

	fp = fopen(sustav, "ab");
	if (fp == NULL) {
		printf("Neuspjesno kreiranje/otvaranje datoteke!!");
		exit(1);
	}
	printf("\nUnesite podatke radnika:\n");
	printf("\nOIB radnika: ");
	scanf("%d", &radnik.oib);
	printf("\nIme radnika: ");
	scanf("%s", radnik.ime);
	printf("\nPrezime radnika: ");
	scanf("%s", radnik.prezime);
	printf("\nDogovorenu placu: ");
	scanf("%f", &radnik.placa);
	printf("\nDan rodjenja: ");
	scanf("%d", &radnik.datumRodjenja.dan);
	printf("\nMjesec rodjenja: ");
	scanf("%d", &radnik.datumRodjenja.mjesec);
	printf("\nGodina rodjenja: ");
	scanf("%d", &radnik.datumRodjenja.godina);
	fwrite(&radnik, sizeof(radnik), 1, fp);

	fclose(fp);
}

void sviRadnici()
{
	FILE* fp;
	struct podatci radnik;

	fp = fopen(sustav, "rb");
	if (fp == 0) {
		printf("Sustav je prazan!\n");
		system("pause");
		return;
	}

	printf("\n\t\tPODATCI O SVIM RADNICIMA\n\n");
	printf("OIB\tIme\t\tPrezime\t\tPlaca\t\tDatum rodjenja\n\n");

	while (1)
	{
		fread(&radnik, sizeof(radnik), 1, fp);

		if (feof(fp))
		{
			break;
		}
		printf("%d\t", radnik.oib);
		printf("%s\t\t", radnik.ime);
		printf("%s\t\t", radnik.prezime);
		printf("%.2f\t\t", radnik.placa);
		printf("%d//%d//%d\n\n", radnik.datumRodjenja.dan, radnik.datumRodjenja.mjesec, radnik.datumRodjenja.godina);

	}
	printf("\n");

	fclose(fp);
	system("pause");
}

void traziRadnika()
{
	FILE* fp;
	struct podatci radnik;
	int oib, br = 0;

	fp = fopen(sustav, "rb");

	printf("\nUnesite OIB radnika:");
	scanf("%d", &oib);
	if (fp == NULL) {
		printf("Neuspjesno kreiranje/otvaranje datoteke!!");
		exit(1);
	}

	while (1)
	{
		fread(&radnik, sizeof(radnik), 1, fp);

		if (feof(fp))
		{
			break;
		}
		if (radnik.oib == oib)
		{
			br = 1;
			printf("\n");
			printf("\t\t PODATCI RADNIKA %d\n\n", radnik.oib);
			printf("\n");
			printf("Ime\t\tPrezime\t\tPlaca\t\tDatum rodjenja\n\n");

			printf("%s\t\t", radnik.ime);
			printf("%s\t\t", radnik.prezime);
			printf("%.2f\t\t", radnik.placa);
			printf("%d//%d//%d\n\n", radnik.datumRodjenja.dan, radnik.datumRodjenja.mjesec, radnik.datumRodjenja.godina);

			printf("\n");
		}
	}
	if (br == 0)
	{
		printf("\nRadnik s unesenim OIB-om nije pronadjen!!!\n");
	}
	fclose(fp);
	system("pause");
}

void izmjeniRadnika()
{
	FILE* fp, *temp;
	struct podatci radnik;
	int oib, br = 0;

	fp = fopen(sustav, "rb");
	temp = fopen("temp.dat", "wb");
	if (fp == NULL) {
		printf("Neuspjesno kreiranje/otvaranje datoteke!!");
		exit(1);
	}
	printf("\nUnesite OIB radnika kojem zelite izmijeniti podatke:\t");
	scanf("%d", &oib);

	while (1)
	{
		fread(&radnik, sizeof(radnik), 1, fp);

		if (feof(fp))
		{
			break;
		}
		if (radnik.oib == oib)
		{
			br = 1;
			printf("\n\tUNESITE NOVE PODATKE RADNIKA\n");
			printf("\nOIB radnika: ");
			scanf("%d", &radnik.oib);
			printf("\nIme radnika: ");
			scanf("%s", radnik.ime);
			printf("\nPrezime radnika: ");
			scanf("%s", radnik.prezime);
			printf("\nDogovorenu placu: ");
			scanf("%f", &radnik.placa);
			printf("\nDan rodjenja: ");
			scanf("%d", &radnik.datumRodjenja.dan);
			printf("\nMjesec rodjenja: ");
			scanf("%d", &radnik.datumRodjenja.mjesec);
			printf("\nGodina rodjenja: ");
			scanf("%d", &radnik.datumRodjenja.godina);
			fwrite(&radnik, sizeof(radnik), 1, temp);
		}
		else
		{
			fwrite(&radnik, sizeof(radnik), 1, temp);
		}
	}
	fclose(fp);
	fclose(temp);

	if (br == 0)
	{
		printf("Radnik s unesenim OIB-om nije pronadjen!!!\n\n");
	}
	else
	{
		fp = fopen(sustav, "wb");
		temp = fopen("temp.dat", "rb");

		while (1)
		{
			fread(&radnik, sizeof(radnik), 1, temp);

			if (feof(temp))
			{
				break;
			}
			fwrite(&radnik, sizeof(radnik), 1, fp);
		}

	}
	fclose(fp);
	fclose(temp);
	system("pause");
}

void obrisiRadnika()
{
	FILE* fp, *temp;
	struct podatci radnik;
	int oib, br = 0;

	fp = fopen(sustav, "rb");
	temp = fopen("temp.dat", "wb");
	if (fp == NULL) {
		printf("Neuspjesno kreiranje/otvaranje datoteke!!");
		exit(1);
	}
	printf("\nUnesite OIB radnika kojeg zelite obrisati iz sustava:\t");
	scanf("%d", &oib);

	while (1)
	{
		fread(&radnik, sizeof(radnik), 1, fp);

		if (feof(fp))
		{
			break;
		}
		if (radnik.oib == oib)
		{
			br = 1;
		}
		else
		{
			fwrite(&radnik, sizeof(radnik), 1, temp);
		}
	}
	fclose(fp);
	fclose(temp);

	if (br == 0)
	{
		printf("Radnik s unesenim OIB-om nije pronadjen!!!\n\n");
	}
	else
	{
		fp = fopen(sustav, "wb");
		temp = fopen("temp.dat", "rb");

		while (1)
		{

			fread(&radnik, sizeof(radnik), 1, temp);

			if (feof(temp))
			{
				printf("Radnik uspjesno uklonjen iz sustava!\n");
				break;
			}
			fwrite(&radnik, sizeof(radnik), 1, fp);
		}
	}
	fclose(fp);
	fclose(temp);
	system("pause");
}


void izlaz() {
	char ch;
	printf("\nJeste li sigurni da zelite izaci iz sustava?(y/n) : \t");
	ch = getche();
	printf("\n");
	if (ch == 'y' || ch == 'Y') {
		printf("Zatvaranje sustava...\n");
		exit(1);
	}
	else {
		printf("Pogresan unos! Vracanje na izbornik...\n");
		system("pause");
		return;
	}
}