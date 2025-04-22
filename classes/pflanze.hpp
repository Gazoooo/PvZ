#ifndef Pflanze_HPP
#define Pflanze_HPP

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
        
        ~ Pflanze() {
            delete pflanze;
        }

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
        
        void hit(int damage){
            this-> hp -= damage;
        }

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