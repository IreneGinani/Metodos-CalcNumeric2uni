#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

#define p 10

std::vector<float> pastas;


float funcao(float x){


	float func = 0;
	float aux = 0;
	for(int i = 0; i < pastas.size(); i++){

		if (i == 0)
			func = pastas[i];

		else{

		
		func += pastas [i] * pow(x,i);
		//cout << func<< endl;
	}

	}

	
	return func; 
}



bool troca_de_sinal(float &inicio, float &fim){


	float x = (inicio + fim)/2;
	inicio = x;
	float condicao = funcao(x) * funcao(x + p);
	int cont = 0;

	while(condicao > 0){

		x = x + p;

		condicao = funcao(x) * funcao(x + p);

		cout << "[" << x << "," << x+p<< "]" << endl;
		cont++;

	}


	fim = x + p;

	cout << "Intervalo encontrado em: " << cont << " iterações"<< endl;

	return true;

}



int main(int argc, char* argv[]){

	std::vector<float> intervalo;
	float inicio, fim;
    std::ofstream infos;
	 if (argc < 2) {
        std::cerr << "Arquivo não fornecido!" << std::endl;
        exit (1);
    }

    

    std::ifstream info(argv[1]);
    std::string line;
    int counter = 1;
        while(!info.eof()){
			getline(info,line);
			std::istringstream ss(line);
        	std::string token;
        	
        	while(getline(ss, token, ' ')) {


		            if((counter == 1) || (counter == 2)) intervalo.push_back(atof(token.c_str()));

		            else pastas.push_back(atof(token.c_str()));
		            counter++;

		            
		            
		        
        }
    }

    info.close();
   
    //cout << funcao(3) << endl;
	if (troca_de_sinal(intervalo[0], intervalo[1])){
		infos.open("infos.txt");
		infos << intervalo[0];
		infos << "\n";
		infos << intervalo[1];
		infos << "\n";
		for (int i = 0; i < pastas.size();i++){
			infos << pastas[i];
			infos << "\n";
		}
		//std::cout<<"deu certo!! Temos um 0 na função do intervalo: " << intervalo[0] << " até: "<< intervalo[1];
	}

}