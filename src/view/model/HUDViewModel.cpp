#include <view/model/HUDViewModel.hpp>
#include <game/object/Player.hpp>
#include <game/object/weapon/Weapon.hpp>

namespace view {

HUDViewModel::HUDViewModel() {
	// TODO Auto-generated constructor stub

}

HUDViewModel::~HUDViewModel() {
	// TODO Auto-generated destructor stub
}

void HUDViewModel::setPlayer(game::Player* player) {
    this->player = player;
    playerEquipment = player->getEquipment();
}

void HUDViewModel::setCurrentWeaponForPlayer(game::Weapon* weapon) {
    player->setCurrentWeapon(weapon);
}

int HUDViewModel::getPlayerExperiencePoints() {
    return player->getExperiencePoints();
}

int HUDViewModel::getPlayerHealth() {
    return player->getHealth();
}

game::Equipment* HUDViewModel::getPlayerEquipment() {
    return playerEquipment;
}

} /* namespace view */
