//     RGB Matrix Project - Utils
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
#ifndef __UTILS_H__
#define __UTILS_H__


void * memcpy_smart(
			void * dest,
			const void * src,
			size_t n,
			bool isSrcProgMem
		)
{
	if (isSrcProgMem) {
		return memcpy_P(dest, src, n);
	} else {
		return memcpy(dest, src, n);
	}
} 


#endif

