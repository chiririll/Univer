#include "LoadFile.h"


void LoadFile::Execute(std::vector<std::string> args) {
    using namespace std;

    if (args.size() < 2) {
        cout << "You need to provide filename" << endl;
        return;
    }

    FileLoader loader(args[1]);
    if (loader.Load(*products))
        cout << "File loaded" << endl;
    else
        cout << "Error: Can't load products list! " << loader.GetError() << endl;
}

std::string LoadFile::GetWord() const {
    return "loadfile";
}

std::string LoadFile::GetDescription() const {
    return "Load products from file";
}

std::string LoadFile::GetArgs() const {
    return "<filename>";
}
