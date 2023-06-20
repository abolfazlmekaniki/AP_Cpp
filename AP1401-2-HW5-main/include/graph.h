#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <iostream>
#include <functional>

template <typename T>
class Graph
{
public:
  Graph() = default;
  ~Graph();
  void addVertex(const T &item);
  void addEdge(const T &v1, const T &v2, int a, std::function<bool(T, T)> func);
  std::vector<T> getNeighbors(T vertex, std::function<bool(T, T)> func);
  std::vector<T> findShortestPath(T source, T destination, std::function<bool(T, T)> func);
  bool isConnected(T source, T destination, std::function<bool(T, T)> func);
  
  int getNumberEdges();
  void disp();

private:
  class Node
  {

  public:
    T value;
    int weight{};
    Node *next{};
    Node(const T &_item) : value{_item}, next{nullptr}, weight{0}
    {
    }
  };
  std::vector<Node *> head;
  std::map<int, std::vector<std::pair<int, int>>> m;
};









struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
    Node(const Node* m):value{m->value},left{m->left},right{m->right}{
      std::cout<<"NOde copy constructor"<<std::endl;
    }
};

Node* insert(Node* root, int value){
    Node* node {new Node{value}};
    node->left = root;
    root = node;
    return root;
};
void deleteNode(Node* root, int value) {
        Node* root2 = nullptr;
        while(root){
            std::cout<<"in while line 70"<<std::endl;
            if(root->value!=value){
                
                std::cout<<" value is :"<<root->value<<std::endl;
                root2 = insert(root2, root->value);
                root = root->left;

            }
            else{
              break;
            }
            
            std::cout<<root->value<<std::endl;
    }
    // root->value = root2->value;
    while(root2){
        std::cout<<" th root2 is :"<< root2->value<<std::endl;
        root->value = root2->value;
        root=insert(root,root2->value);
        root2= root2->left;
    }
    std::cout<<" th root is :"<< root->value<<std::endl;
    delete root;
    root = root2;
};
Node* find(Node* root, int value) {

    while(root->left){

            if(root->left->value==value){
                return root->left;
            };

            root = root->left;
    }
    return nullptr;
    
};
void printInOrder(Node* root) {
    std::cout<<"print the root ................."<<std::endl;
    int i=1;
    while(root){
        std::cout<<i<<" th root is :"<< root->value<<std::endl;
        root= root->left;
    }
};



#include "graph.hpp"

#endif
