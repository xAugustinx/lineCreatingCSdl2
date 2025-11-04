#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>


int tworzenieLini(SDL_Renderer* renderWFunkcji, int poczotekX,int poczotekY,int koniecX,int koniecY)
{
    if (poczotekX > koniecX) {
        int meowMeowUwU = poczotekX;

        poczotekX = koniecX;
        koniecX = meowMeowUwU;
    }
    if (poczotekY > koniecY) {
        int meowMeowUwU = poczotekY;

        poczotekY = koniecY;
        koniecY = meowMeowUwU;
    }

    int deltaX = koniecX - poczotekX;
    int deltaY = koniecY - poczotekY;

    double pierwiastek = sqrt( deltaX*deltaX + deltaY*deltaY);


    double proporcjeX = (double)pierwiastek / deltaX;
    double proporcjeY = (double)pierwiastek / deltaY;

    proporcjeX = (double)deltaY / (double)deltaX;
    proporcjeY = (double)deltaX / (double)deltaY;

    double licznikX = 0;
    double licznikY = 0;

    for (int i = 0; i < pierwiastek; i++) {
        for (int superProporcjeX = 0; superProporcjeX < proporcjeX; superProporcjeX++) {
            SDL_RenderDrawPoint(renderWFunkcji, poczotekX + (int)licznikX + superProporcjeX, poczotekY + (int)licznikY);
        }
        for (int superProporcjeY = 0; superProporcjeY < proporcjeY; superProporcjeY++) {
            SDL_RenderDrawPoint(renderWFunkcji, poczotekX + (int)licznikX , poczotekY + (int)licznikY + superProporcjeY);
        }

        licznikX = (double)licznikX + (double)proporcjeX;
        licznikY = (double)licznikY + (double)proporcjeY;
    }
}

int main() {
    SDL_Window* meowOkno = SDL_CreateWindow (
        "FajneOkno",
        150,
        100,
        1500,
        1000,
        SDL_WINDOW_SHOWN
        );

    SDL_Renderer* meowRender = SDL_CreateRenderer (meowOkno, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event meowEvent;
    SDL_RenderSetLogicalSize(meowRender,150,100);

    int wyloczanieProgramu = 1;

    while (wyloczanieProgramu) {
        SDL_SetRenderDrawColor(meowRender,0,0,0,255);
        SDL_RenderClear(meowRender);

        SDL_SetRenderDrawColor(meowRender,255,255,255,255);

        tworzenieLini(meowRender,1,1,20,40);

        while (SDL_PollEvent(&meowEvent)) {
            if (meowEvent.type == SDL_QUIT ) {
                wyloczanieProgramu = 0;
            }
        }

        SDL_RenderPresent(meowRender);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer (meowRender);
    SDL_DestroyWindow (meowOkno);
    return 0;


}