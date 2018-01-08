#pragma once
#include <string>
#include "FSNode.h"

class Directory : public FSNode {
    public:
        explicit Directory(std::string name = "");
        virtual ~Directory();

        virtual Node* clone() const override;

        virtual void print(std::ostream &os) const override;
        friend std::ostream & operator << (std::ostream &os, const Directory &d);
};