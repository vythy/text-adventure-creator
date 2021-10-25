#include "../include/node.hpp"
#include <iostream>
using namespace std;

// setting static members
int Node::score = 0;
string Node::scoreName = "points";
string Node::endMessage = "Your score is: ";

// constructor
Node::Node(int w, string p, string ao) {
    weight = w;
    prompt = p;
    answerOption = ao;
}

// Traverse one layer through every adjacent node to get answer options
vector<string> Node::bfs() {
    vector<string> options;
    for (Node v : adj) {
        options.push_back(v.getAnswerOption());
    }
    return options;
}

// Traverse one layer down a single node to go to the next level
// s determines whether the dfs is only used to traverse the graph (0) or to add to score too (1)
Node* Node::dfs(int v, bool s) {
    // automatically choose 0 as the default answer option if the user's choice is out of bounds
    if (v > adj.size() || v < 0) v = 0;

    // add to score only if s is true
    if (s) score += adj[v].getWeight();

    return &adj[v];
}

// function for inserting nodes into the digraph/tree
// returns a pointer to the newly created node
Node* Node::insert(Node v) {
    adj.push_back(v);

    return &(adj.back());
}

// function for printing out the end message and score
void Node::endGame() {
    cout << endMessage << "\n";
    cout << "Your " << scoreName << " is " << score << "\n";
}
