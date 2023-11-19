#pragma once
#ifndef __XML_TAGS_H__
#define __XML_TAGS_H__

namespace XMLTags {
	//Level
	const char* const ROOT = "Level";

	const char* const ROW_COUNT = "RowCount";
	const char* const COLUMN_COUNT = "ColumnCount";
	const char* const ROW_SPACING = "RowSpacing";
	const char* const COLUMN_SPACING = "ColumnSpacing";
	const char* const BACKGROUND_TEXTURE = "BackgroundTexture";

	//Bricks
	const char* const BRICK_TYPES = "BrickTypes";
	const char* const BRICK_TYPE = "BrickType";
	
	const char* const ID = "Id";
	const char* const TEXTURE = "Texture";
	const char* const HIT_POINTS = "HitPoints";
	const char* const HIT_SOUND = "Hit_Sound";
	const char* const BREAK_SOUND = "BreakSound";
	const char* const BREAK_SCORE = "BreakScore";

	const char* const BRICK_PLACEMENT = "Bricks";
}

#endif // !__XML_TAGS_H__
