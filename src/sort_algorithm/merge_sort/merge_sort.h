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
#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_
#include<vector>

namespace ads { // Algorithm and Data Structure

template <typename RandomAccessIterator,
          typename Compare = std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>>
void merge(RandomAccessIterator first, RandomAccessIterator middle,
           RandomAccessIterator last, Compare compare=Compare()) {
	typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
	if (std::distance(first, middle) < 1 || std::distance(middle, last) < 1)    return;
	std::vector<T> temp(first, last);
	auto current = temp.begin();
	auto lhs_iter = first;
	auto rhs_iter = middle;
	while (lhs_iter != middle && rhs_iter != last) {
		if (compare(*lhs_iter, *rhs_iter))
			*current++ = *lhs_iter++;
		else
			*current++ = *rhs_iter++;
	}
	if (lhs_iter != middle && rhs_iter == last)
		std::copy(lhs_iter, middle, current);
	if (lhs_iter == middle && rhs_iter != last)
		std::copy(rhs_iter, last, current);
	std::copy(temp.begin(), temp.end(), first);
}

template <typename RandomAccessIterator,
          typename Compare = std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last, Compare compare=Compare()) {
	auto len = std::distance(first, last);
	if (len < 2)    return;
	auto middle = first + (len >> 1);
	merge_sort(first, middle);
	merge_sort(middle, last);
	merge(first, middle, last, compare);
}

} // namespace ads

#endif // MERGE_SORT_H_
