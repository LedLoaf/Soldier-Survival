#include <string>
#include <iostream>

#include <graphic/amazin/painter/WarViewPainter.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Color.hpp>


namespace graphic {
namespace amazin {


WarViewPainter::WarViewPainter(view::WarViewModel* warViewModel) {
    this->warViewModel = warViewModel;
    
    init();
}
    

void WarViewPainter::init() {    
    
    enemyHealthIndicator = new sf::Sprite();
    enemyHealthIndicator->SetX(100);
    enemyHealthIndicator->SetY(30);
    enemyHealthIndicator->SetColor(sf::Color::Red);
    enemyHealthIndicator->SetX(warViewModel->getEnemyPosition().getX());
    enemyHealthIndicator->SetY(warViewModel->getEnemyPosition().getY() - 15);    

    
    drawables.push_back(enemyHealthIndicator);
}


void WarViewPainter::update() {   
    //enemyHealthIndicator->Resize(warViewModel->getEnemyHealth() / 10, enemyHealthIndicator->GetSize().y);
}
    


}
}
