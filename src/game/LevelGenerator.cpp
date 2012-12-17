#include <game/LevelGenerator.hpp>
#include <game/object/LevelDescription.hpp>

#include "view/model/HUDViewModel.hpp"

namespace game {

LevelGenerator::LevelGenerator(game::LevelDescription* levelDescription) {
    this->levelDescription = levelDescription;
    
    mapModel = new view::MapViewModel(levelDescription->getSizeWidth(), levelDescription->getSizeHeight());
    
    map = new tileType*[height];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            mapModel->put(new util::Location::Position(i, j), new game::object::Terrain(GRASS));
        }
    }
    
	this->generateWalls();
	this->generateForest();
	this->generateRivers();
	this->placeEnemies();
	this->placeNPC();
	this->placeBoss();
	this->placePlayer();
}

void LevelGenerator::generateWalls() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height-1 || j == 0 || j == width-1) {
                mapModel->put(new util::Location::Position(i, j), new game::object::Obstacle(WALL));
                //std::cout << i << "," << j << " -> WALL" << std::endl;
            }
        }
    }
}

void LevelGenerator::generateForest() {
    int cntForests = rand() % 5 + 6;
    
    for (int x = 0; x < cntForests; ++x) {
        
        Point *p = new Point(rand() % width, rand() % height);
        int dx = (rand() % 30 + 5) * width;
        int dy = (rand() % 30 + 5) * height;
        dx = roundf((float)dx / 100);
        dy = roundf((float)dy / 100);
        
        //std::cout << p->x << "," << p->y << " FIELD: " << dx << "x" << dy << " -> FOREST CENTER" << std::endl;
        
        this->placeRandomly(p, dx, dy, 0.10, new game::object::Obstacle(TREE));
        
    }
}

void LevelGenerator::generateRivers() {
    
    Point *p;
    vectorDirection oryginalVector, vector;
    oryginalVector = vector = (vectorDirection)(rand() % 4);
    
    int twistedRiver = rand() % (height/8) + 3;
    
    int bridgeProbability = rand() % 3 + 95;
    
    if (vector == vdDown) { // topside -> down
        p = new Point(rand() % (width-2) + 1, 0);
    } else if (vector == vdLeft) { // rightside -> left
        p = new Point(width-1, rand() % (height-2) + 1);
    } else if (vector == vdUp) { // bottomside -> up
        p = new Point(rand() % (width-2) + 1, height-1);
    } else { // leftside -> right
        p = new Point(0, rand() % (height-2) + 1);
    }
    
    mapModel->put(new util::Location::Position(p->x, p->y), new game::object::Obstacle(RIVER));
    std::cout << "River starts: " << p->x << "," << p->y << std::endl;
    
    bool notEnd = true;
    while (notEnd) {
        int len = rand() % twistedRiver + 3;
        if (vector == vdDown || vector == vdUp) {
            len *= height;
        } else {
            len *= width;
        }
        len = roundf((float)len / 100);
        std::cout << "River len: " << len << " direction to " << vector << std::endl;
        
        if (vector == vdDown) {
            int sectionLen = p->y + len;
            for (; p->y <= sectionLen; ++p->y) {
                notEnd = placeRiverOrBridge(p, bridgeProbability);
            }
        } else if (vector == vdLeft) {
            int sectionLen = p->x - len;
            for (; p->x >= sectionLen; --p->x) {
                notEnd = placeRiverOrBridge(p, bridgeProbability);
            }
        } else if (vector == vdUp) {
            int sectionLen = p->y - len;
            for (; p->y >= sectionLen; --p->y) {
                notEnd = placeRiverOrBridge(p, bridgeProbability);
            }
        } else if (vector == vdRight) {
            int sectionLen = p->x + len;
            for (; p->x <= sectionLen; ++p->x) {
                notEnd = placeRiverOrBridge(p, bridgeProbability);
            }
        }
        
        bool randomReady = false;
        while (!randomReady) {
            vectorDirection newVector = (vectorDirection)(rand() % 4);
            if (oryginalVector == vdDown && newVector == vdUp) {
                continue;
            }
            if (oryginalVector == vdLeft && newVector == vdRight) {
                continue;
            }
            if (oryginalVector == vdUp && newVector == vdDown) {
                continue;
            }
            if (oryginalVector == vdRight && newVector == vdLeft) {
                continue;
            }
            
            if (vector == vdDown && newVector == vdUp) {
                continue;
            }
            if (vector == vdLeft && newVector == vdRight) {
                continue;
            }
            if (vector == vdUp && newVector == vdDown) {
                continue;
            }
            if (vector == vdRight && newVector == vdLeft) {
                continue;
            }
            vector = newVector;
            randomReady = true;
        }
        
        //notEnd = false;
    }
    std::cout << "River starts: " << p->x << "," << p->y << std::endl;
}

bool LevelGenerator::placeRiverOrBridge(Point *p, int bridgeProbability) {
    if (p->x >= 0 && p->x < width && p->y >= 0 && p->y < height) {
        if (p->x >= 1 && p->x < width-1 && p->y >= 1 && p->y < height-1 && rand() % 100 > bridgeProbability) {
            mapModel->put(new util::Location::Position(p->x, p->y), new game::object::Terrain(BRIDGE));
        } else {
            mapModel->put(new util::Location::Position(p->x, p->y), new game::object::Obstacle(RIVER));
        }
        return true;
    } else {
        return false;
    }
}

