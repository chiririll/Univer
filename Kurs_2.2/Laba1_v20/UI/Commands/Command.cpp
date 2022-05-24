#include "Command.h"

bool Command::IsMe(const std::string &word) const {
    return word == this->GetWord();
}
