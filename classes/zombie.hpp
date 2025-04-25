#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


/**
 * @class Zombie
 * @brief Represents a zombie in the game, with attributes like health, damage, and the ability to move.
 */
class Zombie{
    
    public:
        string name;
        bool slowed = false;
        int x;
        int y;
        int hp;
        int dmg;
        int moveSpeed; 
        Image *z;

        int bildgröße = 80;
        int timer = 0; //for attacking plants
        
        int slowtimer = 0; // not used yet
    
    public:

        /**
         * @brief Destructor to clean up dynamically allocated resources (zombie image).
         */
        ~ Zombie() {
            delete z;
        }
        
        /**
         * @brief Constructor to initialize a zombie object with a specific name, position, and optional garden reference.
         * 
         * @param name Name of the zombie (e.g., "normal_zombie", "cone_zombie")
         * @param x X coordinate for the zombie's position
         * @param y Y coordinate for the zombie's position
         * @param garten Optional SVG reference for the garden where the zombie is placed
         */
        Zombie(string name, int x, int y, SVG* garten = nullptr) {
            
            this->y = y;
            this->x = x;

            if (name == "normal_zombie") {
                z = new Image("img/normal_zombie.png",x,y,bildgröße+10,bildgröße+10,garten);
                this->hp = 100;
                this->dmg = 50;
                this->moveSpeed = 5;
                this->name = name;

            } else if(name == "cone_zombie") {
                z = new Image("img/cone_zombie.png",x,y,bildgröße+10,bildgröße+10,garten);
                this->hp = 150;
                this->dmg = 45;
                this->moveSpeed = 5;
                this->name = name;
            }
        }
        
         /**
         * @brief Moves the zombie to the left by its move speed.
         * 
         * This method updates both the zombie's position and its image.
         */
        void move(){
            this-> x -= moveSpeed;
            z -> moveBy(-moveSpeed,0);
             
        }
        
        /**
         * @brief Reduces the zombie's health by the given damage amount.
         * 
         * @param damage The amount of damage to subtract from the zombie's health
         */
        void hit(int damage){
            this-> hp -= damage;
         }

         /**
         * @brief Slows down the zombie by reducing its movement speed.
         */
         void slow(){
            this->slowed = true;
            this-> moveSpeed -= 3;
       }

       /**
     * @brief Resets the zombie's speed back to normal after it has been slowed.
     * 
     * This method checks if the zombie is slowed and, after a certain time, resets its speed.
     * 
     * @note Currently unused in the game logic.
     */
       void accelerate (){
            if (this->slowed){
                if (slowtimer == 50) {
                    this->slowed = false;
                this-> moveSpeed = 5;
                    this->slowtimer = 0;
                
                } else {
                    slowtimer++;
                }
            }
       }
};

#endif