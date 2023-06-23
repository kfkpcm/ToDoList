#include "raylib.h"
#include <iostream>
#include <cstring>

#define NUM_FRAMES  3
constexpr auto MAX_INPUT_CHARS = 25;

typedef enum GameScreen { LOGO = 0, TITLE, INFO } GameScreen;
int main(void)
{
    // Initialization
    const int screenWidth = 1000;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "To-Do List");
    GameScreen currentScreen = LOGO;

    int framesCounter = 0;
    SetTargetFPS(60); // Set desired framerate (frames-per-second)
    Vector2 mousePoint = { 0.0f, 0.0f };

    //info
    Texture2D button = LoadTexture("../Pictures/info.png");
    float frameHeight = (float)160;
    Rectangle sourceRec = { 785, 98, (float)160, frameHeight };
    Rectangle btnBounds = { 820, 98, (float)button.width, frameHeight };

    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false;         // Button action should be activated
    
    //textbox 1
    std::string name;
    Rectangle textBox = { 10, 100, 600, 50 };
    //textbox 2
    std::string name1;
    Rectangle textBox1 = { 10, 200, 600, 50 };
    //textbox 3
    std::string name2;
    Rectangle textBox2 = { 10, 300, 600, 50 };
    //textbox 4
    std::string name3;
    Rectangle textBox3 = { 10, 400, 600, 50 };
    //textbox 5
    std::string name4;
    Rectangle textBox4 = { 10, 500, 600, 50 };

    bool mouseOnText = false;

    // Load textures
    Texture2D logo = LoadTexture("../Pictures/logo1.png");
    Texture2D checkmark = LoadTexture("../Pictures/white.png");
    Texture2D checkmark1 = LoadTexture("../Pictures/green.png");
    Texture2D star1 = LoadTexture("../Pictures/starw.png");
    Texture2D star2 = LoadTexture("../Pictures/stary.png");
    Texture2D checkbig = LoadTexture("../Pictures/checkbig.png");
    Texture2D starbig = LoadTexture("../Pictures/starybig.png");

    //checkmark 1 + star 
    Rectangle checkw = { 610, 95, 60, 60 };
    Rectangle starw = { 700, 95, 60, 60 };
    int star = 0;
    int check = 0;
    //checkmark 2 + star 
    Rectangle checkw1 = { 610, 195, 60, 60 };
    Rectangle starw1 = { 700, 195, 60, 60 };
    int starc = 0;
    int check1 = 0;
    //checkmark 3 + star 
    Rectangle checkw2 = { 610, 295, 60, 60 };
    Rectangle starw2 = { 700, 295, 60, 60 };
    int starcc = 0;
    int check2 = 0;
    //checkmark 4 + star 
    Rectangle checkw3 = { 610, 395, 60, 60 };
    Rectangle starw3 = { 700, 395, 60, 60 };
    int star3 = 0;
    int check3 = 0;
    //checkmark 5 + star 
    Rectangle checkw4 = { 610, 495, 60, 60 };
    Rectangle starw4 = { 700, 495, 60, 60 };
    int star4 = 0;
    int check4 = 0;

    Image Iicon = LoadImage("../Pictures/checkmark.png");
    Texture Ticon = LoadTextureFromImage(Iicon);
    SetWindowIcon(Iicon);

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
        case LOGO:
        {
            if (IsKeyPressed(KEY_ENTER))
                currentScreen = TITLE;
        } break;
        case TITLE:
        {
            if (IsKeyPressed(KEY_DELETE))
                currentScreen = LOGO;

            //checkmarks
            if (CheckCollisionPointRec(mousePoint, checkw))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    check = 1; 
            if (CheckCollisionPointRec(mousePoint, checkw1))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    check1 = 1;
            if (CheckCollisionPointRec(mousePoint, checkw2))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    check2 = 1;
            if (CheckCollisionPointRec(mousePoint, checkw3))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    check3 = 1;
            if (CheckCollisionPointRec(mousePoint, checkw4))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    check4 = 1;
            //stars
            if (CheckCollisionPointRec(mousePoint, starw))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    star = 1;
            if (CheckCollisionPointRec(mousePoint, starw1))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    starc = 1;
            if (CheckCollisionPointRec(mousePoint, starw2))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    starcc = 1;
            if (CheckCollisionPointRec(mousePoint, starw3))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    star3 = 1;
            if (CheckCollisionPointRec(mousePoint, starw4))
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    star4 = 1;

            //BUTTON 
            // Update
            mousePoint = GetMousePosition();
            btnAction = false;
            // Check button state
            if (CheckCollisionPointRec(mousePoint, btnBounds))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    btnState = 2;
                    currentScreen = INFO;
                }
                else btnState = 1;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
            }
            else btnState = 0;
            // Calculate button frame rectangle to draw depending on button state
            sourceRec.y = btnState * frameHeight;

            //textbox 1
            if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
            else mouseOnText = false;
            if (mouseOnText)
            {
                // Get char pressed (unicode character) on the queue
                int key = GetCharPressed();
                // Check if more characters have been pressed on the same frame
                while (key > 0)
                {
                    // NOTE: Only allow keys in range [32..125]
                    if ((key >= 32) && (key <= 125) )

                        name += static_cast<char>(key);
                    key = GetCharPressed(); // Check next character in the queue
                }
                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    if (!name.empty())
                        name.pop_back();
                }
            }
            else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            if (mouseOnText) framesCounter++;
            else framesCounter = 0;
            //textbox 2
            if (CheckCollisionPointRec(GetMousePosition(), textBox1)) mouseOnText = true;
            else mouseOnText = false;
            if (mouseOnText)
            {
                int key = GetCharPressed();
                while (key > 0)
                {
                    if ((key >= 32) && (key <= 125))
                        name1 += static_cast<char>(key);
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    if (!name1.empty())
                        name1.pop_back();
                }
            }
            else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            if (mouseOnText) framesCounter++;
            else framesCounter = 0;
            //textbox3
            if (CheckCollisionPointRec(GetMousePosition(), textBox2)) mouseOnText = true;
            else mouseOnText = false;
            if (mouseOnText)
            {
                int key = GetCharPressed();
                while (key > 0)
                {
                    if ((key >= 32) && (key <= 125))
                        name2 += static_cast<char>(key);
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    if (!name2.empty())
                        name2.pop_back();
                }
            }
            else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            if (mouseOnText) framesCounter++;
            else framesCounter = 0;
            //textbox4
            if (CheckCollisionPointRec(GetMousePosition(), textBox3)) mouseOnText = true;
            else mouseOnText = false;
            if (mouseOnText)
            {
                int key = GetCharPressed();
                while (key > 0)
                {
                    if ((key >= 32) && (key <= 125))
                        name3 += static_cast<char>(key);
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    if (!name3.empty())
                        name3.pop_back();
                }
            }
            else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            if (mouseOnText) framesCounter++;
            else framesCounter = 0;
            //textbox5
            if (CheckCollisionPointRec(GetMousePosition(), textBox4)) mouseOnText = true;
            else mouseOnText = false;
            if (mouseOnText)
            {
                int key = GetCharPressed();
                while (key > 0)
                {
                    if ((key >= 32) && (key <= 125))
                        name4 += static_cast<char>(key);
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_BACKSPACE) || IsKeyDown(KEY_BACKSPACE))
                {
                    if (!name4.empty())
                        name4.pop_back();
                }
            }
            else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            if (mouseOnText) framesCounter++;
            else framesCounter = 0;
        } break;
        case INFO:
        {
            if (IsKeyPressed(KEY_ENTER))
                currentScreen = TITLE;
        } break;
        default: break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (currentScreen)
        {
        case LOGO:
        {
            DrawTexture(logo, screenWidth / 2 - logo.width / 2, screenHeight / 3 - logo.height / 2, RAYWHITE);
            DrawText("TODO", screenWidth / 2 - logo.width / 2 + 25, 50, 40, PURPLE);
            DrawText("The app to finish tasks: quick, easy, productive.", 150, 380, 30, BLACK);
            DrawText("(press enter to continue!!)", 360, 450, 20, LIGHTGRAY);

        } break;
        case TITLE:
        {
            //textbox 1
            DrawTexture(checkmark, 610, 95, WHITE);
            DrawTexture(star1, 700, 95, WHITE);
            DrawText("Your tasks are the following:", 10, 20, 50, PURPLE);
            DrawRectangleRec(textBox, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)100, (int)600, (int)50, BLACK);
            DrawText(name.c_str(), (int)10, (int)100, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox.x + 8 + MeasureText(name.c_str(), 40), (int)textBox.y + 12, 40, BLACK);
            if (check == 1)
            {
                DrawTexture(checkmark1, 610, 95, WHITE);
                name = "";
                DrawTexture(star1, 700, 95, WHITE);
                star = 0;
            }
            else
            {
                DrawTexture(checkmark, 610, 95, WHITE);
                if (star == 1)
                    DrawTexture(star2, 700, 95, RAYWHITE);
            }
            
            check = 0;
            
            //textbox 2
            DrawTexture(checkmark, 610, 195, WHITE);
            DrawTexture(star1, 700, 195, WHITE);
            DrawRectangleRec(textBox1, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)200, (int)600, (int)50, BLACK);
            DrawText(name1.c_str(), (int)10, (int)200, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox1.x + 8 + MeasureText(name1.c_str(), 40), (int)textBox1.y + 12, 40, BLACK);
            if (check1 == 1)
            {
                DrawTexture(checkmark1, 610, 195, WHITE);
                name1 = "";
                DrawTexture(star1, 700, 195, WHITE);
                starc = 0;
            }
            else
            {
                DrawTexture(checkmark, 610, 195, WHITE);
                if (starc == 1)
                    DrawTexture(star2, 700, 195, RAYWHITE);
            }
            check1 = 0;
            //textbox 3
            DrawTexture(checkmark, 610, 295, WHITE);
            DrawTexture(star1, 700, 295, WHITE);
            DrawRectangleRec(textBox2, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)300, (int)600, (int)50, BLACK);
            DrawText(name2.c_str(), (int)10, (int)300, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox2.x + 8 + MeasureText(name2.c_str(), 40), (int)textBox2.y + 12, 40, BLACK);
            if (check2 == 1)
            {
                DrawTexture(checkmark1, 610, 295, WHITE);
                name2 = "";
                DrawTexture(star1, 700, 295, WHITE);
                starcc = 0;
            }
            else
            {
                DrawTexture(checkmark, 610, 295, WHITE);
                if (starcc == 1)
                    DrawTexture(star2, 700, 295, RAYWHITE);
            }
            check2 = 0;
            //textbox 4
            DrawTexture(checkmark, 610, 395, WHITE);
            DrawTexture(star1, 700, 395, WHITE);
            DrawRectangleRec(textBox3, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)400, (int)600, (int)50, BLACK);
            DrawText(name3.c_str(), (int)10, (int)400, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox3.x + 8 + MeasureText(name3.c_str(), 40), (int)textBox3.y + 12, 40, BLACK);
            if (check3 == 1)
            {
                DrawTexture(checkmark1, 610, 395, WHITE);
                name3 = "";
                DrawTexture(star1, 700, 395, WHITE);
                star3 = 0;
            }
            else
            {
                DrawTexture(checkmark, 610, 395, WHITE);
                if (star3 == 1)
                    DrawTexture(star2, 700, 395, RAYWHITE);
            }
            check3 = 0;
            //textbox 5
            DrawTexture(checkmark, 610, 495, WHITE);
            DrawTexture(star1, 700, 495, WHITE);
            DrawRectangleRec(textBox4, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)500, (int)600, (int)50, BLACK);
            DrawText(name4.c_str(), (int)10, (int)500, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox4.x + 8 + MeasureText(name4.c_str(), 40), (int)textBox4.y + 12, 40, BLACK);
            if (check4 == 1)
            {
                DrawTexture(checkmark1, 610, 495, WHITE);
                name4 = "";
                DrawTexture(star1, 700, 495, WHITE);
                star4 = 0;
            }
            else
            {
                DrawTexture(checkmark, 610, 495, WHITE);
                if (star4 == 1)
                    DrawTexture(star2, 700, 495, RAYWHITE);
            }
            check4 = 0;

            //design
            DrawRectangle(800, -1, 200, 650, PURPLE);
            DrawRectangle(820, 24, 160, 50, WHITE);
            DrawText("Help:", 850, 30, 40, BLACK);
            //button
            DrawTextureRec(button, sourceRec, (Vector2{ btnBounds.x, btnBounds.y }), WHITE);
        } break;

        case INFO:
        {
            //explanation
            DrawRectangle(0, -1, 200, 650, PURPLE);
            DrawRectangle(25, 50, 150, 150, WHITE);
            DrawText("INFO", 50, 105, 40, BLACK);
            DrawText("This function shows", 215, 75, 40, BLACK);
            DrawText("the information menu.", 215, 135, 40, BLACK);

            DrawTexture(checkbig, 25, 250, WHITE);
            DrawTexture(starbig, 25, 450, WHITE);
            DrawText("Finished task.", 215, 300, 40, BLACK);
            DrawText("Important task.", 215, 505, 40, BLACK);

            DrawLine(700, 0, 700, 650, BLACK);
            DrawText("Creators:", 750, 40, 40, BLACK);
            DrawText("Daniel Uzunov", 710, 120, 40, BLACK);
            DrawText("Georgi Dinev", 710, 180, 40, BLACK);
            DrawText("Doriana Petkova", 710, 240, 35, BLACK);
            DrawText("(press enter to go back)", 715, 600, 20, LIGHTGRAY);
        } break;
        default: break;
        }
        EndDrawing();
        
    }
    // De-Initialization
    UnloadTexture(button);
    return 0;
    CloseWindow();
}
// Check if any key is pressed
// NOTE: We limit keys check to keys between 32 (KEY_SPACE) and 126
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();
    if ((key >= 32) && (key <= 126)) keyPressed = true;
    return keyPressed;
}
