#include "Engine.h"
#include "TextureHolder.h"
#include <iomanip>
#include <iostream>
#include <sstream>

void Engine::Draw()
{
    Vector2f textPosition = {0,0};
    stringstream ss;

    //Clear previous frame
    m_Window.clear();
    m_Window.setView(m_MainView);
    m_Window.setView(m_HudView);    
    Vector2f mouseWorldPosition;
    m_Window.setMouseCursorVisible(false);
	Sprite spriteCrosshair;
	Texture textureCrosshair = TextureHolder::GetTexture("graphics/crosshair1.png");
	spriteCrosshair.setTexture(textureCrosshair);
	spriteCrosshair.setOrigin(25, 25);

    switch (state)
    {
    case (State::MAIN_MENU):
        textboxString = "Zombie Shooter V2";
        DrawTextBox(textBox, textboxString, MAIN_MENU_CHAR_SIZE*2, {windowSize.x/2,0}, TextBoxAnchor::TOP_CENTER);

        textboxString = "Press Enter to Start";
        DrawTextBox(textBox, textboxString, MAIN_MENU_CHAR_SIZE, { windowSize.x/2, windowSize.y/2 });

        m_Window.draw(textBox);
        break;
        
    case (State::PLAYING):
        m_Window.draw(background, &textureBackground);
        m_Window.draw(player->GetSprite());
        mouseWorldPosition = m_Window.mapPixelToCoords(Mouse::getPosition(), m_HudView);
        spriteCrosshair.setPosition(mouseWorldPosition);
        m_Window.draw(spriteCrosshair);
        for (size_t i = 0; i < gm->GetZombies().size(); i++)
        {
            m_Window.draw(gm->GetZombies()[i]->GetSprite());
        }

        ss << fixed << setprecision(2) << m_TimeElapsed;
        textboxString = ss.str();
        textPosition = { windowSize.x - ((MAIN_MENU_CHAR_SIZE * textboxString.length())/2), 0};
        DrawTextBox(textBox, textboxString, MAIN_MENU_CHAR_SIZE, textPosition, TextBoxAnchor::TOP_LEFT);
        break;
        
    case (State::PAUSED):
        break;
        
    case (State::GAME_OVER):
        break;
    }
        
	m_Window.display();
}

void Engine::DrawTextBox(Text& _textbox, std::string _text, int _fontSize, Vector2f _textPosition, TextBoxAnchor originPoint)
{
    _textbox.setCharacterSize(_fontSize);
    _textbox.setString(_text);

    switch (originPoint)
    {
    case (TextBoxAnchor::TOP_LEFT):
        _textbox.setOrigin(0,0);
        break;
    case (TextBoxAnchor::TOP_CENTER):
        _textbox.setOrigin(_textbox.getGlobalBounds().width/2, 0);
        break;
    case (TextBoxAnchor::TOP_RIGHT):
        _textbox.setOrigin(_textbox.getGlobalBounds().width, 0);
        break;
    case (TextBoxAnchor::MIDDLE_LEFT):
        _textbox.setOrigin(0, _textbox.getGlobalBounds().height/2);
        break;
    case (TextBoxAnchor::CENTER):
        _textbox.setOrigin(_textbox.getGlobalBounds().width/2, _textbox.getGlobalBounds().height/2);
        break;
    case (TextBoxAnchor::MIDDLE_RIGHT):
        _textbox.setOrigin(_textbox.getGlobalBounds().width, _textbox.getGlobalBounds().height/2);
        break;
    case (TextBoxAnchor::BOTTOM_LEFT):
        _textbox.setOrigin(0, _textbox.getGlobalBounds().height);
        break;
    case (TextBoxAnchor::BOTTOM_CENTER):
        _textbox.setOrigin(_textbox.getGlobalBounds().width/2, _textbox.getGlobalBounds().height);
        break;
    case (TextBoxAnchor::BOTTOM_RIGHT):
        _textbox.setOrigin(_textbox.getGlobalBounds().width, _textbox.getGlobalBounds().height);
        break;
    }
    _textbox.setPosition(_textPosition.x, _textPosition.y);
    m_Window.draw(_textbox);
}