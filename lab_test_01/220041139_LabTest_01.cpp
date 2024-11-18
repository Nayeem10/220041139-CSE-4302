#include <iostream>
#include <algorithm>
#include <string.h>
#include <time.h>
using namespace std;

class MyString{
    char *str;
public:
    MyString(){
        str = new char[1];
        str[0] = '\0';
    }
    MyString(MyString &other){
        str = new char[other.length()];
        strcpy(str, other.getString());
    }
    MyString(char *ar){
        int sz = strlen(ar);
        str = new char[sz];
        strcpy(str, ar);
    }
    void assignString(char ar[]){
        int sz = strlen(ar);
        str = new char[sz];
        strcpy(str, ar);
    }
    char* getString(){
        char* ret = new char[strlen(str)];
        strcpy(ret, str); 
        return ret;
    }
    int length(){
        return strlen(str);
    }
    void display(){
        printf("%s\n", str);
    }
    ~MyString(){
        delete[] str;
    }
};

char* randomString(int len){
    char *str;
    str = new char[len + 1];
    for(int i = 0; i < len; i++){
        str[i] = ('a' + rand() % 26);
    }
    str[len] = '\0';
    return str;
}

void sortByLength(MyString ar[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(ar[j].length() > ar[j + 1].length()){
                char *temp = ar[j].getString();
                ar[j].assignString(ar[j + 1].getString());
                ar[j + 1].assignString(temp);
            }
        }
    }
}

int main(){
    srand(time(0));
    MyString ar[10];
    for(int i = 0; i < 10; i++){
        ar[i].assignString(randomString(rand() % 10 + 1));
    }
    for(int i = 0; i < 10; i++){
        ar[i].display();
    }
    cout<<'\n';
    sortByLength(ar, 10);
    for(int i = 0; i < 10; i++){
        ar[i].display();
    }
    return 0;
}