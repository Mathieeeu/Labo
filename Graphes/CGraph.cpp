#include <unordered_map>
#include <set>
#include <fstream>
#include <iostream>
#include "CNode.cpp"
#include "CEdge.cpp"

class CGraph 
{
private:
    std::unordered_map<int, CNode> m_nodes;
    std::set<CEdge> m_edges;
    // Note : Unordered_map : hashmap liant les noeuds et leur valeur (recherche plus rapide qu'une liste classique)
    // Note : Set = liste ordonnée d'objets

public:
    void addNode(int n) {
        m_nodes[n] = CNode(n);
    }

    void addMultipleNodes(int number, int start = 0) {
        for (int i = start; i < start + number; i++) {
            addNode(i);
        }
    }

    void addEdge(int node1, int node2) {
        CEdge edge(node1, node2);
        if (m_edges.find(edge) == m_edges.end()) {
            m_edges.insert(edge);
            m_nodes[node1].addVoisin(node2);
            m_nodes[node2].addVoisin(node1);
        }
    }

    void addRandomEdges(float probability) {
        int nb = 0;
        srand(time(NULL)); // Initialisation de la graine pour la fonction rand()
        for (const auto& pair1 : m_nodes) {
            for (const auto& pair2 : m_nodes) {
                if (pair1.first < pair2.first && (float)rand() / RAND_MAX < probability) {
                    addEdge(pair1.first, pair2.first);
                    nb++;
                }
            }
        }
        std::cout << nb << " aretes ajout\202es" << std::endl;
    }

    const std::unordered_map<int, CNode>& getNodes() const { return m_nodes; }
    const std::set<CEdge>& getEdges() const { return m_edges; }

    CNode* getNodeById(int id) {
        auto it = m_nodes.find(id);
        if (it != m_nodes.end()) {
            return &it->second;
        }
        return nullptr;
    }

    CEdge* getEdgeByNodes(int node1, int node2) {
        CEdge edge(node1, node2);
        auto it = m_edges.find(edge);
        if (it != m_edges.end()) {
            return const_cast<CEdge*>(&(*it));
        }
        return nullptr;
    }

    void exportToGEXF(const std::string& filename) 
    {
        std::ofstream file(filename);

        // En-tête du fichier GEXF
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        file << "<gexf xmlns=\"http://www.gexf.net/1.2draft\" version=\"1.2\">\n";
        file << "<graph node=\"static\" defaultedgetype=\"undirected\">\n";

        // Définition des attributs d'un noeud
        file << "<attributes class=\"node\" mode=\"static\">\n";
        file << "<attribute id=\"0\" title=\"Value\" type=\"integer\"/>\n";
        file << "</attributes>\n";

        // Définition des attributs d'une arête
        file << "<attributes class=\"edge\" mode=\"static\">\n";
        file << "<attribute id=\"0\" title=\"Weight\" type=\"integer\"/>\n";
        file << "</attributes>\n";
        // Note : Pas utilisé ici, mais peut être utile pour ajouter des poids aux arêtes

        // Export des noeuds
        file << "<nodes>\n";
        const auto& nodes = getNodes();
        for (const auto& pair : nodes) {
            const CNode& node = pair.second;
            file << "<node id=\"" << node.getId() << "\" label=\"" << node.getId() << "\">\n";
            file << "<attvalues>\n";
            file << "<attvalue for=\"0\" value=\"" << node.getValeur() << "\"/>\n";
            file << "</attvalues>\n";
            file << "</node>\n";
        }
        file << "</nodes>\n";

        // Export des arêtes
        file << "<edges>\n";
        int edgeId = 0;
        const auto& edges = getEdges();
        for (const auto& edge : edges) {
            file << "<edge id=\"" << edgeId++ << "\" source=\"" << edge.getNode1() << "\" target=\"" << edge.getNode2() << "\" >\n";
            file << "<attvalues>\n";
            file << "<attvalue for=\"0\" value=\"" << edge.getWeight() << "\"/>\n";
            file << "</attvalues>\n";
            file << "</edge>\n";
        }
        file << "</edges>\n";

        file << "</graph>\n";
        file << "</gexf>\n";

        file.close();

        std::cout << "Graphe export\202 dans " << filename << std::endl;
    }
};
