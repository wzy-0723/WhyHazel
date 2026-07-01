#pragma once
#include <glad/glad.h>
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <fmt/format.h>
#include <stdint.h>
#ifdef HZ_PLATFORM_WINDOWS
#include <windows.h>
#endif


#include "Log.h"
#include "Instrumentor.h"
#include <imgui.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <filesystem>
#include "FileUtil.h"


#include "Base.h"
#include "PlatformDetection.h"

#ifdef HZ_PLATFORM_WINDOWS
#ifndef NOMINMAX
// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
#define NOMINMAX
#endif
#endif