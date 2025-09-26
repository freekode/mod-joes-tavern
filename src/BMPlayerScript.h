#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class ModBeerMaster_PlayerScript : public PlayerScript
{

public:
    ModBeerMaster_PlayerScript() : PlayerScript("ModBeerMaster_PlayerScript") {}

    void OnPlayerLogin(Player *player) override;
};
