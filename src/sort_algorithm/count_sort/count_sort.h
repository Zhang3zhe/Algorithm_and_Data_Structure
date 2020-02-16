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
#ifndef COUNT_SORT_H_
#define COUNT_SORT_H_
#include<vector>

namespace ads { // Algorithm and Data Structure

template <typename RandomAccessIterator>
void count_sort(RandomAccessIterator first, RandomAccessIterator last,
                const typename std::iterator_traits<RandomAccessIterator>::value_type& max_val) {
	typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
	static_assert(std::is_integral<T>::value, "Sequence to be sorted must be integer!");
	if (last - first < 2)	return;
	auto len = last - first;
	std::vector<T> counter(max_val + 1);
	std::vector<T> result(len);
	for (auto iter = first; iter != last; ++iter)
		++ counter[*iter];
	for (size_t i = 1; i < counter.size(); ++i)
		counter[i] += counter[i - 1];
	for (size_t i = len; i > 0; --i) {
		size_t j = i - 1;
		result[counter[*(first + j)] - 1] = *(first + j);
		-- counter[*(first + j)];
	}
	std::copy(result.begin(), result.end(), first);
}

} // namespace ads

#endif // COUNT_SORT_H_
