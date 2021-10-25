#include <iostream>
#include "../include/node.hpp"
#include "../include/parse.hpp"
using namespace std;

void loadLevel(Node* current);
void displayEnding(Node* current, int barLength=50);
void displayBar(int n);

int main() {
    string f;
    cout << "Enter the name of your story: "; cin >> f; f += ".txt";
    Parse* parser = new Parse("./stories/" + f);
    Node* game = parser->process();
    Node* currentLevel = game;

    while (!(currentLevel->end())) {
        loadLevel(currentLevel);
        int choice = 0; cin >> choice; 
        currentLevel = currentLevel->dfs(--choice);
    }

    displayEnding(game);

    delete parser;
    delete game;
    return 0;
}

void loadLevel(Node* current) {
    string p = current->getPrompt(); cout << "\n";
    displayBar(p.length());
    cout << p << "\n";
    displayBar(p.length());
    cout << "\nWhat will you do?\n\n";

    vector<string> options = current->bfs();
    for (int i = 0; i < options.size(); ++i) {
        cout << i+1 << ": " << options[i] << "\n";
    }
}

void displayEnding(Node* current, int barLength) {
    cout << "\n";
    displayBar(barLength);
    current->endGame();
    displayBar(barLength);
}

void displayBar(int n) {
    for (int i = 0; i < n; ++i) cout << "-";
    cout << "\n";
}

