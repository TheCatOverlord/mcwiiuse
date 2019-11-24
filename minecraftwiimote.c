#include <wiiuse.h>
#include <stdio.h>
#include <unistd.h>
#include <xdo.h>

#define MAX_WIIMOTES 1

int mousesensivity = 15;

/* wasd is mapped to the arrow pad
   A left mouse click
   B right mouse click
   minus is e
   1 and 2 is scroll up and down
   z is space
   c is shift*/

//handler for general events
void handle_event(struct wiimote_t* wm, const xdo_t * xdoSession)
{
    printf("\n--General event--\n");

    //handling pressing buttons
    if (IS_PRESSED(wm, WIIMOTE_BUTTON_A)) //if button A is pressed
    {
        printf("A button is pressed.\n");
        xdo_mouse_down(xdoSession,CURRENTWINDOW,1);
    }
    if (IS_PRESSED(wm, WIIMOTE_BUTTON_B)) //if button B is press
    {
        printf("B button is pressed.\n");
        xdo_mouse_down(xdoSession,CURRENTWINDOW,3);
    }
    if (IS_PRESSED(wm,WIIMOTE_BUTTON_HOME)) //if the home button is pressed
    {
        printf("Home button is pressed.\n");
        xdo_send_keysequence_window_down(xdoSession,CURRENTWINDOW,"e",1000);
    }
    if (IS_PRESSED(wm,WIIMOTE_BUTTON_UP)) //if the up button is pressed
    {
        printf("Up button is pressed.\n");
        xdo_send_keysequence_window_down(xdoSession, CURRENTWINDOW, "w",1000); //press down the W key
    }
    if (IS_PRESSED(wm,WIIMOTE_BUTTON_RIGHT)) //if the right button is pressed
    {
        printf("Right button is pressed.\n");
        xdo_send_keysequence_window_down(xdoSession, CURRENTWINDOW, "d",1000); //press down the D key
    }
    if (IS_PRESSED(wm,WIIMOTE_BUTTON_LEFT)) //if the left button is pressed
    {
        printf("Left button is pressed.\n");
        xdo_send_keysequence_window_down(xdoSession, CURRENTWINDOW, "a",1000); //press down the A key
    }
    if (IS_PRESSED(wm,WIIMOTE_BUTTON_DOWN)) //if the down button is pressed
    {
        printf("Down button is pressed.\n");
        xdo_send_keysequence_window_down(xdoSession, CURRENTWINDOW, "s",1000); //press down the S key
    }
    if (IS_PRESSED(wm,WIIMOTE_BUTTON_MINUS)) //if minus button is pushed
    {
        printf("Minus button is pressed.\n");
        mousesensivity--;
    }
    if (IS_PRESSED(wm, WIIMOTE_BUTTON_PLUS)) //if the plus button is pushed
    {
        printf("Plus button is pressed.\n");
        mousesensivity++;
    }
    if (IS_PRESSED(wm, WIIMOTE_BUTTON_ONE)) //if the one button is pushed
    {
        printf("One button is pressed.\n");
        xdo_mouse_down(xdoSession,CURRENTWINDOW,4);
    }
    if (IS_PRESSED(wm, WIIMOTE_BUTTON_TWO)) //if the two button is pushed
    {
        printf("Two button is pressed.\n");
        xdo_mouse_down(xdoSession,CURRENTWINDOW,5);
    }

    //handle releasing buttons
    if (IS_RELEASED(wm, WIIMOTE_BUTTON_A)) //if the A button is released
    {
        printf("A button is released.\n");
        xdo_mouse_up(xdoSession,CURRENTWINDOW,1);
    }
    if (IS_RELEASED(wm, WIIMOTE_BUTTON_B)) //if the B button is released
    {
        printf("B button is released.\n");
        xdo_mouse_up(xdoSession,CURRENTWINDOW,3);
    }
    if (IS_RELEASED(wm,WIIMOTE_BUTTON_HOME)) //if the home button is released
    {
        printf("Home button is released.\n");
        xdo_send_keysequence_window_up(xdoSession,CURRENTWINDOW,"e",1000);
    }
    if (IS_RELEASED(wm,WIIMOTE_BUTTON_UP)) //if the up button is released
    {
        printf("Up button is released.\n");
        xdo_send_keysequence_window_up(xdoSession,CURRENTWINDOW,"w",1000); //release the W key
    }
    if (IS_RELEASED(wm,WIIMOTE_BUTTON_RIGHT)) //if the right button is released
    {
        printf("Right button is released.\n");
        xdo_send_keysequence_window_up(xdoSession,CURRENTWINDOW,"d",1000); //release the D key
    }
    if (IS_RELEASED(wm,WIIMOTE_BUTTON_LEFT)) //if the left button is released
    {
        printf("Left button is released.\n");
        xdo_send_keysequence_window_up(xdoSession,CURRENTWINDOW,"a",1000); //release the A key
    }
    if (IS_RELEASED(wm,WIIMOTE_BUTTON_DOWN)) //if the down button is released
    {
        printf("Down button is released.\n");
        xdo_send_keysequence_window_up(xdoSession,CURRENTWINDOW,"s",1000); //release the S key
    }
    if (IS_RELEASED(wm,WIIMOTE_BUTTON_MINUS)) //if the minus button is released
    {
        printf("Minus button is released.\n");
        
    }
    if (IS_RELEASED(wm, WIIMOTE_BUTTON_PLUS)) //if the plus button is released
    {
        printf("Plus button is released.\n");
    }
    if (IS_RELEASED(wm, WIIMOTE_BUTTON_ONE)) //if the one button is released
    {
        printf("One button is released.\n");
        xdo_mouse_up(xdoSession,CURRENTWINDOW,4);
    }
    if (IS_RELEASED(wm, WIIMOTE_BUTTON_TWO)) //if the two button is released
    {
        printf("Two button is released.\n");
        xdo_mouse_up(xdoSession,CURRENTWINDOW,5);
    }


    //Handle nunchuk events
    if (wm->exp.type == EXP_NUNCHUK || wm->exp.type == EXP_MOTION_PLUS_NUNCHUK) //if a nunchuk is connected
    {
		/* nunchuk */
		struct nunchuk_t* nc = (nunchuk_t*)&wm->exp.nunchuk; //make a struct for the nunchuk data

		if (IS_PRESSED(nc, NUNCHUK_BUTTON_C)) { //if the c button is pressed
			printf("Nunchuk: C pressed\n");
            xdo_send_keysequence_window_down(xdoSession,CURRENTWINDOW,"shift",1000); //press the shift key
		}
		if (IS_PRESSED(nc, NUNCHUK_BUTTON_Z)) { //if the z button is pressed
 			printf("Nunchuk: Z pressed\n");
            xdo_send_keysequence_window_down(xdoSession,CURRENTWINDOW,"space",1000); //press the space key
		}
        if (IS_RELEASED(nc, NUNCHUK_BUTTON_C)) //if the c button is released
        {
            xdo_send_keysequence_window_up(xdoSession,CURRENTWINDOW,"shift",1000); //release the shift key
        }
        if (IS_RELEASED(nc, NUNCHUK_BUTTON_Z))
        {
            xdo_send_keysequence_window_up(xdoSession,CURRENTWINDOW,"space",1000); //release the space key
        }

        //print stuff about the nunchuk
		printf("nunchuk joystick angle:     %f\n", nc->js.ang);
		printf("nunchuk joystick magnitude: %f\n", nc->js.mag);

        //mouse logic
        if (nc->js.mag > 0.2) //if the magnitude is greater than .2 (software defined deadzone)
        {
            int moveX = nc->js.x * 10;
            int moveY = nc->js.y * -10;

            xdo_move_mouse_relative(xdoSession, moveX, moveY);

            //int distance = (nc->js.mag -.2) * mousesensivity;
            //float angle = nc->js.ang;
            // if (angle > 337.5 || angle < 22.5)
            // {
            //     //left
            //     xdo_move_mouse_relative(xdoSession,(distance * -1), 0);
            // }
            // if (angle > 292.5 && angle < 337.5)
            // {
            //     //leftup
            //     xdo_move_mouse_relative(xdoSession,(distance * -1), (distance * -1));

            // }
            // if (angle > 247.5 && angle < 337.5)
            // {
            //     //up
            //     xdo_move_mouse_relative(xdoSession,0, (distance * -1));
            // }
            // if (angle > 202.5 && angle < 247.5)
            // {
            //     //right up
            //     xdo_move_mouse_relative(xdoSession,distance, (distance * -1));
            // }
            // if (angle > 157.5 && angle < 202.5)
            // {
            //     //right
            //     xdo_move_mouse_relative(xdoSession,distance, 0);
            // }
            // if (angle > 112.5 && angle < 157.5)
            // {
            //     //rightdown
            //     xdo_move_mouse_relative(xdoSession,distance, distance);
            // }
            // if (angle > 67.5 && angle < 112.5)
            // {
            //     //down
            //     xdo_move_mouse_relative(xdoSession,0, distance);
            // }
            // if (angle > 22.5 && angle < 67.5)
            // {
            //     //leftdown
            //     xdo_move_mouse_relative(xdoSession,(distance * -1), distance);
            // }
        }
    }
}

