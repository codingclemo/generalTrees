#pragma once
#include <string>

class FSNode : public Node {
    protected:
        std::string name; 

    public:
        explicit FSNode(std::string name = "");
        FSNode(const FSNode &fsn);
        virtual ~FSNode();

        virtual std::string getName() const;

        virtual void print(std::ostream &os) const = 0;
        friend std::ostream & operator << (std::ostream &os, const FSNode &fsn);
};