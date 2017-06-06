#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

float CoeficienteLagrange(int n, int k, float b, float an){

	float indice = 1.0/(n-k);
	float raiz = b/an;
	float L = 1 + pow(raiz,indice);
	return L;

}

int main(int argc, char* argv[]){

	std::vector<float> limite_superior;
	std::vector<float> limite_inferior;
	std::vector<float> limite_superiorneg;
	std::vector<float> limite_inferiorneg;
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


		            if((counter >= 1) && (counter <= 4)) limite_superior.push_back(atof(token.c_str()));

		            else if ((counter >= 5) && (counter <= 8))limite_inferior.push_back(atof(token.c_str()));

		            else if((counter >= 9) && (counter <= 12)) limite_superiorneg.push_back(atof(token.c_str()));

		            else if ((counter >= 13) && (counter <= 16))limite_inferiorneg.push_back(atof(token.c_str()));
		           
		            counter++;

		            
		            
		        
        }
    }



    info.close();

    infos.open("intervalos.txt");
    cout << "Intervalo das Raízes Positivas\n";
    
	//cout << "intervalo positivo inferior\n";
	if (!limite_inferior.empty())
	cout << "["<< 1.0/CoeficienteLagrange(limite_inferior[0],limite_inferior[1],limite_inferior[2],limite_inferior[3]) << ",";
	infos << "\n";
	if (!limite_superior.empty())
		cout << CoeficienteLagrange(limite_superior[0],limite_superior[1],limite_superior[2],limite_superior[3]) <<	"]"<<endl;
	infos << "\n";
	cout << "Intervalo das Raízes Negativas\n";
	infos << "\n";
	infos << "intervalo negativo inferior\n";
	if (!limite_superiorneg.empty())
	cout << "[" << -1*CoeficienteLagrange(limite_superiorneg[0],limite_superiorneg[1],limite_superiorneg[2],limite_superiorneg[3])<<",";
	if (!limite_inferiorneg.empty())
		cout << -1.0/CoeficienteLagrange(limite_inferiorneg[0],limite_inferiorneg[1],limite_inferiorneg[2],limite_inferiorneg[3]) << "]"<<endl;
	
	infos << "\n";
   
    

}