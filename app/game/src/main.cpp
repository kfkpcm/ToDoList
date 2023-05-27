#include "raylib.h"
#define NUM_FRAMES  3 
#define MAX_INPUT_CHARS 28
typedef enum GameScreen { LOGO = 0, TITLE, INFO } GameScreen;
int main(void)
{

    const int screenWidth = 1000;
    const int screenHeight = 650;
    InitWindow(screenWidth, screenHeight, "To-Do List");
    GameScreen currentScreen = LOGO;
    int framesCounter = 0;
    SetTargetFPS(60);
    char name[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount = 0;
    Rectangle textBox = { 10, 100, 600, 50 };
    bool mouseOnText = false;

    while (!WindowShouldClose())
    {

        switch (currentScreen)
        {
        case LOGO:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = TITLE;
                Image icon = LoadImage("Pictures\notes.png");
                SetWindowIcon(icon);
            }
        } break;
        case TITLE:
        {

            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = INFO;
            }
            Image icon = LoadImage("Pictures\notes.png");
            SetWindowIcon(icon);
            if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
            else mouseOnText = false;
            if (mouseOnText)
            {
                SetMouseCursor(MOUSE_CURSOR_IBEAM);
                int key = GetCharPressed();
                while (key > 0)
                {
                    if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                    {
                        name[letterCount] = (char)key;
                        name[letterCount + 1] = '\0';
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

        } break;

        case INFO:
        {

            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = TITLE;
            }
            Image icon = LoadImage("Pictures\notes.png");
            SetWindowIcon(icon);
        } break;
        default: break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentScreen)
        {
        case LOGO:
        {
            Image logo = LoadImage("Pictures\logo.png");

            DrawText("TODO", 430, 50, 40, PURPLE);
            DrawText("The app to finish tasks: quick, easy, productive.", 150, 325, 30, BLACK);
            DrawText("(press enter to continue!!)", 360, 400, 20, LIGHTGRAY);

        } break;
        case TITLE:
        {
            DrawText("Your tasks are the following:", 10, 20, 50, PURPLE);
            DrawRectangleRec(textBox, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)100, (int)600, (int)50, BLACK);
            DrawText(name, (int)10, (int)100, 40, BLACK);
            DrawRectangle(10, 200, 600, 50, LIGHTGRAY);
            DrawRectangleLines((int)10, (int)200, (int)600, (int)50, BLACK);
            DrawText(name, (int)10, (int)200, 40, BLACK);
            DrawRectangle(800, -1, 200, 650, PURPLE);
            DrawRectangle(820, 24, 160, 50, WHITE);
            DrawRectangle(820, 98, 160, 160, WHITE);
            DrawRectangle(820, 282, 160, 160, WHITE);
            DrawRectangle(820, 466, 160, 160, WHITE);
            DrawText("Help:", 850, 30, 40, BLACK);
            DrawText("ADD", 860, 150, 40, BLACK);
            DrawText("DELETE", 830, 350, 35, BLACK);
            DrawText("INFO", 850, 520, 40, BLACK);


        } break;

        case INFO:
        {
            DrawRectangle(0, -1, 200, 650, PURPLE);
            DrawRectangle(25, 50, 150, 150, WHITE);
            DrawRectangle(25, 250, 150, 150, WHITE);
            DrawRectangle(25, 450, 150, 150, WHITE);
            DrawText("ADD", 60, 105, 40, BLACK);
            DrawText("DELETE", 30, 305, 35, BLACK);
            DrawText("INFO", 50, 505, 40, BLACK);
            DrawText("This function adds a", 215, 75, 40, BLACK);
            DrawText("task to your list.", 215, 135, 40, BLACK);
            DrawText("This function deletes a", 215, 275, 40, BLACK);
            DrawText("task from your list.", 215, 335, 40, BLACK);
            DrawText("This function shows", 215, 475, 40, BLACK);
            DrawText("the information menu.", 215, 535, 40, BLACK);
            DrawLine(700, 0, 700, 650, BLACK);
            DrawText("This app is", 715, 60, 40, BLACK);
            DrawText("designed to", 715, 120, 40, BLACK);
            DrawText("help organize", 715, 180, 40, BLACK);
            DrawText("your work.", 715, 240, 40, BLACK);
            DrawText("(press enter to go back)", 715, 600, 20, LIGHTGRAY);

        } break;
        default: break;
        }

        EndDrawing();

    }

    CloseWindow();

    return 0;
    if (IsKeyPressed(KEY_ESCAPE));
    CloseWindow();
}
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;
    return keyPressed;
}


