/*
 * Author: Grace Gibson
 * Date Created: 2/15/2022
 * This header file will be used to hack time. 
 */
#ifndef MINI1
#define MINI1


#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
namespace watch_out {
    class TimeHacking {
        public:
            //constructor to create TimeHacking class object and sets objectToHack based upon the input argument
            TimeHacking(std::string objectToHack);
            //sets the time to hack based on the input in seconds 
            void setTimeToHack(int seconds);
            //gets and returns the time to hack 
            int getTimeToHack();
            //gets and returns the object to hack 
            std::string getObjectToHack();
            //hackTime will hack time by sleeping for a number of seconds the user set and then indicate that time (objectToHack) was hacked
            void hackTime();
        
        private:
            int time_to_hack; //time till indicating that time was hacked
            std::string objectToHack; //object that will be hacked

    };
}



#endif
