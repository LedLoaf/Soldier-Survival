#ifndef GAME_MASTER_ENGINE_HPP_
#define GAME_MASTER_ENGINE_HPP_

#include <graphic/GraphicEngine.hpp>
#include <game/object/LevelDescription.hpp>

class GameMasterEngine {
public:
	void setGraphicEngine(GraphicEngine& graphicEngine);
	void run();
	void runLevelSelection();
	void runLevel(LevelDescription& levelDescription);
	void pauseLevel();
	void resumeLevel();

private:
	void returnToGame();
};

#endif














