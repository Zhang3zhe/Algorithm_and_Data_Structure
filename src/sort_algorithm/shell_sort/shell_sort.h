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
#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_

namespace ads { // Algorithm and Data Structure

template <typename RandomAccessIterator, typename Compare = std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>>
void shell_sort(const RandomAccessIterator first, const RandomAccessIterator last, Compare compare=Compare()) {
	const auto len = std::distance(first, last);
	if (len < 2)	return;
	for (std::size_t gap = (len >> 1); gap > 0; gap = (gap >> 1)) {
		for (std::size_t group = 0; group < gap; ++group) {
			for (std::size_t current = group + gap; current < (std::size_t)len; current += gap) {
				if (compare(*(first + current), *(first + current - gap))) {
					auto key = *(first + current);
					int i = (int)current - gap;
					while (i >= 0 && compare(key, *(first + i))) {
						*(first + gap + i) = *(first + i);
						i -= gap;
					}
					*(first + gap + i) = key;
				}
			}
		}
	}
}

} // namespace ads

#endif // SHELL_SORT_H_
