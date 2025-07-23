//### ✅** Cerințe complete pentru codul tău**
//
//-- -
#include<stdio.h>
#include<stdlib.h>
//
//1. * *Definește o structură `Masina` care să conțină următoarele atribute : **
//
//*`id` de tip `int`
//* `nrLocuri` de tip `int`
//* `marca` de tip pointer la `char`, alocat dinamic
//* `capacitateC` de tip `float` (capacitatea cilindrică)
//* `normaPoluare` de tip `char` (ex: '3', '4', '5', '6')
struct Masina {
	int id;
	int nrLocuri;
	char* marca;
	float capacitate;
	char norma;
};
typedef struct Masina Masina;
Masina init(int id, int nrLocuri, char* marca, float capacitate, char norma) {
	Masina m;

	m.id = id;
	m.nrLocuri = nrLocuri;
	m.capacitate = capacitate;
	m.norma = norma;
	if (marca == NULL) {
		m.marca = NULL;

	}
	else {
		m.marca = (char*)malloc(sizeof(char) * strlen(marca) + 1);
		strcpy_s(m.marca, strlen(marca) + 1, marca);
	}
	return m;

}
int main() {
	
	

	return 0;
}
//

//2. * *Scrie o funcție `initializare` care primește valorile pentru fiecare atribut și returnează o structură `Masina`. * *
//
//*Dacă parametrul `marca` este NULL, câmpul `marca` va rămâne NULL.
//* Altfel, alocă dinamic spațiu pentru `marca` și copiază valoarea primită.
//
//3. * *Scrie o funcție `afisare` care primește o structură `Masina` și afișează toate atributele acesteia.* *
//
//4. * *Scrie o funcție `afisareVector` care primește un vector de `Masina` și numărul de elemente, și afișează fiecare mașină apelând funcția `afisare`.**
//
//5. * *Scrie o funcție `copiazaPrimeleMasini` care primește : **
//
//*un vector de mașini
//* numărul de elemente din vector
//* numărul de elemente pe care vrei să le copiezi
//
//Funcția va returna un vector nou care conține primele `nrElementeCopiate` mașini copiate prin alocare nouă și inițializare.
//
//6. * *Scrie o funcție `dezalocare` care primește : **
//
//*adresa unui vector de mașini
//* adresa numărului de elemente
//
//Funcția va elibera memoria pentru fiecare `marca` și apoi vectorul propriu - zis, setând pointerul la NULL și numărul de elemente la 0.
//
//7. * *Scrie o funcție `copiazaMasiniCuCCMare` care:**
//
//*primește un vector de mașini, numărul de elemente, un prag de capacitate cilindrică
//* returnează(prin pointeri) un vector nou cu mașinile care au capacitatea mai mare decât pragul
//
//8. * *Scrie o funcție `getPrimaMasinaDupaMarca` care primește : **
//
//*un vector de mașini
//* numărul de elemente
//* un șir de caractere care reprezintă marca de căutat
//
//Funcția returnează prima mașină care are marca egală cu cea primită.Dacă nu există, returnează o mașină cu `nrLocuri = 0`, `marca = NULL`, `capacitateC = 0`, `normaPoluare = '0'`.
//
//9. * *În funcția `main`: * *
//
//*alocă un vector dinamic de 3 mașini și inițializează - le cu valori
//* afișează vectorul de mașini
//* copiază primele 2 mașini într - un vector nou și afișează - l
//* eliberează memoria vectorului copiat
//* copiază mașinile care au capacitatea cilindrică mai mare decât 10
//* afișează noul vector rezultat și eliberează memoria
//* caută prima mașină cu marca `"Opel"` și afișează - o
//* la final, eliberează memoria alocată pentru vectorul inițial
//
//-- -
//
//### ✅ * *Extra * *
//
//*Codul calculează și compară capacitatea cilindrică cu un prag.
//* Se practică tehnica de * *deep copy * *când se alocă memoria pentru câmpul `marca`.
//
//-- -
//
//Vrei să - ți scriu și o variantă * *simplificată sau comentată pas cu pas * *?
