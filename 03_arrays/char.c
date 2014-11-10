#include <stdio.h>

int main(){
  char text[] = "Ich bin ein Text ohne Sinn, aber mit den Zahlen 0,8,1,5";
  int i = 0;

  while(text[i] != '\0'){
    printf("%c - %3d\n", text[i], text[i]);
    i++;
  }

  return 0;
}
