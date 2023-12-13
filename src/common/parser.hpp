#ifndef COMMON_PARSER_H
#define COMMON_PARSER_H

#include <string>
#include <vector>

using namespace std;

struct Auction {
    string id;
    int isOpen;
};

struct Bid {
    string bidderId;
    string value;
    string date;
    string time;

    string timeSinceStart; // seconds from start of auction until this bid
};

struct End {
    string date;
    string time;
    string duration; // duration of auction in seconds
};

struct ShowRecordStruct {
    string hostId;
    string auctionName;
    string assetFrame;
    string startValue;
    string startDate;
    string startTime;
    string timeActive; // seconds from start of auction until now

    // last 50 bids, from lowest value to highest
    vector<Bid> bids; 

    // auction end date, time and duration
    End end;

    bool hasBids() {
        return this->bids.size() > 0;
    }

    // returns last bid or empty bid if there are no bids
    string lastBid() {
        if(this->hasBids())
            return this->bids[this->bids.size() - 1].value;
        else return "";
    }

    bool hasEnded() {
        return this->end.date != "";
    }
};

class Parser {
    public:
        Parser(string input);
        string getCommand();
        vector<string> getArgs();
        string getInput();

        vector<Auction> parseAuctions();

        ShowRecordStruct parseShowRecord();

    private:
        string input;
        string command;
        vector<string> args;
};

#endif