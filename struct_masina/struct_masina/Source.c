#include<stdio.h>
//Definește o structură Masina care să conțină următoarele atribute :
//id(int),nrLocuri(int),marca(pointer la char alocat dinamic)
//capacitateC(float, capacitate cilindrică)
//normaPoluare(char, de exemplu '3', '4', '5', '6')
//Implementează o funcție de inițializare pentru o structură Masina care :
//primește toți parametrii necesari
//alocă dinamic memoria pentru marca
//copiază valoarea primită pentru marca în câmpul structurii
//Implementează o funcție afisare care primește o variabilă de tip Masina și afișează toate informațiile despre aceasta în format lizibil.
//Implementează o funcție modifica_NrLocuri care primește un pointer la o structură Masina și un nou număr de locuri și actualizează acest câmp doar dacă numărul este pozitiv.
//Implementează o funcție dezalocare care eliberează memoria alocată dinamic pentru marca și setează pointerul la NULL.
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
	return 0;
}