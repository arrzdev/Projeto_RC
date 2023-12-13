#include "fs.hpp"

string Fs::getPath() {
    return this->path;
}

bool Fs::open() {
    // Isto nao consegue abrir o ficheiro dentro de uma pasta
    this->fd = ::open(this->path.c_str(), O_WRONLY | O_APPEND | O_CREAT, 0644);

    if(this->fd < 0) {
        return false;
    }

    return true;
}

bool Fs::close() {
    if(!isOpen() || ::close(this->fd) < 0) {
        return false;
    }

    return true;
}

bool Fs::isOpen() {
    return this->fd != -1;
}

bool Fs::write(vector<string>* data) {
    if(!open()) {
        return false;
    }

    for(size_t i = 0; i < data->size(); i++) {
        if(write(&data->at(i)) == false) {
            return false;
        }
    }

    return true;
}

bool Fs::write(string* data) {
    if(!isOpen()) {
        return false;
    }
    
    if(::write(this->fd, data->c_str(), data->size()) < 0) {
        return false;
    }

    return true;
}

// returns array of size (File size / chuncks_size) + 1
bool Fs::read(vector<string>* data, size_t chuncks_size) {
    //TODO done for server, check if this works
    // Nao consegui testar

    if(!open()) {
        return false;
    }

    string buffer = string("", chuncks_size);

    while(true) {
        ssize_t bytes_read = ::read(this->fd, &buffer, chuncks_size);

        if(bytes_read < 0) {
            return false;
        }

        if(bytes_read == 0) {
            break;
        }

        data->push_back(string(buffer, bytes_read));
    }

    return true;
}