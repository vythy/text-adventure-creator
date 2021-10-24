#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

class Node {
    private:
        std::vector<Node*> adj;
        std::string prompt, answerOption;
        int weight = 0;
    public:
        Node* parent = NULL;
        static int score;
        static std::string scoreName;
        
        Node(int w=0, std::string ao="", std::string p="");
        ~Node();
        std::vector<std::string> bfs();
        Node* dfs(int v);
        Node* insert(Node* v);
        
        std::string getPrompt() { return prompt; }
        std::string getAnswerOption() { return answerOption; }
        int getWeight() { return weight; }
        bool end() { return !(adj.size()); }
};

#endif