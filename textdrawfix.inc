







#if !defined _INC_textdraw_streamer
	#error Use include textdraw-streamer!
#endif
#define _INC_textdraw_streamer






stock DestroyPlayerTDList(playerid, PlayerText:list[MAX_PLAYERS][], length = sizeof list[]) {
    CancelSelectTextDraw(playerid);

    for (new i; i < length; ++i) {
        PlayerTextDrawDestroy(playerid, list[playerid][i]);
        list[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
    }
}

stock ShowPlayerTDList(playerid, const PlayerText:list[MAX_PLAYERS][], bool:allowClick = false, length = sizeof list[]) {
    for (new i; i < length; ++i)
        PlayerTextDrawShow(playerid, list[playerid][i]);

    if (allowClick)
        SelectTextDraw(playerid, 0xFFFFFF7F);

    return 1;
}

stock HidePlayerTDList(playerid, const PlayerText:list[MAX_PLAYERS][], length = sizeof list[]) {
    for (new i; i < length; ++i)
        PlayerTextDrawHide(playerid, list[playerid][i]);

    return 1;
}

stock HideTDList(playerid, Text:list[], length = sizeof list) {
    for (new i; i < length; ++i)
        TextDrawHideForPlayer(playerid, list[i]);

    return 1;
}

stock ShowTDList(playerid, const Text:list[], length = sizeof list) {
    for (new i; i < length; ++i)
        TextDrawShowForPlayer(playerid, list[i]);

    return 1;
}