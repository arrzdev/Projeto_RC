#include "database.hpp"

int userIsRegistered(string uid){
  // Build the path to the password file
  string path = "ASDIR/USERS/" + uid + "/" + uid + "_pass.txt";

  // Check if the directory exists
  return filesystem::exists(path);
}

int userIsLoggedIn(string uid){
  // Build the path to the login file
  string path = "ASDIR/USERS/" + uid + "/" + uid + "_login.txt";

  // Check if the directory exists
  return filesystem::exists(path);
}


void logoutUser(string uid){
  // Build the path to the login file
  string path = "ASDIR/USERS/" + uid + "/" + uid + "_login.txt";

  // Remove the login file
  filesystem::remove(path);
}

void registerUser(string uid, string password){
  // Build the paths to the user directory and password file
  string userPath = "ASDIR/USERS/" + uid;
  string passwordPath = userPath + "/" + uid + "_pass.txt";

  // Build the paths to the hosted and bidded directories
  string hostedPath = userPath + "/HOSTED";
  string biddedPath = userPath + "/BIDDED";

  // Create the directories if they dont exist
  filesystem::create_directories(userPath);
  filesystem::create_directories(hostedPath);
  filesystem::create_directories(biddedPath);

  // Store the password
  ofstream file(passwordPath);
  file << password;

  //close the file
  file.close();
}

void unregisterUser(string uid){
  // Build the path to the user directory
  string path = "ASDIR/USERS/" + uid + "/" + uid + "_pass.txt";

  // Remove the password file
  filesystem::remove_all(path);
}


int passwordMatches(string uid, string password){
  // Build the path to the password file
  string path = "ASDIR/USERS/" + uid + "/" + uid + "_pass.txt";

  // Open the file
  ifstream file(path);
  if (!file) { throw runtime_error("Could not open file"); }
  
  // Read the password from the file
  string filePassword;
  getline(file, filePassword);

  //close the file
  file.close();

  // Compare the passwords
  return filePassword == password;
}

void createLoginFile(string uid){
  // Build the path to the login file
  string path = "ASDIR/USERS/" + uid + "/" + uid + "_login.txt";

  // Create the login file
  ofstream file(path);
}


string getUserBids(string uid){
  // Build the path to the bidded directory
  string bidsDirPath = "ASDIR/USERS/" + uid + "/BIDDED";
  string bids = "";

  for (const auto &entry : filesystem::directory_iterator(bidsDirPath)){
    string aid_filename = entry.path().filename(); // get the filename
    string aid = aid_filename.substr(0, aid_filename.length() - 4); // remove .txt
    
    // Get the auction state
    int state = getAuctionState(aid);

    // Format bid message and add it to the string
    bids += " " + aid + " " + to_string(state);
  }

  return bids;
}


string getUserAuctions(string uid){
  // Build the path to the hosted directory
  string hostedDirPath = "ASDIR/USERS/" + uid + "/HOSTED";
  string auctions = "";

  for (const auto &entry : filesystem::directory_iterator(hostedDirPath)){
    // Get the auction state
    string aid_filename = entry.path().filename(); // remove .txt
    string aid = aid_filename.substr(0, aid_filename.length() - 4);
    int state = getAuctionState(aid);

    // Format auction message and add it to the string
    auctions += " " + aid + " " + to_string(state);
  }

  return auctions;
}

string getAllAuctions(){
  // Build the path to the auctions directory
  string auctionsDirPath = "ASDIR/AUCTIONS";
  string auctions = "";

  for (const auto &entry : filesystem::directory_iterator(auctionsDirPath)){
    // Get the auction aid
    string aid = entry.path().filename(); // remove .txt
    
    // Get the auction state
    int state = getAuctionState(aid);

    // Format auction message and add it to the string
    auctions += " " + aid + " " + to_string(state);
  }

  return auctions;
}


int auctionExists(string aid){
  // Build the path to the auction file
  string startAuctionPath = "ASDIR/AUCTIONS/" + aid + "/START_" + aid + ".txt";
  return filesystem::exists(startAuctionPath);
}

int getAuctionState(string aid){
  // Build the path to the auction file
  string endendAuctionPath = "ASDIR/AUCTIONS/" + aid + "/" + "END_" + aid + ".txt";
  return !filesystem::exists(endendAuctionPath);
}


string getAuctionInfo(string aid){
  // Build the path to the auction file
  string auctionFilePath = "ASDIR/AUCTIONS/" + aid + "/START_" + aid + ".txt";
  
  // Get auction info
  ifstream file(auctionFilePath);

  string uid, name, asset_fname, start_value, timeactive, start_date, start_time, start_fulltime;
  file >> uid >> name >> asset_fname >> start_value >> timeactive >> start_date >> start_time >> start_fulltime;
  string auctionInfo = uid + " " + name + " " + asset_fname + " " + start_value + " " + start_date + " " + start_time + " " + timeactive;

  // Close the file
  file.close();

  return auctionInfo;
}

string getAuctionBidsInfo(string aid){
  // Build the path to the bids directory
  string bidsDirPath = "ASDIR/AUCTIONS/" + aid + "/BIDS";
  string bids = "";

  // Create a priority queue to store the top 50 bids
  priority_queue<int, vector<int>, less<int>> topBids;
  for (const auto &entry : filesystem::directory_iterator(bidsDirPath)){
    // Get the bid value from the file name
    string filename = entry.path().filename().string();
    int bidValue = stoi(filename.substr(0, filename.find(".txt")));

    // Add the bid value to the queue
    topBids.push(bidValue);

    // If the size of the queue exceeds 50, pop the top element
    if (topBids.size() > 50){
      topBids.pop();
    }
  }

  // Now, topBids contains the top 50 bids with the highest at the top
  // Pop elements from the priority queue into a vector
  vector<int> sortedBids;
  while (!topBids.empty()){
    sortedBids.push_back(topBids.top());
    topBids.pop();
  }

  // Reverse the vector to sort it in ascending order
  reverse(sortedBids.begin(), sortedBids.end());

  // Process the bids in the order of bid value
  for (const auto &bidValue : sortedBids){
    // Convert the bid value to a string with 6 digits and leading zeros
    stringstream ss;
    ss << setw(6) << setfill('0') << bidValue;
    string bidValueStr = ss.str();

    // Open the corresponding file
    ifstream file(bidsDirPath + "/" + bidValueStr + ".txt");

    // TODO: throw exception or just continue?
    if (!file){ throw runtime_error("Could not open file"); }

    // Get the bid data
    string bidData;
    getline(file, bidData);

    // Close the file
    file.close();

    // Format bid message and add it to the string
    bids += " B " + bidData;
  }

  return bids;
}

string getAuctionEndInfo(string aid){
  // Build the path to the auction file
  string endendAuctionPath = "ASDIR/AUCTIONS/" + aid + "/END_" + aid + ".txt";
  string endInfo = "";

  // if the auction has not ended 
  if (!filesystem::exists(endendAuctionPath)){ 
    return endInfo; // empty string
  }

  // if the auction has ended
  ifstream file(endendAuctionPath);

  // TODO: throw exception or just continue?
  if (!file) { throw runtime_error("Could not open file");}

  // Get the end data
  string endData;
  getline(file, endData);

  // Close the file
  file.close();

  // Format end message and add it to the string
  endInfo = " E " + endData;

  return endInfo;
}
