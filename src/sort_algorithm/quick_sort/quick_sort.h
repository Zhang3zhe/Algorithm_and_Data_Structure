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
#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

namespace ads { // Algorithm and Data Structure

// ��Ҫ�ѵ�3�������β�Ҳ����ΪĬ�ϲ������� partition_iter =  last - 1
// ����ģ����Ʋ���֧�ִӺ����β��Ƶ������β�
template <typename RandomAccessIterator, typename Compare = std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>>
RandomAccessIterator partition(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator partition_iter, Compare compare=Compare()) {
	if (last - first == 0)	return last;
	std::swap(*(partition_iter), *(last - 1));
	auto current = first;
	auto less_next = first;
	while (current != (last - 1)) {
		if (compare(*current, *(last - 1))) {
			std::swap(*current, *less_next);
			++ less_next;
		}
		++ current;
	}
	std::swap(*less_next, *(last - 1));
	return less_next;
}

// ���㷨������ָ�� ����С�Ƚϱ�׼�� �ķ����㷨
// ����Ĭ��ģ����� std::less<>
template <typename RandomAccessIterator, typename Compare = std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>>
inline void quick_sort(RandomAccessIterator first, RandomAccessIterator last, Compare compare=Compare()) {
	if (last - first < 2)	return;
	auto pivot_iter = ads::partition(first, last, last - 1, compare);
	quick_sort(first, pivot_iter, compare);
	if(pivot_iter != last)
		quick_sort(pivot_iter + 1, last, compare);
}

} // namespace ads

#endif // QUICK_SORT_H_
