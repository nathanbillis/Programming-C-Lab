/*
 *	A program to demonstrate simple graphical operations
 */

/*  This line allows the compiler to understand the
 *	graphics functions
 */
 #include <graphics_lib.h>

int main(void)
{
    /* Declare variables for the x and y positions */
    int user_x;
    int user_y;
    int scale;
    int head_pos_x;
    int head_pos_y;
    int top_leg_x;
    int top_leg_y;
    int arm_y;
    int radius;

    GFX_InitWindow(640, 480);
    scale = 50;
    radius = 25;

	/* ask user for start x position and start y position */
	printf("Enter Start x-coordinate:\n");
	scanf("%d", &user_x);
    printf("Enter Start y-coordinate:\n");
	scanf("%d", &user_y);
	printf("%d %d\n", user_x, user_y);

	/*calculate position for top of leg, head and arm */
	top_leg_x = user_x + scale;
	top_leg_y = user_y - scale;
	head_pos_x = top_leg_x;
	head_pos_y = top_leg_y - scale ;
	arm_y = head_pos_y + ((top_leg_y - head_pos_y)*0.5);



	GFX_InitWindow(640, 480);
	GFX_SetColour(RED);

	/* Draw the Stickman */

	GFX_DrawLine(user_x , user_y, top_leg_x, top_leg_y, 5);
	GFX_DrawLine(top_leg_x, top_leg_y, top_leg_x + scale, top_leg_y + scale , 5 );
	GFX_DrawLine(top_leg_x, top_leg_y, head_pos_x, head_pos_y , 5);
	GFX_DrawLine(user_x, arm_y, top_leg_x + scale, arm_y , 5); /* draw Arm */
	GFX_DrawCircle(head_pos_x, head_pos_y - radius, radius , 5);


    /* move the contents of the screen buffer to the display */
    GFX_UpdateDisplay();

	/* Wait for a user's signal to exit*/
	getchar();
	printf("Please press enter");
    getchar();

    /* remove the display */
    GFX_CloseWindow();


    return 0;
}
