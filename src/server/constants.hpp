#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#define PORT_FLAG "-p"
#define VERBOSE_FLAG "-v"

#define DEFAULT_PORT 58000
#define DEFAULT_VERBOSE false

#define MAX_AUCTIONS 999
#define AUCTION_SIZE 5 // AID status
#define COMMAND_REPLY 3
#define STATUS 3

//max protocol command size
#define CHUNCKS COMMAND_REPLY + 1 + STATUS + AUCTION_SIZE*MAX_AUCTIONS + 1

#endif