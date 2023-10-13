#include <iostream>
#include <sstream>
#include "graph.hpp"
#include "listaAdjacencia.hpp"

int main(int argc, char *argv[])
{
    Grafo grafo;
 
    //Recebe entrada do grafo.
    int numVertices;
    std::cout << "numero de Vértices: ";
    std::cin >> numVertices;
    std::vector<std::vector<int>> listaNumVizinhos(numVertices); // Uma matriz de vetores para armazenar vizinhos

    int numArestas;
    std::cout << "Número de arestas: ";
    std::cin >> numArestas;

    int grauMinimo;
    std::cout << "Grau mínimo do grafo: ";
    std:: cin >> grauMinimo;

    int grauMaximo;
    std::cout << "Grau máximo do grafo: ";
    std:: cin >> grauMaximo;


    for (int i = 0; i < numVertices; i++)
    {
        int numVizinhos;
        std::cout << "Número de vizinhos do vértice " << i + 1 << ": ";
        std::cin >> numVizinhos;

        for (int j = 0; j < numVizinhos; j++)
        {
            int vizinho;
            std::cout << "Vizinho " << j + 1 << " do vértice " << i + 1 << ": ";
            std::cin >> vizinho;

            listaNumVizinhos[i].push_back(vizinho); // Adiciona o vizinho ao vetor correspondente ao vértice i
        }
    }

    if (argc < 2)
    {
        std::cerr << "Uso: " << argv[0] << " <operacao> [argumentos]" << std::endl;
        return 1;
    }
    std::string operacao = argv[1];

    if (operacao == "-d")
    {
        // Executa a operação "-d" sem ler informações do grafo antecipadamente
        std::cout << "Quantidade de vértices: " << grafo.QuantidadeVertices(numVertices) << std::endl;
        std::cout << "Quantidade de arestas: " << grafo.QuantidadeArestas(numArestas) << std::endl;
        std::cout << "Grau mínimo: " << grafo.GrauMinimo(grauMinimo) << std::endl;
        std::cout << "Grau máximo: " << grafo.GrauMaximo(grauMaximo) << std::endl;
    }
    else if (operacao == "-n")
    {
        grafo.ImprimeVizinhos(numVertices, listaNumVizinhos);
    }
    else if (operacao == "-k")
    {
        int grafoCompleto = grafo.EhGrafoCompleto(numArestas, numVertices);
        std::cout << "O grafo é completo? " << grafoCompleto << std::endl;
    }
    else
    {
        std::cerr << "Operação inválida: " << operacao << std::endl;
        return 1;
    }

    return 0;
}
