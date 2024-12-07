#include "CGraph.cpp"

int main() {
    CGraph graph;

    // Ajout de l'ensemble des noeuds
    graph.addMultipleNodes(30);

    // Ajout de l'ensemble des arêtes
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);
    graph.addEdge(2, 4);
    graph.addEdge(5, 6);
    graph.addEdge(5, 7);
    graph.addEdge(5, 5);
    graph.addEdge(5, 1);
    graph.addEdge(6, 0);

    // Ajout de liens pour tous les noeuds vers le noeud 0
    for (int i = 0; i < 30; i++) {
        graph.addEdge(i, 0);
    }

    // // Ajout de liens aléatoires
    // graph.addRandomEdges(0.1);

    // Changement des poids des noeuds et des arêtes
    graph.getNodeById(2)->setValeur(5);
    graph.getNodeById(6)->setValeur(10);
    graph.getEdgeByNodes(1, 2)->setWeight(5);
    graph.getEdgeByNodes(2, 3)->setWeight(7);
    graph.getEdgeByNodes(6, 0)->setWeight(10);
    // Note : c'est pas parfait, si le noeud n'est pas trouvé, ça plante, il faudrait gérer les erreurs...

    // Exportation dans un format utilisable sur Gephi
    graph.exportToGEXF("main.gexf");

    return 0;
}

// Executer sous Linux :
// g++ -o graph main.o
// ./graph
