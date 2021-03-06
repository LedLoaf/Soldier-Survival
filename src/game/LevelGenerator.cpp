#include <math.h>
#include <time.h>
#include <cstdlib>

#include <game/LevelGenerator.hpp>
#include <game/object/LevelDescription.hpp>

#include "view/model/HUDViewModel.hpp"
#include "game/object/MapObject.hpp"
#include <game/object/Ground.hpp>
#include "game/object/Enemy.hpp"
#include "game/object/Equipment.hpp"
#include <util/Location.hpp>

namespace game {

LevelGenerator::LevelGenerator(game::LevelDescription* levelDescription) {
    this->levelDescription = levelDescription;
    
    mapModel = new view::MapViewModel(levelDescription->getMapWidth(), levelDescription->getMapHeight());
    
    
//    map = new tileType*[mapModel->getMapHeight()];
//    for (int i = 0; i < mapModel->getMapHeight(); ++i) {
//        for (int j = 0; j < mapModel->getMapWidth(); ++j) {
//            mapModel->put(new util::Location::Position(i, j), new game::MapObject(MapObject::));
//        }
//    }
    
	this->generateWalls();
	this->generateForest();
	this->generatePaths();
	this->generatePaths();
	this->generatePaths();
	this->generateRivers();
	this->generateRivers();
    this->generateGrass();
    this->generateGround();
    this->generateSand();
    
	this->placeEnemies();
//	this->placeNPC();
	this->placeBoss();
    
    this->generatePlayer();
	this->placePlayer();
    this->placeHealthPacks();
        
        /*
        for (int i = 0; i < mapModel->getMapHeight(); i++) {
            for (int j = 0; j < mapModel->getMapWidth(); j++) {
                std::cout << mapModel->getVisibleMapObject(i, j)->getType();
            }   
            std::cout << std::endl; 
        }
        */   
}

void LevelGenerator::generateWalls() {
    for (int i = 0; i < mapModel->getMapHeight(); ++i) {
        for (int j = 0; j < mapModel->getMapWidth(); ++j) {
            if (i == 0 || i == mapModel->getMapHeight()-1 || j == 0 || j == mapModel->getMapWidth()-1) {
                mapModel->put(i, j, new game::NotMovingMapObject(game::MapObject::WALL));
                //std::cout << i << "," << j << " -> WALL" << std::endl;
            }
        }
    }
}

void LevelGenerator::generateForest() {
    int cntForests = rand() % 8 + 14;
    
    for (int x = 0; x < cntForests; ++x) {
        //std::cout << "getMapWidth" << mapModel->getMapWidth() << ", getMapHeight " << mapModel->getMapHeight() << std::endl;
        util::Location::Position *p = new util::Location::Position(rand() % mapModel->getMapWidth(), rand() % mapModel->getMapHeight());
        int dx = (rand() % 50 + 5) * mapModel->getMapWidth();
        int dy = (rand() % 50 + 5) * mapModel->getMapHeight();
        dx = round((float)dx / 100);
        dy = round((float)dy / 100);
        
        //std::cout << p->getX() << "," << p->getY() << " FIELD: " << dx << "x" << dy << " -> FOREST CENTER" << std::endl;
        
        this->placeRandomly(p, dx, dy, 0.04, new NotMovingMapObject(MapObject::TREE));
        
    }
}

void LevelGenerator::generateGrass() {
    for (int x = 0; x < mapModel->getMapWidth(); x++) {
        for (int y = 0; y < mapModel->getMapHeight(); y++) {
                mapModel->put(x, y, new game::Ground(MapObject::GRASS));
        }
    }
}

void LevelGenerator::generateSand() {
    int _x = round(rand()% mapModel->getMapWidth());
    int _y = round(rand()% mapModel->getMapHeight());
    
    int dx = rand()%(mapModel->getMapWidth()-10) / 2.0;
    int dy = rand()%(mapModel->getMapHeight()-10) / 2.0;
    dx += 10;
    dy += 10;
    
    for (int x = -dx; x < dx; x++) {
        if (_x+x <= 0 || _x+x >= mapModel->getMapWidth()-1) {
            continue;
        }
        
        for (int y = -dy; y < dy; y++) {
            if (_y+y <= 0 || _y+y >= mapModel->getMapHeight()-1) {
                continue;
            }
            float ddx = (float)(x)/(float)dx;
            float ddy = (float)(y)/(float)dy;
            if (ddx*ddx + ddy*ddy <= 1) {
                mapModel->put(_x+x, _y+y, new game::Ground(MapObject::SAND));
            }
        }
    }
}

void LevelGenerator::generateGround() {
    int _x = round(rand()% mapModel->getMapWidth());
    int _y = round(rand()% mapModel->getMapHeight());
    
    int dx = rand()%(mapModel->getMapWidth()-10) / 2.0;
    int dy = rand()%(mapModel->getMapHeight()-10) / 2.0;
    dx += 10;
    dy += 10;
    
    for (int x = -dx; x < dx; x++) {
        if (_x+x <= 0 || _x+x >= mapModel->getMapWidth()-1) {
            continue;
        }
        
        for (int y = -dy; y < dy; y++) {
            if (_y+y <= 0 || _y+y >= mapModel->getMapHeight()-1) {
                continue;
            }
            float ddx = (float)(x)/(float)dx;
            float ddy = (float)(y)/(float)dy;
            if (ddx*ddx + ddy*ddy <= 1) {
                mapModel->put(_x+x, _y+y, new game::Ground(MapObject::GROUND));
            }
        }
    }
}

void LevelGenerator::generateRivers() {
    
    util::Location::Position *p;
    util::Location::Vector oryginalVector, vector;
    
    util::Location::Vector vectorPool[4] = {util::Location::UP, util::Location::RIGHT, util::Location::DOWN, util::Location::LEFT}; 
    oryginalVector = vector = vectorPool[(rand() % 4)];
    
    
    int twistedRiver = rand() % (mapModel->getMapHeight()/8) + 3;
    int bridgeProbability = rand() % 3 + 95;
    
    if (vector == util::Location::DOWN) { // topside -> down
        p = new util::Location::Position(rand() % (mapModel->getMapWidth()-2) + 1, 0);
    } else if (vector == util::Location::LEFT) { // rightside -> left
        p = new util::Location::Position(mapModel->getMapWidth()-1, rand() % (mapModel->getMapHeight()-2) + 1);
    } else if (vector == util::Location::UP) { // bottomside -> up
        p = new util::Location::Position(rand() % (mapModel->getMapWidth()-2) + 1, mapModel->getMapHeight()-1);
    } else { // leftside -> right
        p = new util::Location::Position(0, rand() % (mapModel->getMapHeight()-2) + 1);
    }
    
    mapModel->put(p->getX(), p->getY(), new game::NotMovingMapObject(MapObject::RIVER));
//    std::cout << "River starts: " << p->getX() << "," << p->getY() << std::endl;
    
    bool notEnd = true;
    while (notEnd) {
        int len = rand() % twistedRiver + 3;
        if (vector == util::Location::DOWN || vector == util::Location::UP) {
            len *= mapModel->getMapHeight();
        } else {
            len *= mapModel->getMapWidth();
        }
        len = round((float)len / 100);
//        std::cout << "River len: " << len << " direction to " << vector << std::endl;
        
        int p_y = p->getY();
        int p_x = p->getX();
        if (vector == util::Location::DOWN) {
            int sectionLen = p->getY() + len;
            for (sectionLen; p_y <= sectionLen; ++p_y) {
                p->setY(p_y);
                notEnd = placeRiverOrBridge(p, bridgeProbability);
            }
        } else if (vector == util::Location::LEFT) {
            int sectionLen = p->getX() - len;
            for (sectionLen; p_x >= sectionLen; --p_x) {
                p->setX(p_x);
                notEnd = placeRiverOrBridge(p, bridgeProbability);
            }
        } else if (vector == util::Location::UP) {
            int sectionLen = p->getY() - len;
            for (sectionLen; p_y >= sectionLen; --p_y) {
                p->setY(p_y);
                notEnd = placeRiverOrBridge(p, bridgeProbability);
            }
        } else if (vector == util::Location::RIGHT) {
            int sectionLen = p->getX() + len;
            for (sectionLen; p_x <= sectionLen; ++p_x) {
                p->setY(p_x);
                notEnd = placeRiverOrBridge(p, bridgeProbability);
            }
        }
        
        bool randomReady = false;
        while (!randomReady) {
            util::Location::Vector newVector = vectorPool[(rand() % 4)];
            if (oryginalVector == util::Location::DOWN && newVector == util::Location::UP) {
                continue;
            }
            if (oryginalVector == util::Location::LEFT && newVector == util::Location::RIGHT) {
                continue;
            }
            if (oryginalVector == util::Location::UP && newVector == util::Location::DOWN) {
                continue;
            }
            if (oryginalVector == util::Location::RIGHT && newVector == util::Location::LEFT) {
                continue;
            }
            if (vector == util::Location::DOWN && newVector == util::Location::UP) {
                continue;
            }
            if (vector == util::Location::LEFT && newVector == util::Location::RIGHT) {
                continue;
            }
            if (vector == util::Location::UP && newVector == util::Location::DOWN) {
                continue;
            }
            if (vector == util::Location::RIGHT && newVector == util::Location::LEFT) {
                continue;
            }
            vector = newVector;
            randomReady = true;
        }
        
        //notEnd = false;
    }
//    std::cout << "River starts: " << p->getX() << "," << p->getY() << std::endl;
}


void LevelGenerator::generatePaths() {
    
    util::Location::Position *p;
    util::Location::Vector oryginalVector, vector;
    
    util::Location::Vector vectorPool[4] = {util::Location::UP, util::Location::RIGHT, util::Location::DOWN, util::Location::LEFT}; 
    oryginalVector = vector = vectorPool[(rand() % 4)];
    
    
    int twistedRiver = rand() % (mapModel->getMapHeight()/8) + 3;
    int bridgeProbability = rand() % 3 + 95;
    
    if (vector == util::Location::DOWN) { // topside -> down
        p = new util::Location::Position(rand() % (mapModel->getMapWidth()-2) + 1, 0);
    } else if (vector == util::Location::LEFT) { // rightside -> left
        p = new util::Location::Position(mapModel->getMapWidth()-1, rand() % (mapModel->getMapHeight()-2) + 1);
    } else if (vector == util::Location::UP) { // bottomside -> up
        p = new util::Location::Position(rand() % (mapModel->getMapWidth()-2) + 1, mapModel->getMapHeight()-1);
    } else { // leftside -> right
        p = new util::Location::Position(0, rand() % (mapModel->getMapHeight()-2) + 1);
    }
    
    mapModel->put(p->getX(), p->getY(), new game::NotMovingMapObject(MapObject::ROAD));
//    std::cout << "River starts: " << p->getX() << "," << p->getY() << std::endl;
    
    bool notEnd = true;
    while (notEnd) {
        int len = rand() % twistedRiver + 3;
        if (vector == util::Location::DOWN || vector == util::Location::UP) {
            len *= mapModel->getMapHeight();
        } else {
            len *= mapModel->getMapWidth();
        }
        len = round((float)len / 100);
//        std::cout << "River len: " << len << " direction to " << vector << std::endl;
        
        int p_y = p->getY();
        int p_x = p->getX();
        if (vector == util::Location::DOWN) {
            int sectionLen = p->getY() + len;
            for (sectionLen; p_y <= sectionLen; ++p_y) {
                p->setY(p_y);
                notEnd = placePath(p);
                
            }
        } else if (vector == util::Location::LEFT) {
            int sectionLen = p->getX() - len;
            for (sectionLen; p_x >= sectionLen; --p_x) {
                p->setX(p_x);
                notEnd = placePath(p);
            }
        } else if (vector == util::Location::UP) {
            int sectionLen = p->getY() - len;
            for (sectionLen; p_y >= sectionLen; --p_y) {
                p->setY(p_y);
                notEnd = placePath(p);
            }
        } else if (vector == util::Location::RIGHT) {
            int sectionLen = p->getX() + len;
            for (sectionLen; p_x <= sectionLen; ++p_x) {
                p->setY(p_x);
                notEnd = placePath(p);
            }
        }
        
        bool randomReady = false;
        while (!randomReady) {
            util::Location::Vector newVector = vectorPool[(rand() % 4)];
            if (oryginalVector == util::Location::DOWN && newVector == util::Location::UP) {
                continue;
            }
            if (oryginalVector == util::Location::LEFT && newVector == util::Location::RIGHT) {
                continue;
            }
            if (oryginalVector == util::Location::UP && newVector == util::Location::DOWN) {
                continue;
            }
            if (oryginalVector == util::Location::RIGHT && newVector == util::Location::LEFT) {
                continue;
            }
            if (vector == util::Location::DOWN && newVector == util::Location::UP) {
                continue;
            }
            if (vector == util::Location::LEFT && newVector == util::Location::RIGHT) {
                continue;
            }
            if (vector == util::Location::UP && newVector == util::Location::DOWN) {
                continue;
            }
            if (vector == util::Location::RIGHT && newVector == util::Location::LEFT) {
                continue;
            }
            vector = newVector;
            randomReady = true;
        }
        
        //notEnd = false;
    }
//    std::cout << "River starts: " << p->getX() << "," << p->getY() << std::endl;
}

void LevelGenerator::generatePlayer() {
    player = new Player(levelDescription->getPlayerEquipment(), mapModel);
    player->setHealth(levelDescription->getPlayerHealth());
}

bool LevelGenerator::placeRiverOrBridge(util::Location::Position *p, int bridgeProbability) {
    if (p->getX() >= 0 && p->getX() < mapModel->getMapWidth() && p->getY() >= 0 && p->getY() < mapModel->getMapHeight()) {
        if (p->getX() >= 1 && p->getX() < mapModel->getMapWidth()-1 && p->getY() >= 1 && p->getY() < mapModel->getMapHeight()-1 && rand() % 100 > bridgeProbability) {
            mapModel->put(p->getX(), p->getY(), new NotMovingMapObject(MapObject::BRIDGE));
        } else {
            mapModel->put(p->getX(), p->getY(), new NotMovingMapObject(MapObject::RIVER));
        }
        return true;
    } else {
        return false;
    }
}

bool LevelGenerator::placePath(util::Location::Position *p) {
    if (p->getX() >= 1 && p->getX() < mapModel->getMapWidth()-1 && p->getY() >= 1 && p->getY() < mapModel->getMapHeight()-1) {
        mapModel->put(p->getX(), p->getY(), new NotMovingMapObject(MapObject::ROAD));
        return true;
    } else {
        return false;
    }
}

void LevelGenerator::placeEnemies() {
    int cntEnemies = rand() % (levelDescription->getEnemyPlacesMax() - levelDescription->getEnemyPlacesMin()) + levelDescription->getEnemyPlacesMin();
    
    for (int x = 0; x < cntEnemies; ++x) {
        
        util::Location::Position *p = new util::Location::Position(rand() % mapModel->getMapWidth(), rand() % mapModel->getMapHeight());
        int dx = (rand() % 16 + 8) * mapModel->getMapWidth();
        int dy = (rand() % 16 + 8) * mapModel->getMapHeight();
        dx = round((float)dx / 100);
        dy = round((float)dy / 100);
        
        //std::cout << p->getX() << "," << p->getY() << " FIELD: " << dx << "x" << dy << " -> FOREST CENTER" << std::endl;
        Enemy *e;
        int et = rand()%5;
        if (et == 0) {
            e = new Enemy(MapObject::ENEMY_A, mapModel);
        } else if (et == 1) {
            e = new Enemy(MapObject::ENEMY_B, mapModel);
        } else if (et == 2) {
            e = new Enemy(MapObject::ENEMY_C, mapModel);
        } else if (et == 3) {
            e = new Enemy(MapObject::ENEMY_D, mapModel);
        } else if (et == 4) {
            e = new Enemy(MapObject::ENEMY_E, mapModel);
        }
        this->placeRandomly(p, dx, dy, levelDescription->getEnemyDensity(), e);
        
    }
}

//void LevelGenerator::placeNPC() {
//    util::Location::Position *p = new util::Location::Position();
//    
//    int hh = mapModel->getMapHeight()/2;
//    int hw = mapModel->getMapWidth()/2;
//    int dh = mapModel->getMapHeight()/5;
//    int dw = mapModel->getMapWidth()/5;
//    
//    bool NPCPlaced = false;
//    while (!NPCPlaced) {
//        std::cout << "NPC Placing" << std::endl;
//        
//        p->getX() = rand() % (2*dw) + hw-dw;
//        p->getY() = rand() % (2*dh) + hh-dh;
//        
//        if (this->checkClearAround(p, 1)) {
//            mapModel->put(new util::Location::Position(p->getX(), p->getY()), new Trader());
//            NPCPlaced = true;
//        }
//    }
//}

void LevelGenerator::placePlayer() {
    // always left side
    int x, y;
    
    bool playerPlaced = false;
    while (!playerPlaced) {
//        std::cout << "Player Placing" << std::endl;
        
        x = rand() % (mapModel->getMapWidth() / 10) + 2;
        y = rand() % (mapModel->getMapHeight() - 2) + 2;
        
        if (this->checkClearAround(new util::Location::Position(x, y), 1)) {
            mapModel->put(x, y, player);
            mapModel->put(x+1, y+1, new Enemy(MapObject::ENEMY_A, mapModel));
            mapModel->put(x+2, y+2, new Enemy(MapObject::ENEMY_A, mapModel));
            mapModel->put(x+3, y+3, new Enemy(MapObject::ENEMY_A, mapModel));
            mapModel->put(x+4, y+4, new Enemy(MapObject::ENEMY_A, mapModel));
            mapModel->put(x+5, y+5, new Enemy(MapObject::ENEMY_A, mapModel));
            
            playerPlaced = true;
        }
    }
}

void LevelGenerator::placeBoss() {
    // always right side
    int x, y;
    
    bool bossPlaced = false;
    while (!bossPlaced) {
//        std::cout << "BOSS Placing" << std::endl;
        
        x = mapModel->getMapWidth() - 2 - rand() % (mapModel->getMapWidth() / 10);
        y = rand() % (mapModel->getMapHeight() - 2) + 2;
        
        if (this->checkClearAround(new util::Location::Position(x, y), 1)) {
            mapModel->put(x, y, new Enemy(MapObject::BOSS, mapModel));
            bossPlaced = true;
        }
    }
}

bool LevelGenerator::checkClearAround(util::Location::Position *p, int radius) {
    
    
    int max_y = (p->getY() + radius > mapModel->getMapWidth()-1) ? mapModel->getMapWidth()-1 : p->getY() + radius;
    int min_y = (p->getY() - radius < 1) ? 1 : p->getY() - radius;
    int max_x = (p->getX() + radius > mapModel->getMapHeight()-1) ? mapModel->getMapHeight()-1 : p->getX() + radius;
    int min_x = (p->getX() - radius < 1) ? 1 : p->getX() - radius;
    
//    std::cout << "Map width: " << mapModel->getMapWidth() << " , height: " << mapModel->getMapHeight() << std::endl;
//    std::cout << "Trying to place! [" << p->getX() << "," << p->getY() << "], {" << min_x << "-" << max_x << ", " << min_y << "-" << max_y << "}" << std::endl;
    
    
    for (int i = min_y; i <= max_y; ++i) {
        for (int j = min_x; j <= max_x; ++j) {
            if (!MapObject::isTerrain(mapModel->getVisibleMapObject(i, j))) {
                return false;
            }
        }
    }
    return true;
}

void LevelGenerator::placeHealthPacks() {
    int numberOfHealthPacks = 20;
    util::Location::Position* position;
    
    MapObject::Type healthPackTypes[2] = {MapObject::HEALTH_PACK, MapObject::FOOD};
    
    int i = 0;
    while (i < numberOfHealthPacks) {
        position = new util::Location::Position(rand() % mapModel->getMapWidth(), rand() % mapModel->getMapHeight());
        if (checkClearAround(position, 1)) {
            mapModel->put(position->getX(), position->getY(), new NotMovingMapObject(healthPackTypes[rand() % 2]));
            i++;
        }
    }    
}

void LevelGenerator::placeRandomly(util::Location::Position *p, int dx, int dy, float density, MapObject* tt) {
    int ttCount = dx*dy;
    ttCount = (float)ttCount * density;
    //ttCount = roundf((float)ttCount / 100);
    //std::cout << "dx: " << dx << ", dy: " << dy << " dens: " << density << ", ttCount: " << ttCount << " (" << (ttCount/(dx*dy)) << "%)" << std::endl;
    
    int x1 = p->getX() - dx/2;
    int x2 = p->getX() + dx/2;
    int y1 = p->getY() - dy/2;
    int y2 = p->getY() + dy/2;
    
    //std::cout << "Field: " << x1 << ","  << x2 << ","  << y1 << "," << y2 << std::endl;
    int i = 0, j = 0;
    while (i < ttCount) {
        util::Location::Position *ptt = new util::Location::Position(rand() % dx + p->getX() - dx/2, rand() % dy + p->getY() - dy/2);
        //std::cout << j+1 << " util::Location::Position: " << ptt->getX() << ","  << ptt->getY();
        if (ptt->getX() >= 0 && ptt->getX() < mapModel->getMapWidth() 
                && ptt->getY() >= 0 && ptt->getY() < mapModel->getMapHeight()) {
            
            if (mapModel->getNotMovingObject(ptt->getX(), ptt->getY()) == NULL || (!MapObject::isWall(mapModel->getNotMovingObject(ptt->getX(), ptt->getY())) 
                    && !MapObject::isRiver(mapModel->getNotMovingObject(ptt->getX(), ptt->getY()))
                    && !MapObject::isBridge(mapModel->getNotMovingObject(ptt->getX(), ptt->getY())))) {
                switch (tt->getType()) {
                    case game::MapObject::GRASS:
//                    case game::MapObject::GRASS_GREEN:
                    case game::MapObject::GROUND:
                    case game::MapObject::WALL:
                    case game::MapObject::RIVER:
                    case game::MapObject::TREE:
                    case game::MapObject::ROAD:
                    case game::MapObject::SAND:
                        // if (tt->getType() == game::MapObject::TREE) std::cout<<"tree!\n";
                        mapModel->put(ptt->getX(), ptt->getY(), dynamic_cast<game::NotMovingMapObject*>(tt));
                        break;
                    case game::MapObject::PLAYER :
                        mapModel->put(ptt->getX(), ptt->getY(), dynamic_cast<game::Player*>(tt));
                        break; 
                    case game::MapObject::ENEMY_A:
                    case game::MapObject::ENEMY_B:
                    case game::MapObject::ENEMY_C:
                    case game::MapObject::ENEMY_D:
                    case game::MapObject::ENEMY_E:
                        mapModel->put(ptt->getX(), ptt->getY(), dynamic_cast<game::Enemy*>(tt));
                        break;
                    default:
                        mapModel->put(ptt->getX(), ptt->getY(), dynamic_cast<game::Character*>(tt));
                        break; 
                }
                //++i;
            }
        } else {
//            std::cout << " -> bad position!";
            //++i;
        }
        
        ++i;
//        std::cout << std::endl;
        
        ++j;
        if (j > dx*dy) {
//            std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
            return;
        }
    }
}
    
view::HUDViewModel* LevelGenerator::getHUDViewModel() {
    if (player == NULL) {
        // rzucic wyjatek, ze player nie zostal zainicjalizowany
        return NULL;
    }
    view::HUDViewModel* hudModel = new view::HUDViewModel();  
    hudModel->setPlayer(player);

    return hudModel;
}

view::MapViewModel* LevelGenerator::getMapViewModel() {
    return mapModel;
}
    

}