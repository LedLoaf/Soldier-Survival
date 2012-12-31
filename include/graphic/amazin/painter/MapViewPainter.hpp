#ifndef MAP_VIEW_PAINTER_HPP_
#define MAP_VIEW_PAINTER_HPP_

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>


#include <util/Key.hpp>
#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>


namespace view {
class ImageViewModel;
class MapViewModel;
}

namespace game {
class MapObject;
class Player;
}

namespace graphic {
namespace amazin {

class MapViewPainter : public SFMLAbstractViewPainter {
public:
	MapViewPainter(view::MapViewModel* model, view::View::Type parentViewType);
    

	virtual void init();
	virtual void update();
    
    /*
     SubMapManager odpowiada za dostarczanie wycinka mapy, ktory ma byc 
     * malowany przez MapViewPainter
     
     * w zaleznosci od polozenia gracza wycina mape
     * gdy gracz dochodzi do krawedzi, SubMapManager uruchamia timer
     * i powoli przesuwa mape (w tym czasie MapViewPainter ciagle ja rysuje)
     */
    
    

private:
    class SubMapManager;
    
	view::MapViewModel* mapViewModel;
    std::vector< std::vector<sf::Sprite*> > mapElementSprites; 
    
    int subMapWidth;
    int subMapHeight;
    int elementSize;
    
    SubMapManager* subMapManager;
    
    class SubMapManager {
    public:
        SubMapManager(view::MapViewModel* model, int subMapWidth, int subMapHeight, int playerToWallSpace);
        void setSubMapWidth(int width);
        void setSubMapHeight(int height);
        void updateSubMap();
        game::MapObject* getElementAt(int x, int y);
        
    private:
        int subMapWidth;
        int subMapHeight;    
        int playerToWallSpace;
        int leftWallPos;
        int topWallPos;
        game::Player* player;
        view::MapViewModel* mapViewModel;        
        
        class SmoothlyMoveSubmapThread : public sf::Thread {
        public:
            SmoothlyMoveSubmapThread(int* currentWallPos, util::Key::Arrow direction) {
                this->direction = direction;
                this->wallPos = *currentWallPos;
                
                switch (direction) {
                    case util::Key::LEFT:
                        afterWallPos -= subMapWidth - playerToWallSpace;
                        break;
                    case util::Key::RIGHT:
                        afterWallPos += subMapWidth - playerToWallSpace; 
                        break;
                    case util::Key::UP:
                        afterWallPos -= subMapHeight - playerToWallSpace;    
                        break;
                }
            }
            
        private:
            util::Key::Arrow direction;            
            int* currentWallPos;            
            int afterWallPos;
            int wallPos;
            int subMapWidth;
            int subMapHeight;      
            int playerToWallSpace;
            
            
            virtual void Run() {

                for (int i = 0; i < fabs(afterWallPos - wallPos); ++i)
                    if (direction == util::Key::LEFT || util::Key::UP)
                        *currentWallPos--;
                    else
                        *currentWallPos++;

                
                    sf::Sleep(0.1f);

            }
        };
        
        
    };
};

}
}


#endif
