#include <unordered_set>

class CNode 
{
private:
    int m_id;
    int m_nValeur;
    std::unordered_set<int> m_Voisins;

public:
    CNode() : m_nValeur(-1) {} // Lui il existe faute de meilleure solution pour une erreur (peut etre résolue entre temps jsp)
    CNode(int id) : m_id(id), m_nValeur(0) {}

    int getId() const { return m_id; }
    int getValeur() const { return m_nValeur; }
    const std::unordered_set<int>& getVoisins() { return m_Voisins; }

    void setValeur(int n) { m_nValeur = n; }
    
    void addVoisin(int id_voisin) {
        m_Voisins.insert(id_voisin);
    }
};
