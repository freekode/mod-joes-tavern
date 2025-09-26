#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class ModBeerMaster_Tourist_ItemScript : public ItemScript
{
public:
    ModBeerMaster_Tourist_ItemScript() : ItemScript("ModBeerMaster_Tourist") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &) override;

private:
    void Teleport(Player *player, GameTele const *tele);
    void AfterTeleport(Player *player);
    GameTele const *GetTeleportLocation();
};
