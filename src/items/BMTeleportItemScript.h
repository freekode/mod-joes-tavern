#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class ModBeerMaster_Teleport_ItemScript : public ItemScript
{
public:
    ModBeerMaster_Teleport_ItemScript() : ItemScript("ModBeerMaster_Teleport") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &) override;

private:
    void GetDrunk(Player *player, uint8 value);
    void Teleport(Player *player, GameTele const *tele);
    void AfterTeleport(Player *player);
    GameTele const *GetTeleportLocation();
};
