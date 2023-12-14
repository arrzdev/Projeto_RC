#include "fs.hpp"

string Fs::getPath() {
    return this->path;
}

/**
 * @param mode READ or WRITE
 */
bool Fs::open(int mode) {
    // Isto nao consegue abrir o ficheiro dentro de uma pasta
    if(mode == READ){
        this->fd = ::open(this->path.c_str(), O_RDONLY, 0644);
    }
    else if(mode == WRITE){
        this->fd = ::open(this->path.c_str(), O_WRONLY | O_CREAT, 0644);
    }
    else{
        return false;
    }

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

bool Fs::write(string* data) {
    if(!isOpen()) {
        return false;
    }
    
    if(::write(this->fd, data->c_str(), data->size()) < 0) {
        return false;
    }

    return true;
}

int Fs::getSize() {
    if(!isOpen()) {
        return -1;
    }

    // set file pointer to beginning of file
    lseek(this->fd, 0, SEEK_SET);

    size_t size = lseek(this->fd, 0, SEEK_END);

    // set file pointer to beginning of file
    lseek(this->fd, 0, SEEK_SET);

    return static_cast<int>(size);
}

bool Fs::read(string* data) {
    if(!isOpen()) {
        return false;
    }

    int size = getSize();

    if(size <= 0) {
        return false;
    }

    char buffer[size];

    // set file pointer to beginning of file
    lseek(this->fd, 0, SEEK_SET);

    ssize_t bytesRead = ::read(this->fd, buffer, size);

    if(bytesRead < 0) {
        return false;
    }

    *data = string(buffer, bytesRead);

    return true;
}