#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definición del tipo de dato Elem
typedef int Elem; 

// Definición de Lista
typedef struct Lista {
    Elem cabeza;
    struct Lista* resto;
} Lista; 

// Función para crear una lista vacía
Lista* vacia() {
    return NULL;
}

// Función para agregar un elemento al inicio de la lista
Lista* cons(Elem nuevoElem, Lista* lista) {
    Lista* nuevaLista = (Lista*)malloc(sizeof(Lista));
    if (nuevaLista == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    nuevaLista->cabeza = nuevoElem;
    nuevaLista->resto = lista;
    return nuevaLista;
}

// Función para verificar si una lista está vacía
bool esVacia(Lista* lista) {
    return lista == NULL;
}

// Función para obtener la cabeza de la lista
Elem cabeza(Lista* lista) {
    if (esVacia(lista)) {
        printf("Error: Lista vacía. No se puede obtener la cabeza.\n");
        exit(EXIT_FAILURE);
    }
    return lista->cabeza;
}

// Función para obtener el resto de la lista
Lista* resto(Lista* lista) {
    if (esVacia(lista)) {
        printf("Error: Lista vacía. No se puede obtener el resto.\n");
        exit(EXIT_FAILURE);
    }
    return lista->resto;
}

// Función para imprimir la lista
void imprimirLista(Lista* lista) {
    while (!esVacia(lista)) {
        printf("%d -> ", cabeza(lista));
        lista = resto(lista);
    }
    printf("NULL\n");
}

// Función para liberar memoria de la lista
void liberarLista(Lista* lista) {
    while (!esVacia(lista)) {
        Lista* temp = lista;
        lista = resto(lista);
        free(temp);
    }
}

int main() {
    // Crear una lista vacía
    Lista* miLista = vacia();
    
    // Agregar elementos a la lista
    miLista = cons(3, miLista);
    miLista = cons(2, miLista);
    miLista = cons(1, miLista);
    
    // Imprimir la lista
    printf("Lista: ");
    imprimirLista(miLista);
    
    // Obtener la cabeza
    printf("Cabeza de la lista: %d\n", cabeza(miLista));
    
    // Obtener el resto de la lista e imprimirlo
    Lista* subLista = resto(miLista);
    printf("Resto de la lista: ");
    imprimirLista(subLista);
    
    // Liberar memoria
    liberarLista(miLista);
    
    return 0;
}
