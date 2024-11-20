#include<iostream>

using namespace std;

class Artwork{
    string title, artist;
    double price, discount;
public:
    Artwork(string title, string artist, double price): title(title), artist(artist), price(price), discount(0){}
    Artwork() {}
    virtual void display(){}
    virtual void applyDiscount(double percentage) {}
    
    void showInfo(){
        cout<<"Title: "<<title<<'\n';
        cout<<"Artist: "<<artist<<'\n';
        cout<<"Price: "<<price<<'\n';
        cout<<"Discount: "<<discount<<'\n';
        cout<<"Price after discount: "<<price * (100.0 - discount) / 100.0<<'\n';
    }
    void setDiscount(double discount){
        this->discount = discount;
    }
};

class Painting : public Artwork{
    string medium;
    double discount;
public:
    Painting(string title, string artist, double price, string medium): Artwork(title, artist, price), medium(medium), discount(0) {}
    void display() override{
        cout<<"Type: Painting\n";
        showInfo(); 
        cout<<"Medium: "<<medium<<'\n';
    }
    void applyDiscount(double percentage) override{
        setDiscount(percentage);
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
    double discount;
public:
    DigitalArt(string title, string artist, double price, string resolution): Artwork(title, artist, price), resolution(resolution), discount(0) {}
    void display() override{
        cout<<"Type: DigitalArt\n";
        showInfo();
        cout<<"Resolution: "<<resolution<<'\n';
    }
    void applyDiscount(double percentage) override{
        setDiscount(percentage + 1);
    }
};

int main(){
    Artwork* art[100];
    art[0] = new Painting("Panting 1", "Person 1", 100000, "Acrylic");
    art[1] = new Sculpture("Sculpture 1", "Person 2", 100000, "Bronze");
    art[2] = new DigitalArt("NFT 1", "Unknown", 100000, "800x800");
    for(int i = 0; i < 3; i++){
        art[i]->applyDiscount(5);
    }
}