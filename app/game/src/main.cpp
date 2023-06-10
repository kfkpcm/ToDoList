#include "raylib.h"
#include <stdlib.h>  
#include <iostream>
#include <sstream>

#define NUM_FRAMES  3 
#define MAX_INPUT_CHARS 25

typedef enum GameScreen { LOGO = 0, TITLE, INFO } GameScreen;
int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "To-Do List");
    GameScreen currentScreen = LOGO;

    
    int framesCounter = 0;
    SetTargetFPS(60);
    Vector2 mousePoint = { 0.0f, 0.0f };

    //info
    Texture2D button = LoadTexture("../Pictures/info.png");
    float frameHeight = (float)160;
    Rectangle sourceRec = { 785, 98, (float)160, frameHeight };
    Rectangle btnBounds = { 820, 98, (float)button.width, frameHeight };

    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false;         // Button action should be activated

    //textbox 1
    char name[MAX_INPUT_CHARS +1 ] = "\0";
    int letterCount = 0;
    Rectangle textBox = { 10, 100, 600, 50 };
    //textbox 2
    char name1[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount1 = 0;
    Rectangle textBox1 = { 10, 200, 600, 50 };
    //textbox 3
    char name2[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount2 = 0;
    Rectangle textBox2 = { 10, 300, 600, 50 };
    //textbox 4
    char name3[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount3 = 0;
    Rectangle textBox3 = { 10, 400, 600, 50 };
    //textbox 5
    char name4[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount4 = 0;
    Rectangle textBox4 = { 10, 500, 600, 50 };

    bool mouseOnText = false;

    // Load textures
    Texture2D logo = LoadTexture("../Pictures/logo1.png");
    
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
            {
                currentScreen = TITLE;
            }
        } break;
        case TITLE:
        {
            
            //BUTTONS 
            mousePoint = GetMousePosition();
            btnAction = false;
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
            sourceRec.y = btnState * frameHeight;


            //textbox 1
            if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
            else mouseOnText = false;
            if (mouseOnText)
            {
                
                int key = GetCharPressed();
                while (key > 0)
                {
                    if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                    {
                        name[letterCount] = (char)key;
                        name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                        letterCount++;
                    }
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    letterCount--;
                    if (letterCount < 0) letterCount = 0;
                    name[letterCount] = '\0';
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
                    if ((key >= 32) && (key <= 125) && (letterCount1 < MAX_INPUT_CHARS))
                    {
                        name1[letterCount1] = (char)key;
                        name1[letterCount1 + 1] = '\0'; // Add null terminator at the end of the string.
                        letterCount1++;
                    }
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    letterCount1--;
                    if (letterCount1 < 0) letterCount1 = 0;
                    name1[letterCount1] = '\0';
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
                    if ((key >= 32) && (key <= 125) && (letterCount2 < MAX_INPUT_CHARS))
                    {
                        name2[letterCount2] = (char)key;
                        name2[letterCount2 + 1] = '\0'; // Add null terminator at the end of the string.
                        letterCount2++;
                    }
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    letterCount2--;
                    if (letterCount2 < 0) letterCount2 = 0;
                    name2[letterCount2] = '\0';
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
                    if ((key >= 32) && (key <= 125) && (letterCount3 < MAX_INPUT_CHARS))
                    {
                        name3[letterCount3] = (char)key;
                        name3[letterCount3 + 1] = '\0'; // Add null terminator at the end of the string.
                        letterCount3++;
                    }
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    letterCount3--;
                    if (letterCount3 < 0) letterCount3 = 0;
                    name3[letterCount3] = '\0';
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
                    if ((key >= 32) && (key <= 125) && (letterCount4 < MAX_INPUT_CHARS))
                    {
                        name4[letterCount4] = (char)key;
                        name4[letterCount4 + 1] = '\0'; // Add null terminator at the end of the string.
                        letterCount4++;
                    }
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_BACKSPACE) || IsKeyDown(KEY_BACKSPACE))
                {
                    letterCount4--;
                    if (letterCount4 < 0) letterCount4 = 0;
                    name4[letterCount4] = '\0';
                }
            }
            else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            if (mouseOnText) framesCounter++;
            else framesCounter = 0;
        } break;

        case INFO:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = TITLE;
            }
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
            DrawText("Your tasks are the following:", 10, 20, 50, PURPLE);
            DrawRectangleRec(textBox, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)100, (int)600, (int)50, BLACK);
            DrawText(name, (int)10, (int)100, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, BLACK);
            //textbox 2
            DrawRectangleRec(textBox1, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)200, (int)600, (int)50, BLACK);
            DrawText(name1, (int)10, (int)200, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox1.x + 8 + MeasureText(name1, 40), (int)textBox1.y + 12, 40, BLACK);
            //textbox 3
            DrawRectangleRec(textBox2, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)300, (int)600, (int)50, BLACK);
            DrawText(name2, (int)10, (int)300, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox2.x + 8 + MeasureText(name2, 40), (int)textBox2.y + 12, 40, BLACK);
            //textbox 4
            DrawRectangleRec(textBox3, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)400, (int)600, (int)50, BLACK);
            DrawText(name3, (int)10, (int)400, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox3.x + 8 + MeasureText(name3, 40), (int)textBox3.y + 12, 40, BLACK);
            //textbox 5
            DrawRectangleRec(textBox4, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)500, (int)600, (int)50, BLACK);
            DrawText(name4, (int)10, (int)500, 40, BLACK);
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox4.x + 8 + MeasureText(name4, 40), (int)textBox4.y + 12, 40, BLACK);

            

            //random
            DrawRectangle(800, -1, 200, 650, PURPLE);
            DrawRectangle(820, 24, 160, 50, WHITE);
            DrawText("Help:", 850, 30, 40, BLACK);
            //button
            DrawTextureRec(button, sourceRec, (Vector2{ btnBounds.x, btnBounds.y }), WHITE);
        } break;

        case INFO:
        {
            DrawRectangle(0, -1, 200, 650, PURPLE);
            DrawRectangle(25, 50, 150, 150, WHITE); 
            DrawText("INFO", 50, 105, 40, BLACK);
            DrawText("This function shows", 215, 75, 40, BLACK);
            DrawText("the information menu.", 215, 135, 40, BLACK);
            
            DrawLine(200, 250, 700, 250, BLACK);

            DrawText("This app is designed ", 215, 300, 40, BLACK);
            DrawText("to help organize ", 215, 380, 40, BLACK);
            DrawText("your work. Using c++", 215, 460, 40, BLACK);
            DrawText("we created TODO.", 215, 540, 40, BLACK);
            
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
    UnloadTexture(button);
    
    return 0;
    CloseWindow();
}
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();
    if ((key >= 32) && (key <= 126)) keyPressed = true;
    return keyPressed;
}

