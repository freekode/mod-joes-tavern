#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class ModBeerMaster_WorldScript : public WorldScript
{
public:
    ModBeerMaster_WorldScript() : WorldScript("ModBeerMaster_WorldScript") {}

    void OnBeforeConfigLoad(bool /*reload*/) override;

private:
    void InitConfig();
};
