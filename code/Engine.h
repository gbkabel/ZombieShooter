#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Engine
{
    public:
        Engine();
        void Run();

    private:
        const int TILE_SIZE = 50;
        const int VERTS_IN_QUAD = 4;

        float m_WindowScale = 0.8f;
        bool m_Playing = false;
        float m_TimeElapsed = 0;

        TextureHolder th;        
        RenderWindow m_Window;
        View m_MainView;
        View m_HudView;

        Sprite m_BackgroundSprite;
        Texture m_BackgroundTexture;

        void Input();
        void Update(float dtAsSeconds);
        void Draw();
};