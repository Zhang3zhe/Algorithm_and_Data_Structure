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
#ifndef SELECT_H_
#define SELECT_H_
#include<cassert>
#include"src/sort_algorithm/quick_sort/quick_sort.h"

namespace ads { // Algorithm and Data Structure

// 对于 A[0..n-1]， rank = 0 表示求最小值， rank = n - 1 表示求最大值
// rank = 1 表示求次小值
template <typename RandomAccessIterator, typename Compare = std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>>
typename std::iterator_traits<RandomAccessIterator>::value_type
select(RandomAccessIterator first, RandomAccessIterator last,
       typename std::iterator_traits<RandomAccessIterator>::difference_type rank, Compare compare=Compare()) {
	auto len = last - first;
	assert(len > 0 && rank >= 0 && rank < len);
	if (len == 1 && rank == 0)	  return *first;
	auto partition_iter = partition(first, last, last - 1, compare);
	auto distance = partition_iter - first;
	if (rank == distance)
		return *partition_iter;
	else if (rank < distance)
		return select(first, partition_iter, rank, compare);
	else
		return select(partition_iter + 1, last, rank - distance - 1, compare);
}

} // namespace ads

#endif // SELECT_H_
