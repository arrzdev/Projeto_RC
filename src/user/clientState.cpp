#include "clientState.hpp"

using namespace std;

string ClientState::getUser() {
    return this->user;
}

void ClientState::setUser(string user) {
    this->user = user;
}

string ClientState::getPassword() {
    return this->password;
}

void ClientState::setPassword(string password) {
    this->password = password;
}