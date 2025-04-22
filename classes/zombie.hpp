#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP



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
        
        int slowtimer = 0; //im Moment nicht gebraucht
    
    public:

        ~ Zombie() {
            delete z;
        }
    
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
        
        void move(){
            this-> x -= moveSpeed;
            z -> moveBy(-moveSpeed,0);
             
        }
        
        void hit(int damage){
            this-> hp -= damage;
         }

         void slow(){
            this->slowed = true;
            this-> moveSpeed -= 3;
       }

       void accelerate (){ //im Moment nicht gebraucht
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