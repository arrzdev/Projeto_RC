#ifndef CLIENT_ERRORS_H
#define CLIENT_ERRORS_H

#include <exception>

using namespace std;

class CostumError : public exception {
    public:
        CostumError(string msg): msg(msg) {}

        const char* what() const throw() {
            return msg.c_str();
        }

    protected:
        string msg;
};

class ConnectionTimeoutError : public CostumError {
    public:
        ConnectionTimeoutError(): CostumError(CONNECTION_TIMEOUT_MSG) {}
};

#endif