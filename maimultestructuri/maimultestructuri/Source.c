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


//

//2. * *Scrie o funcție `initializare` care primește valorile pentru fiecare atribut și returnează o structură `Masina`. * *
//
//*Dacă parametrul `marca` este NULL, câmpul `marca` va rămâne NULL.
//* Altfel, alocă dinamic spațiu pentru `marca` și copiază valoarea primită.
//
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
//3. * *Scrie o funcție `afisare` care primește o structură `Masina` și afișează toate atributele acesteia.* *
//
void afisare(Masina m) {
	printf("%d\n", m.id);
	printf("%d\n", m.nrLocuri);
	if (m.marca != NULL) {

		printf("%s\n", m.marca);
	}
	printf("%f\n", m.capacitate);
	printf("%c\n", m.norma);

}

//4. * *Scrie o funcție `afisareVector` care primește un vector de `Masina` și numărul de elemente, și afișează fiecare mașină apelând funcția `afisare`.**
void afisareVector(Masina* masini, int nr) {
	for (int i = 0;i < nr;i++) {
		afisare(masini[i]);
	}
}
//5. * *Scrie o funcție `copiazaPrimeleMasini` care primește : **
//
//*un vector de mașini
//* numărul de elemente din vector
//* numărul de elemente pe care vrei să le copiezi
//
//Funcția va returna un vector nou care conține primele `nrElementeCopiate` mașini copiate prin alocare nouă și inițializare.
//

Masina deep(Masina m) {
	return init(m.id, m.nrLocuri, m.marca, m.capacitate, m.norma);
}
Masina* copiazaPrimeleMasini(Masina* masini, int nr, int nrElementeCopiate) {
	Masina* masiniNou = (Masina*)malloc(sizeof(Masina) * nrElementeCopiate);
	for (int i = 0;i < nrElementeCopiate;i++) {
		//masiniNou[i] = masini[i];
		masiniNou[i] = deep(masini[i]);
	}
	return masiniNou;
}
//6. * *Scrie o funcție `dezalocare` care primește : **
//
//*adresa unui vector de mașini
//* adresa numărului de elemente
void dezalocare(Masina* masini, int nr) {
	for (int i = 0;i < nr;i++) {
		free(masini[i].marca);

	}
	free(masini);
	masini = NULL;
}
//
//Funcția va elibera memoria pentru fiecare `marca` și apoi vectorul propriu - zis, setând pointerul la NULL și numărul de elemente la 0.
//
//7. * *Scrie o funcție `copiazaMasiniCuCCMare` care:**
//
//*primește un vector de mașini, numărul de elemente, un prag de capacitate cilindrică
//* returnează(prin pointeri) un vector nou cu mașinile care au capacitatea mai mare decât pragul
Masina* copiazaMasiniCuCCMare(Masina* masini, int nr, int prag) {
	int count = 0;
	for (int i = 0;i < nr;i++) {
		if (masini[i].capacitate > prag) {
			count++;
		}
	}
	Masina* nou = (Masina*)malloc(count * sizeof(Masina));
	int j = 0;
	for (int i = 0;i < nr;i++) {
		if (masini[i].capacitate > prag) {
			//nou[j] = masini[i];
			nou[j] = deep(masini[i]);
			j++;
		}
	}
	return nou;
}
//
//8. * *Scrie o funcție `getPrimaMasinaDupaMarca` care primește : **
//
//*un vector de mașini
//* numărul de elemente
//* un șir de caractere care reprezintă marca de căutat
//
//Funcția returnează prima mașină care are marca egală cu cea primită.Dacă nu există, returnează o mașină cu `nrLocuri = 0`, `marca = NULL`, `capacitateC = 0`, `normaPoluare = '0'`.
//
Masina getPrimaMasinaDupaMarca(Masina* masini, int nr, char* mc) {
	for (int i = 0;i < nr;i++) {
		if (strcmp(masini[i].marca, mc)) {
			
		}
		else {
			return masini[i];
		}
	}
	
		return init(0, 0, NULL, 0, 0);
}
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
int main() {
	Masina m = init(10, 5, "marca", 100, '1');
	afisare(m);
	Masina m1= init(11, 5, "VW", 150, '1');
	Masina m2 = init(12, 5, "marca", 200, '1');
	Masina* masini = (Masina*)malloc(sizeof(Masina) * 3);
	masini[0] = m;
	masini[1] = m1;
	masini[2] = m2;
	afisareVector(masini, 3);
	Masina* masiniNou = copiazaPrimeleMasini(masini, 3, 2);
	afisareVector(masiniNou, 2);
	Masina* x = copiazaMasiniCuCCMare(masini, 3, 0);
	printf("_--------------------\n");

	afisareVector(x,3);
	printf("------------");
	Masina m5 = getPrimaMasinaDupaMarca(masini, 3, "VW");
	afisare(m5);
	
	dezalocare(masini, 3);
	dezalocare(x, 3);
	dezalocare(masiniNou, 2);
	


	return 0;
}