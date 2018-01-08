#pragma once

#include <string>
#include "Node.h"

class StringNode : public Node {
    private:
        std::string value; 

    public: 
        explicit StringNode(std::string value = "");
        StringNode(const StringNode &sn);
        virtual ~StringNode(); 
        virtual void print(std::ostream &os) const override; 
        virtual Node* clone() const override; 

        friend std::ostream & operator << (std::ostream &os, const StringNode &sn);
};