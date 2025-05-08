#include "cub3d.h"

void    init_data(t_cub *cub)
{
    cub->elements.C = 0;
    cub->elements.E = 0;
    cub->elements.EA = 0;
    cub->elements.F = 0;
    cub->elements.N = 0;
    cub->elements.NO = 0;
    cub->elements.C = 0;
    cub->elements.F = 0;
    cub->elements.SO = 0;
    cub->elements.WE = 0;
}

// mlx_image_t** transfer_to_two_dimensional(mlx_image_t* image)
// {
//     int i = 0;
//     int j = 0;
//     mlx_image_t** new_image = malloc((image->height + 1) * sizeof(mlx_image_t *));

//     while(i < image->height)
//     {
//         j = 0;
//         while(j < image->width)
//         {
//             new_image[i][j].pixels = image[i].pixels;
//         }
//     }
// }

// void    convert_png_to_image(t_cub *cub)
// {
//     cub->images.north_image = transfer_to_two_dimensional(mlx_texture_to_image(cub->mlx.mlx_ptr, cub->textures.north_texture));
//     mlx_delete_texture(cub->textures.north_texture);
//     cub->images.south_image = transfer_to_two_dimensional(mlx_texture_to_image(cub->mlx.mlx_ptr, cub->textures.south_texture));
//     mlx_delete_texture(cub->textures.south_texture);
//     cub->images.west_image = transfer_to_two_dimensional(mlx_texture_to_image(cub->mlx.mlx_ptr, cub->textures.west_texture));
//     mlx_delete_texture(cub->textures.west_texture);
//     cub->images.east_image = transfer_to_two_dimensional(mlx_texture_to_image(cub->mlx.mlx_ptr, cub->textures.east_texture));
//     mlx_delete_texture(cub->textures.east_texture);
//     if (!cub->images.north_image || !cub->images.south_image || !cub->images.west_image || !cub->images.east_image)
//     {
//         ft_free(cub->map.map);
//         printf("%s\n", mlx_strerror(mlx_errno));
//         mlx_delete_texture(cub->textures.north_texture);
//         mlx_delete_texture(cub->textures.south_texture);
//         mlx_delete_texture(cub->textures.west_texture);
//         mlx_delete_texture(cub->textures.east_texture);
//         exit(1);
//     }
// }

int main(int ac, char **av)
{
    if(ac == 2)
    {
        t_cub cub;
        check_file(av[1]);
        init_data(&cub);
        parsing_file(&cub, av[1]);
        cub.mlx.mlx_ptr = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", 0);
        // convert_png_to_image(&cub);
        mlx_loop_hook(cub.mlx.mlx_ptr, key_hook, &cub);
        mlx_loop(cub.mlx.mlx_ptr);     
    }
    else
    {
        write(2, "Invalid Arguments!\n", ft_strlen("Invalid Arguments!\n"));
        return(1);
    }
    return(0);
}
