#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <memory>
#include <thread>

#include "core/utils/logger/logger.h"
#include "core/thirdparty/minhook/minhook.h"
#include "core/thirdparty/MonkeGUI.h"
#include "core/bootstrap_cheat.h"

#include "game/hooked/hooked.h"
#include "game/sdk/SDK.hpp"