//Cerințe
//
//Definirea structurii Masina
//

#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include <string.h>

struct  Masina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct Masina Masina;
Masina init(int id,int nrUsi,float pret,char* model,char* numeSofer,unsigned char serie) {
	Masina m;
	m.id = id;
	m.nrUsi = nrUsi;
	m.pret = pret;
	m.model = malloc(strlen(model) + 1);
	strcpy_s(m.model, strlen(model) + 1, model);

	m.numeSofer= malloc(strlen(numeSofer) + 1);
	strcpy_s(m.numeSofer, strlen(numeSofer) + 1, numeSofer);

	m.serie = serie;
	return m;

}

void afisare(Masina m) {
	printf("id %d\n", m.id);
	printf("nr usi %d\n", m.nrUsi);
	printf("pret %f\n", m.pret);
	printf("model %s\n", m.model);
	printf("nume sofer %s\n", m.numeSofer);
	printf("serie %c\n", m.serie);
}

//Să se definească o structură StructuraMasina care conține următoarele câmpuri :
//
//int id – identificatorul unic al mașinii.
//
//int nrUsi – numărul de uși al mașinii.
//
//float pret – prețul mașinii.
//
//char* model – modelul mașinii(alocat dinamic).
//
//char* numeSofer – numele șoferului(alocat dinamic).
//
//unsigned char serie – seria mașinii(un singur caracter).
//
//Se va defini un alias typedef pentru structură cu numele Masina.
//
//Funcții de afișare
//
//Să se implementeze o funcție void afisareMasina(Masina m) care afișează toate informațiile despre o mașină.
//
//Să se implementeze o funcție void afisareVectorMasini(Masina* masini, int nrMasini) care afișează toate mașinile dintr - un vector.
void afisareVectorMasini(Masina* masini, int nrMasini) {
	
	for (int i = 0;i < nrMasini;i++) {
		printf("masina %d\n", i+ 1);
		afisare(masini[i]);
		printf("\n");
	}
}
//
//Gestionarea dinamică a unui vector de mașini
//
//Să se implementeze o funcție void adaugaMasinaInVector(Masina * *masini, int* nrMasini, Masina masinaNoua) care adaugă o mașină nouă într - un vector alocat dinamic, realocând memorie.
void adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) {
	(*nrMasini)++;
	Masina* copie = (Masina*)malloc((*nrMasini) * sizeof(Masina));
	for (int i = 0;i < (*nrMasini) - 1;i++) {
		copie[i] = (*masini)[i];
	}
	copie[(*nrMasini) - 1] = masinaNoua;
	free(*masini);
	*masini = copie;
	
	
		
	}

//Citirea din fișier
//
//Fișierul masini.txt va conține informații despre mașini, câte o mașină pe linie, cu atribute separate prin, sau;.Exemplu:
//
//1, 4, 15000.5, BMW, Ion, A
//2, 2, 22000.0, Audi, Andrei, B
//
//
//Să se implementeze o funcție Masina citireMasinaFisier(FILE* f) care citește o linie din fișier și returnează structura Masina aferentă.
//
//Masina citireMasinaFisier(FILE* f) {
//	
//	char sep[4] = ",\n;";
//	char line[101];
//	fgets(line, 100, f);
//	Masina aux;
//	/*aux.id = atoi(strtok(line, sep));
//	aux.nrUsi = atoi(strtok(NULL, sep));
//	aux.pret = atof(strtok(NULL, sep));*/
//	aux.id = 0;
//	aux.nrUsi = 0;
//	aux.pret = 0;
//
//	/*char* buffer = strtok(NULL, sep);
//	aux.model= (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy_s(aux.model, strlen(buffer) + 1, buffer);*/
//	aux.model = (char*)malloc(3);
//	aux.model = "ab";
//
//	/*buffer = NULL;
//	buffer = strtok(NULL, sep);
//	aux.numeSofer=(char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//	strcpy_s(aux.numeSofer, strlen(buffer) + 1, buffer);*/
//	aux.numeSofer = (char*)malloc(3);
//	aux.numeSofer = "ab";
//
//	//buffer = strtok(NULL, sep);
//	//aux.serie = buffer[0];
//	aux.serie = 'z';
//
//	return aux;
//
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//	FILE* f;
//	f = fopen(numeFisier, "r");
//	Masina* v = NULL;
//
//	while (!feof(f)) {
//		adaugaMasinaInVector(&v,nrMasiniCitite,citireMasinaFisier(f));
//	}
//
//	
//	return v;
//}
int citireFisier(const char* numeFisier) {
	FILE* f;
	f = fopen(numeFisier, "r");
	
	int x;
	char buffer[100];
	
	fgets(buffer, 100, f);

	char sep[4] = ",\n;";
	x = atoi(strtok(buffer, sep));

	return x;

}