//handle controller status
void handle_ctrl_status(struct wiimote_t* wm)
{
	printf("\n\n--- CONTROLLER STATUS [wiimote id %i] ---\n", wm->unid);

	printf("attachment:      %i\n", wm->exp.type);
	printf("speaker:         %i\n", WIIUSE_USING_SPEAKER(wm));
	printf("ir:              %i\n", WIIUSE_USING_IR(wm));
	printf("leds:            %i %i %i %i\n", WIIUSE_IS_LED_SET(wm, 1), WIIUSE_IS_LED_SET(wm, 2), WIIUSE_IS_LED_SET(wm, 3), WIIUSE_IS_LED_SET(wm, 4));
	printf("battery:         %f %%\n", wm->battery_level);
}

//handle disconnect if the power off button is pressed
void handle_disconnect(wiimote* wm)
{
    printf("\n\n--- DISCONNECTED [wiimote id %i] ---\n", wm->unid);
}

//check if a wiimote is connected
short any_wiimote_connected(wiimote** wm, int wiimotes)
{
	int i;
	if (!wm) {
		return 0;
	}

	for (i = 0; i < wiimotes; i++) {
		if (wm[i] && WIIMOTE_IS_CONNECTED(wm[i])) {
			return 1;
		}
	}

	return 0;
}

