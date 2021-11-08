#include <hangout_engine/platform/entry_point.h>
#include <hangout_engine/platform/game.h>

class GameJamProject : public HE::Game {
public:
    explicit GameJamProject(std::string title) : HE::Game(std::move(title)) {
        std::cout << "Hello, world!" << std::endl;
    }

protected:
    void Update(float deltaTime) override {
        //std::cout << "Updating!" << std::endl;
    }
};

HE::Game* HE::CreateGame() {
    return new GameJamProject("The best project");
};
