/*
 * Copyright (C) 2021 Chris Lamberson
 *
 * This file is part of Ingrate.
 *
 * Ingrate is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * Ingrate is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Ingrate.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

int
main(int argc, char **argv)
{
  SDL_Window *win;
  SDL_Event ev;

  SDL_Init(SDL_INIT_VIDEO);

  if (!(win = SDL_CreateWindow("Ingrate",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               400, 300, 0)))
  {
    fprintf(stderr, "%s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  for (;;) {
    SDL_WaitEvent(&ev);

    switch (ev.type) {
    case SDL_QUIT:
      goto done;
    }
  }

done:
  SDL_Quit();
  return EXIT_SUCCESS;
}
