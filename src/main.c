/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:11:18 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/17 17:53:43 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void randomizeCell(char **grid) {
    int x, y;
    do {
        x = rand() % 20;
        y = rand() % 40;
    }
    while (grid[x][y] != '0');
    grid[x][y] = '1';
}

void audio_callback(void *userdata, Uint8 *stream, int len)
{
	(void)userdata;
    static int phase = 0;
    for (int i = 0; i < len / 2; i++, phase++) {
        ((Sint16*)stream)[i] = (phase / 200 % 2) ? AMPLITUDE : -AMPLITUDE;
    }
}

void play_fizzbuzz_sound4()
{
    SDL_AudioSpec spec;
    spec.freq = 121212;
    spec.format = AUDIO_S16SYS;
    spec.channels = 4;
    spec.samples = 4096;
    spec.callback = audio_callback;

    if (SDL_OpenAudio(&spec, NULL) < 0) {
        printf("Erreur audio : %s\n", SDL_GetError());
        return;
    }

    SDL_PauseAudio(0);
    Mix_SetPanning(255, 255, 255);
    SDL_Delay(32);
    SDL_CloseAudio();
}

void play_fizzbuzz_sound3()
{
    SDL_AudioSpec spec;
    spec.freq = 210000;
    spec.format = AUDIO_S16SYS;
    spec.channels = 4;
    spec.samples = 4096;
    spec.callback = audio_callback;

    if (SDL_OpenAudio(&spec, NULL) < 0) {
        printf("Erreur audio : %s\n", SDL_GetError());
        return;
    }

    SDL_PauseAudio(0);
    SDL_Delay(90); // Jouer pendant 500ms
    SDL_CloseAudio();
}

void play_fizzbuzz_sound2()
{
    SDL_AudioSpec spec;
    spec.freq = SAMPLE_RATE;
    spec.format = AUDIO_S16SYS;
    spec.channels = 4;
    spec.samples = 4096;
    spec.callback = audio_callback;

    if (SDL_OpenAudio(&spec, NULL) < 0) {
        printf("Erreur audio : %s\n", SDL_GetError());
        return;
    }

    SDL_PauseAudio(0);
    SDL_Delay(90); // Jouer pendant 500ms
    SDL_CloseAudio();
}

void play_fizzbuzz_sound()
{
    SDL_AudioSpec spec;
    spec.freq = 0;
    spec.format = AUDIO_S16SYS;
    spec.channels = 4;
    spec.samples = 8196;
    spec.callback = audio_callback;

    if (SDL_OpenAudio(&spec, NULL) < 0)
    {
        printf("Erreur audio : %s\n", SDL_GetError());
        return;
    }

    SDL_PauseAudio(0);
    SDL_Delay(500);
    SDL_CloseAudio();
}

void applyFizzBuzz(char **grid, int n)
{
    if (n % 3 == 0 && n % 5 == 0)
    {
        for (int i = 0; i < 40; i++)
            for (int j = 0; j < 60; j++)
                if (grid[i][j] == '1' || grid[i][j] == '2')
                    grid[i][j] = '0';
        printf("FizzBuzz!\n");
		play_fizzbuzz_sound();
        randomizeCell(grid);
    }
    if (n % 3 == 0)
    {
        for (int i = 0; i < 40; i++)
            for (int j = 0; j < 60; j++)
                if (grid[i][j] == '1')
                    grid[i][j] = '2';
        printf("Fizz!\n");
        play_fizzbuzz_sound2();
        randomizeCell(grid);
    }
    else if (n % 5 == 0)
    {
        for (int i = 0; i < 40; i++)
            for (int j = 0; j < 60; j++)
                if (grid[i][j] == '2')
                    grid[i][j] = '1';
        printf("Buzz!\n");
        play_fizzbuzz_sound3();
        randomizeCell(grid);
    }
}

int	exit_param(void *param)
{
	(void)param;
	exit(0);
}

int	begin_render(t_game *game, char **grid)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error, impossible to init mlx\n");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, 40 * 64,
			20 * 64 + 90, "FizzBuzz");
	if (!game->win)
	{
		ft_printf("Error, impossible to init win\n");
		return (0);
	}
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!game->textures)
	{
		ft_printf("Error, impossible to create textures\n");
		return (0);
	}
	get_images(game);
	render_map(game, grid);
	return (1);
}

int	main(void)
{
	t_game	game;

	char **grid;
	char *line = "0000000000000000000000000000000000000000000000000000000000000";

	SDL_Init(SDL_INIT_AUDIO);
	grid = malloc(sizeof(char *) * 40);
    for (int i = 0; i < 40; i++)
		grid[i] = ft_strdup(line);
	if (!begin_render(&game, grid))
	{
		ft_printf("Error, Render impossible !\n");
		free_resources(&game);
		return (0);
	}
	srand(time(NULL));

    for (int i = 1; i <= ITERATIONS; i++) {
        printf("%d\n", i);
        randomizeCell(grid);
        applyFizzBuzz(grid, i);
		play_fizzbuzz_sound4();
		render_map(&game, grid);
    }
    mlx_loop(game.mlx);
	free_resources(&game);
	SDL_Quit();
	return (1);
}
