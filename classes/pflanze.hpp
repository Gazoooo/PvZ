#ifndef Pflanze_HPP
#define Pflanze_HPP

/**
 * @class Pflanze
 * @brief Represents a plant object in a game, including attributes like health, damage, and the ability to shoot projectiles.
 */
class Pflanze {

    public:
        string name;
        int x;
        int y;

        int cost;
        int hp;
        int dmg;
        int projectilespeed;
        Image *pflanze;
        Circle *projectile;
        vector<Circle*> projectileList;
        int bildgröße = 80;
        int timer = 0; //for shoot 
        
        /**
         * @brief Destructor to clean up dynamically allocated resources (image and projectiles).
         */
        ~ Pflanze() {
            delete pflanze;
        }

        /**
         * @brief Constructor to initialize a plant object with a specific name, position, and optional garden reference.
         * 
         * @param name Name of the plant (e.g., "Erbsenkanone", "Walnuss", etc.)
         * @param x X coordinate for the plant's position
         * @param y Y coordinate for the plant's position
         * @param garten Optional SVG reference for the garden in which the plant is placed
         */
        Pflanze(string name, int x, int y, SVG* garten = nullptr) {
            this->x = x;
            this->y = y;
            
            if (name == "Erbsenkanone") {
                pflanze = new Image("img/erbsenkanone.png",x,y,bildgröße,bildgröße,garten);
                this-> projectilespeed = 10;
                this->hp = 100;
                this->cost = 100;
                this->dmg = 50;
                this->name = name;
            }

            if (name == "Walnuss") {
                pflanze = new Image("img/walnuss.png",x,y,bildgröße+40,bildgröße+40,garten);
                this-> projectilespeed = 0;
                this->hp = 300;
                this->cost = 50;
                this->dmg = 0;
                this->name = name;
            }
            
            if (name == "Sonnenblume"){
                pflanze = new Image("img/sonnenblume.png",x,y,bildgröße,bildgröße,garten);
                this->hp = 100;
                this->projectilespeed = 0;
                this->cost = 50;
                this->dmg = 0;
                this->name = name;
            } 

            if (name =="Eiskanone"){
                pflanze = new Image("img/eiskanone.png",x,y,bildgröße,bildgröße,garten);
               this->hp=100;
                this->projectilespeed = 15;
                this->cost = 125;
                this->dmg = 25;
                this->name = name;
            }
        }
        
        /**
         * @brief Reduces the plant's health by the given damage value.
         * 
         * @param damage The amount of damage to reduce from the plant's health
         */
        void hit(int damage){
            this-> hp -= damage;
        }

        /**
         * @brief Creates and shoots a projectile based on the plant's type.
         * 
         * Depending on the plant, the projectile is created with a color (light blue for "Eiskanone", yellow for others).
         * The projectile is added to the projectile list.
         * 
         * @param garten Optional SVG reference for the garden to draw the projectile in
         */
        void shoot(SVG* garten = nullptr) { 
            if (this->projectilespeed != 0) {
                    projectile = new Circle(this->x, this->y, 10, garten);
                    if (this->name == "Eiskanone") {
                        projectile->setFill("lightblue");
                    } else {
                        projectile->setFill("yellow");
                    }
                    this->projectileList.push_back(projectile);
            }
        }

        /**
         * @brief Moves the projectiles horizontally based on the plant's projectile speed.
         * 
         * This function iterates over all projectiles in the list, moving them to the right based on their speed.
         * If a projectile goes beyond the screen (x > 1200), it is deleted and removed from the list.
         * 
         * @param garten Optional SVG reference for the garden to draw the projectile movement in
         */
        void moveProjectile (SVG* garten = nullptr) {
            if (this->projectileList.size() != 0) {
                vector<Circle*>::iterator projektil = this->projectileList.begin();
                while (projektil != this->projectileList.end()) {
                    if ((*projektil)->getX() > 1200) {
                        delete *projektil;
                        this->projectileList.erase(projektil);
                        
                    } else {
                        (*projektil)->moveTo((*projektil)->getX() + projectilespeed,this->y);
                        projektil++;
                    }
                }
            }
        }
};


#endif