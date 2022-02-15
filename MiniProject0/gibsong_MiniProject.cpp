#include "gibsong_MiniProject.hpp"

//constructor & setters
watch_out::TimeHacking::TimeHacking(std::string objectToHack) {
    this->objectToHack = objectToHack; //sets objectToHack class variable to input argument 
}
void watch_out::TimeHacking::setTimeToHack(int seconds) {
    this->time_to_hack = seconds; //sets time_to_hack class variable to input argument
}
//getters
int watch_out::TimeHacking::getTimeToHack(){
    return this->time_to_hack;
}
std::string watch_out::TimeHacking::getObjectToHack() {
    return this->objectToHack;
}
void watch_out::TimeHacking::hackTime() {
    std::this_thread::sleep_for(std::chrono::seconds(time_to_hack)); //thread will sleep for time_to_hack in seconds
    std::cout << this->objectToHack << " was hacked!\n"; //print to screen after sleeping that the object was hacked

}
//program's entry point
 int main() {
     //get input from user
    std::string objectToHack;
    std::cout << "What object would you like to hack?\n";
    std::cin >> objectToHack;
    int time; 
    std::cout << "How many seconds do you want to hack it for?\n";
    std::cin >> time;
    //create object and use time setter
    watch_out::TimeHacking hack(objectToHack);
    hack.setTimeToHack(time);
    //get the private class variables and display to screen 
    std::cout << "Object to hack: " << hack.getObjectToHack() << "\n";
    std::cout << "Time to hack: " << hack.getTimeToHack() << " seconds\n";
    //run hackTime to make it sleep and then hack time
    hack.hackTime();

    return 0;
 }