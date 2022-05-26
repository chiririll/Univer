#include "SaveFile.h"


void SaveFile::Execute(std::vector<std::string> args) {
    using namespace std;

    if (args.size() < 2) {
        cout << "You need to provide filename" << endl;
        return;
    }

    FileLoader loader(args[1]);
    if (loader.Save(*products))
        cout << "Products saved" << endl;
    else
        cout << "Error: Can't save products to file! " << loader.GetError() << endl;
}

std::string SaveFile::GetWord() const {
    return "savefile";
}

std::string SaveFile::GetDescription() const {
    return "Saves products to file";
}

std::string SaveFile::GetArgs() const {
    return "<filename>";
}
