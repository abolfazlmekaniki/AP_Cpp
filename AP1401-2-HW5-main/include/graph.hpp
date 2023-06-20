#define INF 0x3f3f3f3f
#include <utility>
#include <set>
typedef std::pair<int, int> iPair;
template <typename T>
void Graph<T>::addVertex(const T &item)
{
    Node *node{new Node{item}};
    head.push_back(node);
    m[item];
}

template <typename T>
Graph<T>::~Graph(){

    for ( auto i :head)
    {
        while(i){
           Node* next{i->next};
           delete i;
           i= next;
        }
    }
    
    
};

template <typename T>
void Graph<T>::addEdge(const T &v1, const T &v2, int a, std::function<bool(T, T)> func)
{
    if (!func(v1, v2))
    {
        int v1_index;
        int v2_index;
        for (size_t i = 0; i < head.size(); i++)
        {
            if (head[i]->value==v1)
                v1_index = i;
            
            if (head[i]->value==v2)
                v2_index = i;
        };
        
        Node* nor{head[v1_index]};
        m[nor->value].push_back(std::make_pair(head[v2_index]->value, a));
        while(nor->weight){
         
            nor = nor->next;
           
        };

        nor->next=new Node{head[v2_index]->value}; 
        nor->weight =a;
        
       
    }
}
template <typename T>
int Graph<T>::getNumberEdges()
{
    return head.size();
};

template <typename T>
void Graph<T>::disp()
{

    for (size_t i = 0; i < head.size(); i++)
    {
        std::cout << "Node " << i << " : " <<std::endl<<"The value is = "<< head[i]->value << std::endl<<"neighbers : "<<std::endl;
        Node* nn{head[i]};
        while (nn->next)
        {
            std::cout<<nn->next->value<<" with weight of : "<<nn->weight<<std::endl;
            nn=nn->next;
        }
        std::cout<<std::endl;
        
    }
};

template <typename T>
std::vector<T> Graph<T>::getNeighbors(T vertex, std::function<bool(T, T)> func)
{
    std::vector<T> neighbors{};
    for (size_t i = 0; i < head.size(); i++)
    {
        if (func(head[i]->value, vertex))
        {
            Node *next_{head[i]->next};
            while (next_)
            {
                neighbors.push_back(next_->value);
                next_ = next_->next;
            }
        }
    }
    return neighbors;
};

template <typename T>
bool Graph<T>::isConnected(T source, T destination, std::function<bool(T, T)> func){
        std::vector<T> neighbors{getNeighbors(source,func)};
        for (size_t i = 0; i < neighbors.size(); i++){
                if(neighbors[i]==destination){
                    return true;
                };
                
        };
        return false;
}


template <typename T>
std::vector<T> Graph<T>::findShortestPath(T source, T destination, std::function<bool(T, T)> func){
    std::priority_queue< iPair, std::vector <iPair> , std::greater<iPair> > pq;
    std::map<int,int> dist;
    std::vector<int>path{source};
    std::vector<int>New_path{};
    for(auto i : m){
        dist[i.first]=INF;
    }
    pq.push(std::make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        path.push_back(u);
        if (u == destination) break; // stop if target is reached

        std::vector< std::pair<int, int> >::iterator i;
        for (auto i = m[u].begin(); i != m[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));
                
            }
        }
    }

    if (dist[destination] != INF) {
        std::set<int>path_;
        for(auto i:path){
            path_.insert(i);
        };
        for(auto i:path_){
            New_path.push_back(i);
        };
        return New_path;
    
    } else {
        std::cout << "No path found from " << source << " to " << destination << std::endl;
        return std::vector<int>{};
    }

}



