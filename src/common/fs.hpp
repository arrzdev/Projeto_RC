#ifndef COMMON_FS_HPP
#define COMMON_FS_HPP

#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;


class Fs {
    public:
        Fs(string path): path(path) {};

        bool write(vector<string>* data);
        bool write(string* data);

        bool read(vector<string>* data, size_t chuncks_size);

        bool isOpen();

        bool open();
        bool close();

        string getPath();


    private:
        string path;

        int fd = -1;

};

#endif