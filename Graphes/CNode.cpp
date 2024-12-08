#include <unordered_set>

class CNode 
{
private:
    int m_id;
    int m_value;
    std::unordered_set<int> m_neighbors;

public:
    CNode() : m_value(-1) {} // Lui il existe faute de meilleure solution pour une erreur (peut etre résolue entre temps jsp)
    CNode(int id) : m_id(id), m_value(0) {}

    int getId() const { return m_id; }
    int getValue() const { return m_value; }
    const std::unordered_set<int>& getNeighbors() const { return m_neighbors; }

    void setValue(int n) { m_value = n; }
    
    void addNeighbor(int neighbor_id) { m_neighbors.insert(neighbor_id); }

    int getDegree() const { return m_neighbors.size(); }
};
