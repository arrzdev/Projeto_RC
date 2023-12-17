#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__

#include <string>
#include <filesystem>
#include <fstream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int userIsRegistered(string uid);
int userIsLoggedIn(string uid);

void logoutUser(string uid);
void registerUser(string uid, string password);
void unregisterUser(string uid);

int passwordMatches(string uid, string password);
void createLoginFile(string uid);

int auctionExists(string aid);
string getUserAuctions(string uid);

string getAllAuctions();

int getAuctionState(string aid);
string getAuctionInfo(string aid);
string getAuctionBidsInfo(string aid);
string getAuctionEndInfo(string aid);

string getUserBids(string uid);

#endif