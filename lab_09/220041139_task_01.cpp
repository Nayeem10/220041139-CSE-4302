#include<iostream>

using namespace std;

class Artwork{
    string title, artist;
    double price;
public:
    Artwork(string title, string artist, double price): title(title), artist(artist), price(price) {}
    Artwork() {}
    virtual void display(){}
    void showInfo(){
        cout<<"Title: "<<title<<'\n';
        cout<<"Artist: "<<artist<<'\n';
        cout<<"Price: "<<price<<'\n';
    }
};

class Painting : public Artwork{
    string medium;
public:
    Painting(string title, string artist, double price, string medium): Artwork(title, artist, price), medium(medium){}
    void display() override{
        cout<<"Type: Painting\n";
        showInfo();
        cout<<"Medium: "<<medium<<'\n';
    }
};

class Sculpture : public Artwork{
    string material;
public:
    Sculpture(string title, string artist, double price, string material): Artwork(title, artist, price), material(material){}
    void display() override{
        cout<<"Type: Sculpture\n";
        showInfo();
        cout<<"Material: "<<material<<'\n';
    }
};

class DigitalArt : public Artwork{
    string resolution;
public:
    DigitalArt(string title, string artist, double price, string resolution): Artwork(title, artist, price), resolution(resolution){}
    void display() override{
        cout<<"Type: DigitalArt\n";
        showInfo();
        cout<<"Resolution: "<<resolution<<'\n';
    }
};

int main(){
    Artwork* art[100];
    art[0] = new Painting("Panting 1", "Person 1", 100000, "Acrylic");
    art[1] = new Sculpture("Sculpture 1", "Person 2", 100000, "Bronze");
    art[2] = new DigitalArt("NFT 1", "Unknown", 100000, "800x800");
}