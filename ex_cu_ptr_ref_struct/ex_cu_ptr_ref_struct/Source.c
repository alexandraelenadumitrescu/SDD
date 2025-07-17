#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
//📌 Nivel 1 — Pointeri & Structuri Simple
//Swap două numere cu pointeri
//
//Inițializare și afișare vector dinamic de numere întregi
//
//Structură Student cu pointer la char pentru nume și dinamic vector de note
//
//Funcție care primește pointer la structură și modifică un câmp

void swap(int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}
struct Student {
	char* nume;
	int* note;
	int nrNote;
};
typedef struct Student Student;
Student init(char* numeNou, int* noteNou,int nrNoteNou) {
	Student s;
	s.nume = (char*)malloc(strlen(numeNou) + 1);
	strcpy_s(s.nume, strlen(numeNou) + 1, numeNou);
	s.nrNote = nrNoteNou;
	s.note = (int*)malloc(sizeof(int) * s.nrNote);
	for (int i = 0;i < s.nrNote;i++) {
		s.note[i] = noteNou[i];
	}
	return s;
}
void modifNume(Student* s, const char* numeNou) {
	free(s->nume);
	s->nume = (char*)malloc(strlen(numeNou) + 1);
	strcpy_s(s->nume, strlen(numeNou) + 1, numeNou);

}
void afis(Student s) {
	printf("----------------------\n");
	for (int i = 0;i < s.nrNote;i++) {
		printf("%d", s.note[i]);

	}
	printf("----------------------\n");
	printf("%s", s.nume);
	printf("----------------------\n");
}
int main() {
	int a = 10;
	int b = 20;
	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
	printf("__________________\n");
	printf("introduceti dimensiunea vectorului\n");

	int dim;
	scanf_s("%d", &dim);
	if (dim <= 0) {
		printf("Dimensiune invalida!\n");
		return 1;
	}

	int* v = (int*)malloc(sizeof(int) * dim);
	if (v == NULL) {
		printf("Alocare esuata!\n");
		return 1;
	}
	
	for (int i = 0;i < dim;i++) {
		printf("introduceti elementul cu numarul %d : ", i+1);
		scanf_s("%d", &v[i]);
	}
	
	for (int i = 0;i < dim;i++) {
		printf(" elementul cu numarul %d : %d \n",i+1,v[i]);
		
	}
	free(v);
	int* w = (int*)malloc(sizeof(int) * 3) ;
	w[0] = 10;
	w[1] = 10;
	w[2] = 10;
	Student s1 = init("acestaesteunnume", w, 3);
	afis(s1);
	modifNume(&s1, "numenou");
	afis(s1);

	free(s1.note);
	free(s1.nume);
	

	
	return 0;
}