#include "MenuFont.h"

MenuFont::MenuFont()
{
	tex_fontImg = GRRLIB_LoadTexture(GameFont);
	GRRLIB_InitTileSet(tex_fontImg, 16,16,32);
}
	
MenuFont::~MenuFont()
{

}
