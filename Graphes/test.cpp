#include "CGraph.cpp"

int main() {
    CGraph graph;

    // Ajout de l'ensemble des noeuds
    graph.addMultipleNodes(99);

    // Ajout de liens pour tous les noeuds vers les noeuds ayant les mêmes chiffres,
    // à chaque nouveau lien, la valeur des noeuds est incrémentée de 1
    for (int i = 0; i < 99; i++) {
        graph.addEdge(i, i % 10);
        graph.getNodeById(i)->setValeur(graph.getNodeById(i)->getValeur() + 1);
        graph.getNodeById(i % 10)->setValeur(graph.getNodeById(i % 10)->getValeur() + 1);

        graph.addEdge(i, i / 10);
        graph.getNodeById(i)->setValeur(graph.getNodeById(i)->getValeur() + 1);
        graph.getNodeById(i / 10)->setValeur(graph.getNodeById(i / 10)->getValeur() + 1);
    }

    // Exportation dans un format utilisable sur Gephi
    graph.exportToGEXF("test.gexf");

    return 0;
}




