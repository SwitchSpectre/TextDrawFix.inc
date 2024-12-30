# ⚓ TextDrawFix - Include

## Credits

  Suporte - [Undefined](https://github.com/guil2k7)
  Suporte - [Ferreira Mapper]()

# 📓 Description

Olá, esta include adiciona funções que substituem as funções padrão do textdraw-streamer e as funções de TextDraw padrão da biblioteca a_samp, oferecendo uma forma mais simples de utilizar certas funções. Além disso, ela adiciona um recurso de depuração (debug) que deveria vir como padrão no textdraw-streamer. Esse recurso ajuda a evitar a sobreposição de IDs na criação de TextDraws, prevenindo bugs que podem ocorrer ao clicar em um TextDraw e ativar a resposta de outro.
# New Functions

```pawn
// Player
stock DestroyPlayerTDList(playerid, PlayerText:list[MAX_PLAYERS][], length = sizeof list[]);
stock ShowPlayerTDList(playerid, const PlayerText:list[MAX_PLAYERS][], bool:allowClick = false, length = sizeof list[]);
stock HidePlayerTDList(playerid, const PlayerText:list[MAX_PLAYERS][], length = sizeof list[]);

// Global
stock HideTDList(playerid, Text:list[], length = sizeof list);
stock ShowTDList(playerid, const Text:list[], length = sizeof list);

```
### Exemple

```pawn
static PlayerText:My_Textdraw[MAX_PLAYERS][3] = {INVALID_PLAYER_TEXT_DRAW, ...};

hook OnPlayerConnect(playerid) {
    CreateTDs(playerid);
    return true;
}
CreateTDs(playerid) {
    My_Textdraw[playerid][0] = CreatePlayerTextDraw(playerid, 0.0, 0.0, "LD_SPAC:white");
    My_Textdraw[playerid][1] = CreatePlayerTextDraw(playerid, 0.0, 0.0, "LD_SPAC:white");
    My_Textdraw[playerid][2] = CreatePlayerTextDraw(playerid, 0.0, 0.0, "LD_SPAC:white");

    ShowPlayerTDList(playerid, My_Textdraw, false);
    SetTimerEx("DestroyTDs", 5000, false, "i", playerid);
}
forward DestroyTDs(playerid);
public DestroyTDs(playerid) {
    DestroyPlayerTDList(playerid, My_Textdraw);
    return true;
}
```
Os Loppings Sao Feitos de Forma Automatica!

Na Criaçao de Cada TextDraw Devera ser adicionado o Parametro **INVALID_PLAYER_TEXT_DRAW**
```pawn

//Modo Incorreto
static PlayerText:My_Textdraw[MAX_PLAYERS][3];

// Modo Correto
static PlayerText:My_Textdraw[MAX_PLAYERS][3] = {INVALID_PLAYER_TEXT_DRAW, ...};

```

Requesitos:

## [textdraw-streamer](https://github.com/guil2k7/samp-textdraw-streamer)