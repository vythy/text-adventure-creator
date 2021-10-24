#include <iostream>
#include "../include/node.hpp"
#include "../include/parse.hpp"
using namespace std;

void loadLevel(Node* current);
void displayBar(int n);

int main() {
    string f;
    cout << "Enter the filename of your story: "; cin >> f;
    Parse* parser = new Parse("./stories/" + f);
    Node* game = parser->process();

    while (!(game->end())) {
        loadLevel(game);
        int choice = 0; cin >> choice; 
        game = game->dfs(--choice);
        cout << '\b';
    }

    delete parser;
    delete game;
    return 0;
}

void loadLevel(Node* current) {
    string p = current->getPrompt(); cout << "\n";
    displayBar(p.length());
    cout << p << "\n";
    displayBar(p.length());
    cout << "\nWhat will you do?\n";

    vector<string> options = current->bfs();
    for (int i = 0; i < options.size(); ++i) {
        cout << i+1 << ": " << options[i] << "\n";
    }
}

void displayBar(int n) {
    for (int i = 0; i < n; ++i) cout << "-";
    cout << "\n";
}

