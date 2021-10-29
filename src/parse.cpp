#include "../include/parse.hpp"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

Parse::Parse(string story) {
    fileName = story;
}

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
    vector<int> treePath;

    while (fin.peek() != EOF) {
        fin >> level >> scoreAward;
        fin.ignore();
        getline(fin, answerOption);
        getline(fin, prompt);

        // retrace path to current node
        current = start;
        vector<int> tempPath;
        for (int i = 1; i < level; ++i) {
            current = current->dfs(treePath[i-1], 0);
            tempPath.push_back(treePath[i-1]);
        }

        treePath = tempPath;
        treePath.push_back(current->getChildren());
        current->insert(Node(scoreAward, prompt, answerOption));
        currentLayer = level+1;
    }
    
    fin.close();
    return start;
}