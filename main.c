#include "../../src/raylib.h"

/*
    A program to draw a button in the center of the screen
    the button will be a rectangle with text inside
    the button will change color when the mouse is over it
    when the button is clicked, Screen coolor will change
*/

// A struct to hold the button data
typedef struct Button
{
    Rectangle rect;
    Color color;
} Button;

Button button_0 = {0}; // The button

// bool to check if the button is clicked
bool button_0_clicked = false;

// Function to initialize the button
void init_button(Button *button, Rectangle rect, Color color)
{
    /*
        This function will initialize the button
        button: the button to initialize
        rect: the button rectangle
        color: the button color
    */

    button->rect = rect;
    button->color = color;
}

// Function to check if the mouse is over the button
bool is_mouse_over_button(Button button)
{
    /*
        This function will check if the mouse is over the button
        button: the button to check
    */

    return CheckCollisionPointRec(GetMousePosition(), button.rect);
}

// Local Functions Declaration
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(void); // Update and draw one frame

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib");

    // Initialize the button
    init_button(&button_0, (Rectangle){screenWidth / 2 - 100, screenHeight / 2 - 50, 200, 100}, RED);

    //--------------------------------------------------------------------------------------
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(void)
{
    // Update
    //----------------------------------------------------------------------------------

    // Check if the mouse is over the button
    if (is_mouse_over_button(button_0))
    {
        button_0.color = BLUE;
    }
    else
    {
        button_0.color = RED;
    }

    // Change the screen collor when the button is clicked
    if (is_mouse_over_button(button_0) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        button_0_clicked = true;
    }

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Draw the button
    DrawRectangleRec(button_0.rect, button_0.color);

    // Draw the button text
    DrawText("Click Me", button_0.rect.x + button_0.rect.width / 2 - MeasureText("Click Me", 20) / 2, button_0.rect.y + button_0.rect.height / 2 - 20 / 2, 20, WHITE);

    // Change the screen color when the button is clicked
    if (button_0_clicked)
    {
        ClearBackground(BLACK);
    }

    DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------
}