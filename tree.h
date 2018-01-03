#ifndef TREE_H
#define TREE_H

#include <ostream>

class Tree {
    protected:
        Node *root;

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
}; 

#endif TREE_H