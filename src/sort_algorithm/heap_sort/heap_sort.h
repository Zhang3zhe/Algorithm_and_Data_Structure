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
#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

namespace ads { // Algorithm and Data Structure

namespace _HeapSort {

// ����ά�����ѵ�����
template <typename RandomAccessIterator, typename Distance>
void _max_heapify(RandomAccessIterator first, RandomAccessIterator last, Distance index) {
	Distance len = last - first;
	if (index >= len)	return;
	auto left = (index << 1) + 1;
	auto right = (index + 1) << 1;
	auto largest = index;
	if (left < len && *(first + left) > *(first + index))
		largest = left;
	if (right < len && *(first + right) > *(first + largest))
		largest = right;
	if (largest != index) {
		std::swap(*(first+index), *(first+largest));
		// �˴����õݹ�ʵ�֣�STL������ѭ��ʵ�ֵ�
		_max_heapify(first, last, largest);
	}
}

template <typename RandomAccessIterator>
void _build_max_heap(RandomAccessIterator first, RandomAccessIterator last) {
	if (last - first < 2)	return;
	auto len = last - first;
	auto index = (len - 2) >> 1;	// ��Ҫע������ҿ�  [ ) �ı߽�����
	while (true) {	  // �� for ѭ���� unsigned ���͵ĵݼ��������б߽�ȷ����������
		_max_heapify(first, last, index);
		if (index == 0)	  return;
		-- index;
	}
}

} // namespace _HeapSort

using _HeapSort::_build_max_heap;
using _HeapSort::_max_heapify;

// ����ָ�� ����С�Ƚϱ�׼�� ������汾�� heap_sort() δ����ʵ��
template <typename RandomAccessIterator>
void heap_sort(RandomAccessIterator first, RandomAccessIterator last) {
	if (last - first < 2)	return;
	_build_max_heap(first, last);
	auto len = last - first;
	for (auto i = len - 1; i > 0; --i) {
		std::swap(*first, *(first + i));
		-- last;
		_max_heapify(first, last, 0);
	}
}

} // namespace ads

#endif // HEAP_SORT_H_
