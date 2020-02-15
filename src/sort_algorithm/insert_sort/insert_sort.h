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
#ifndef INSERT_SORT_H_
#define INSERT_SORT_H_

namespace ads { // Algorithm and Data Structure

// 不局限于随机访问迭代器， vector 和 list 都能使用
template <typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void insert_sort(const Iterator first, const Iterator last, Compare compare=Compare()) {
	auto len = std::distance(first, last);
	if (len < 2)	return;
	auto current = first;	
	for (++current; current != last; ++current) {
		auto key = *current;
		auto iter = current;
		while (std::distance(first, iter) > 0 && compare(key, *(--iter))) {
			auto temp_iter = iter;
			++ temp_iter;
			*temp_iter = *iter;
		}
		auto iter_copy = iter;
		++ iter_copy;
		if (std::distance(first, iter_copy) > 0 && !compare(key, *(--iter_copy)))    ++ iter;
		*iter = key;
	}
}

} // namespace ads

#endif // INSERT_SORT_H_
