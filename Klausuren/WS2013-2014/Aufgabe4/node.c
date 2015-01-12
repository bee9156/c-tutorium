#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* list_create_node(int data) {
    node_t* new_node = malloc(sizeof(node_t));
    
    new_node -> data = data;
    new_node -> next = NULL;
    
    return new_node;
}

void list_insert_front_proc(node_t** panchor, int data){
    // abspeichern des alten Anfangs
    node_t* old_start = *panchor;
    
    // erstellen neues Listenelement
    node_t* new_node = list_create_node(data);
    
    // laut Angabe muss nicht auf NULL überprüft werden
    new_node -> next = old_start;
    
    // hinterlegen des neuen Anfangs
    *panchor = newNode;
}

void reverse(node_t* normal, node_t** prev){
    // anlegen Hilfsvariablen
    // Um eine Liste umzudrehen benötigen wir 3 Hilfsvariablen, wobei hierfür der Parameter prev verwendet werden darf
    
    // Hilfsvariable aktuelles element
    node_t* cur_elem = normal;
    // Hilfsvariable nächstes element
    node_t* next_elem = normal -> next;
    
    // so lang das nächste Element != NULL ist, ist ein weiteres Element vorhanden
    while(next_elem != NULL){
        // nächstes Element verschieben
        next_elem = cur_elem -> next;
        
        // alten Listenanfang an aktuelles Element anhängen
        cur_elem -> next = *prev;
        // neuen Listenanfang abspeichern
        *prev = cur_elem;
        
        // nächstes Listenelement greifen
        cur_elem = next_elem;
    }
}

// vorgegebene Funktionen
list_free(node_t* a){
    if (a != NULL){
        list_free(a->next);
    }
    
    free(a);
}

list_print_data_from_front(node_t* a){
    if (a != NULL){
        printf("  %d", a->data);
        list_print_data_from_front(a->next);
    } else {
        printf("\n");
    }
}

int main(){
    node_t* anchor = NULL;
    
    list_insert_front_proc(&anchor, 10);
    list_insert_front_proc(&anchor, 20);
    list_insert_front_proc(&anchor, 30);
    list_insert_front_proc(&anchor, 40);
    
    // print list
    printf("         list:");
    list_print_data_from_front(anchor);
    
    node_t* reverted;   // no init
    reverse(anchor, &reverted);
    
    // print reverted list
    printf("reverted list:");
    list_print_data_from_front(reverted);
    
    // cleanup
    list_free(anchor);
    
    
    return 0;
}