#include "showasset.hpp"

void ShowAsset::send(){
    string data = formatData();

    this->networkClient->sendData(data);
}

void ShowAsset::receive(){
    string data = this->networkClient->receiveData();

    Parser parser = Parser(data);

    string command = parser.getCommand();
    vector<string> args = parser.getArgs();

    if(command != TCP_SHOW_ASSET_RESPONSE || args.size() < 1) {
        //TODO handle error
    }

    string status = args[0];

    if(status == STATUS_OK){
        string fileName = args[1];
        string fileSize = args[2];

        printf("Asset %s: %s has %s bytes\n", this->assetId.c_str(), fileName.c_str(), fileSize.c_str());

        args.erase(args.begin(), args.begin() + 3);

        saveFile(fileName, &args);

    }
    else if(status == STATUS_NOK){
        printf("Asset %s not found\n", this->assetId.c_str());
    }
}

string ShowAsset::formatData() {
    return string(TCP_SHOW_ASSET_COMMAND) + " " + assetId + "\n";
}

void ShowAsset::saveFile(string fileName, vector<string>* fileData) {
    Fs fs = Fs(fileName);

    // join vector into string
    string fileDataString = "";

    for(size_t i = 0; i < fileData->size(); i++) {
        if(i == fileData->size() - 1) {
            fileDataString.append(fileData->at(i));
            
        }else {
            fileDataString.append(fileData->at(i) + " ");
        }
    }

    fs.open();

    fs.write(&fileDataString);

    fs.close();
}