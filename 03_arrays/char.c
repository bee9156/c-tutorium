#include <stdio.h>
#include <string.h>


int main(){
  char text[] = "Ich bin ein Text ohne Sinn, aber mit den Zahlen 0,8,1,5";
  int i = 0;
/*
  while(text[i] != '\0'){
    printf("%c - %3d\n", text[i], text[i]);
    i++;
  }

  int bsp = '8' - '0';

  printf("%d\n", bsp);
*/
  char arr[] = "hallo";

  int j = 0;


  for ( i = 0; i < strlen(arr); i++) {  // Schleife 1
    for (j = 0; j < i; j++) {           // Schleife 2
      printf("*");
    }
    
    printf("%c", arr[i]);

    for (j++; j < strlen(arr); j++) {    // Schleife 3
      printf("*");
    }

    printf("\n");
  }

  return 0;
}
