#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int berechneZuwachs(char* string) {

    if (string == NULL) return -1;     // hier: optional, Angabe lesen!!
    if (strlen(string) < 3) return -1; // optional, Prüfung auf mind. 3 Zeichen
    
    int result = 0;
    
    int i =0;
    
    for (i = 0; i < strlen(string); i++) {  // alternativ: string[i] != '\0'
        if (string[i] == '*'){          // alternativ: string[i] >= '0' && string[i] <= '9'
            if (string[i+1] >= '3' && string[i+1] <= '9'){  // optional
                result += string[i+1] -'0' - 3;
            }
        }
    
    }
    
    
    return result;
}

char* uncompress(char* string) {
    if(string == NULL) return;  // hier nicht nötig, siehe Angabe

    char* neu = malloc((strlen(string) + berechneZuwachs(string) +1) * sizeof(char));

    int i = 0;
    int target = 0;
    
    for (i = 0; i < strlen(string); i++){
        if (string[i] != '*') {
            neu[target] = string[i];
            target++;
        } else {
            int zahl = string[i+1] - '0';
            
            for (zahl -= 1;zahl > 0; zahl--){
                neu[target] = string[i-1];
                target++;
            } 
            
            i++;
        }
    }
    
    neu[target] = '\0';

    return neu;         // nachträglich hinzugefügt
}



int main (void) {
  char* orig = "AAAABBBBCCJJJJHHHSSZZZZZZZZNNNCCCCCCCC";
  char* compressed ="A*4B*4CCJ*4HHHSSZ*8NNNC*8";

  /*puts("Originalstring:");
  printf("%s\n", wanted);

  puts("Codierter String:");
  char* encoded = encode(orig);
  printf("%s\n", encoded);
  puts("Überprüfung:");
  printf("%s\n", wanted);*/


  puts("Decodierter String:");
  char* decoded = uncompress(compressed);
  printf("%s\n", decoded);
  puts("Überprüfung:");
  printf("%s\n", orig);

  //free(encoded);

  return 0;
}