void LevelGenerator::placeEnemies() {
    int cntEnemies = rand() % (LevelDescription->getEnemyPlacesMax() - LevelDescription->getEnemyPlacesMin()) + LevelDescription->getEnemyPlacesMin();
    
    for (int x = 0; x < cntEnemies; ++x) {
        
        Point *p = new Point(rand() % width, rand() % height);
        int dx = (rand() % 5 + 3) * width;
        int dy = (rand() % 5 + 3) * height;
        dx = roundf((float)dx / 100);
        dy = roundf((float)dy / 100);
        
        //std::cout << p->x << "," << p->y << " FIELD: " << dx << "x" << dy << " -> FOREST CENTER" << std::endl;
        
        this->placeRandomly(p, dx, dy, LevelDescription->getEnemyDensity(), ttEnemy);
        
    }
}

void LevelGenerator::placeNPC() {
    Point *p = new Point();
    
    int hh = height/2;
    int hw = width/2;
    int dh = height/5;
    int dw = width/5;
    
    bool NPCPlaced = false;
    while (!NPCPlaced) {
        std::cout << "NPC Placing" << std::endl;
        
        p->x = rand() % (2*dw) + hw-dw;
        p->y = rand() % (2*dh) + hh-dh;
        
        if (this->checkClearAround(p, 1)) {
            mapModel->put(new util::Location::Position(p->x, p->y), new game::Character(TRADER));
            NPCPlaced = true;
        }
    }
}

void LevelGenerator::placePlayer() {
    // always left side
    Point *p = new Point();
    
    bool playerPlaced = false;
    while (!playerPlaced) {
        std::cout << "Player Placing" << std::endl;
        
        p->x = rand() % (width / 10) + 2;
        p->y = rand() % (height - 2) + 2;
        
        if (this->checkClearAround(p, 1)) {
            mapModel->put(new util::Location::Position(p->x, p->y), new game::Character(PLAYER));
            playerPlaced = true;
        }
    }
}

void LevelGenerator::placeBoss() {
    // always right side
    Point *p = new Point();
    
    bool bossPlaced = false;
    while (!bossPlaced) {
        std::cout << "BOSS Placing" << std::endl;
        
        p->x = width - 2 - rand() % (width / 10);
        p->y = rand() % (height - 2) + 2;
        
        if (this->checkClearAround(p, 1)) {
            mapModel->put(new util::Location::Position(p->x, p->y), new game::Character(BOSS));
            bossPlaced = true;
        }
    }
}

bool LevelGenerator::checkClearAround(Point *p, int radius) {
    
    
    int max_y = (p->y + radius > width-1) ? width-1 : p->y + radius;
    int min_y = (p->y - radius < 1) ? 1 : p->y - radius;
    int max_x = (p->x + radius > height-1) ? height-1 : p->x + radius;
    int min_x = (p->x - radius < 1) ? 1 : p->x - radius;
    
    std::cout << "Trying to place! [" << p->x << "," << p->y << "], {" << min_x << "-" << max_x << ", " << min_y << "-" << max_y << "}" << std::endl;
    
    
    for (int i = min_y; i <= max_y; ++i) {
        for (int j = min_x; j <= max_x; ++j) {
            std::cout << "   [" << j << "," << i << "] -> " << this->convertTileTypeToChar(map[j][i]) << std::endl;
            if (!mapModel->isTypeOfTerrain(i, j)) {
                return false;
            }
        }
    }
    return true;
}

void LevelGenerator::placeRandomly(Point *p, int dx, int dy, float density, void tt) {
    int ttCount = dx*dy;
    ttCount = (float)ttCount * density;
    //ttCount = roundf((float)ttCount / 100);
    std::cout << "dx: " << dx << ", dy: " << dy << " dens: " << density << ", ttCount: " << ttCount << " (" << (ttCount/(dx*dy)) << "%)" << std::endl;
    
    int x1 = p->x - dx/2;
    int x2 = p->x + dx/2;
    int y1 = p->y - dy/2;
    int y2 = p->y + dy/2;
    
    //std::cout << "Field: " << x1 << ","  << x2 << ","  << y1 << "," << y2 << std::endl;
    int i = 0, j = 0;
    while (i < ttCount) {
        Point *ptt = new Point(rand() % dx + p->x - dx/2, rand() % dy + p->y - dy/2);
        std::cout << j+1 << " Point: " << ptt->x << ","  << ptt->y;
        if (ptt->x >= 0 && ptt->x < width && ptt->y >= 0 && ptt->y < height) {
            std::cout << " -> GOOD POSITION!";
            if (!mapModel->isObjectAt(new util::Location::Position(ptt->x, ptt->y), game::object::Obstacle(WALL) && !mapModel->isObjectAt(new util::Location::Position(ptt->x, ptt->y), game::object::Obstacle(RIVER) && !mapModel->isObjectAt(new util::Location::Position(ptt->x, ptt->y), game::object::Terrain(BRIDGE) && !mapModel->isObjectAt(new util::Location::Position(ptt->x, ptt->y), tt) {
                std::cout << " -> GOOD TO SET NEW TYPE HERE!";

                mapModel->put(new util::Location::Position(ptt->x, ptt->y), tt);
                //++i;
            }
        } else {
            std::cout << " -> bad position!";
            //++i;
        }
        
        ++i;
        std::cout << std::endl;
        
        ++j;
        if (j > dx*dy) {
            std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
            return;
        }
    }
}
    
view::HUDViewModel* LevelGenerator::getHUDViewModel() {
    view::HUDViewModel* hudModel = new view::HUDViewModel();
    
    hudModel->setWeapons(levelDescription->getPlayerWeapons());
}

view::MapViewModel* LevelGenerator::getMapViewModel() {
    return mapModel;
}
    

}