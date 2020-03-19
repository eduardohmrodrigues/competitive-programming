#include <cstdio>
#include <iostream>
#include <climits>
#include <map>
#include <vector>

class node{

public:
    int index;
    int min_weight;
    std::map<int, int> edges;
    std::vector<int> path;

    node(int index){
        this->index = index;
        this->min_weight = INT_MAX;
        this->edges.clear();
        this->path.clear();
    }

    ~node(){}

    void set_min_weight(int w){
        this->min_weight = w < this->min_weight ? w : this->min_weight;
    }

    void insert_edge(int vertex, int weight){
        this->edges[vertex] = weight;
    }

    void reset_soft(){
        this->min_weight = INT_MAX;
        this->path.clear();
    }

    void reset_hard(){
        this->edges.clear();
        this->path.clear();
        this->min_weight = INT_MAX;
    }

    void to_string(){
        printf("index: %d weight: %d\n", index, min_weight);
    }
};

class graph{
private:
    int initial_vertex;

public:
    std::map<int, node*> visited_vertices;
    std::map<int, node*> unvisited_vertices;

    graph(){}

    ~graph(){}

    void visit(int index){
        this->visited_vertices[index] = this->unvisited_vertices[index];
        this->unvisited_vertices.erase(index);
        node curr = *(this->visited_vertices[index]);

        for(std::map<int, int>::iterator it=curr.edges.begin(); it!=curr.edges.end(); ++it){
            if(this->unvisited_vertices.find(it->first) != this->unvisited_vertices.end()){
                this->unvisited_vertices[it->first]->set_min_weight(curr.min_weight + it->second);
            }else{
                this->visited_vertices[it->first]->set_min_weight(curr.min_weight + it->second);
            }
        }
    }

    void reset_soft(){
        unvisited_vertices.insert(visited_vertices.begin(), visited_vertices.end());
        visited_vertices.clear();
        for(std::map<int, node*>::iterator it=unvisited_vertices.begin(); it!=unvisited_vertices.end(); ++it){
            it->second->reset_soft();
        }

        initial_vertex = -1;
    }

    int find_next_unvisited(){
        int minWeight = INT_MAX, index = -1;

        for(std::map<int, node*>::iterator it=unvisited_vertices.begin(); it!=unvisited_vertices.end(); ++it){
            if(it->second->min_weight < minWeight){
                minWeight = it->second->min_weight;
                index = it->first;
            }
        }

        return index;
    }

    void set_initial_vertex(int index){
        this->unvisited_vertices[index]->set_min_weight(0);
        visit(index);
        initial_vertex = index;
    }

    void resize(int size){
        reset_soft();
         for(std::map<int, node*>::iterator it=unvisited_vertices.begin(); it!=unvisited_vertices.end(); ++it){
            delete it->second;
        }


        this->unvisited_vertices.clear();
        for(int i=1; i<=size; ++i){
            this->unvisited_vertices[i] = new node(i);
        }
    }

    void insert_edge(int a, int b, int weight){
        this->unvisited_vertices[a]->insert_edge(b, weight);
        this->unvisited_vertices[b]->insert_edge(a, weight);
    }

    bool find_path(int p){
        int unvisited = find_next_unvisited();
        if(unvisited == -1) return false;
        visit(unvisited);

        if(unvisited != p)
            return find_path(p);
        else
            return true;
    }

    void populate_path(int p){
        int curr = p, minWeight = visited_vertices[p]->min_weight;

        node* selectedNode = visited_vertices[p];
        selectedNode->path.push_back(p);

        while(curr != initial_vertex){
            node n = *(visited_vertices[curr]);

            for(std::map<int, int>::iterator it=n.edges.begin(); it!=n.edges.end(); ++it){
                if(visited_vertices.find(it->first) != visited_vertices.end() && visited_vertices[it->first]->min_weight < minWeight){
                    curr = it->first;
                    minWeight = visited_vertices[curr]->min_weight;
                }
            }

            selectedNode->path.push_back(curr);
        }
    }

    void remove_path_to(int p){
        std::vector<int> path = visited_vertices[p]->path;

        for(int i=1; i<path.size(); ++i){
            visited_vertices[path[i-1]]->edges.erase(path[i]);
            visited_vertices[path[i]]->edges.erase(path[i-1]);
        }

        reset_soft();
    }

    void print(){
        for(std::map<int, node*>::iterator it=visited_vertices.begin(); it!=visited_vertices.end(); ++it){
            printf("%d: ", it->first);
            for(std::map<int, int>::iterator it2=it->second->edges.begin(); it2!=it->second->edges.end(); ++it2){
                printf("(%d, %d) ", it2->first, it2->second);
            }
            printf("\n");
        }

        for(std::map<int, node*>::iterator it=unvisited_vertices.begin(); it!=unvisited_vertices.end(); ++it){
            printf("%d: ", it->first);
            for(std::map<int, int>::iterator it2=it->second->edges.begin(); it2!=it->second->edges.end(); ++it2){
                printf("(%d, %d) ", it2->first, it2->second);
            }
            printf("\n");
        }
    }
};

int main(){
    graph g;
    int edges, vertices, a, b, w, cost;
    bool found = false;

    while(scanf("%d", &vertices) != EOF && vertices > 0){
        scanf("%d", &edges);
        g.resize(vertices);

        for(int i=0; i<edges; ++i){
            scanf("%d %d %d", &a, &b, &w);
            g.insert_edge(a, b, w);
        }

        if(vertices == 1 || edges == 0){
            printf("You need more vertices or more edges\n");
            continue;
        }

        g.set_initial_vertex(1);
        found = g.find_path(vertices);
        if(!found){
            printf("No path found!\n");
            continue;
        }

        cost = g.visited_vertices[vertices]->min_weight;
        printf("Weight 1 -> %d = %d\n", vertices, g.visited_vertices[vertices]->min_weight);
/*        g.populate_path(vertices);
        g.remove_path_to(vertices);

        g.set_initial_vertex(1);
        found = g.find_path(vertices);
        if(!found){
            printf("Back to jail\n");
            continue;
        }

        cost += g.visited_vertices[vertices]->min_weight;
        printf("%d\n", cost);
*/
    }

     return 0;
}
