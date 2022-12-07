#include "Engine.h"
#include <iomanip>
#include <iostream>
#include <sstream>

void Engine::Draw()
{
    //Clear previous frame
    m_Window.clear();
    m_Window.setView(m_MainView);
    m_Window.setView(m_HudView);    
    Vector2f mouseWorldPosition;


    switch (state)
    {
    case (State::MAIN_MENU):
        RenderMainMenu();
        break;
        
    case (State::PLAYING):
        RenderGameScene();
        break;
        
    case (State::PAUSED):
        break;
        
    case (State::GAME_OVER):
        RenderGameOverScene();
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

void Engine::RenderMainMenu()
{
    textboxString = "Zombie Shooter V2";
    DrawTextBox(textbox, textboxString, MAIN_MENU_CHAR_SIZE*2, {windowSize.x/2,0}, TextBoxAnchor::TOP_CENTER);

    textboxString = "Press Enter to Start";
    DrawTextBox(textbox, textboxString, MAIN_MENU_CHAR_SIZE, { windowSize.x/2, windowSize.y/2 });

    m_Window.draw(textbox);
}

void Engine::RenderGameScene()
{
    stringstream ss;
    Vector2f textPosition = {0,0};
    textbox.setFillColor(Color::White);

    m_Window.setMouseCursorVisible(false);
    m_Window.draw(background, &textureBackground);
    m_Window.draw(player->GetSprite());
    m_Window.draw(weapon.GetSprite());

    vector<Zombie*> tempZombies = gm->GetZombies();
    for (size_t i = 0; i < tempZombies.size(); i++)
    {
        m_Window.draw(tempZombies[i]->GetSprite());
    }

    for (size_t i = 0; i < gm->GetBullets().size(); i++)
    {
        m_Window.draw(gm->GetBullets()[i]->GetSprite());
    }

    spriteCrosshair.setPosition(mouseScreenPosition);
    m_Window.draw(spriteCrosshair);

    ss << fixed << setprecision(2) << m_TimeElapsed;
    textboxString = ss.str();
    textPosition = { windowSize.x - ((MAIN_MENU_CHAR_SIZE * textboxString.length())/2), 0};
    textbox.setFillColor(Color::White);
    DrawTextBox(textbox, textboxString, MAIN_MENU_CHAR_SIZE, textPosition, TextBoxAnchor::TOP_LEFT);

    textboxString = "Health: " + to_string(player->GetHealth());
    textPosition = {0,0};
    textbox.setFillColor(Color::Red);
    DrawTextBox(textbox, textboxString, MAIN_MENU_CHAR_SIZE, textPosition, TextBoxAnchor::TOP_LEFT);

    textboxString = "Score: " + to_string(gm->GetScore());
    textPosition = {0, windowSize.y * 0.98f};
    textbox.setFillColor(Color::White);
    DrawTextBox(textbox, textboxString, MAIN_MENU_CHAR_SIZE, textPosition, TextBoxAnchor::BOTTOM_LEFT);
}

void Engine::RenderGameOverScene()
{
    Vector2f textPosition = {0,0};
    stringstream ss;
    ss.str("");

    textboxString = "Game Over";
    textPosition = {windowSize.x/2, windowSize.y/2};
    textbox.setFillColor(Color::Red);
    DrawTextBox(textbox, textboxString, MAIN_MENU_CHAR_SIZE, {textPosition.x, textPosition.y - textPosition.y/2}, TextBoxAnchor::CENTER);

    ss << "Your score: " << gm->GetScore() << " points.";
    textbox.setFillColor(Color::White);
    DrawTextBox(textbox, ss.str(), MAIN_MENU_CHAR_SIZE/2, textPosition, TextBoxAnchor::CENTER);

    ss.str("");
    ss << "You survived for: " << fixed << setprecision(2) << m_TimeElapsed << " seconds.";
    textbox.setFillColor(Color::White);
    DrawTextBox(textbox, ss.str(), MAIN_MENU_CHAR_SIZE/2, {textPosition.x, textPosition.y + textPosition.y/2}, TextBoxAnchor::CENTER);
}