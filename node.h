#ifndef NODE_H
#define NODE_H

#include <ostream>

class Node {
    private:
        Node *firstChild, *nextSibling;
    
    public:
        explicit Node(Node *firstChild = nullptr, Node *nextSibling = nullptr);
        virtual ~Node();
        virtual Node* getFirstChild() const;
        virtual Node* getNextSibling() const;
        virtual void setFirstChild(Node *n);
        virtual void setNextSibling(Node *n);
        virtual void print(std::ostream &os) const = 0;

}; 

#endif NODE_H