#include "tui.hpp"
#include <ncurses.h>
#include <iostream>

namespace tui {
    void run(std::vector<ProxyInfo>& proxies) {
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);

        int highlight = 0;
        int ch;
        while(true) {
            clear();
            mvprintw(0,0,"yetanotherproxy - q quit, up/down select");
            for(int i=0;i<proxies.size() && i<20;i++) {
                if(i==highlight) attron(A_REVERSE);
                int color = proxies[i].ok ? 1 : 2;
                attron(COLOR_PAIR(color));
                mvprintw(i+2,0,"%s:%d latency=%.0fms",
                    proxies[i].ip.c_str(), proxies[i].port, proxies[i].latency_ms);
                attroff(COLOR_PAIR(color));
                if(i==highlight) attroff(A_REVERSE);
            }
            refresh();
            ch = getch();
            if(ch=='q') break;
            else if(ch==KEY_DOWN && highlight<proxies.size()-1) highlight++;
            else if(ch==KEY_UP && highlight>0) highlight--;
        }
        endwin();
    }
}
