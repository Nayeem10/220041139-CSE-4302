#include<iostream>
using namespace std;

class Time{
private:
    int hour = 0, minute = 0, second = 0;
    bool isValid(int& hour, int& minute, int& second){
        return hour >= 0 && hour < 24 && minute >= 0 && minute
         < 60 && second >= 0 && second < 60;
    }

public:
    void reset(int h, int m, int s){
        if(isValid(h, m, s)){
            hour = h, minute = m, second = s;
        }else{
            cerr << "Error: Invalid time!\n";
        }
    }

    void advance(int h, int m, int s){
        int carry = 0;
        second += s;
        carry = second / 60;
        second %= 60;
        minute += (carry + m);
        carry = minute / 60;
        minute %= 60;
        hour += (carry + h);
        hour %= 24; 
    }

    int hours(){
        return hour;
    }
    int minutes(){
        return minute;
    }
    int seconds(){
        return second;
    }

    void print() const{
        cout << "Current time: " 
             << hour << (hour > 1 ? " Hours " : " Hour ")
             << minute << (minute > 1 ? " Minutes " : " Minute ")
             << second << (second > 1 ? " Seconds" : " Second")
             << endl;
    }

};

int main(){ 
    Time t1;
    t1.print();
    t1.reset(10, 10, 10);
    t1.print();
    t1.advance(13, 50, 50);
    t1.print();

    return 0;
}