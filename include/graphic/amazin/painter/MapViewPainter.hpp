#ifndef MAP_VIEW_PAINTER_HPP_
#define MAP_VIEW_PAINTER_HPP_

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>


#include <util/Key.hpp>
#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <view/model/MapViewModel.hpp>

namespace util {
    class SFMLAmazinResource;
}

namespace view {
class ImageViewModel;
}

namespace game {
class MapObject;
class Player;
}

namespace graphic {
namespace amazin {
    


class MapViewPainter : public SFMLAbstractViewPainter {
public:
	MapViewPainter(view::MapViewModel* model);


	virtual void init();
	virtual void update();
    
    void allocateMapElementSprites(int subMapWidth, int subMapHeight);

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
    sf::Sprite*** mapElementSprites; 
    
    int subMapWidth;
    int subMapHeight;
    int elementWidth;
    int elementHeight;
    
    SubMapManager* subMapManager;
    util::SFMLAmazinResource* sfmlAmazinResource;
    
    
    class SubMapManager {
    public:
        SubMapManager(view::MapViewModel* model, int subMapWidth, int subMapHeight, int playerToWallSpace);
        void setSubMapWidth(int width);
        void setSubMapHeight(int height);
        void updateSubMap();
        game::MapObject* getElementAt(int x, int y);
        
        static int leftWallPos;
        static int topWallPos;
        
    private:
        static int subMapWidth;
        static int subMapHeight;    
        int playerToWallSpace;
        game::Player* player;
        view::MapViewModel* mapViewModel;        
        static bool mapIsUpdating;
        
        class SmoothlyMoveSubmapWallThread : public sf::Thread {
        public:
            SmoothlyMoveSubmapWallThread(view::MapViewModel* mapViewModel, int* currentWallPos, int playerToWallSpace, util::Key::Arrow direction) {
                this->mapModel = mapViewModel;
                this->direction = direction;
                this->wallPos = *currentWallPos;
                this->currentWallPos = currentWallPos;
                this->playerToWallSpace = playerToWallSpace;
                
                switch (direction) {
                    case util::Key::LEFT:
                        maxAfterWallPos = leftWallPos - subMapWidth / 2;
                        if (maxAfterWallPos < 0)
                            maxAfterWallPos = 0;
                        break;
                    case util::Key::RIGHT:
                        maxAfterWallPos = leftWallPos + subMapWidth / 2; 
                        if (maxAfterWallPos > mapViewModel->getMapHeight())
                            maxAfterWallPos = mapViewModel->getMapHeight();
                        break;
                    case util::Key::UP:
                        maxAfterWallPos = topWallPos - playerToWallSpace; 
                        if (maxAfterWallPos < 0)
                            maxAfterWallPos = 0;
                        break;
                    case util::Key::DOWN:
                        maxAfterWallPos = topWallPos + playerToWallSpace; 
                        if (maxAfterWallPos > mapViewModel->getMapHeight())
                            maxAfterWallPos = mapViewModel->getMapHeight();
                        break;                        
                        
                }
            }
            
        private:
            util::Key::Arrow direction;            
            int* currentWallPos;            
            int maxAfterWallPos;
            int wallPos;
            int playerToWallSpace;
            view::MapViewModel* mapModel;
            sf::Mutex GlobalMutex;
            
            virtual void Run() {
                mapIsUpdating = true;
//                std::cout << "maxAfterWallPos: " << maxAfterWallPos << ", wallPos: " << wallPos << std::endl;
                GlobalMutex.Lock();
                
                while (true) {
                    if (direction == util::Key::LEFT && leftWallPos > maxAfterWallPos && leftWallPos > 0)
                        leftWallPos--;
                    else if (direction == util::Key::RIGHT && leftWallPos < maxAfterWallPos && leftWallPos < mapModel->getMapWidth() - subMapWidth)
                        leftWallPos++;
                    else if (direction == util::Key::DOWN && topWallPos < maxAfterWallPos && topWallPos < mapModel->getMapHeight() + subMapHeight)
                        topWallPos++;
                    else if (direction == util::Key::UP && topWallPos > maxAfterWallPos && topWallPos > 0)
                        topWallPos--;
                    else
                        break;
                    
                    sf::Sleep(0.1f);
                }
                GlobalMutex.Unlock();
                
                mapIsUpdating = false;
            }
        };
        
        
    };
};

}
}


#endif
