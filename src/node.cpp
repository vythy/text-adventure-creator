#include "../include/node.hpp"
#include <iostream>
using namespace std;

int Node::score = 0;
string Node::scoreName = "points";

Node::Node(int w, string p, string ao) {
    weight = w;
    prompt = p;
    answerOption = ao;
}

Node::~Node() {
    for (Node *v : adj) {
        delete v;
    }
}

// Traverse one layer through every adjacent node to get answer options
vector<string> Node::bfs() {
    vector<string> options;
    for (Node* v : adj) {
        options.push_back(v->getAnswerOption());
    }
    return options;
}

// Traverse one layer down a single node
Node* Node::dfs(int v) {
    if (v > adj.size()) v = 0;
    return adj[v];
}

Node* Node::insert(Node* v) {
    adj.push_back(v);
    v->parent = this;
    return v;
}
