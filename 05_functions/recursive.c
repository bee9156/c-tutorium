/*
Diese Datei enthält ein paar rekursive Funktionen
*/

// includes
#include <stdio.h>

// Vorwärtdeklarationen
int rec_faculty(int a);
int it_faculty(int a);
int rec_array_sum(int* arr, int i);
int it_array_sum(int* arr);

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

	result = it_faculty(ende);
	printf("Die Fakultät von %d ist %d (iterativ)\n", ende, result);

	result = rec_array_sum(arr, 0);
	printf("Die Summe des Arrays ist %d (rekursiv)\n", result);

	result = it_array_sum(arr);
	printf("Die Summe des Arrays ist %d (iterativ)\n", result);

    printf("%d\n", arr[7]);
	

	return 0;
}



/*












int rec_faculty(int a) {
	if (a == 0) {
		return 1;
	} else {
		return a * rec_faculty(a-1);
	}
}*/

int it_faculty(int a) {
	int result = 1;

	while (a > 0) {
		result = result * a;
		a--;
	}

	return result;
}

/*int rec_array_sum(int* arr, int i) {
	if (i >= 0) {
		return 	arr[i] + rec_array_sum(arr, i -1);
	} else {
		return 0;
	}
}*/

int it_array_sum(int* arr) {
	int i;
	int result = 0;

	for (i = 0; arr[i] != '\0'; i++) {
		result = result + arr[i];
	}

	return result;
}	