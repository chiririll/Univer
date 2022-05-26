#include "FileLoader.h"

std::string strip(const std::string &str, int end) {
    int start = 0;
    
    for (; str[start] == ' ' || str[start] == '\t'; start++);
    for (; str[end] == ' ' || str[end] == '\t'; end--);

    return str.substr(start, end-start);
}

bool FileLoader::Load(std::vector<Product*> &products) {
    std::ifstream fin(file_path);
    
    // Checking if file exists
    if (fin.fail()) {
        PushError("File '" + file_path + "' does not exists!");
        return false;
    }

    // Reading lines
    std::string line;
    ProductCreator creator(GetPrefix() + "\t");
    for (int line_number = 1; std::getline(fin, line); line_number++) {
        // Skipping comments and empty lines
        if (line.empty() || line[0] == '#')
            continue;

        // Reading fields
        std::vector<std::string> fields;
        int semicolon_pos;
        do {
            semicolon_pos = line.find(';');
            fields.push_back(strip(line, semicolon_pos));
            line.erase(0, semicolon_pos + 1);
        }
        while (semicolon_pos != std::string::npos);
        
        // Creating product
        Product* product = creator.CreateProduct(fields);
        if (product == NULL)
            std::cout << "Error: Can't load product at line " << line_number << ": " << creator.GetError() << std::endl;
        else
            products.push_back(product);
    }

    return true;
}

bool FileLoader::Save(const std::vector<Product*> &products) {
    
}
