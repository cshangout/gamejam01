#pragma once

#if __EMSCRIPTEN__
    #include <GLES3/gl3.h>
#else
    #define GLAD
    #include <glad/glad.h>
#endif