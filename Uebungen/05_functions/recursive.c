/*
Diese Datei enthält ein paar rekursive Funktionen
*/

// includes
#include <stdio.h>

// Vorwärtdeklarationen
int rec_faculty(int a);
int rec_array_sum(int* arr, int i);

// definitionen
int rec_faculty(int a){
    if (a == 0){
        return 1;
    } else {
        return a * rec_faculty(a-1);
    }
}

int rec_array_sum(int* arr, int i){
    if ( arr[i] == '\0') {
        return 0;
    } else {
        return arr[i] + rec_array_sum(arr, i + 1);
    }
}

// main
int main(){
	int start = 0;
	int ende = 10;
	int result;
	int arr[7] = {2, 6, 7, 8, 3, 2, 0};

	result = rec_faculty(ende);
	printf("Die Fakultät von %d ist %d (rekursiv)\n", ende, result);

	result = rec_array_sum(arr, 0);
	printf("Die Summe des Arrays ist %d (rekursiv)\n", result);
	

	return 0;
}