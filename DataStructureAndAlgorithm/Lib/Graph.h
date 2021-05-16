#pragma once
#include <list>
#include <queue>
#include <stack>
#include <functional>

template <class T>
class Graph {
public:
    struct Node {
        T data;
        bool visited;
        std::list<Node*> neighbors;

        Node() {
            visited = false;
        }

        Node(T d) : Node() {
            data = d;
        }
    };

    std::string bfs(std::function<std::string(T)> to_string, Node* node) {
        std::queue<Node*> queue;
        queue.push(node);
        std::string res = "";
        while (!queue.empty()) {
            Node* cur = queue.front(); queue.pop();
            cur->visited = true;
            for (auto neighbor : cur->neighbors) {
                if (!neighbor->visited) {
                    queue.push(neighbor);
                }
            }
            res += to_string(cur->data);
        }
        return res;
    }

    std::string dfs(std::function<std::string(T)> to_string, Node* node) {
        std::stack<Node*> stack;
        stack.push(node);
        std::string res = "";
        while (!stack.empty()) {
            Node* cur = stack.top(); stack.pop();
            cur->visited = true;
            for (auto neighbor : cur->neighbors) {
                if (!neighbor->visited) {
                    stack.push(neighbor);
                }
            }
            res += to_string(cur->data);
        }
        return res;
    }

};