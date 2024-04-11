#include "cheats.hpp"

namespace CTRPluginFramework {
    u32 Test1Color = 0xFF0000FF;
    u32 Test2Color = 0xFF0000FF;
    u32 Test3Color = 0xFF0000FF;
    bool Test1, Test2, Test3;

    int cursorx = 30;
    int cursory = 30;

    bool DrawTouchMenu( const Screen &scr ) {
        if(scr.IsTop) {
            scr.DrawRect(0, 0, 100, 110, Color::Black);
            scr.DrawRect(0, 0, 100, 110, Color::White, false);

            scr.DrawRect(5, 17, 5, 5, Color(Test1Color));
            scr.DrawRect(5, 27, 5, 5, Color(Test2Color));
            scr.DrawRect(5, 37, 5, 5, Color(Test3Color));
            scr.Draw("TouchMenu", 5, 5, Color::White);
            scr.Draw("Test1", 10, 15, Color::White);
            scr.Draw("Test2", 10, 25, Color::White);
            scr.Draw("Test3", 10, 35, Color::White);

            scr.DrawRect(cursorx, cursory, 3, 3, Color::Cyan);
        }
        return true;
    }

    void TouchMenu( void ) {
        bool menucheck;

        if(menucheck == false) {
            if(Controller::IsKeysPressed(L + DPadRight)) {
                OSD::Run(DrawTouchMenu);
                menucheck = true;
            }
        }
        if(menucheck == true) {
            if(Controller::IsKeysPressed(R + DPadLeft)) {
                OSD::Stop(DrawTouchMenu);
                menucheck = false;
            }

            if(Controller::IsKeyDown(CPadLeft)) {
                cursorx -= 1;
            }
            if(Controller::IsKeyDown(CPadRight)) {
                cursorx += 1;
            }
            if(Controller::IsKeyDown(CPadUp)) {
                cursory -= 1;
            }
            if(Controller::IsKeyDown(CPadDown)) {
                cursory += 1;
            }
            
            if(Controller::IsKeyPressed(A)) {
                if(cursorx >= 5 && cursorx <= 9 && cursory >= 17 && cursory <= 21) {
                    if(Test1 == false) {
                        OSD::Notify("Test1: Enabled", Color::Green);
                        Test1Color = 0x00FF00FF;
                        Test1 = true;
                    } 
                    else if(Test1 == true) {
                        OSD::Notify("Test1: Disabled", Color::Red);
                        Test1Color = 0xFF0000FF;
                        Test1 = false;
                    }
                }
                else if(cursorx >= 5 && cursorx <= 9 && cursory >= 27 && cursory <= 31) {
                    if(Test2 == false) {
                        OSD::Notify("Test2: Enabled", Color::Green);
                        Test2Color = 0x00FF00FF;
                        Test2 = true;
                    }
                    else if(Test2 == true) {
                        OSD::Notify("Test2: Disabled", Color::Red);
                        Test2Color = 0xFF0000FF;
                        Test2 = false;
                    }
                }
                else if(cursorx >= 5 && cursorx <= 9 && cursory >= 37 && cursory <= 41) {
                    if(Test3 == false) {
                        OSD::Notify("Test3: Enabled", Color::Green);
                        Test3Color = 0x00FF00FF;
                        Test3 = true;
                    }
                    else if(Test3 == true) {
                        OSD::Notify("Test3: Disabled", Color::Red);
                        Test3Color = 0xFF0000FF;
                        Test3 = false;
                    }
                }
            }
        }
    }
}