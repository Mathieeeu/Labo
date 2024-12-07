// Structure de graphe pondéré & Algorithme de Dijkstra en C 

#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647

// structure pour représenter une arête du graphe
struct Edge {
    int src, dest, weight;
};

// structure pour représenter un graphe
struct Graph {
    int V, E; // Nombre de sommets et d'arêtes
    struct Edge* edge; // Tableau d'arêtes
};

// fonction pour créer un graphe avec V sommets et E arêtes
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

// fonction pour afficher le graphe
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->E; ++i) {
        printf("Edge %d: %d --(%d)--> %d\n", i, graph->edge[i].src, graph->edge[i].weight, graph->edge[i].dest);
    }
}

// fnoction pour trouver le sommet avec la distance minimale
int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// fonction pour afficher le tableau des distances
void printSolution(int dist[], int V, int src) {
    printf("Vertex \t Distance from Source (%d)\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

/* fonction pour implémenter l'algorithme de Dijkstra
        Algorithme de Dijkstra :
            1 - Initialiser les distances de tous les sommets comme infinies et la distance de la source comme 0.
            2 - Trouver le sommet avec la distance minimale parmi les sommets non traités.
            3 - Mettre à jour les valeurs des distances des sommets adjacents.
            4 - Répéter les étapes 2 et 3 jusqu'à ce que tous les sommets soient traités.
*/
void dijkstra(struct Graph* graph, int src) {
    
    int V = graph->V;
    int dist[V]; // tableau pour stocker la distance la plus courte de chaque sommet
    int sptSet[V]; // tableau pour savoir si le sommet est inclus dans le chemin le plus court

    // Initialiser les distances et sptSet
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    // la distance du sommet source à lui-même est évidemment 0 :)
    dist[src] = 0;

    // trouver le chemin le plus court pour tous les sommets
    for (int count = 0; count < V - 1; count++) {
        // Choisir le sommet avec la distance minimale
        int u = minDistance(dist, sptSet, V);

        // marquer le sommet comme ayant été traité
        sptSet[u] = 1;

        // mettre à jour les valeurs des distances des sommets adjacents
        for (int v = 0; v < V; v++) {
            for (int i = 0; i < graph->E; i++) {
                if (graph->edge[i].src == u && graph->edge[i].dest == v && !sptSet[v] &&
                    dist[u] != INT_MAX && dist[u] + graph->edge[i].weight < dist[v]) {
                    dist[v] = dist[u] + graph->edge[i].weight;
                }
            }
        }
    }

    // Afficher le tableau des distances
    printSolution(dist, V, src);
}

int main() {
    int V = 5; // nombre de sommets dans le graphe
    int E = 8; // nombre d'arêtes dans le graphe

    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 4;
    graph->edge[1].weight = 20;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 30;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 40;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 50;

    graph->edge[5].src = 2;
    graph->edge[5].dest = 3;
    graph->edge[5].weight = 60;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 4;
    graph->edge[6].weight = 70;

    graph->edge[7].src = 2;
    graph->edge[7].dest = 0;
    graph->edge[7].weight = 80;

    printGraph(graph);

    dijkstra(graph, 0);
    dijkstra(graph, 2);

    // libération de la mémoire
    free(graph->edge);
    free(graph);

    return 0;
}