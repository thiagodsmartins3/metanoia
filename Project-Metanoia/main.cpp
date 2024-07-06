#include "window.hpp"
#include "exceptions.hpp"
#include <iostream>
#include "spriter.hpp"

int main()
{
    Window win;
    Spriter* spriter = new Spriter();

    try {
        spriter->loadTexture("", sf::IntRect(10, 10, 128, 128));
    }
    catch (Exceptions exc) {
        std::cout << exc.what();
        return 1;
    }
    

    win.run(
        [&spriter]() -> Spriter* {
            return spriter;
        }
    );

    delete spriter;

    return 0;
}