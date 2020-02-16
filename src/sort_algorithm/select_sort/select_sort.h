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
#ifndef SELECT_SORT_H_
#define SELECT_SORT_H_

namespace ads { // Algorithm and Data Structure

template <typename Iterator,
          typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void select_sort(Iterator first, Iterator last, Compare compare=Compare()) {
	auto len = std::distance(first, last);
	if (len < 2)	return;
	for (auto beg = first; beg != last; ++beg) {
		auto min_iter = beg;
		for (auto iter = beg; iter != last; ++iter) {
			if (compare(*iter, *min_iter))
				min_iter = iter;
		}
		std::swap(*beg, *min_iter);
	}
}

} // namespace ads

#endif // SELECT_SORT_H_
