#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* list_create_node(int data)
{
    // Speicherplatz fuer das neue Listenelement reservieren
    node_t* newNode = malloc(sizeof(node_t));

    // data-Element initialisieren
    newNode -> data = data;
    // next-Element mit NULL initialisieren
    newNode -> next = NULL;

    // neues Element zurueckgeben
    return newNode;
}

void list_insert_end_proc(node_t** panchor, int data)
{
    // anlegen eines temporaeren Pointers
    node_t* anchor = *panchor;

    // Ueberpruefung ob uebergebener Pointer ein Listenelement ist
    if (anchor == NULL){
        // Falls nicht vorhanden: erstelle neues Listenelement und weise es dem uebergebenem Pointer zu
        *panchor = list_create_node(data);
    } else {
        // Fall Listenelement vorhanden:

        // ueberpruefung ob weitere Elemente vorhanden sind
        while (anchor ->next != NULL){
            // weiteres Element vorhanden, eine Ebene tiefer
            anchor = anchor->next;
        }

        // neues Element am Listenende einfuegen
        anchor->next = list_create_node(data);
    }
}

node_t* list_append(node_t* anchor_a, node_t* anchor_b){
    // ueberpruefung ob uebergebener Pointer a NULL-Pointer ist
    if (anchor_a == NULL) {
        // Fall ja: andere NULL-Pointer auf Pointer b
        anchor_a = anchor_b;
    } else {
        // Fall nein: gehe in naechstes Listenelement und uebergebe Pointer b
        anchor_a -> next = list_append(anchor_a -> next, anchor_b);
    }

    // gebe Pointer a zurueck
    return anchor_a;
}

void list_free(node_t* anchor){
    // free the whole list
    if (anchor != NULL) {
        if (anchor -> next != NULL) {
            list_free(anchor -> next);
        }
        free(anchor);
    }
}

int main(){
    node_t* anchor_a = NULL;
    node_t* anchor_b = NULL;

    list_insert_end_proc(&anchor_a, 10);
    list_insert_end_proc(&anchor_a, 20);
    list_insert_end_proc(&anchor_b, 30);
    list_insert_end_proc(&anchor_b, 40);

    anchor_a = list_append(anchor_a, anchor_b);

    // Visualisierung start (kein Prüfungsinhalt)
    // Ausgabe der Liste a
    puts("Liste A:");
    node_t* cur_item = anchor_a;
    while (cur_item != NULL){
        printf("Data: %2d\n", cur_item ->data);
        cur_item = cur_item -> next;
    }

    // Ausgabe der Liste b
    puts("Liste B:");
    cur_item = anchor_b;
    while (cur_item != NULL){
        printf("Data: %2d\n", cur_item ->data);
        cur_item = cur_item -> next;
    }
    // Visualisierung ende;

    list_free(anchor_a);

    // Aufgabe d)
    // list_free(anchor_b);
    
    return EXIT_SUCCESS;
}
