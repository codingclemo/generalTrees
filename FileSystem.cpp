#include <ostream>
#include "FileSystem.h"
#include "FSNode.h"
#include "File.h"
#include "Directory.h"

using namespace std;

/* constructor */
FileSystem::FileSystem()
    :Tree() {
}

/* destructor */
FileSystem::~FileSystem(){
}


FSNode* FileSystem::findNode(const string &path) const {
    /* Does not work for subdirectories */
    string requestedDir = path;
    FSNode *currentNode = nullptr;
    FSNode *temp = nullptr;

    temp = getRoot();
    string tempName = temp.getName();

    while (temp != nullptr && tempName != requestedDir) {
        temp = temp->getFirstChild();
        tempName = temp.getName();
    }
    
    if (tempName == requestedDir) {
        return *temp;
    } else {
        cout << "Requested directory not found!" << endl;
        return nullptr;
    }
}

void FileSystem::touch(const std::string &path, const std::string &filename){
    // get path node

    // create filename node
    FSNode *insertPtr = findDir(path);
    File newFile(filename);
    insertChild(insertPtr, newFile);
}   //create new file

void FileSystem::mkdir(const std::string &path, const std::string &dirname){
    // get path node
    
    // create dirname node
    Directory newDir(dirname);
    // insertChild (pathnode, directorynode)
    Directory insertPtr = findDir(path);
    insertChild(insertPtr, newDir);
}    //create new directory

void FileSystem::rm(const std::string &path, const std::string &filename){
    // get path node

    // get filename node
    File *removePtr = findFile(path, filename);
    deleteSubtree(removePtr);
}     //remove file

void FileSystem::rmdir(const std::string &path, const std::string &dirname){
    // get path node

    // get dirname node
    Directory *removePtr = findDir(path);
    deleteSubtree(removePtr);
}    //remove directory

void FileSystem::ls() const {
    // get all dirnodes
    // print dirnodes
    // get all filenodes
    // print filenodes

}       