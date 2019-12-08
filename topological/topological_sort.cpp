#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

// 邻接表的数据结构
typedef struct chart_node {
    string name;
    int indegree;
    struct list<chart_node *> next; // 指向后驱节点

    bool operator ==(const struct chart_node & node) {
        return this->name == node.name;
    }
    bool operator ==(const string & name) {
        return this->name == name;
    }
} CHART_NODE;

class CTopologicalSort {
public:
    virtual ~CTopologicalSort() {
        for_each(m_nodes.begin(), m_nodes.end(), [](CHART_NODE *& it){ if (it) delete it, it = nullptr; });
    }
    void addNode(const string & from, const string & to);
    void output();
    CHART_NODE * find(const string & name);

private:
    list<CHART_NODE *> m_nodes;
};

CHART_NODE * CTopologicalSort::find(const string & name) {
    for (auto it = m_nodes.begin(); it != m_nodes.end(); ++it) {
        if (**it == name)
            return *it;
    }

    return nullptr;
}

void CTopologicalSort::addNode(const string & from, const string & to) {
    CHART_NODE * nodefrom = find(from);
    CHART_NODE * nodeto = find(to);

    if (nodefrom && nodeto) {
        for (auto it = nodefrom->next.begin(); it != nodefrom->next.end(); ++it) {
            if (*nodeto == **it)
                return;
        }
    }

    if (nullptr == nodefrom) {
        nodefrom = new CHART_NODE;
        nodefrom->name = from;
        m_nodes.push_back(nodefrom);
    }

    if (nullptr == nodeto) {
        nodeto = new CHART_NODE;
        nodeto->name = to;
        m_nodes.push_back(nodeto);
    }

    nodeto->indegree++;
    nodefrom->next.push_back(nodeto);
}

void CTopologicalSort::output() {
    for (auto it = m_nodes.begin(); it != m_nodes.end(); ++it) {
        CHART_NODE * node = *it;
        cout << node->name;
        for (auto itnt = node->next.begin(); itnt != node->next.end(); ++itnt) {
            cout << " ---> ";
            cout << (*itnt)->name;
        }
        cout << endl;
    }
}


int main(int argc, char *argv[]) {
    CTopologicalSort sort;

    sort.addNode("1", "2");
    sort.addNode("1", "3");
    sort.addNode("2", "4");
    sort.addNode("3", "5");

    sort.output();
}
