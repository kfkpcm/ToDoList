#include "raylib.h"
#define NUM_FRAMES  3 

int main(void)
{
    InitWindow(800, 450, "To-Do List");
    const int screenWidth = 800;
    const int screenHeight = 450;
    Texture2D button = LoadTexture("Pictures/button.png");
    float frameHeight = (float)button.height / NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)button.width, frameHeight };
    Rectangle btnBounds = { screenWidth/2.0f - button.width/2.0f, screenHeight/2.0f - button.height/NUM_FRAMES/2.0f, (float)button.width, frameHeight };
    int btnState = 0;
    bool btnAction = false;
    Vector2 mousePoint = { 0.0f, 0.0f };
    SetTargetFPS(60);
 
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Here's your To-Do List!", 190, 200, 20, BLACK);
        ClearBackground(RAYWHITE);
        DrawTextureRec(button, sourceRec, Vector2{ 190, 200 }, RED);
        EndDrawing();
        mousePoint = GetMousePosition();
        btnAction = false;
        if (CheckCollisionPointRec(mousePoint, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        sourceRec.y = btnState * frameHeight;
        
        UnloadTexture(button);

 
    }

    CloseWindow();

    return 0;
}