//main function
int main()
{
    //declare varibles
    wiimote** wiimotes; //wiimotes array
    int found, connected; //how many wiimotes found and connected

    xdo_t * xdoSession = xdo_new(NULL); //init xdo and save it in a struct

    //init the wiimotes array
    wiimotes = wiiuse_init(MAX_WIIMOTES);
    //find some wiimotes in the area
    found = wiiuse_find(wiimotes,MAX_WIIMOTES,5);
    if (!found)
    {
        printf("[Error] No wiimotes found\n");
        return 0;
    }

    //connect to the wiimotes
    connected = wiiuse_connect(wiimotes, MAX_WIIMOTES);
    if (connected)
    {
        printf("[Info] Connected to %i wiimotes (of %i found).\n",connected,found);
    }
    else 
    {
        printf("[Error] Failed to connect to any wiimote.\n");
        return 0;
    }
    
    //set the wiimotes leds
    wiiuse_set_leds(wiimotes[0],WIIMOTE_LED_1);

    //rumble to know its connected
    wiiuse_rumble(wiimotes[0],1);
    usleep(500000);
    wiiuse_rumble(wiimotes[0],0);

    //while any wiimotes are connected
    while (any_wiimote_connected(wiimotes, MAX_WIIMOTES))
    {
        if(wiiuse_poll(wiimotes,MAX_WIIMOTES)) //check if an event happened
        {
            int i = 0;
            for (; i < MAX_WIIMOTES; i++) //for all wiimotes in the array 
            {
                switch (wiimotes[i]->event) //switch for events
                {
                    case WIIUSE_EVENT: //if a normal event
                        handle_event(wiimotes[i],xdoSession); //handle it
                        break;

                    case WIIUSE_STATUS: //if calling status
                        handle_ctrl_status(wiimotes[i]); //handle it
                        break;

                    case WIIUSE_DISCONNECT: //if disconnect
                    case WIIUSE_UNEXPECTED_DISCONNECT: //if unexpected disconnect
                        handle_disconnect(wiimotes[i]); //handles that too
                        break;

                    case WIIUSE_NUNCHUK_INSERTED: //if a nunchuk is added
                        printf("Nunchunk has been added.\n");
                        break;

                    case WIIUSE_CLASSIC_CTRL_INSERTED: //if a classic controller is added
                        printf("Classes controller has been added.\n");
                        break;

                    case WIIUSE_WII_BOARD_CTRL_INSERTED: //if a wii balence board is added
                        printf("Balence board controller has been added.\n");
                        break;
                    
                    case WIIUSE_MOTION_PLUS_ACTIVATED: //if motion plus is added/activated
                        printf("Motion+ has been activated.\n");
                        break;

                    //in the case that anything is removed
                    case WIIUSE_NUNCHUK_REMOVED:
					case WIIUSE_CLASSIC_CTRL_REMOVED:
					case WIIUSE_WII_BOARD_CTRL_REMOVED:
                    case WIIUSE_MOTION_PLUS_REMOVED:
                        handle_ctrl_status(wiimotes[i]);
                        printf("An expansion has been removed.\n");
                        break;

                    default:
                        break;
                }
            }
        }
    }

    //cleanup the mess and exit
    wiiuse_cleanup(wiimotes, MAX_WIIMOTES);
    xdo_free(xdoSession);
    return 0;    
}
