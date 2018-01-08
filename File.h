#pragma once
#include <string>
#include "FSNode.h"

class File : public FSNode {
    private:
        std::string contents; 

    public:
        explicit File(std::string name = "", std::string contents = "");
        virtual ~File();

        virtual Node* clone() const override;

        virtual Node* getFirstChild() const override;

        virtual void print(std::ostream &os) const override;
        friend std::ostream & operator << (std::ostream &os, const File &f);
};