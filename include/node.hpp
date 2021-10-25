#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

class Node {
    private:
        // adjacency list to store one way edges from this node to its children
        std::vector<Node> adj;

        // story prompt to execute once node is reached and answer option to get to node
        std::string prompt, answerOption;

        // points gained for choosing this node
        int weight = 0;
    public:
        static int score;
        static std::string scoreName, endMessage;
        
        // constructor
        Node(int w=0, std::string ao="", std::string p="");

        // traversing the tree and inserting new nodes
        std::vector<std::string> bfs();
        Node* dfs(int v, bool s=1);
        Node* insert(Node v);
        
        // getters
        std::string getPrompt() { return prompt; }
        std::string getAnswerOption() { return answerOption; }
        int getWeight() { return weight; }
        int getChildren() { return adj.size(); };

        // functions for checking if the game is over and what to do upon end
        bool end() { return !(adj.size()); }
        void endGame();
};

#endif