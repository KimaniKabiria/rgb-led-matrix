//     RGB Matrix Project - RGBImage
//     Copyright (C) 2017 Michael Kamprath
//
//     This file is part of RGB Matrix Project.
// 
//     RGB Matrix Project is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
// 
//     RGB Matrix Project is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
// 
//     You should have received a copy of the GNU General Public License
//     along with RGB Matrix Project.  If not, see <http://www.gnu.org/licenses/>.
#ifndef __RGBIMAGE_H__
#define __RGBIMAGE_H__

/***

Each byte controls one LED. Each color get two bits to indicate color intensity (0,1,2,3).
The bits of the byte are laid out as follows:

	Bits   0   4
		   |---|---
		   TURRGGBB

	T = transparent
	U = unused
	R = Red
	G = Green
	B = Blue

*/
class Glyph;

typedef unsigned char ColorType;

const ColorType TRANSPARENT_COLOR = B10000000;
const ColorType WHITE_COLOR = 0x3F;
const ColorType GRAY_COLOR = 0x2A;
const ColorType DARK_GRAY_COLOR = 0x15;
const ColorType BLACK_COLOR = 0;
const ColorType RED_COLOR = 0x30;
const ColorType GREEN_COLOR = 0x0C;
const ColorType BLUE_COLOR = 0x03;
const ColorType YELLOW_COLOR = 0x3C;
const ColorType AQUA_COLOR = 0x0F;
const ColorType MAGENTA_COLOR = 0x33;
const ColorType PINK_COLOR = 0x26;
const ColorType ORANGE_COLOR = 0x34;
const ColorType CORAL_COLOR = 0x39;
const ColorType TURQUOISE_COLOR = 0x1E;
const ColorType VIOLET_COLOR = 0x27;
const ColorType PURPLE_COLOR = B00010001;
const ColorType LIME_COLOR = 0x2D;
const ColorType SLATE_BLUE_COLOR = 0x16;

const static unsigned char RED_MASK = 0x30;
const static unsigned char RED_BIT_SHIFT = 4;

const static unsigned char GREEN_MASK = 0x0C;
const static unsigned char GREEN_BIT_SHIFT = 2;

const static unsigned char BLUE_MASK = 0x03;
const static unsigned char BLUE_BIT_SHIFT = 0;

class RGBImage {
private:
	int _rows;
	int _columns;
	ColorType* _data;

	int _dataSize;
	
	bool _dirty;

public:
	RGBImage(int rows, int columns);
	RGBImage(int rows, int columns, ColorType* data );
	RGBImage(const RGBImage& other);
	virtual ~RGBImage();

	int rows(void) const		{ return _rows; }
	int columns(void) const		{ return _columns; }

	bool isDirty( void) const	{ return _dirty; }
	void setNotDirty()			{ _dirty = false; }
	
	void copy(const RGBImage& other);

	ColorType& pixel( int row, int column );
	const ColorType& pixel( int row, int column ) const;
	
	
	void placeImageAt( const RGBImage& image, int row, int column );
	void paintColor( ColorType color ); 
	void drawLine(
		int startRow,
		int startColumn,
		int stopRow,
		int stopColumn,
		ColorType color
	);
	void drawRectangle( 
		int tlRow,
		int tlColumn,
		int brRow,
		int brColumn,
		ColorType color,
		bool fill = true
	);
	
	void drawGlyph(
			const Glyph& image,
			int row,
			int column,
			ColorType foreground,
			ColorType background = TRANSPARENT_COLOR
		);
};

#endif //__RGBIMAGE_H__
