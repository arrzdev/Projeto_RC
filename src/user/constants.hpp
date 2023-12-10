#ifndef USER_CONSTANTS_H
#define USER_CONSTANTS_H

#define UDP 1
#define TCP 2

#define IP_FLAG "-n"
#define PORT_FLAG "-p"
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT 58000

#define LOGIN "login"
#define LOGOUT "logout"
#define UNREGISTER "unregister"
#define EXIT "exit"
#define OPEN "open"
#define CLOSE "close"
#define MY_AUCTIONS "myauctions"
#define MY_AUCTIONS_SHORT "ma"
#define MY_BIDS "mybids"
#define MY_BIDS_SHORT "mb"
#define LIST "list"
#define LIST_SHORT "l"
#define SHOW_ASSET "show_asset"
#define SHOW_ASSET_SHORT "sa"
#define BID "bid"
#define BID_SHORT "b"
#define SHOW_RECORD "show_record"
#define SHOW_RECORD_SHORT "sr"

#define STATUS_OK "OK"
#define STATUS_NOK "NOK"
#define STATUS_REGISTERD "REG"
#define STATUS_UNREGISTERD "UNR"
#define STATUS_NOT_LOGGED_IN "NLG"

#define UDP_LOGIN_COMMAND "LIN"
#define UDP_LOGOUT_COMMAND "LOU"
#define UDP_UNREGISTER_COMMAND "UNR"
#define UDP_MY_AUCTIONS_COMMAND "LMA"  

#define UDP_LOGIN_RESPONSE "RLI"
#define UDP_LOGOUT_RESPONSE "RLO"
#define UDP_UNREGISTER_RESPONSE "RUR"
#define UDP_MY_AUCTIONS_RESPONSE "RMA"

#define LOGIN_SUCCESS "successfull login"
#define LOGIN_FAILURE "incorrect login attempt"
#define LOGIN_REGISTER "new user registered"

#define LOGOUT_SUCCESS "successfull logout"
#define LOGOUT_FAILURE "user not logged in"
#define LOGOUT_UNREGISTER "unknown user"

#define UNREGISTER_SUCCESS "successfull unregister"
#define UNREGISTER_FAILURE "incorrect unregister attempt"
#define UNREGISTER_UNREGISTER "unknown user"

#endif // USER_CONSTANTS_H