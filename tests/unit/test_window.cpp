#define BOOST_TEST_MODULE WindowAndBoardTests

#include <boost/test/included/unit_test.hpp>
#include "window.h"

BOOST_AUTO_TEST_CASE(test_create_window) {
    Window window;
    window.createWindow();

    // Check if the window and renderer are not null
    BOOST_CHECK(window.window != nullptr);
    BOOST_CHECK(window.renderer != nullptr);

    // Clean up
    SDL_DestroyRenderer(window.renderer);
    SDL_DestroyWindow(window.window);
    SDL_Quit();
}

BOOST_AUTO_TEST_CASE(test_draw_board) {
    Window window;
    window.createWindow();
    window.drawBoard();

    // Simulate rendering and drawing board, can't directly test visual output
    // You can add more specific tests here depending on what you want to verify

    // Clean up
    SDL_DestroyRenderer(window.renderer);
    SDL_DestroyWindow(window.window);
    SDL_Quit();
}
