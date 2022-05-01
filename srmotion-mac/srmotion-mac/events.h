#ifndef events_h
#define events_h

#include <string>
#include "packet.h"
#include <iostream>
#include "gt.hpp"
#include "proton/hash.hpp"
#include "proton/rtparam.hpp"
#include "proton/variant.hpp"
#include "server.h"
#include "utils.h"
#include "print.h"
#include <fstream>
#include <chrono>
#include <thread>
#include <future>
#include "dialog.h"
#include "math.h"

//return value: true - dont send original packet, false - send original packet
namespace events {

    namespace out {
        static std::string saveworld;
        static std::string packets = "`b[`#S`b]:SrMotion#1337 `o";
        static std::string dc = "SrMotion#1337";
        static std::string bnn = "isodogusprivkeyb";
        static std::string kck = "isodogusprivkeyk";
        static std::string pll = "isodogusprivkeyp";
        static std::string ip;
        static std::string type;
        static std::string xyposition;
        static std::string name = "";
        static std::string nid = "1";
        static std::string currentuid;
        static std::string unaccesspaketi;
        static std::string country = "tr";
        static std::string deneme;
        static std::string autopullsayi = "0";
        static std::string mode = "`5Pull";
        static std::string owneruid;
        static bool taxsystem = false;
        static bool fastmmode = false;
        static bool dicemod = false;
        static bool worldbanjoinmod = false;
        static bool autopull = false;
        static bool fastdrop = false;
        static bool fasttrash = false;
        static bool visualspin = false;
        static bool wltroll = false;
        static bool wrenchpull = false;
        static bool autoacc = false;
        static bool autounacc = false;
        static int yuzde = 10;
        static int test;
        static int aa = 0;
        static int wlx = 0;
        static int wly = 0;
        static int uidz;
        static int setx = 0;
        static int sety = 0;
        static int id = 12;
        static int doorid = 123;
        static int posx = 0;
        static int posy = 0;
        static int ruletsayi = 0;
        static int iditemm = 0;
        static int loggedin = 1;
        static int type2;
        static bool autohosts = false;
        static bool dicespeed = false;
        static bool visdice = false;
        static int sayi = 1;
        extern std::string expired;
        bool worldoptions(std::string option);
        bool variantlist(gameupdatepacket_t* packet);
        bool pingreply(gameupdatepacket_t* packet);
        bool generictext(std::string packet);
        bool gamemessage(std::string packet);
        bool state(gameupdatepacket_t* packet);

    }; // namespace out
    namespace in {
        bool variantlist(gameupdatepacket_t* packet);
        bool generictext(std::string packet);
        bool gamemessage(std::string packet);
        bool sendmapdata(gameupdatepacket_t* packet);
        bool state(gameupdatepacket_t* packet);
        bool tracking(std::string packet);
    }; // namespace in
};     // namespace events


#endif /* events_h */
