#include "../include/parse.hpp"
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

Parse::Parse(string story) {
    fileName = story;
}

// this function was a horrible idea
Node* Parse::process() {
    ifstream fin(fileName);
    if (!fin) {
        cout << "error reading file" << "\n";
        exit(EXIT_FAILURE);
    }

    string scoreName, initialPrompt;
    getline(fin, scoreName);
    getline(fin, initialPrompt);

    Node* current = new Node(0, initialPrompt);
    current->scoreName = scoreName;

    int currentLayer = 1, level, scoreAward;
    string answerOption, prompt;

    while (fin.peek() != EOF) {
        fin >> level >> scoreAward;
        fin.ignore();
        getline(fin, prompt);
        getline(fin, answerOption);

        if (level < currentLayer) {
            int distance = currentLayer-level;
            for (int i = 0; i < distance; ++i) {
                current = current->parent;
                --currentLayer;
            }
        }

        current = current->insert(new Node(scoreAward, prompt, answerOption));
        currentLayer = level+1;
    }

    while (current->parent != NULL) {
        current = current->parent;
    }
    
    fin.close();
    return current;
}