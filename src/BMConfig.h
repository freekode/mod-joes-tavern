#include "Player.h"

extern bool modBmEnabled;
extern bool modBmAnnounce;

template <class F>
void BMSchedule(Player *player, std::chrono::milliseconds delay, F &&func)
{
    player->m_Events.AddEventAtOffset(std::forward<F>(func), delay);
};
