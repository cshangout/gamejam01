#pragma once
#include <string>

namespace HE {
    struct WindowData {
        std::string title;
        uint32_t width, height;
    };

    class Window {
    public:
        virtual ~Window() = default;
        virtual void OpenWindow(WindowData data) = 0;
        virtual bool Update() = 0;
        virtual void MakeContextCurrent() = 0;

        virtual std::pair<int, int> GetWindowExtents() = 0;
        virtual void SwapBuffer() = 0;
    };
}