#pragma once
#include <ostream>
#include "tree.h"

class FileSystem : public Tree {
    public:
        explicit FileSystem();      //constructor
        virtual ~FileSystem();      //destructor

        void touch(const std::string &path, const std::string &filename);   //create new file
        void mkdir(const std::string &path, const std::string &dirname);    //create new directory
        void rm(const std::string &path, const std::string &filename);      //remove file
        void rmdir(const std::string &path, const std::string &dirname);    //remove directory
        void ls() const;                                                    //list file system content
}; 