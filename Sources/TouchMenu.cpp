#include "cheats.hpp"

namespace CTRPluginFramework {
    u32 Test1Color = 0xFF0000FF;
    u32 Test2Color = 0xFF0000FF;
    u32 Test3Color = 0xFF0000FF;
    bool Test1, Test2, Test3;

    int cursorx = 30;
    int cursory = 30;

    void EDCheats(u32 &color, std::string name, bool cheats) {
        if (cheats) {
            OSD::Notify(Utils::Format("%s: Disabled", name.c_str()), Color::Red);
            color = 0x00FF00FF;
            cheats = false;
        } else {
            OSD::Notify(Utils::Format("%s: Enabled", name.c_str()), Color::Green);
            color = 0xFF0000FF;
            cheats = true;
        }
    }

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
    
    void TouchMenu() {
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
                    EDCheats(Test1Color, "Test1", Test1);
                }
                else if(cursorx >= 5 && cursorx <= 9 && cursory >= 27 && cursory <= 31) {
                    EDCheats(Test2Color, "Test2", Test2);
                }
                else if(cursorx >= 5 && cursorx <= 9 && cursory >= 37 && cursory <= 41) {
                    EDCheats(Test3Color, "Test3", Test3);
                }
            }
        }
    }
}