#include <iostream>
#include <string>

class Entity
{
public:
    virtual std::string GetName(){ return "Entity"; }

    Entity();
    virtual ~Entity();

};
Entity::Entity(){
    std::cout << "Entity constructor call" << std::endl;
}
Entity::~Entity(){
    std::cout << "Entity deconstructor call" << std::endl;
}

class Player: public Entity
{
private:
    std::string m_name;
public:
    Player(const std::string name):m_name(name) {
        std::cout << "Player constructor call" << std::endl;
    }
    ~Player();

    std::string GetName(){ return m_name; }
};
Player::~Player(){
    std::cout << "Player deconstructor call" << std::endl;
}
class PlayerArray
{
public: 
    Player** array;

    PlayerArray();
    ~PlayerArray();
};
PlayerArray::PlayerArray(){
    array = nullptr;
}
PlayerArray::~PlayerArray(){
    if (array != nullptr){
        delete[] array;
        array = nullptr;
    }
}

int main()
{
    //Entity e;
    //std::cout << e.GetName() << std::endl;
    //Player p("Edward");
    //std::cout << p.GetName() << std::endl;

    Entity* pe = new Player("Karin");
    std::cout <<pe->GetName() << std::endl; 
    
    delete pe;

    return 0;
}