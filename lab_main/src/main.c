/* include  Graphics lib */
 #include <graphics_lib.h>

int main(void)
{
    /* Declare variables for the graphics */
    int user_x;
    int user_y;
    int width;
    int height;
    int scale;
    int radius;
    int can_play;

    /* Body parts */
    int head_pos_x;
    int head_pos_y;
    int top_leg_x;
    int top_leg_y;
    int arm_y;
    int right_hand;

    /* Projectiles */
    double proj_x;
    double proj_y;
    double gravity;
    double time;
    double proj_x_init;
    double proj_y_init;
    double vel_x;
    double vel_y;


    scale = 50;
    radius = 25;
    width = 600;
    height = 300;

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
	right_hand = top_leg_x + scale;


	/* Check to see if it's in the area */
	if (user_x < 0)
	{
        can_play = 0;
        printf("Sorry out of range\n");
	}
	else if (head_pos_y - 2*scale < 0 )
	{
        can_play = 0;
        printf("Sorry out of range\n");
	}
	else if (top_leg_x + scale > width)
	{
        can_play = 0;
        printf("Sorry out of range\n");
	}
	else if (user_y > height)
	{
        can_play = 0;
        printf("Sorry out of range\n");
    }
	else
	{
        can_play = 1;

    }

    /* When usr can play */
	if (can_play == 1)
	{


        GFX_InitWindow(width, height);
        GFX_SetColour(WHITE);

        /* Draw the Stickman */

        GFX_DrawLine(user_x , user_y, top_leg_x, top_leg_y, 5);
        GFX_DrawLine(top_leg_x, top_leg_y, top_leg_x + scale, top_leg_y + scale , 5 );
        GFX_DrawLine(top_leg_x, top_leg_y, head_pos_x, head_pos_y , 5);
        GFX_DrawLine(user_x, arm_y, top_leg_x + scale, arm_y , 5); /* draw Arm */
        GFX_DrawCircle(head_pos_x, head_pos_y - radius, radius , 5); /* draw head */
        GFX_DrawLine(0, user_y, width, user_y, 3);


        /* move the contents of the screen buffer to the display */
        GFX_UpdateDisplay();

        /* Drawing the Projectile */

        /* define the variable */
        proj_x_init = right_hand;
        proj_y_init= arm_y;
        proj_x = proj_x_init + 0.01;
        proj_y = proj_x_init;
        gravity = 9.81;
        vel_x = 30;
        vel_y = 30;

        /* draw the projectile */
        GFX_MoveTo(proj_x_init, proj_y_init);
        while (proj_y < user_y)
        {
        time = (proj_x - proj_x_init)/ vel_x;
        proj_y = proj_y_init - (vel_y * time) +(gravity * time * time)/2;
        GFX_DrawLineTo(proj_x, proj_y, 3);
        proj_x += 1;
        GFX_UpdateDisplay();
        }


        /* Wait for a user's signal to exit*/
        getchar();
        printf("Please press enter");
        getchar();

        /* remove the display */
        GFX_CloseWindow();
    }


    return 0;
}
