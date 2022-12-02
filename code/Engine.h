#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"

using namespace sf;

class Engine
{
    public:
        Engine();
        void Run();

    private:
        const int TILE_SIZE = 50;
        const int VERTS_IN_QUAD = 4;
        Vector2f windowSize = {640, 368};


        float m_WindowScale = 0.8f;
        bool m_Playing = false;
        float m_TimeElapsed = 0;

    	Player player;
        Clock clock;

        VertexArray background;
        Texture textureBackground;
        TextureHolder th;        
        RenderWindow m_Window;
        View m_MainView;
        View m_HudView;

	    Time gameTimeTotal;
    	Vector2i mouseScreenPosition;

        Sprite m_BackgroundSprite;
        Texture m_BackgroundTexture;

        void Input();
        void Update(float dtAsSeconds);
        void Draw();
};