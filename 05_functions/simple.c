/*
Diese Datei enthält ein paar simple Funktionen und deren Verwendung

*/

// includes
#include <stdio.h>

// Vorwärtsdeklarationen
int delta(int a, int b);
void exchange(int a, int b);
void exchange2(int* a, int* b);
int char_to_int(char c);
char int_to_char(int a);


// definitionen
int delta(int a, int b) {
	if (a > b){
		return a-b;
	} else {
		return b-a;
	}
}

void exchange(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void exchange2(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int char_to_int(char c) {
	return c - '0';
}

char int_to_char(int a) {
	return a + '0';
}

// Main
int main(){
	int i = 0;
	int a = 5;
	int b = 7;
	char c = 'X';
	int d = 75;
    double e = 0.0007;

    int result = delta(a, b);

	printf("Der Unterschied zwischen %d und %d beträgt %d\n", a, b, delta(a, b));

	exchange(a, b);

	printf("Der Unterschied zwischen %d und %d beträgt %d\n", a, b, delta(a, b));

	exchange2(&a, &b);

	printf("Der Unterschied zwischen %d und %d beträgt %d\n", a, b, delta(a, b));

	printf("Das Zeichen %c hat den Wert %d\n", c, char_to_int(c));
	printf("Die Zahl %d gehört zu Zeichen %c\n", d, d);

    printf("%.3f\n", e);





	return 0;
}