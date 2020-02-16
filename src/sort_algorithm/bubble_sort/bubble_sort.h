/**
 * Copyright (c) 2020-02 https://github.com/Zhang3zhe All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

namespace ads { // Algorithm and Data Structure

template <typename Iterator,
          typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void bubble_sort(Iterator first, Iterator last, Compare compare=Compare()) {
	auto len = std::distance(first, last);
	if (len < 2)	return;
	for (auto i = 0; i < len - 1; ++i) {
		-- last;
		for (auto iter = first; iter != last; ++iter) {
			auto next = iter;
			++ next;
			if (compare(*next, *iter))
				std::swap(*iter, *next);
		}
	}
}

} // namespace ads

#endif // BUBBLE_SORT_H_
