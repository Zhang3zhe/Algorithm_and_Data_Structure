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
#ifndef BUCKET_SORT_H_
#define BUCKET_SORT_H_
#include<vector>
#include<cassert>
#include"src/sort_algorithm/insert_sort/insert_sort.h"

namespace ads { // Algorithm and Data Structure

template <typename Iterator>
void bucket_sort(const Iterator first, const Iterator last,
	             const typename std::iterator_traits<Iterator>::value_type& min_val,
                 const typename std::iterator_traits<Iterator>::value_type& max_val,
                 const std::size_t bucket_size = 10) {
	typedef typename std::iterator_traits<Iterator>::value_type T;
	assert(min_val <= max_val);
	auto len = std::distance(first, last);
	if (len < 2)	return;
	std::vector<std::vector<T>> buckets(bucket_size, std::vector<T>());
	for (auto iter = first; iter != last; ++iter) {
		auto index = (*iter - min_val) * bucket_size / (max_val - min_val + 1);
		buckets.at(index).push_back(*iter);
	}
	auto pos_iter = first;
	for (std::size_t i = 0; i < bucket_size; ++i) {
		insert_sort(buckets[i].begin(), buckets[i].end());
		std::copy(buckets[i].begin(), buckets[i].end(), pos_iter);
		pos_iter += buckets[i].size();
	}
}

} // namespace ads

#endif // BUCKET_SORT_H_
