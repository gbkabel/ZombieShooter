#pragma once

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"
#include "Zombie.h"
#include "GameManager.h"
#include "Weapon.h"
#include <vector>

using namespace std;
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

    Font m_UiFont;
    Font m_TitleFont;
        
    Text textbox;
    const int MAIN_MENU_CHAR_SIZE = 32;

    enum class TextBoxAnchor { TOP_LEFT, TOP_CENTER, TOP_RIGHT, MIDDLE_LEFT, CENTER, MIDDLE_RIGHT, BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT };
	enum class State { MAIN_MENU, PAUSED, GAME_OVER, PLAYING };
	State state = State::MAIN_MENU;

    float m_WindowScale = 0.8f;
    float m_TimeElapsed;

    Player* player;
    GameManager* gm;

    Clock clock;

    VertexArray background;
    Texture textureBackground;
    TextureHolder th;        
    RenderWindow m_Window;
    View m_MainView;
    View m_HudView;

	Time m_TotalGameTime;
    Vector2f mouseScreenPosition;

    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;

	Sprite spriteCrosshair;
    Texture textureCrosshair;

    string textboxString = "Debug";
    Weapon weapon;

    void Input();
    void Update(float dt);
    void Draw();

    void DrawTextBox(Text& _textbox, string _text, int _fontSize, Vector2f _textPosition, TextBoxAnchor originPoint = TextBoxAnchor::CENTER);
    void RenderMainMenu();
    void RenderGameScene();
    void RenderGameOverScene();
};