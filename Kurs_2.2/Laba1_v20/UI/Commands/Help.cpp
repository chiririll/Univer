#include "Help.h"

void Help::Execute(std::vector<std::string> args) {
    using namespace std;

    cout << "Here is some help:" << endl;
    cout << "Type <command> <argument>[] to execute command." << endl;

    cout << endl << "Here is a list of all commands:" << endl;
    for (Command* cmd : *commands)
        cout << cmd->GetWord() << " " << cmd->GetArgs() << "\t - " << cmd->GetDescription() << endl;
}

std::string Help::GetWord() const {
    return "help";
}

std::string Help::GetDescription() const {
    return "Display help";
}

std::string Help::GetArgs() const {
    return "";
}