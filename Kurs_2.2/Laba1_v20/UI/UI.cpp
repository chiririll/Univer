#include "UI.h"

UI::UI(Loader* loader) {
    // Initializing products
    this->products_loader = loader;
    loader->Load(this->products);

    // Initializing commands
    commands.push_back(new Help(&commands));
    // commands.push_back(new )
}

UI::~UI() {
    // Deleting commands
    for (Command* cmd : commands)
        delete cmd;

    // Deleting products
    //for (Product product: products)
    //    delete product;
}

void UI::SplitCmd(std::string str_cmd, std::vector<std::string>& args) const {
    int pos = 0;
    do {
        pos = str_cmd.find(" ");
        args.push_back(str_cmd.substr(0, pos));
        str_cmd.erase(0, pos + 1);
    } while (pos != std::string::npos);
}

bool UI::ReadCommand() {
    using namespace std;
    
    string input;
    vector<string> args;

    cout << "-> ";
    getline(cin, input);
    
    // Splitting line to args
    SplitCmd(input, args);

    if (args.size() < 1)
        return true;

    if (args[0] == "exit")
        return false;

    // Finding command
    bool found = false;
    for (Command* cmd : this->commands)
        if (found = cmd->IsMe(args[0]) | found)
            cmd->Execute(args);
    
    if (!found)
        std::cout << "Unknown command. Type 'help' for more info." << std::endl;

    return true;
}

void UI::StartLoop() {
    while (ReadCommand());
}
