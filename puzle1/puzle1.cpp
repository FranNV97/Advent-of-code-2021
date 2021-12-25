#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>

void lectura(std::vector<int>& numeros){
   std::fstream archivo;
   std::string linea; 
   int contador = 0;
   archivo.open("input_puzle1.txt");
   if(archivo.is_open()){
        while(std::getline(archivo,linea)){
            //std::getline(archivo,linea);
            contador++;
            if(contador >= 1998)
                std::cout<<linea<<"\n";
            numeros.push_back(std::stoi(linea));
        }
   }
   std::cout<<"hay "<<contador<<std::endl;
}

void prueba(){
    std::vector<int> hola;
    std::size_t size = 2001;
    std::cout<<hola.size()<<" "<<hola.capacity();
    hola.reserve(size);
    std::cout<<hola.capacity();
}

int parteA(std::vector<int> numeros){
    int contador, actual, previo;
    actual = previo = contador = 0;
    for(int i = 0; i < numeros.size(); i++){
        if(numeros[i] < numeros[i + 1])
            contador++;
    }
    return contador;
}

int parteA2(std::vector<int> numeros){
    int contador, previo, actual, iteracion; 
    contador = previo = actual = iteracion = 0;
    for(int i = 2; i < numeros.size(); i++){
        //std::cout<<"Iteracion "<<iteracion<<std::endl;
        //std::cout<<"Numeros del previo: "<<numeros[i - 2]<<" "<<numeros[i - 1]<<" "<<numeros[i]<<"\n";
        //std::cout<<"Numeros del actual: "<<numeros[i - 1]<<" "<<numeros[i]<<" "<<numeros[i + 1]<<"\n";
        previo = numeros[i] + numeros[i - 1] + numeros[i - 2];
        actual = numeros[i + 1] + numeros[i] + numeros[i - 1];
        //std::cout<<"Suma previo: "<<previo<<" suma actual: "<<actual<<"\n";
        if(previo < actual)
            contador++;
        iteracion++;
    }
    std::cout<<contador<<std::endl;
    return contador;
}

int parteA22(std::vector<int> numeros){
    int contador, previo, actual, iteracion; 
    contador = previo = actual = iteracion = 0;
    for(int i = 3; i < numeros.size() - 1; ++i){
        //std::cout<<"Iteracion "<<iteracion<<std::endl;
        //std::cout<<"Numeros del previo: "<<numeros[i - 3]<<" "<<numeros[i - 2]<<" "<<numeros[i - 1]<<"\n";
        //std::cout<<"Numeros del actual: "<<numeros[i - 2]<<" "<<numeros[i - 1]<<" "<<numeros[i]<<"\n";
        previo = numeros[i - 3] + numeros[i - 2] + numeros[i - 1];
        actual = numeros[i] + numeros[i - 1] + numeros[i - 2];
        //std::cout<<"Suma previo: "<<previo<<" suma actual: "<<actual<<"\n";
        if(actual > previo)
            contador++;
        iteracion++;
    }
    return contador;
}

int main(){
    std::vector<int> numeros;
    numeros.reserve(2000);
    lectura(numeros);
    //prueba();
    std::cout<<numeros.capacity()<<"\n";
    std::cout<<numeros[1999]<<"\n";
    int partea = parteA(numeros);
    int partea2 = parteA2(numeros);
    int partea22 =parteA22(numeros);
    std::cout<<"resultado del A: "<<partea<<" y del B: "<<partea2<<" y del C: "<<partea22;
}