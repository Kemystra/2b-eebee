#include "hideBot.h"


void HideBot::hide() {
    // Check if the bot can still hide
    if (hideAmount > 0) {
        // Hide the bot by setting isHidden to true, this will be checked every single time the bot is attacked
        isVisible = false;
        hideAmount--; // Decrease the hide amount
        selfLog("Hidden.");
    }
}