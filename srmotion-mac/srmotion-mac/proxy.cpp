#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include "enet/include/enet.h"
#include "http.h"
#include "server.h"
#include "print.h"
#include <fstream>
#include "events.h"
#include "utils.h"
#include <regex>
#include "cmdexecute.hpp"
server* g_server = new server();

using namespace std;
vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}


bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}


int main() {
    //cout << "NOTE: NO MORE UPDATES & HELPS TO SRMOTION PROXY, WE'RE WORKING ON FLEXFARM DO NOT FORGET JOIN OUR DISCORD(SrMotion#1337)" << endl;
    //system("start https://discord.gg/CAjMzKNeJX");

    printf("Parsing the server_data.php\n");
    
    //const auto server_address = L"http://growtopia1.com/growtopia/server_data.php";
    std::string s_reply = exec("curl --silent -X POST \"http://growtopia1.com/growtopia/server_data.php\"");
    string delimiter = "|";
    vector<string> v = split(s_reply.c_str(), delimiter);
    
    int port = std::stoi(v[2]);
    std::string ipAdress(v[1].c_str());
    g_server->m_port = port;
    g_server->portz = port;
    

    replace(ipAdress, "\nport", "");
    cout << "Parsing port and ip is done. port is " << to_string(g_server->m_port).c_str() << " and ip is " << ipAdress.c_str() << endl;
    g_server->m_server = ipAdress.c_str();
    g_server->serverz = ipAdress.c_str();
    
    system("Color a");
    printf("Based on enet by ama.\n");
    events::out::type2 = 2;
    g_server->ipserver = "127.0.0.1";
    g_server->create = "0.0.0.0";
    std::thread http(http::run, g_server->ipserver, "17191");
    http.detach();
    print::set_color(LightGreen);
    enet_initialize();
    if (g_server->start()) {
       print::set_text("Server & client proxy is running.\n", LightGreen);
       while (true) {
       g_server->poll();
         std::this_thread::sleep_for(std::chrono::milliseconds(1));
       }
  }
   else
    print::set_text("Failed to start server or proxy.\n", LightGreen);
}
