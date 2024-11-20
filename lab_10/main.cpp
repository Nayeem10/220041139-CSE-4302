#include<iostream>
#include<time.h>
using namespace std;

class CharacterActions{
protected:
    int health, attackPower, mana, specialPower, increment, defProbability;
    bool isDead;
public:
    CharacterActions(int health, int attackPower, int specialPower, int increment, int defProbability) : health(health), attackPower(attackPower), specialPower(specialPower), mana(0), increment(increment), defProbability(defProbability), isDead(0) {}
    virtual void attack(CharacterActions *other) = 0;
    virtual void defend(const int atk) = 0;
    virtual void specialAttack(CharacterActions *other) = 0;
    virtual void displayStat() = 0;

    int getHealth(){
        return health;
    }
    void updateHealth(int dmg){
        health -= dmg;
    }
    void updateMana(int amount){
        mana += amount;
    }
    void updateDeath(){
        isDead = 1;
    }
};

class BaseCharacter : public CharacterActions{
public:
    BaseCharacter(int health, int attackPower, int specialPower, int increment, int defProbability): CharacterActions(health, attackPower, specialPower, increment, defProbability) {}
    
};

class Warrior : public BaseCharacter{
public:
    Warrior(int health, int attackPower, int specialPower) : BaseCharacter(health, attackPower, specialPower, 50, 3) {}
    void attack(CharacterActions *other){
        if(isDead || other->getHealth() <= 0) return;
        cout << "Warrior attacks with power " << attackPower << endl;
        other->defend(attackPower);
        updateMana(increment);
    }
    void defend(int atk){
        if(isDead) return;
        if(rand() % defProbability == 0){
            cout << "Warrior blocked the attack" << endl;
            return;
        }
        cout << "Warrior takes " << atk << " damage" << endl;
        updateHealth(atk);
        if(health < 0){
            updateDeath();
            cout << "Warrior Died" << endl;
        }
    }
    void specialAttack(CharacterActions *other){
        if(isDead || other->getHealth() <= 0) return;
        if(mana == 100){
            cout << "Warrior used Berserk Rage with power " << specialPower << endl;
            other->defend(specialPower);
            updateMana(-100);
        }
    }
    void displayStat(){
        cout << "Warrior: " << endl;
        cout << "Current Health: " << health << endl;
        cout << "Current Mane: " << mana << endl;
    }
};

class Mage : public BaseCharacter{
public:
    Mage(int health, int attackPower, int specialPower) : BaseCharacter(health, attackPower, specialPower, 50, 3) {}
    void attack(CharacterActions *other){
        if(isDead || other->getHealth() <= 0) return;
        cout << "Mage attacks with power " << attackPower << endl;
        other->defend(attackPower);
        updateMana(increment);
    }
    void defend(int atk){
        if(isDead) return;
        if(rand() % defProbability == 0){
            cout << "Mage blocked the attack" << endl;
            return;
        }
        cout << "Mage takes " << atk << " damage" << endl;
        updateHealth(atk);
        if(health < 0){
            updateDeath();
            cout << "Mage Died" << endl;
        }
    }
    void specialAttack(CharacterActions *other){
        if(isDead || other->getHealth() <= 0) return;
        if(mana == 100){
            cout << "Mage used Arcane Blast with power " << specialPower << endl;
            other->defend(specialPower);
            updateMana(-100);
        }
    }
    void displayStat(){
        cout << "Mage: " << endl;
        cout << "Current Health: " << health << endl;
        cout << "Current Mane: " << mana << endl;
    }
};

class Archer : public BaseCharacter{
public:
    Archer(int health, int attackPower, int specialPower) : BaseCharacter(health, attackPower, specialPower, 50, 3) {}
    void attack(CharacterActions *other){
        if(isDead || other->getHealth() <= 0) return;
        cout << "Archer attacks with power " << attackPower << endl;
        other->defend(attackPower);
        updateMana(increment);
    }
    void defend(int atk){
        if(isDead) return;
        if(rand() % defProbability == 0){
            cout << "Archer blocked the attack" << endl;
            return;
        }
        cout << "Archer takes " << atk << " damage" << endl;
        updateHealth(atk);
        if(health < 0){
            updateDeath();
            cout << "Archer Died" << endl;
        }
    }
    void specialAttack(CharacterActions *other){
        if(isDead || other->getHealth() <= 0) return;

        if(mana == 100){
            cout << "Archer used Fire Arrow with power " << specialPower << endl;
            other->defend(specialPower);
            updateMana(-100);
        }
    }
    void displayStat(){
        cout << "Archer: " << endl;
        cout << "Current Health: " << health << endl;
        cout << "Current Mane: " << mana << endl;
    }
};

class Boss : public BaseCharacter{
public:
    Boss(int health, int attackPower, int specialPower) : BaseCharacter(health, attackPower, specialPower, 0, 1) {}
    void attack(CharacterActions *other){
        if(isDead || other->getHealth() <= 0) return;
        cout << "Boss attacks with power " << attackPower << endl;
        other->defend(attackPower);
        updateMana(increment);
    }
    void defend(int atk){
        if(isDead) return;
        cout << "Boss takes " << atk << " damage" << endl;
        updateHealth(atk);
        if(health < 0){
            updateDeath();
            cout << "Boss Died" << endl;
        }
    }
    void specialAttack(CharacterActions *other){
        
    }
    void displayStat(){
        cout << "Boss: " << endl;
        cout << "Current Health: " << health << endl;
    }
};

class GameEngine{
    CharacterActions *warrior, *mage, *archer, *boss;
public:
    GameEngine(CharacterActions *warrior, CharacterActions *mage, CharacterActions *archer, CharacterActions *boss) : warrior(warrior), mage(mage), archer(archer), boss(boss) {}
    void action(CharacterActions *a, CharacterActions *b){
        a->attack(b);
        a->specialAttack(b);
    }
    void gameStart(){
        int move = 0;
        while(boss->getHealth() > 0 and (warrior->getHealth() > 0 || mage->getHealth() > 0 || archer->getHealth() > 0)){
            if(move){
                action(boss, warrior);
                action(boss, mage);
                action(boss, archer);
            }else{
                action(warrior, boss);
                action(mage, boss);
                action(archer, boss);
            }
            cout<<endl;
            move ^= 1;
        }
        if(boss->getHealth() <= 0 and warrior->getHealth() > 0 and mage->getHealth() > 0 and archer->getHealth() > 0){
            cout << "Boss defeated. Players win!!" << endl;
        }else{
            cout << "Player lost the game" << endl;
        }
    }
};

int main(){
    srand(time(0));
    CharacterActions *warrior = new Warrior(100, 25, 35);
    CharacterActions *mage = new Mage(120, 20, 30);
    CharacterActions *archer = new Archer(90, 20, 35);
    CharacterActions *boss = new Boss(150, 30, 0);
    GameEngine game(warrior, mage, archer, boss);
    game.gameStart();
}
