#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath> 


int moda_multimap(const std::multimap<int, double>& dicionario) {
    // Verificar se o multimap está vazio
    if (dicionario.empty()) {
        throw std::invalid_argument("multimap vazio");
    }

    // Criar um vetor para armazenar as chaves com as maiores frequências
    std::vector<int> modas;

    // Inicializar a variável para armazenar a maior frequência encontrada
    int max_frequencia = 0;

    // Loop para percorrer as chaves do multimap
    for (auto it = dicionario.begin(); it != dicionario.end(); ++it) {
        int chave = it->first;
        double valor_anterior = it->second;

        // Inicializar a variável para armazenar a frequência da chave atual
        int frequencia = 1;

        // Vetor para armazenar as chaves com valores próximos
        std::vector<int> chaves_proximas = { chave };

        // Loop para percorrer os valores para a chave atual
        while (++it != dicionario.end() && it->first == chave) {
            double valor_atual = it->second;
            double diff = std::abs(valor_atual - valor_anterior);
            if (diff < 2.5) {
                chaves_proximas.push_back(chave);
                frequencia++;
            }
            valor_anterior = valor_atual;
        }

        // Voltar o iterador para a última posição analisada
        --it;

        // Verificar se a frequência atual é maior que a frequência máxima encontrada até agora
        if (frequencia > max_frequencia) {
            max_frequencia = frequencia;
            modas = chaves_proximas;
        }
    }

    // Calcular a média das modas
    double moda_media = 0;
    for (int chave : modas) {
        moda_media += chave;
    }
    moda_media /= modas.size();

    // Arredondar a média das modas para o inteiro mais próximo
    return static_cast<int>(std::round(moda_media));
}

int main()
{

std::multimap<int, double> dicionario = {{1, 3.56},
                                         {2, 5.56},
                                         {2, 6.56},
                                         {3, 8.34}, 
                                         {3, 10.56}, 
                                         {2, 12.30}, 
                                         {2, 13.66}, 
                                         {2, 14.52}, 
                                         {2, 15.56}, 
                                         {2, 16.28}, 
                                         {3, 17.45},
                                         {3, 18.45},
                                         {3, 18.50},
                                         {3, 28.50},
                                         {3, 38.50},
                                         {3, 48.50},
                                         {3, 58.50},
                                         {3, 68.50},
                                         {3, 78.50},
                                         {3, 88.50},
                                         {3, 98.50},
                                         {3, 118.50},
                                         {3, 201.45},  
                                         {3, 239.56}};

for (auto const & [key, value]:dicionario)
{
    std::cout << key << ":" << value << std::endl;
}
std::cout << "A moda e:" << moda_multimap(dicionario) << std::endl;
return 0;
}