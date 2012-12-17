#ifndef MAP_VIEW_PAINTER_HPP_
#define MAP_VIEW_PAINTER_HPP_

#include <view/View.hpp>
#include <view/model/MapViewModel.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>

namespace graphic {
namespace amazin {

class MapViewPainter : public SFMLAbstractViewPainter {
public:
	MapViewPainter(view::ImageViewModel* model, view::View::Type parentViewType);
    

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
	view::MapViewModel* mapViewModel;
    std::vector< std::vector<sf::Sprite*> > mapElementSprites; 
    
    int subMapWidth;
    int subMapHeight;
    int elementSize;
    
    SubMapManager* subMapManager;
    
    class SubMapManager {
    public:
        SubMapManager(view::MapViewModel* model);
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
                    case util::Key::UP:
                        afterWallPos += subMapHeight - playerToWallSpace;       
                        break;
                }
            }
            
        private:
            util::Key::Arrow direction;            
            int currentWallPos;            
            int afterWallPos;
            int wallPos;
            
            virtual void Run() {

                for (int i = 0; i < fabs(afterWallPos - wallPos); ++i)
                switch (direction) {
                     case util::Key::LEFT || util::Key::UP:
                        *currentWallPos--;
                        break;
                     case util::Key::RIGHT || util::Key::DOWN:
                        *currentWallPos++;
                        break;                        
                }
                
                sf::Sleep(0.1f);

            }
        };
        
        
    };
};

}
}


#endif
