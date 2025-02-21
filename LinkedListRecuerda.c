#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Elem;

typedef struct Lista{
    Elem cabeza;
    struct Lista* resto;
} Lista;

Lista* vacia(){
    return NULL;
}

Lista* cons(Elem cabeza, Lista* lista){
    Lista* nuevo = (Lista*)malloc(sizeof(Lista));
    if (!nuevo) return NULL;
    nuevo->cabeza = cabeza;
    nuevo->resto = lista;
    return nuevo;
}

bool esVacia(Lista* lista){
    return lista == NULL;
}

Elem cabeza(Lista* lista){
    return lista->cabeza;
}

Lista* resto(Lista* lista){
    if (esVacia(lista)) return NULL;
    else
        return lista->resto;
}

void impLista(Lista* lista){
    while(!esVacia(lista)){
        printf(" %d ->", cabeza(lista));
        lista = lista->resto;
    }
    printf(" NULL");
}

void liberarLista(Lista* lista){
    while(!esVacia(lista)){
        Lista* aux = lista;
        lista = resto(lista);
        free(aux);
    }
}

Lista* pegaLista(Lista* l1, Lista* l2){
    if(esVacia(l1))
        return l2;
    else
        return(cons(cabeza(l1), pegaLista(resto(l1), l2)));
}

Lista* invertirOrden(Lista* l){
    if(esVacia(l))
        return l;
    else
        return pegaLista(invertirOrden(resto(l)), cons(cabeza(l), vacia()));
}

Lista* insertarOrdenado(Elem e, Lista* l) {
    if (esVacia(l) || e <= cabeza(l)) 
        return cons(e, l);
    else
        return cons(cabeza(l), insertarOrdenado(e, resto(l)));
}

Lista* ordenarLista(Lista* l){
    if (esVacia(l))
        return l;
    else
        return insertarOrdenado(cabeza(l), ordenarLista(resto(l)));
}

int main(){
    // Crear dos listas
    Lista* lista1 = vacia();
    lista1 = cons(3, cons(1, cons(5, vacia())));
    
    Lista* lista2 = vacia();
    lista2 = cons(4, cons(2, cons(7, vacia())));
    
    printf("\n Lista 1: ");
    impLista(lista1);
    printf("\n Lista 2: ");
    impLista(lista2);
    
    // Unir listas con pegaLista
    Lista* listaUnida = pegaLista(lista1, lista2);
    printf("\n Lista Unida: ");
    impLista(listaUnida);
    
    // Ordenar la lista unida
    Lista* listaOrdenada = ordenarLista(listaUnida);
    printf("\n Lista Ordenada: ");
    impLista(listaOrdenada);
    
    // Insertar un elemento en orden
    listaOrdenada = insertarOrdenado(6, listaOrdenada);
    printf("\n Lista con 0 insertado en orden: ");
    impLista(listaOrdenada);
    
    // Invertir la lista
    Lista* listaInvertida = invertirOrden(listaOrdenada);
    printf("\n Lista Invertida: ");
    impLista(listaInvertida);
    
    // Liberar memoria
    liberarLista(listaInvertida);
    
    return 0;
}
