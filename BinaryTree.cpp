#include <iostream>
using namespace std;

class Nodo{
   private:
     int valor;
     Nodo *izq;
     Nodo *der;

   friend class ArbolBinary;

   public:
     Nodo(int valor, Nodo *izq=nullptr, Nodo *der=nullptr){
         this->valor = valor;
         this->izq = izq;
         this->der = der;
     }
};

typedef Nodo *NodoArbol; //Arbol Binario de Busqueda

class ArbolBinary{
   private:
     NodoArbol raiz;
   public:
     ArbolBinary(){
        this->raiz = nullptr;
     }
     ~ArbolBinary(){};
     NodoArbol getRaiz();
     void insertar(NodoArbol &subArbol, int valor);
     void verArbol(NodoArbol subArbol, int nivel=0);
     void preOrden(NodoArbol subArbol);
     void enOrden(NodoArbol subArbol);
     void postOrden(NodoArbol subArbol);
     void borrar(NodoArbol &subArbol, int valor);
     bool comprobar(NodoArbol &subArbol);
     bool ArbolBinary::busqueda(NodoArbol arbol,int n);
};


NodoArbol crearNodo(int valor){
     NodoArbol nuevoNodo = new Nodo(valor);
     return nuevoNodo;
}


NodoArbol ArbolBinary::getRaiz(){
    return this->raiz;
}

void ArbolBinary::insertar(NodoArbol &subArbol, int valor){
     if (this->raiz == nullptr){ //el arbol esta vacio
         this->raiz = crearNodo(valor);
         return;
     }
     if(subArbol==nullptr){ //el nodo es una hoja
           subArbol = crearNodo(valor);
     }
     else if(valor < subArbol->valor)
          insertar(subArbol->izq, valor);
     else if(valor > subArbol->valor)
          insertar(subArbol->der, valor);
}
bool ArbolBinary::comprobar(NodoArbol &subArbol){
     if (this->raiz == nullptr){
         return false;
     }
     if(subArbol==nullptr)
        return true;
     else if(raiz->valor > subArbol->valor)
          return false;
     else if(raiz->valor < subArbol->valor)
          return false;
    else
        true;
}

void ArbolBinary::borrar(NodoArbol &subArbol, int valor){
  if(this->raiz != nullptr){
    if(subArbol == nullptr){
      this->raiz == nullptr;
    }
  }
}

bool ArbolBinary::busqueda(NodoArbol arbol,int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->valor == n){		
          return true;
	}
	else if(n < arbol->valor){
		return busqueda(arbol->izq,n);
	}
	else{
		return busqueda(arbol->der,n);
	}
}

void ArbolBinary::preOrden(NodoArbol subArbol){
     if(subArbol!=nullptr){
          cout << subArbol->valor <<" ";
          preOrden(subArbol->izq);
          preOrden(subArbol->der);
     }
}

void ArbolBinary::enOrden(NodoArbol subArbol){
     if(subArbol!=nullptr){
          enOrden(subArbol->izq);
          cout << subArbol->valor << " ";
          enOrden(subArbol->der);
     }
}

void ArbolBinary::postOrden(NodoArbol subArbol){
     if(subArbol!=nullptr){
          postOrden(subArbol->izq);
          postOrden(subArbol->der);
          cout << subArbol->valor << " ";
     }
}

void ArbolBinary::verArbol(NodoArbol subArbol, int nivel){
     if(subArbol==nullptr)
          return; //el arbol esta vacio
     verArbol(subArbol->der, nivel+1);
     for(int i=0; i<nivel; i++)
         cout<<"   ";  //espacios que ayudan a visualizar el arbol
     cout<< subArbol->valor <<endl;
     verArbol(subArbol->izq, nivel+1);
}



int main(){
    ArbolBinary arbol;
    int nNodos;  // numero de nodos del arbol
    int valor; // elemento a insertar en cada nodo
    bool comprobar;

    cout << "\n====[ ARBOL BINARIO DE BUSQUEDA ]======================\n" << endl;
    cout << " Numero de nodos del arbol:  ";
    cin >> nNodos;
    cout << endl;

    for(int i=0; i<nNodos; i++){
        cout << " Valor del nodo " << i+1 << ": ";
        cin >> valor;

        NodoArbol raizArbol = arbol.getRaiz();
        arbol.insertar(raizArbol, valor);
        comprobar=arbol.comprobar(raizArbol);
    }

    if(comprobar==false)
        cout<<true;

    cout << "\n Mostrando ABB \n\n";
    arbol.verArbol( arbol.getRaiz());

    cout << "\n Recorridos del ABB";
    cout << "\nEn orden   :  ";
       arbol.enOrden(arbol.getRaiz());
    cout << "\nPre Orden  :  ";
       arbol.preOrden(arbol.getRaiz());
    cout << "\nPost Orden :  ";
       arbol.postOrden(arbol.getRaiz());

    cout << endl << endl;
    return 0;
}
