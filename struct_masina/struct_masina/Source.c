#include<stdio.h>
#include<stdlib.h>
//Definește o structură Masina care să conțină următoarele atribute :
//id(int),nrLocuri(int),marca(pointer la char alocat dinamic)
//capacitateC(float, capacitate cilindrică)
//normaPoluare(char, de exemplu '3', '4', '5', '6')
struct Masina {
	int id;
	int nrLocuri;
	char* marca;
	float cap;
	char norma;

};
typedef struct Masina Masina;
//Implementează o funcție de inițializare pentru o structură Masina care :
//primește toți parametrii necesari
//alocă dinamic memoria pentru marca
//copiază valoarea primită pentru marca în câmpul structurii
Masina init(int idn,int nrlocn,char* marcan,float capn,char norman) {
	Masina m;
	m.id = idn;
	m.nrLocuri = nrlocn;
	m.marca = (char*)malloc(strlen(marcan) + 1);
	strcpy_s(m.marca, strlen(marcan) + 1, marcan);
	m.cap = capn;
	m.norma = norman;
	return m;
}

//Implementează o funcție afisare care primește o variabilă de tip Masina și afișează toate informațiile despre aceasta în format lizibil.
void afis(Masina m) {
	printf("%d\n", m.id);
	printf("%d\n", m.nrLocuri);
	printf("%s\n", m.marca);
	printf("%f\n", m.cap);
	printf("%c\n", m.norma);

}
//Implementează o funcție modifica_NrLocuri care primește un pointer la o structură Masina și un nou număr de locuri și actualizează acest câmp doar dacă numărul este pozitiv.
void modifNrLocuri(Masina* m, int nou) {
	if (nou > 0) {
		m->nrLocuri = nou;
	}
}
//Implementează o funcție dezalocare care eliberează memoria alocată dinamic pentru marca și setează pointerul la NULL.
void dez(Masina* m) {
	free(m->marca);
	(*m).marca = NULL;
}
//În main :
//creează o variabilă de tip Masina folosind funcția de inițializare
//afișează mașina
//modifică numărul de locuri cu o valoare nouă
//afișează din nou mașina
//dezalocă memoria ocupată de marca mașinii
//afișează din nou mașina(pentru a verifica că pointerul marca este acum NULL)
//afișează dimensiunea în octeți a unui pointer la structură Masina
//afișează dimensiunea în octeți a structurii Masina

int main() {
	Masina m1;
	printf("%d\n", sizeof(m1));
	m1 = init(101, 5, "dacia", 2000, 6);
	afis(m1);
	modifNrLocuri(&m1, 6);
	afis(m1);
	printf("%d\n", sizeof(m1));
	dez(&m1);
	printf("%d", sizeof(m1));
	printf("%d", sizeof(Masina*));
	return 0;
}