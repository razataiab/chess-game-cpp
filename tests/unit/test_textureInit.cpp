#define BOOST_TEST_MODULE TexturesTests

#include <boost/test/included/unit_test.hpp>
#include "textures.h"
#include <SDL2/SDL.h>  // Include SDL2 header for testing purposes

BOOST_AUTO_TEST_CASE(test_texture_init) {
    // Initialize SDL for testing (you might need additional setup)
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Renderer* renderer = nullptr;  // Mock renderer for testing
    Textures textures;
    textures.textureInit(renderer, "path_to_texture.png", 100, 200);

    // Check if texture properties are set correctly
    BOOST_CHECK_EQUAL(textures.textureX, 100);
    BOOST_CHECK_EQUAL(textures.textureY, 200);
    BOOST_CHECK(textures.texture != nullptr);

    // Clean up
    SDL_DestroyTexture(textures.texture);
    SDL_Quit();
}

BOOST_AUTO_TEST_CASE(test_texture_on_window) {
    // Initialize SDL for testing (you might need additional setup)
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Renderer* renderer = nullptr;  // Mock renderer for testing
    Textures textures;
    textures.textureInit(renderer, "path_to_texture.png", 100, 200);

    // Test the rendering of texture on the window
    BOOST_REQUIRE_NO_THROW(textures.textureOnWindow(renderer));

    // Clean up
    SDL_DestroyTexture(textures.texture);
    SDL_Quit();
}
