//Merge Sort
//Es un algoritmo de ordenamiento que sigue la estrategia divide y vencerás.
//Primero divide una lista en partes iguales hasta que quedan sublistas de 1 o 0 elementos.
//Luego las recombina en forma ordenada.
//Complejidad: O(n log n)

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec, vector<int> &left_vec, vector<int> &right_vec){

    int leftsize = left_vec.size(); //Tamaño del vector izquierdo
    int rightsize = right_vec.size(); //Tamaño del vector derecho

    //indices para recorrer los vectores
    int i=0; //indice para el vector 
    int l=0; //indice para el vector izquierdo
    int r=0; //indice para el vector derecho

    while(l<leftsize && r<rightsize){ //Mientras no se haya recorrido todo el vector izquierdo y derecho

        if(left_vec[l] < right_vec[r]){ //Si el elemento del vector izquierdo es menor al del vector derecho
            vec[i] = left_vec[l]; //Se asigna el elemento del vector izquierdo al vector original
            l++; //Se incrementa el indice del vector izquierdo
            i++; //Se incrementa el indice del vector original

        }

        else{ //Si el elemento del vector derecho es menor al del vector izquierdo
            vec[i] = right_vec[r]; //Se asigna el elemento del vector derecho al vector original
            r++; //Se incrementa el indice del vector derecho
            i++; //Se incrementa el indice del vector original
        }
    }

    while(l<leftsize){ //Mientras no se haya recorrido todo el vector izquierdo
        vec[i] = left_vec[l]; //Se asigna el elemento del vector izquierdo al vector original
        l++; //Se incrementa el indice del vector izquierdo
        i++; //Se incrementa el indice del vector original
    }
    while(r<rightsize){ //Mientras no se haya recorrido todo el vector izquierdo
        vec[i] = right_vec[r]; //Se asigna el elemento del vector izquierdo al vector original
        r++; //Se incrementa el indice del vector izquierdo
        i++; //Se incrementa el indice del vector original
    }
}

void mergesort(vector<int> &vec){

    int n = vec.size();
    if(n<=1){return;} //Caso base
    int center = n/2;

    //Creamos dos vectores para dividir el vector original con el size inicial basado en el centro y el tamaño del vector original
    vector<int> left_vec(center); //Vector izquierdo
    vector<int> right_vec(n-center); //Vector derecho

    for(int i=0; i<n; i++){ //Aqui se divide el vector en dos, izquierdo y derecho, y se llena cada uno con los elementos correspondientes
        if(i<center){
            left_vec[i] = vec[i]; //Se llena el vector izquierdo
        }else{
            right_vec[i-center] = vec[i]; //Se llena el vector derecho en base al centro
        }
    }

    //--Divide--//
    mergesort(left_vec); //Se llama recursivamente a la función mergesort para el vector izquierdo
    mergesort(right_vec); //Se llama recursivamente a la función mergesort para el vector derecho

    //--Conquer--//
    merge(vec, left_vec, right_vec); //Se llama a la función merge para unir los vectores izquierdo y derecho
}

void print(vector<int> &vec){ //Función para imprimir el vector
    cout<<endl<<"[";
    for(int i=0; i<vec.size(); i++){
        if(i<vec.size()-1){
            cout<<vec[i]<<", ";
            }else{
                cout<<vec[i];
            }
    }
    cout<<"]"<<endl<<endl;
}

int main(){

    vector<int> vec = {12, 3, 7, 9, 14, 6, 11, 2};

    cout<<endl<<"Vector original: ";
    print(vec); 

    mergesort(vec); 

    cout<<endl<<"Vector ordenado: ";
    print(vec);

    return 0;
}

