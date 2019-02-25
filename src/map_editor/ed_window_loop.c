
#include "wolf3d.h"

static void		refresh_window(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	SDL_RenderClear(win->rend);
	put_map(win);
	SDL_RenderPresent(win->rend);
}


static void		keyboard_event(t_win *win, const Uint8 *state)
{
	if (state[SDL_SCANCODE_W])
		win->pos.y -= 1;
	else if (state[SDL_SCANCODE_S])
		win->pos.y += 1;
	if (state[SDL_SCANCODE_A])
		win->pos.x -= 1;
	else if (state[SDL_SCANCODE_D])
		win->pos.x += 1;

}

static int	pevent(t_win *win, SDL_Event event)
{
	if (event.type == SDL_QUIT)
            return (0);
	else if (event.type == SDL_MOUSEWHEEL)
	{
		if (event.wheel.y > 0)
			win->map.unit += 1;
		else if (event.wheel.y < 0)
			win->map.unit = (win->map.unit > 1) ? win->map.unit -1 : 1;
		printf("unit = %d\n", win->map.unit);
	}
	return (1);
}

int ed_window_loop(t_win *win)
{
	const Uint8 *state;
	SDL_Event	event;
	int loop;

	state = SDL_GetKeyboardState(NULL);
	loop = 1;
	if (!win)
		return (0);
	while (loop)
	{
		SDL_PumpEvents();
		keyboard_event(win, state);
		if (SDL_PollEvent(&event))
			if (!pevent(win, event))
				loop = 0;
		refresh_window(win);
	}
	return (1);
}