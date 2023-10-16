#include <map>
#include "TwitterData.h"

using namespace std;

void printMap(std::map<std::string, TwitterData> map);

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = { {"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"} };
    TwitterData* twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    std::map < std::string , TwitterData > twitterMapUsername;
    twitterMapUsername["rangerPower"] = twitter_data[0];
    twitterMapUsername["kittyKat72"] = twitter_data[1];
    twitterMapUsername["lexi5"] = twitter_data[2];
    twitterMapUsername["savage1"] = twitter_data[3];
    twitterMapUsername["smithMan"] = twitter_data[4];


    //Part 1

    std::cout << "Search by key/username" << endl;
    printMap(twitterMapUsername);
    auto searchUser = twitterMapUsername.find("savage1");
    if (searchUser != twitterMapUsername.end()) {
        std::cout << "Searched for Key savage1: Value: " << searchUser->second.print() << endl;
        twitterMapUsername.erase(twitterMapUsername.find("savage1"));
    }



    //Part 2
    std::map < std::string, TwitterData > twitterMapEmail;
    twitterMapEmail["smitRick@gmail.com"] = twitter_data[0];
    twitterMapEmail["kat@gmail.com"] = twitter_data[1];
    twitterMapEmail["lexi5@gmail.com"] = twitter_data[2];
    twitterMapEmail["ksavage@gmail.com"] = twitter_data[3];
    twitterMapEmail["rick@hotmail.com"] = twitter_data[4];
    std::cout << "\nSearch by email" << endl;
    printMap(twitterMapEmail);

    auto searchEmail = twitterMapEmail.find("kat@gmail.com");
    if (searchEmail != twitterMapEmail.end()) {
        std::cout << "Searched for Key kat@gmail.com : Value: " << searchEmail->second.print() << endl;
        twitterMapEmail.erase(twitterMapEmail.find("kat@gmail.com"));
    }

    return 0;
}

void printMap(std::map<std::string, TwitterData> map) {
    for (const auto& i : map) {
        std::cout << "Key: " << i.first << "\t\tValue: " << i.second.print() << endl;
    }
}