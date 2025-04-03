

int	ft_clean_init_raycast(t_data *data)
{
	if (!ft_get_player_dir(data))
		return (1);
	if (!ft_get_player_pos(data))
		return (1);
	return (0);
}
