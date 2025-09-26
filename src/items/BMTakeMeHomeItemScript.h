#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class ModBeerMaster_TakeMeHome_ItemScript : public ItemScript
{
public:
    ModBeerMaster_TakeMeHome_ItemScript() : ItemScript("ModBeerMaster_TakeMeHome") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &) override;
};