Masina citireMasinaFisier(char* line) {
	
	char sep[4] = ",\n;";
	//char line[101];*/
	//fgets(line, 100, f);
	Masina aux;
	aux.id = atoi(strtok(line,sep));

	aux.nrUsi = atoi(strtok(NULL, sep));

	aux.pret = atof(strtok(NULL, sep));

	char* buffer = strtok(NULL, sep);
	aux.model = (char*)malloc(sizeof(char) * (strlen(buffer)+1));
	strcpy_s(aux.model, strlen(buffer) + 1, buffer);

	buffer = strtok(NULL, sep);
	aux.numeSofer = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
	strcpy_s(aux.numeSofer, strlen(buffer) + 1, buffer);

	buffer = strtok(NULL, sep);
	aux.serie = buffer[0];
	
	return aux;


}
Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
	FILE* f;

	f = fopen(numeFisier, "r");
	Masina* vector=NULL;
	/*while (!feof(f)) {
		adaugaMasinaInVector(&vector, nrMasiniCitite, citireMasinaFisier(f));
	}*/
	char line[256];
	while (fgets(line, sizeof(line), f)) {
		Masina m = citireMasinaFisier(line);
		adaugaMasinaInVector(&vector, nrMasiniCitite, m);
	}
	return vector;
}
//
//Să se implementeze o funcție Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) care parcurge fișierul și returnează vectorul de mașini citite.
//
//Dezalocarea memoriei
//
//Să se implementeze o funcție void dezalocareVectorMasini(Masina** vector, int* nrMasini) care eliberează memoria alocată pentru vector și pentru câmpurile de tip șir de caractere.
//
void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
	if (*vector != NULL) {
		for (int i = 0; i < *nrMasini; i++) {
			free((*vector)[i].model);
			free((*vector)[i].numeSofer);
		}
		free(*vector);
		*vector = NULL;
		*nrMasini = 0;
	}
}

//Funcția main
//
//În main să se citească vectorul de mașini din fișierul masini.txt.
//
//Să se afișeze vectorul obținut.
//
//Să se elibereze memoria alocată.
//
//Să se afișeze din nou vectorul(pentru a verifica dezalocarea).
int main() {
	//printf("test");
	Masina m;
	m.id = 10;
	Masina m1 = init(100, 6, 300, "dacia2", "sofer2", 'b');
	afisare(m1);
	Masina m2 = init(200, 6, 300, "dacia3", "sofer3", 'c');
	printf("test vector\n");
	Masina* masini = malloc(2*sizeof(Masina));
	masini[0] = m1;
	masini[1] = m2;
	afisareVectorMasini(masini, 2);
	printf("--------------\n");
	int nr = 2;
	adaugaMasinaInVector(&masini, &nr, m2);
	afisareVectorMasini(masini, nr);
	printf("------------------\nACEASTA ESTE MASINA CITITA DIN FISIER");
	/*Masina mf = citireMasinaFisier("masini.txt");
	afisare(mf);*/
	int n = 0;
	Masina* v = NULL;
		v = citireVectorMasiniFisier("masini.txt", &n);
	afisareVectorMasini(v,n);
	//printf("%d", citireFisier("chiar.txt"));
	dezalocareVectorMasini(&v, &n);
	printf("Dupa dezalocare, nrMasini = %d\n", n);
	afisareVectorMasini(v, n); 

	return 0;
}






