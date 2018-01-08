#pragma once
#include <ostream>
#include "node.h"

class Tree {
    private:
        void printRecursive(Node &n, int depth, std::ostream &os) const;
        virtual void copySubtree(Node &dest, Node &source);

    protected:
        Node *root;
        int nodeCount;

    public:
        Tree();
        virtual ~Tree();
        virtual Node* getRoot() const;
        virtual void insertChild(Node *parent, Node *child);
        virtual void deleteSubtree(Node *node);
        virtual int getNodeCount() const;
        virtual void Clear();
        virtual void DeleteElements();
        virtual void print(std::ostream &os) const;
        
        Tree& operator = (const Tree &t);

        friend std::ostream & operator << (std::ostream &os, const Tree &t);
}; 