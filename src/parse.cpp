#include "../include/parse.hpp"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

Parse::Parse(string story) {
    fileName = story;
}

// this function was a horrible idea lol
Node* Parse::process() {
    ifstream fin(fileName);
    if (!fin) {
        cout << "Error reading file" << "\n";
        exit(EXIT_FAILURE);
    }

    string scoreName, initialPrompt, endMessage;
    getline(fin, scoreName);
    getline(fin, initialPrompt);
    getline(fin, endMessage);

    Node* start = new Node(0, initialPrompt);
    Node* current = start;
    current->scoreName = scoreName;
    current->endMessage = endMessage;

    int currentLayer = 1, level, scoreAward;
    string answerOption, prompt;
    queue<int> treePath;

    while (fin.peek() != EOF) {
        fin >> level >> scoreAward;
        fin.ignore();
        getline(fin, prompt);
        getline(fin, answerOption);

        if (level < currentLayer) {
            current = start;
            for (int i = 1; i < level; ++i) {
                current = current->dfs(treePath.front(), 0);
                treePath.pop();
            }
            treePath = queue<int>();
        }

        treePath.push(current->getChildren());
        current = current->insert(Node(scoreAward, prompt, answerOption));
        currentLayer = level+1;
    }
    
    fin.close();
    return start;
}