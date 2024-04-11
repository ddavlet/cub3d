/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:00:24 by mrizhakov         #+#    #+#             */
/*   Updated: 2024/04/11 21:38:03 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int map_parsing(char *filename)
{
    int fd;
    char *map;
    // map = NULL;
    printf("Parsing map\n");
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening map\n");
        close(fd);
        exit(errno);
    }
    if (fd != -1)
    {
        printf("File : %s \n", filename);
        printf("Map opened\n");
    }
    printf("Logging out map for debugging purposes\n");

    map = get_next_line(fd);
    printf("%s", map);
    free(map);

    while (map != NULL)
    // while (map != NULL || ft_strncmp(map, "(null)", 6) == 0)
    {
        map = get_next_line(fd);
        printf("%s", map);
        free(map);
    }
    close(fd);
    return (0);
}