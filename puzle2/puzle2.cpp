#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>

void lectura(std::vector<std::pair<std::string,int>>& container){
    std::fstream archivo;
    std::string linea, direccion; 
    int valor = 0;
    archivo.open("input_puzle2");
    if(archivo.is_open()){
        while(std::getline(archivo,linea)){
            std::stringstream split(linea);
            split >> direccion >> valor;
            container.push_back(std::make_pair(direccion, valor));
        }
    }
}

void parteA(std::vector<std::pair<std::string,int>> container){
    int horizontal, depth;
    horizontal = depth = 0;
    for(int i = 0; i < container.size(); i++){
        switch(container[i].first[0]){
            case 'f':
                horizontal += container[i].second;
            break;

            case 'd':
                depth += container[i].second;
            break;

            case 'u':
                depth -= container[i].second;
            break;
        }
    }
    int total = horizontal * depth;
    std::cout<<total<<"\n";
}

void parteB(std::vector<std::pair<std::string,int>> container){
    int horizontal, depth, aim;
    horizontal = depth = aim = 0;
    for(int i = 0; i < container.size(); i++){
        switch(container[i].first[0]){
            case 'f':
                horizontal += container[i].second;
                depth += aim * container[i].second;
            break;

            case 'd':
                aim += container[i].second;
            break;

            case 'u':
                aim -= container[i].second;
            break;
        }
    }
    int total = horizontal * depth;
    std::cout<<total<<"\n";
}

int main(){
    std::vector<std::pair<std::string,int>> container;
    container.reserve(1000);
    lectura(container);
    parteA(container);
    parteB(container);
    /*std::string linea = "linea 5";
    std::stringstream partir(linea);
    std::string tipo; int x;
    partir >> tipo >> x;
    std::cout<<"tipo: "<<tipo<<" x: "<<x;
    std::vector<std::pair<std::string,int>> container2;
    container2.push_back(std::make_pair("hola", 3));
    switch(container2[0].first[0]){
        case 'o':
        std::cout<<"holaaa";
        break;
        default:
        std::cout<<"adios";
    }
    std::string hola = "hola";
    std::cout<<hola[0];
    const char* p = hola.c_str();
    std::cout<<p<<"\n";
    int x = 3;
    int* x2 = &x;
    std::cout<<*x2<<"\n";
    char c = 'c';
    char* c2 = &c;
    std::cout<<&c2<<"\n";*/
    
}