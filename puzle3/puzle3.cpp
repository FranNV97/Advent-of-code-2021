#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

void lectura(std::vector<std::string>& container){
    std::fstream archivo;
    std::string linea;
    archivo.open("input_puzle3.txt");
    while(std::getline(archivo,linea)){
        container.push_back(linea);
    }
}

int decimalConvert(unsigned long long binary){
    int result, exp;
    result = exp = 0;
    while(binary > 0){
        int digit = binary % 10;
        if (digit == 1)
            result += pow(2, exp);
        ++exp;
        binary /= 10;
    }
    return result;
}

void parteA(std::vector<std::string> container){
    int count0, count1,totalconsumption;
    unsigned long long gammavalue, epsilonvalue;
    std::string gammarate, epsilonrate;
    gammarate = epsilonrate = "";
    gammavalue = epsilonvalue = totalconsumption = 0;
    //std::cout<<container[0][3];
    for(int i = 0; i < container[i].length(); i++){
        count0 = count1 = 0;
        for(int j = 0; j < container.size(); j++){
            if(container[j][i] == '0')
                ++count0;
            else
                ++count1;
        }
        if(count0 > count1){
            gammarate = gammarate + '0';
            epsilonrate = epsilonrate + '1';
        }
        else{
            gammarate = gammarate + '1';
            epsilonrate = epsilonrate + '0';
        }
    }
    
    std::cout<<gammarate<<" "<<epsilonrate<<"\n";
    gammavalue = std::stoll(gammarate);
    epsilonvalue = std::stoll(epsilonrate);
    int gammadec = decimalConvert(gammavalue);
    int epsidec = decimalConvert(epsilonvalue);
    totalconsumption = gammadec * epsidec;
    std::cout<<"Consumo: "<<totalconsumption<<"\n";
}

void parteB(std::vector<std::string> container){
    std::vector<bool> check;//true means
    check.reserve(container.size());
}

int main(){
    unsigned long long z = 4294967296;
    //std::cout<<z;
    int x2 = 10110;
    int y = decimalConvert(x2);
    //std::cout<<y;
    std::vector<std::string> container;
    container.reserve(1000);
    lectura(container);
    parteA(container);
    std::string prueba = "3578";
    int x = 0;
    for(int i = 0; i < prueba.length(); i++){
        std::string substring = prueba.substr(i,1);
        x = x * 10 + std::stoi(substring);
    }
    //std::cout<<x;
}