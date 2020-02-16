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
#ifndef RADIX_SORT_H_
#define RADIX_SORT_H_
#include<cmath>
#include<cassert>
#include"src/sort_algorithm/insert_sort/insert_sort.h"

namespace ads { // Algorithm and Data Structure

namespace _RadixSort {

template <typename T>
T _digit_on_n(T num, std::size_t n) {
	static_assert(std::is_integral<T>::value, "T must be integer!");
	assert(num >= 0);
	return num / (T)std::pow(10, n) - num / (T)std::pow(10, n + 1) * 10;
}

} // namespace _RadixSort

using _RadixSort::_digit_on_n;

template <typename Iterator>
void radix_sort(const Iterator first, const Iterator last, std::size_t width) {
	typedef typename std::iterator_traits<Iterator>::value_type T;
	static_assert(std::is_integral<T>::value, "Sequence to be sorted must be integer!");
	assert(width > 0);
	auto len = std::distance(first, last);
	if (len < 2)	return;
	for (std::size_t i = 0; i < width; ++i) {
		auto compare = [i](T lhs, T rhs) { return _digit_on_n(lhs, i) < _digit_on_n(rhs, i); };
		insert_sort(first, last, compare);
	}
}

} // namespace ads

#endif // RADIX_SORT_H_
